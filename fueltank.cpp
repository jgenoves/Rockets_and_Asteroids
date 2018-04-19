//
// Created by willf on 4/16/2018.
//

#include "fueltank.h"
using namespace std;
#include <iostream>


fueltank::fuelTank(){
    fuel = 5;
}

int fuelTank::getFuel() {
    return fuel;
}

void fuelTank::setFuel(int f) {
    fuel = f;
}

void fuelTank::useFuel() {
    if(fuel > 0){
        fuel--;
        cout << "remaining file: " << fuel << endl;
    } else{
        cout << "out of fuel" << endl;
    }
}