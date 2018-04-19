//
// Created by willf on 4/16/2018.
//

#ifndef GRAPHICS_FUELTANK_H
#define GRAPHICS_FUELTANK_H


class fueltank {
private:
    int fuel;
public:

    fueltank();


    int getFuel();
    void setFuel(int f);

    void useFuel();
};


#endif //GRAPHICS_FUELTANK_H
