//<>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cmath>
#include<random>




//Calculate midpoint for a certain square
std::vector<std::vector<double>> midPointDisplacement2D(double H, int nrIterations, bool bordeDisplacement){
    double range;
    int length = pow(2, nrIterations) + 1; //how many values do we have thanks to the number of iterations we want to build the terrain
    int step = length - 1;


    std::vector<std::vector<double>> zValues(length, std::vector<double>(length, 0));

    int halfStep = step/2;

    if(bordeDisplacement){
        range = pow(2, -2*H) * 10 * 3.5;
        std::random_device rd;  // Utiliza un dispositivo de entropía para inicializar el generador
        std::mt19937 gen(rd()); // Mersenne Twister generador inicializado con rd()

        // Definir la distribución entre -x y x
        std::uniform_real_distribution<> distrib(-range, range);

        zValues[0][0] = distrib(gen);
        zValues[0][step] = distrib(gen); 
        zValues[step][step] = distrib(gen); 
        zValues[step][0] = distrib(gen); 
    }


    //Step value goes for x and y axis

    for (int n = 1; n <= nrIterations; n++){ //do this nrIterations times
        range = pow(2, -2*n*H) * 10 * 3.5;

        std::random_device rd;  // Utiliza un dispositivo de entropía para inicializar el generador
        std::mt19937 gen(rd()); // Mersenne Twister generador inicializado con rd()

        // Definir la distribución entre -x y x
        std::uniform_real_distribution<> distrib(-range, range);

        for (int i = 0; i < length - step; i+=step){
            for (int j = 0; j < length - step; j+=step){
                //upper midpoint of square
                zValues[i+step][j+halfStep] = (zValues[i+step][j] + zValues[i+step][j+step])/2 + distrib(gen);
                //lower midpoint of square
                zValues[i][j+halfStep] = (zValues[i][j] + zValues[i][j+step])/2 + distrib(gen);
                //left midpoint of square
                zValues[i+halfStep][j] = (zValues[i][j] + zValues[i+step][j])/2 + distrib(gen);
                //right midpoint of square
                zValues[i+halfStep][j+step] = (zValues[i][j+step] + zValues[i+step][j+step])/2 + distrib(gen);

                //center midpoint
                zValues[i+halfStep][j+halfStep] = (zValues[i][j] + zValues[i+step][j] + zValues[i+step][j+step] + zValues[i][j+step])/4 + distrib(gen);
            }
            
            


            
        }
        step = step/2;
        halfStep = halfStep/2;
        

    }
    
    /*for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            std::cout << "Punto = (" << i << ", " << j << ", " << zValues[i][j] << ")" << std::endl;    
        }        
    }*/
    

    return zValues;

};


std::vector<std::vector<double>> diamondSquareAlgorithm(double H, int nrIterations, bool bordeDisplacement){
    double range;
    int length = pow(2, nrIterations) + 1; //how many values do we have thanks to the number of iterations we want to build the terrain
    int step = length - 1;

    std::vector<std::vector<double>> zValues(length, std::vector<double>(length, 0));

    int halfStep = step/2;

    if(bordeDisplacement){
        range = pow(2, -2*H) * 10 * 1.5;
        std::random_device rd;  // Utiliza un dispositivo de entropía para inicializar el generador
        std::mt19937 gen(rd()); // Mersenne Twister generador inicializado con rd()

        // Definir la distribución entre -x y x
        std::uniform_real_distribution<> distrib(-range, range);

        zValues[0][0] = distrib(gen);
        zValues[0][step] = distrib(gen); 
        zValues[step][step] = distrib(gen); 
        zValues[step][0] = distrib(gen); 
    }


    //Step value goes for x and y axis
    for (int n = 1; n <= nrIterations; n++){ //do this nrIterations times
        range = pow(2, -2*n*H) * 10 * 3.5;

        std::random_device rd;  
        std::mt19937 gen(rd());

        // Definir la distribución entre -x y x
        std::uniform_real_distribution<> distrib(-range, range);

        //diamond step
        for (int i = 0; i < length - step; i+=step){
            for (int j = 0; j < length - step; j+=step){

                zValues[i+halfStep][j+halfStep] = (zValues[i][j] + zValues[i+step][j] + zValues[i+step][j+step] + zValues[i][j+step])/4 + distrib(gen);

            }
        }
        std::cout << "Se hizo diamond" << std::endl;   

        //Diamond step
        /*
        for (int i = 0; i < length - step; i+=step){
            for (int j = 0; j < length - step; j+=step){
                bool top, down, left, right = false;

                if (j == 0){
                    //left midpoint
                    zValues[i+halfStep][j] = (zValues[i][j] + zValues[i+step][j] + zValues[i+halfStep][j+halfStep])/3 + distrib(gen);
                    left = true;
                    
                } 
                if (i == 0){
                    //lower midpoint of square
                    zValues[i][j+halfStep] = (zValues[i][j] + zValues[i][j+step] + zValues[i+halfStep][j+halfStep])/3 + distrib(gen);
                    down = true;

                }
                if (j == length - step){
                    //right midpoint
                    zValues[i+halfStep][j+step] = (zValues[i][j+step] + zValues[i+step][j+step] + zValues[i+halfStep][j+halfStep])/3 + distrib(gen);
                    right = true;
                }
                if (i == length - step){
                    //top midpoint
                    zValues[i+step][j+halfStep] = (zValues[i+step][j] + zValues[i+step][j+step]+ zValues[i+halfStep][j+halfStep])/3 + distrib(gen);
                    top = true;

                }

                if(!left){
                    zValues[i+halfStep][j] = (zValues[i][j] + zValues[i+step][j] + zValues[i+halfStep][j+halfStep] + zValues[i-halfStep][j-halfStep])/4 + distrib(gen);
                }
                if(!top){
                    zValues[i+step][j+halfStep] = (zValues[i+step][j] + zValues[i+step][j+step]+ zValues[i+halfStep][j+halfStep] + zValues[i+step+halfStep][j+halfStep])/4 + distrib(gen);
                }
                if(!right){
                    zValues[i+halfStep][j+step] = (zValues[i][j+step] + zValues[i+step][j+step] + zValues[i+halfStep][j+halfStep] + zValues[i+halfStep][j+step+halfStep])/4 + distrib(gen);
                }
                if(!down){
                    zValues[i][j+halfStep] = (zValues[i][j] + zValues[i][j+step] + zValues[i+halfStep][j+halfStep] + zValues[i-halfStep][j-halfStep])/4 + distrib(gen);
                }


                std::cout << "Se hizo iteracion j=" << j << std::endl;   
                
            }
            std::cout << "Se hizo iteracion i=" << i << std::endl;    
        }
        */
        for (int i = 0; i < length; i += halfStep) {
            for (int j = (i + halfStep) % step; j < length; j += step) {
            double sum = 0;
            int count = 0;
            if (i >= halfStep) {
                sum += zValues[i - halfStep][j];
                count++;
            }
            if (i + halfStep < length) {
                sum += zValues[i + halfStep][j];
                count++;
            }
            if (j >= halfStep) {
                sum += zValues[i][j - halfStep];
                count++;
            }
            if (j + halfStep < length) {
                sum += zValues[i][j + halfStep];
                count++;
            }
            zValues[i][j] = sum / count + distrib(gen);
            }
        }


        step = step/2;
        halfStep = halfStep/2;
        

    }
    return zValues;
}



