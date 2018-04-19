//
// Created by Thomas Stockham on 4/18/18.
//

#include <iostream>
#include "shapes.h"
#include "rocket.h"
#include "graphics.h"
/*
using namespace std;

int main() {



    /********** TESTING FOR SHAPE CLASS ***********/

    /*
    //default constructor testing
    Shape s;
    if (s.getCenter().x != 0 && s.getCenter().y != 0){
            cout << "FAILED shape default constructor point test" << endl;
        }
    if (s.getArea() != 0){
        cout << "FAILED shape default constructor area test" << endl;
    }
    if (s.getFill().red != 0 && s.getFill().blue !=0 && s.getFill().green != 0){
        cout << "FAILED shape default constructor fill test" << endl;
    }
    if (s.getPerimeter() != 0){
        cout << "FAILED shape default constructor perimeter test" << endl;
    }
    //non-default testing 1
    Shape s1({1,1}, {1,1,1});
    if (s1.getCenter().x != 1 && s.getCenter().y != 1){
        cout << "FAILED shape non-default constructor point test" << endl;
    }
    if (s1.getArea() != 0){
        cout << "FAILED shape non-default constructor area test" << endl;
    }
    if (s1.getFill().red != 1 && s.getFill().blue !=1 && s.getFill().green != 1){
        cout << "FAILED shape non-default constructor fill test" << endl;
    }
    if (s1.getPerimeter() != 0){
        cout << "FAILED shape non-default constructor perimeter test" << endl;
    }
    //non-default testing 2
    Shape s2(1, 1, 0.5, 0.5, 0.5);
    if (s2.getCenter().x != 1 && s.getCenter().y != 1){
        cout << "FAILED shape non-default constructor point test" << endl;
    }
    if (s1.getArea() != 0){
        cout << "FAILED shape non-default constructor/getter area test" << endl;
    }
    if (s1.getFill().red != 0.5 && s.getFill().blue !=0.5 && s.getFill().green != 0.5){
        cout << "FAILED shape non-default constructor fill/getter test" << endl;
    }
    if (s1.getPerimeter() != 0){
        cout << "FAILED shape non-default constructor perimeter/getter test" << endl;
    }

    // Getters and setters testing
    s.setPoint({1,1});
    if (s.getCenter().x != 1 && s.getCenter().y != 1){
        cout << "FAILED shape getter and setter point 1-val test" << endl;
    }
    s.setPoint(2,2);
    if (s.getCenter().x != 2 && s.getCenter().y != 2){
        cout << "FAILED shape getter and setter point 2-val test" << endl;
    }
    s.move(2,2);
    if (s.getCenter().x != 4 && s.getCenter().y != 4){
        cout << "FAILED shape getter and setter move test" << endl;
    }
}
*/