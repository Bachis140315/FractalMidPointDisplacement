#include "Aux_funcs.hpp"
#include <cassert>
#include <vector>
#include <iostream>

void testSpaceDivider(){
    Point TLC;TLC.x = 0;TLC.y = 1;TLC.z = 0;
    Point TRC;TRC.x = 1;TRC.y = 1;TRC.z = 0;
    Point BLC;BLC.x = 0;BLC.y = 0;BLC.z = 0;
    Point BRC;BLC.x = 1;BRC.y = 0;BRC.z = 0;
    Point p;p.x = 0.5,p.y =0.5; p.z = 0.6;
    std::vector<Point> TL;
    std::vector<Point> BL;
    std::vector<Point> R;
    pointSpaceDivider(TLC,TRC,BLC,BRC,p,TL,BL,R);
    
    Point test; test.x = 0;test.y = 1; test.z = 0;
    assert(TL[0].x == test.x && "SpaceDivider not working");
    assert(TL[0].y == test.y && "SpaceDivider not working");
    assert(TL[0].z == test.z && "SpaceDivider not working");

    test; test.x = 0.5;test.y = 1; test.z = 0;
    assert(TL[1].x == test.x && "SpaceDivider not working");
    assert(TL[1].y == test.y && "SpaceDivider not working");
    assert(TL[1].z == test.z && "SpaceDivider not working");

    test; test.x = 0;test.y = 0.5; test.z = 0;
    assert(TL[2].x == test.x && "SpaceDivider not working");
    assert(TL[2].y == test.y && "SpaceDivider not working");
    assert(TL[2].z == test.z && "SpaceDivider not working");

    test; test.x = 0.5;test.y = 0.5; test.z = 0.6;
    assert(TL[3].x == test.x && "SpaceDivider not working");
    assert(TL[3].y == test.y && "SpaceDivider not working");
    assert(TL[3].z == test.z && "SpaceDivider not working");
    

     test; test.x = 0;test.y = 0.5; test.z = 0;
    assert(BL[0].x == test.x && "SpaceDivider not working");
    assert(BL[0].y == test.y && "SpaceDivider not working");
    assert(BL[0].z == test.z && "SpaceDivider not working");

     test; test.x = 0.5;test.y = 0.5; test.z = 0.6;
    assert(BL[1].x == test.x && "SpaceDivider not working");
    assert(BL[1].y == test.y && "SpaceDivider not working");
    assert(BL[1].z == test.z && "SpaceDivider not working");

     test; test.x = 0;test.y = 0; test.z = 0;
    assert(BL[2].x == test.x && "SpaceDivider not working");
    assert(BL[2].y == test.y && "SpaceDivider not working");
    assert(BL[2].z == test.z && "SpaceDivider not working");

     test; test.x = 0.5;test.y = 0; test.z = 0;
    assert(BL[3].x == test.x && "SpaceDivider not working");
    assert(BL[3].y == test.y && "SpaceDivider not working");
    assert(BL[3].z == test.z && "SpaceDivider not working");

    test; test.x = 0.5;test.y = 1; test.z = 0;
    assert(BL[0].x == test.x && "SpaceDivider not working");
    assert(BL[0].y == test.y && "SpaceDivider not working");
    assert(BL[0].z == test.z && "SpaceDivider not working");

     test; test.x = 0.5;test.y = 0.5; test.z = 0.6;
    assert(BL[1].x == test.x && "SpaceDivider not working");
    assert(BL[1].y == test.y && "SpaceDivider not working");
    assert(BL[1].z == test.z && "SpaceDivider not working");

     test; test.x = 0;test.y = 0; test.z = 0;
    assert(BL[2].x == test.x && "SpaceDivider not working");
    assert(BL[2].y == test.y && "SpaceDivider not working");
    assert(BL[2].z == test.z && "SpaceDivider not working");

     test; test.x = 0.5;test.y = 0; test.z = 0;
    assert(BL[3].x == test.x && "SpaceDivider not working");
    assert(BL[3].y == test.y && "SpaceDivider not working");
    assert(BL[3].z == test.z && "SpaceDivider not working");
}


int main(int argc, char **argv){
    testSpaceDivider();

    return 0;
    
}