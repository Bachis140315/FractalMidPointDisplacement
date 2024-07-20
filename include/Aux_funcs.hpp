#include<vector>
#include<cmath>

struct Segment
{
    double xlenght; //lenght of segment in x
    double ylenght;
    double xoffset; //where the top left corner is
    double yoffset;
    int size;   //how many points does 1 side have (2N +1)
    std::vector<std::vector<double>> zValues;
    
};



//anything else than this seems like an overkill for the scope of this project
struct Point
{
    double x, y, z;
};


void merge(Point *array, int const left, int const mid, int const right, int x);

void mergeSort(Point *array, int const begin, int const end,int x);

//divides the space in 3 
//top left corner, top right corner, bottom left corner, point 
//top left box, top right box, right box
//TL format 0 = top left corner, 1 = top right corner, 2 = bottom left corner
void pointSpaceDivider(Point TLC,Point TRC, Point BLC, Point BRC,Point p,
        std::vector<Point> &TL,std::vector<Point> &BL,std::vector<Point> &R);


std::vector<int> colorMountain(double min, double max, double value);

std::vector<std::vector<double>> createControlSurface(int niterations);