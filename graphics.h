//
// Created by Thomas Stockham on 4/5/18.
//

#ifndef graphics_h
#define graphics_h

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#include "shapes.h"

#else
#include <GL/glut.h>
#endif

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init(void);

// Initialize OpenGL Graphics
void InitGL(void);

// Callback functions for GLUT */
bool isOverlapping(const point &p, const Rect &r);
bool isOverlappingRects(const Rect &r1, const Rect &r2);
double distance (const point &p1, const point &p2);
bool isOverlapping(const point &p, const Circle &c);
bool isOverlappingCircles(const Circle &c1, const Circle &c2);
bool isOverlappingCirRect(const Circle &c, const Rect &r);


// Draw the window - this is where all the GL actions are
void display(void);

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int extra);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

#endif /* graphics_h */