void createOFFMidpoint(int length, std::vector<std::vector<double>> & z, std::string filename){

    //Start  file
    std::ofstream outfile(filename);

    if (!outfile) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return ;
    }

    //Initial values
    outfile << "COFF" << std::endl;
    outfile << length * length << " " << (length - 1)*(length - 1) << " " << 0 << std::endl;


    //Temporal way to get the maximum and min value of z
    double max = 0;
    double min = 100000000;
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            if(max < z[i][j]){
                max = z[i][j];
            } 
            if(min > z[i][j]){
                min = z[i][j];
            } 
        } 
    }
    
    //Vertex
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            double colHeight =(z[i][j] - min)/(max - min);
            outfile << " " << i << "  " << j << "  " << z[i][j] << " " << 50 << " " << floor(colHeight*255)  << " "<<  255 << std::endl;
        }   
    }

    //Faces in squares from down left corner, to up right corner
    for (int i = 0; i < length - 1; i++){
        for (int j = 0; j < length - 1; j++){
            outfile << " " << 4 << " " << (length * i) + j << " " << (length * i) + j + 1 
            << " " << (length * (i + 1)) + j + 1 << " " << (length * (i + 1)) + j << std::endl;
        }    
    }
    
};





int main(){
    int iterations = 6;
    double h = 0.6;
    std::string finalWord = "refined";

    std::vector<std::vector<double>> resultRandom = midPointDisplacement2D(h, iterations, true);
    std::cout << "Se hizo el random" << std::endl;

    std::vector<std::vector<double>> resultDiamondSquare = diamondSquareAlgorithm(h, iterations, true);
    std::cout << "Se hizo el diamondSquare" << std::endl;

    //RandomFile
    std::ostringstream ossRandom;
    ossRandom << "random_" 
    << "n_" << iterations 
    << "_h_" << h 
    << finalWord
    << ".off";
    std::string filenameRandom = ossRandom.str();

    std::cout << "Se hizo el nombre random" << std::endl;

    //RandomFile
    std::ostringstream ossDiamondSquare;
    ossDiamondSquare << "diamondSquare_" 
    << "n_" << iterations 
    << "_h_" << h 
    << finalWord
    << ".off";
    std::string filenameDiamondSquare = ossDiamondSquare.str();
    std::cout << "Se hizo el nombre diamondSquare" << std::endl;

    createOFFMidpoint(pow(2, iterations) + 1, resultRandom, filenameRandom);
    std::cout << "Se hizo el off random" << std::endl;
    createOFFMidpoint(pow(2, iterations) + 1, resultDiamondSquare, filenameDiamondSquare);

    std::cout << "Se hizo el off diamondSquare" << std::endl;

    return 0;
}