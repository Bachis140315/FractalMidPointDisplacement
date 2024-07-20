#include "Aux_funcs.hpp"


std::vector<std::vector<double>> midPointDisplacement2D(double H, int nrIterations, bool bordeDisplacement);

std::vector<std::vector<double>> midPointDisplacement2DStep(double H, int nrIterations, std::vector<Point> bordeDisplacement);

std::vector<Segment> midPointDisplacement2D2(std::vector<Point> refPoints,double H, int nrIterations);

std::vector<std::vector<double>> diamondSquareAlgorithm(double H, int nrIterations, bool bordeDisplacement);

std::vector<std::vector<double>> midPointDisplacement2DControlled(double H, int nrIterations, bool bordeDisplacement);