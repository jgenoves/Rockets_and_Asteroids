//
// Created by willf on 4/16/2018.
//

#include "fueltank.h"
using namespace std;
#include <iostream>


fueltank::fueltank(){
    //TODO: fuel amount should equal random number between 1 and 20, circle size of item should depend on amount of fuel

}

double fueltank::getFuel() const {
    return fuel;
}

void fueltank::setFuel(int f) {
    fuel = f;
}

