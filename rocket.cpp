//
// Created by Thomas Stockham on 4/5/18.
// Edited by Jordan Genovese on 4/17/18
//

#include "rocket.h"

Rocket::Rocket() : hullStat(notDamaged), hullHealth(100), fuelAmount(100){
    Rect baseRect();
}

hullStatus Rocket::getHulLStat() const {
    return notDamaged;
}
int Rocket::getPosX() const {
    point p = baseRect.getCenter();
    return p.x ;
}

int Rocket::getPosY() const {
    point p = baseRect.getCenter();
    return p.y ;
}

double Rocket::getFuelAmount() const {
    return 0;
}

double Rocket::getHullHealth() const{
    return hullHealth;
}

void Rocket::setFuelAmount(double fuel) {
    if(fuelAmount + fuel > 100){
        fuelAmount == 100;
    }else if(fuelAmount + fuel < 0){
        fuelAmount == 0;
    }else{
        fuelAmount += fuel;
    }
}

void Rocket::setFuelTankToFull() {
    fuelAmount == 100;
}

void Rocket::sethullStat(const hullStatus h) {
    hullStat = h;
}

void Rocket::setRocketPos(int x, int y) {
    baseRect.setPoint(x, y);
}

void Rocket::setHullHealth(double h) {
    hullHealth = h;
}

void Rocket::refuel(fueltank fuel) {
    setFuelAmount(fuel.getFuel());
}

void Rocket::move(direction d) {
    switch (d){
        case up:
            baseRect.move(0, 30);
            drawRocket();
            break;
        case down:
            baseRect.move(-30, 0);
            drawRocket();
            break;
        case right:
            baseRect.move(30, 0);
            drawRocket();
            break;
        case left:
            baseRect.move(0, -30);
            drawRocket();
            break;
    }
}

void Rocket::drawRocket() {

    if(hullStat == notDamaged) {
        baseRect.setDimensions(20, 40);
        baseRect.setColor(1.0, 1.0, 1.0);
        baseRect.draw();
        //TODO: Draw rest of rocket relative to coordinates of the baseRect
    }


}
