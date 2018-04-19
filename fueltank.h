//
// Created by willf on 4/16/2018.
//

#ifndef GRAPHICS_FUELTANK_H
#define GRAPHICS_FUELTANK_H

#include "shapes.h"

class fueltank {
private:
    double fuel;
    Circle body;

public:

    fueltank();


    double getFuel() const;
    void setFuel(int f);

    void draw();
};


#endif //GRAPHICS_FUELTANK_H
