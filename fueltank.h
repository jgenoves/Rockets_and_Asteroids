//
// Created by willf on 4/16/2018.
//

#ifndef GRAPHICS_FUELTANK_H
#define GRAPHICS_FUELTANK_H


class fuelTank {
private:
    int fuel;
public:

    fuelTank();


    int getFuel();
    void setFuel(int f);

    void useFuel();
};


#endif //GRAPHICS_FUELTANK_H