#include "DisplacementAlgoritms.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cmath>
#include<random>



void createOFFMidpoint2(std::vector<Segment> &segments, std::string filename){

    //Start  file
    std::ofstream outfile(filename);

    if (!outfile) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return ;
    }
    int totalVertices = 0;
    int totalFaces = 0;
    for(int k = 0; k < segments.size(); k++){
        totalVertices = totalVertices + segments[k].size*segments[k].size;
        totalFaces = totalFaces + (segments[k].size-1)*(segments[k].size-1);
    }
    //Initial values
    outfile << "COFF" << std::endl;
    outfile << totalVertices << " " << totalFaces << " " << 0 << std::endl;
    double max = 0;
    double min = 100000000;

    for (int k = 0; k < segments.size(); k++){
    //Temporal way to get the maximum and min value of z
        int length = segments[k].size;
        std::vector<std::vector<double>> z = segments[k].zValues;
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
    }

    for (int k = 0; k < segments.size(); k++){
    //Vertex
        std::vector<std::vector<double>> z = segments[k].zValues;
        int length = segments[k].size;
        double xnorm = segments[k].xlenght;
        double ynorm = segments[k].ylenght;
        double xoffset = segments[k].xoffset;
        double yoffset = segments[k].yoffset;
        for (int i = 0; i < length; i++){
            for (int j = 0; j < length; j++){
                double colHeight =(z[i][j] - min)/(max - min);
                
                outfile << " " << i*xnorm + xoffset << "  " << j*ynorm + yoffset<< "  " << z[i][j] << " " << 50 << " " << floor(colHeight*255)  << " "<<  255 << std::endl;
            }   
        }
    }
    int index_segment = 0;
    for (int k = 0; k < segments.size(); k++){
        int length = segments[k].size;
        int size = length*length;
        //Faces in squares from down left corner, to up right corner
        for (int i = 0; i < length - 1; i++){
            for (int j = 0; j < length - 1; j++){
                outfile << " " << 4 << " " << (length * i) + j + index_segment << " " << (length * i) + j + 1  + index_segment
                << " " << (length * (i + 1)) + j + 1  + index_segment << " " << (length * (i + 1)) + j + index_segment << std::endl;
            }    
        }
        index_segment = index_segment + size;
    }
};


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
            std::vector<int> colors = colorMountain(min,max,z[i][j]);

            outfile << " " << i << "  " << j << "  " << z[i][j] << " " << colors[0] << " " << colors[1]  << " "<<  colors[2] << std::endl;
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
    std::cout << "Añadir numero de iteraciones:";
    int iterations;
    std::cin >> iterations;
    double h = 0.6;
    std::string finalWord = "refined";
    std::vector<Point> refPoints; 

    
    
    
    std::vector<std::vector<double>> resultRandom = midPointDisplacement2D(h, iterations, true);
    std::cout << "Se hizo el random" << std::endl;

    //RandomFile
    std::ostringstream ossRandom;
    ossRandom << "random_" 
    << "n_" << iterations 
    << "_h_" << h 
    << finalWord
    << ".off";
    std::string filenameRandom = ossRandom.str();
    std::cout << "Se hizo el nombre random" << std::endl;
    createOFFMidpoint(pow(2, iterations) + 1, resultRandom, filenameRandom);
    std::cout << "Se hizo el off random" << std::endl;

    

    std::vector<std::vector<double>> resultDiamondSquare = diamondSquareAlgorithm(h, iterations, true);
    std::cout << "Se hizo el diamondSquare" << std::endl;

    //RandomFile
    std::ostringstream ossDiamondSquare;
    ossDiamondSquare << "diamondSquare_" 
    << "n_" << iterations 
    << "_h_" << h 
    << finalWord
    << ".off";
    std::string filenameDiamondSquare = ossDiamondSquare.str();
    std::cout << "Se hizo el nombre diamondSquare" << std::endl;
    
    
    createOFFMidpoint(pow(2, iterations) + 1, resultDiamondSquare, filenameDiamondSquare);

    std::cout << "Se hizo el off diamondSquare" << std::endl;

    return 0;
}