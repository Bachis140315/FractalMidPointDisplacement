#include "DisplacementAlgoritms.hpp"
#include <cstddef>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <random>

int main(int argc, char* argv[]) {


    if (argc != 3 ) {
      std::cerr << "Uso: " << argv[0]
                << "n of iterations, 0 midpoint or 1 diamond"
                << std::endl;
      return 2;
    }
    using std::chrono::microseconds;
    if (std::stoi(argv[2]) == 0){
      int iterations = std::stoi(argv[1]);
      double h = 0.6;

      auto t_start = std::chrono::high_resolution_clock::now();

      std::vector<std::vector<double>> resultRandom = midPointDisplacement2D(h, iterations, true);
      auto t_end = std::chrono::high_resolution_clock::now();

      auto totalTime =
      std::chrono::duration_cast<microseconds>(t_end - t_start).count();
      std::cout << totalTime; 
    }
    if (std::stoi(argv[2]) == 1){
      int iterations = std::stoi(argv[1]);
      double h = 0.6;

      auto t_start = std::chrono::high_resolution_clock::now();

      std::vector<std::vector<double>> resultRandom = diamondSquareAlgorithm(h, iterations, true);
      auto t_end = std::chrono::high_resolution_clock::now();

      auto totalTime =
      std::chrono::duration_cast<microseconds>(t_end - t_start).count();
      std::cout << totalTime; 
    }
}