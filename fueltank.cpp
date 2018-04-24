//
// Created by willf on 4/16/2018.
//

#include "fueltank.h"
#include <iostream>

using namespace std;

//TODO:: figure out base fuel amount
//TODO:: Get Graphics fuel-bar working
//TODO:: implement abstract class and upgradable fuel tank amounts
fuelTank::fuelTank(){
    fuel = 100;
}

int fuelTank::getFuel() {
    return fuel;
}

void fuelTank::setFuel(int f) {
    fuel = f;
}

void fuelTank::useFuel() {
    if (fuel > 0) {
        fuel--;
        cout << "remaining fuel: " << fuel << endl;
    }
}

bool fuelTank::hasFuel() {
    if(fuel == 0){
        return false;
    }
    return true;
}