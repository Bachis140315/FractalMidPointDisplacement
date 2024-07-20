//<>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cmath>
#include<random>
#include "DisplacementAlgoritms.hpp"





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

std::vector<std::vector<double>> midPointDisplacement2DControlled(double H, int nrIterations, bool bordeDisplacement){
    double range;
    int length = pow(2, nrIterations) + 1; //how many values do we have thanks to the number of iterations we want to build the terrain
    int step = length - 1;

    std::vector<std::vector<double>> ControlValues = createControlSurface(nrIterations);
    std::vector<std::vector<double>> zValues(length, std::vector<double>(length, 0));

    int halfStep = step/2;

    if(bordeDisplacement){
        range = pow(2, -2*H) * 10 * 3.5;
        std::random_device rd;  // Utiliza un dispositivo de entropía para inicializar el generador
        std::mt19937 gen(rd()); // Mersenne Twister generador inicializado con rd()

        // Definir la distribución entre -x y x
        std::uniform_real_distribution<> distrib(-range, range);
         

        zValues[0][0] = ControlValues[0][0] - distrib(gen);
        zValues[0][step] = ControlValues[0][0] - distrib(gen); 
        zValues[step][step] = ControlValues[0][0] - distrib(gen); 
        zValues[step][0] = ControlValues[0][0] - distrib(gen); 
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
                double mu = ControlValues[i+step][j+halfStep] - (zValues[i+step][j] + zValues[i+step][j+step])/2;
                double sigma = 0.0000001*abs(mu);
                std::normal_distribution<> dist(mu, sigma);
                zValues[i+step][j+halfStep] = (zValues[i+step][j] + zValues[i+step][j+step])/2 + dist(gen);
                //lower midpoint of square
                mu = ControlValues[i][j+halfStep] - (zValues[i][j] + zValues[i][j+step])/2;
                sigma = 0.000000001*abs(mu);
                std::normal_distribution<> dist2(mu, sigma);
                zValues[i][j+halfStep] = ControlValues[i][j+halfStep] - (zValues[i][j] + zValues[i][j+step])/2 + dist2(gen);
                //left midpoint of square
                mu =  ControlValues[i+halfStep][j] - (zValues[i][j] + zValues[i+step][j])/2;
                sigma = 0.000000001*abs(mu);
                std::normal_distribution<> dist3(mu, sigma);
                zValues[i+halfStep][j] = ControlValues[i+halfStep][j] - (zValues[i][j] + zValues[i+step][j])/2 + dist3(gen);
                //right midpoint of square
                mu =  ControlValues[i+halfStep][j+step] - (zValues[i][j+step] + zValues[i+step][j+step])/2;
                sigma = 0.000000001*abs(mu);
                std::normal_distribution<> dist4(mu, sigma);
                zValues[i+halfStep][j+step] = ControlValues[i+halfStep][j+step] - (zValues[i][j+step] + zValues[i+step][j+step])/2 + dist4(gen);

                
                //center midpoint
                mu =  ControlValues[i+halfStep][j+halfStep] - (zValues[i][j] + zValues[i+step][j] + zValues[i+step][j+step] + zValues[i][j+step])/4;
                sigma = 0.000000001*abs(mu);
                std::normal_distribution<> dist5(mu, sigma);
                zValues[i+halfStep][j+halfStep] = ControlValues[i+halfStep][j+halfStep] - (zValues[i][j] + zValues[i+step][j] + zValues[i+step][j+step] + zValues[i][j+step])/4 + dist5(gen);
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


std::vector<std::vector<double>> midPointDisplacement2DStep(double H, int nrIterations, std::vector<Point> bordeDisplacement){
    double range;
    int length = pow(2, nrIterations) + 1; //how many values do we have thanks to the number of iterations we want to build the terrain
    int step = length - 1;


    std::vector<std::vector<double>> zValues(length, std::vector<double>(length, 0));

    int halfStep = step/2;

    if(bordeDisplacement.size() == 0){
        range = pow(2, -2*H) * 10 * 3.5;
        std::random_device rd;  // Utiliza un dispositivo de entropía para inicializar el generador
        std::mt19937 gen(rd()); // Mersenne Twister generador inicializado con rd()

        // Definir la distribución entre -x y x
        std::uniform_real_distribution<> distrib(-range, range);

        zValues[0][0] = distrib(gen);
        zValues[0][step] = distrib(gen); 
        zValues[step][step] = distrib(gen); 
        zValues[step][0] = distrib(gen); 

        if(bordeDisplacement[0].z != 0)
        zValues[0][0] = bordeDisplacement[3].z;
        if(bordeDisplacement[1].z != 0)
        zValues[0][step] = bordeDisplacement[0].z;
        if(bordeDisplacement[2].z != 0)
        zValues[step][step] = bordeDisplacement[1].z;
        if(bordeDisplacement[3].z != 0)
        zValues[step][0] = zValues[step][4];
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
    
    return zValues;

};



std::vector<Segment> midPointDisplacement2D2(std::vector<Point> refPoints,double H, int nrIterations){

    //this isnt efficient but for the demo will be okay
    Point *aux = new Point[refPoints.size()];
    for(int i = 0; i < refPoints.size(); i++){
        aux[i] = refPoints[i];
    }
    mergeSort(aux,0,refPoints.size()-1,1);
    for(int i = 0; i < refPoints.size(); i++){
        refPoints[i] = aux[i];
    }
    
    std::vector<std::vector<Point>> spaces;
    int length = pow(2, nrIterations) + 1;
    Point TLC;TLC.x = 0;TLC.y = length-1;
    Point TRC;TRC.x = length;TRC.y = length;
    Point BLC;BLC.x = 0;BLC.y = 0;
    Point BRC;BRC.x = length;BRC.y = 0;
    for(int i = 0; i < refPoints.size(); i++){
        std::vector<Point> TL;
        std::vector<Point> BL;
        std::vector<Point> R;
        pointSpaceDivider(TLC,TRC,BLC,BRC,refPoints[i],TL,BL,R);
        spaces.push_back(TL);
        spaces.push_back(BL);
        TLC = R[0];
        TRC = R[1];
        BLC = R[2];
        if(i == refPoints.size()){
            spaces.push_back(R);
        }
    }

    std::vector<Segment> segments;
    for(int i = 0; i < spaces.size(); i++){
        std::vector<std::vector<double>> zValues = midPointDisplacement2DStep(H,nrIterations,spaces[i]);
        Segment segment;
        segment.size = pow(2, nrIterations) + 1;
        segment.xlenght = spaces[i][1].x - spaces[i][0].x;
        segment.ylenght = spaces[i][0].y - spaces[i][3].y;
        segment.xoffset = spaces[i][3].x;
        segment.yoffset = spaces[i][3].y;
        segment.zValues = zValues;
        segments.push_back(segment);
        }
    return segments;
}





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








