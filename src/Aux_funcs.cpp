#include "Aux_funcs.hpp"
#include <vector>

void merge(Point *array, int const left, int const mid, int const right, int x){
    
    int const subArrayOne = mid - left + 1; 
    int const subArrayTwo = right - mid;    

    // Create temp arrays
    Point *leftArray = new Point[subArrayOne];
    Point *rightArray = new Point[subArrayTwo];


    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++){
        
        leftArray[i] = array[left + i];
        
        
    }
    for (int j = 0; j < subArrayTwo; j++){
        rightArray[j] = array[mid + 1 + j];
        }
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if(x == 1){
            if (leftArray[indexOfSubArrayOne].x
                <= rightArray[indexOfSubArrayTwo].x) {
                array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
        if(x == 0){
            if (leftArray[indexOfSubArrayOne].y
                <= rightArray[indexOfSubArrayTwo].y) {
                array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;


}


// begin is for left index and end is right index
// of the sub-array of arr to be sorted
//int x = 1 if sort in x, 0 if sort in y 
void mergeSort(Point *array, int const begin, int const end,int x)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin)/2;
    if(x==1){
        mergeSort(array, begin, mid,1);
        mergeSort(array, mid + 1, end,1);
        merge(array, begin, mid, end,1);
    }
    else{
        mergeSort(array, begin, mid,0);
        mergeSort(array, mid + 1, end,0);
        merge(array, begin, mid, end,0);
    }
}





//divides the space in 3 
//top left corner, top right corner, bottom left corner, point 
//top left box, top right box, bottom left box, bottom right box
void pointSpaceDivider(Point TLC,Point TRC, Point BLC,Point BRC,Point p,
        std::vector<Point> &TL,std::vector<Point> &BL,std::vector<Point> &R){
    
    Point left;
    left.x = TLC.x;
    left.y = p.y;
    left.z = 0;

    Point up;
    up.x = p.x;
    up.y = TLC.y;
    up.z = 0;

    Point down;
    down.x = p.x;
    down.y = BLC.y;
    down.z = 0;

    Point right;
    right.x = TRC.x;
    right.y = p.y;
    right.z = 0;
   

    TL.push_back(TLC);TL.push_back(up);TL.push_back(left);TL.push_back(p);

    BL.push_back(left);BL.push_back(p);BL.push_back(BLC);BL.push_back(down);

    R.push_back(up);R.push_back(TRC);R.push_back(down);R.push_back(BRC);


}


std::vector<int> colorMountain(double min, double max, double value){
    std::vector<int> RGB;
    double scale = (value - min)/(max - min);
    if(scale > 0.7){
        
        RGB.push_back(floor(255));
        RGB.push_back(floor(scale*25 + 230));
        RGB.push_back(floor(scale*25 + 230));
    }
    else{
        RGB.push_back(floor(150));
        RGB.push_back(floor(255-scale*255));
        RGB.push_back(floor(0));
    }
    return RGB;

}

std::vector<std::vector<double>> createControlSurface(int niterations){
    int length = pow(2, niterations) + 1;
    std::vector<std::vector<double>> zValues(length, std::vector<double>(length, 0));
    for (int i = 0; i < length -1; i++){
            for (int j = 0; j < length; j++){
                if(j>floor(length/2) && i>floor(length/2) && j>floor(length*3/2) && j>floor(length*3/2)){
                    zValues[i][j] =10;
                }
        }
    }
    return zValues;
}