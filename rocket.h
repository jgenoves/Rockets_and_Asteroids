//
// Created by Thomas Stockham on 4/5/18.
//

#ifndef GRAPHICS_ROCKET_H
#define GRAPHICS_ROCKET_H

#include "shapes.h"
#include "graphics.h"
#include "fueltank.h"

//Possibility? Use this enum to determine how the rocket should look based on health.
enum hullStatus {notDamaged, Damaged, veryDamaged };

//Enum used to determine which direction the Rocket should move in
enum direction {up, down, left, right};

class Rocket {
private:

    hullStatus hullStat; //Enum used to determine which graphics should represent the rocket. Based on hullHealth
    Rect baseRect;
    double fuelAmount; // 100 is full fuel
    double hullHealth; //100 is full health

    //Center coordinates for the rocket


public:

    //Non-Default Constructor for the rocket. Note, this
    //is the only constructor, and will assemble and draw all the
    //shapes to the correct dimensions for the parts.
    //This also initializes the rocket fuel supply to full.
    Rocket();

    //getters
    hullStatus getHulLStat() const;
    double getFuelAmount() const;
    double getHullHealth() const;
    int getPosX() const;
    int getPosY() const;

    /*
     * R: amount to add to fuel tank
     * M: FuelTank amount
     * E: adds fuelAmount to fuel tank. This is performed when
     *      the rocket collects a fuel supply in the level.
     *      Note: fuel supply cannot exceed 100 in valye
     */
    void setFuelAmount(double fuel);

    /*
     * R: nothing
     * M: FuelTank amount
     * E: this will set the FuelTank value to 100.
     */
    void setFuelTankToFull();


    //setter for hullStat
    void sethullStat(const hullStatus h);
    void setRocketPos(int x, int y);
    void setHullHealth(double h);

    /*
     * R: fueltank object
     * M: fuelAmount
     * E: adds fueltank object value to fuelAmount
     *
     */
    void refuel(fueltank fuel);

    /*
     * R:
     * M: rocket's graphical shapes and FuelTank amount
     * E:  Moves rocket's location on the map (moves all rocket's shapes
     *      relative to the center of the rocket). Error
     *      checking implemented to ensure rocket does not
     *      clip outside of map.
     *      Moving the rocket also spends fuel.
     */
    void move(direction d);


    /*
     * R: nothing
     * M: rockets shapes
     * E: draws the rocket on the screen
     */
    void drawRocket();




};


#endif //GRAPHICS_ROCKET_H
