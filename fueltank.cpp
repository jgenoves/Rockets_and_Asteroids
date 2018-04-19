//
// Created by willf on 4/16/2018.
//

#include "fueltank.h"
using namespace std;
#include <iostream>


fueltank::fueltank(){
    fuel = 5;
}

int fueltank::getFuel() {
    return fuel;
}

void fueltank::setFuel(int f) {
    fuel = f;
}

void fueltank::useFuel() {
    if(fuel > 0){
        fuel--;
        cout << "remaining fule: " << fuel << endl;
    } else{
        cout << "out of fuel" << endl;
    }
}