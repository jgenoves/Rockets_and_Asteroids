//
// Created by Thomas Stockham on 4/5/18.
//

#include "graphics.h"
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include "shapes.h"
#include <ctime>
#include "fueltank.h"

using namespace std;

enum mode {
    info, start, game, endgame
};

GLdouble width, height;
int wd;
int score = 0, money = 0;
int rad = 15;
mode screen;
Rect myRectangle;
Circle myCircle, c1, c2, c3, p1,p2;
fuelTank f1;
vector <Circle> stars;
vector <Circle> stars2;
vector <Circle> coins;


void init() {
    screen = start;

    width = 500;
    height = 720;

    //initialize rectangle
    myRectangle.setDimensions(20.0, 40.0);
    myRectangle.setColor(1.0, 1.0, 1.0);
    myRectangle.setPoint((width / 2) - (int)myRectangle.getWidth(), (height-10) - (int) myRectangle.getHeight());


    //Initialize Circle
    myCircle.setRadius(50.0);
    myCircle.setColor(0.556863, 0.137255, 0.137255);
    myCircle.setPoint(350, 200);

    c1.setRadius(10.0);
    c1.setColor(1.0, 1.0, 0.0);
    c1.setPoint(350, 200);

    p1.setRadius(700);
    p1.setColor(0.329412, 0.329412, 0.329412);
    p1.setPoint(250, 1390);

    p2.setRadius(150);
    p2.setColor(0.9, 0.2, 0.2);
    p2.setPoint(450, -100);



    //Initialize stars
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        stars.push_back(Circle(rand() % 5 + 1, rand() % (int) width, rand() % int(height), 1.0, 1.0, 1.0));
    }
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        stars2.push_back(Circle(rand() % 5 + 1, rand() % (int) width, rand() % int(height), 1.0, 1.0, 1.0));
    }
    srand(time(NULL));
    rad = 15;
    for (int i = 0; i < 5; i++) {
        coins.push_back(Circle(rad, rand() % (int) width, rand() % int(height) * -2, 1.0, 1.0, 0.0));
    }

}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.02f, 0.02f, 0.17f, 1.0f); // Blue and opaque
}


/************* START ***************/
void displayStart() {
    for (int i = 0; i < stars.size(); i++) {
        stars[i].draw();
    }
    string message2 = "Deep Blue";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(200, 300);
    for (char c: message2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    string message1 = "Click anywhere to begin";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(180, 350);
    for (char c: message1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }

}
/********** INFO ***************/
void displayInfo(){
    for (int i = 0; i < stars.size(); i++) {
        stars[i].draw();
    }
    string messageI = "Welcome to Deep Blue.";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(80, 340);
    for (char c: messageI) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    string messageI2 = "Your objective is to fly your rocket as high as possible.";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(80, 360);
    for (char c: messageI2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    string messageI3 = "Avoid asteroids, and collect coins for power-ups";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(80, 380);
    for (char c: messageI3) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    string messageI4 = "Use Planets and fuel tanks to fuel up!";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(80, 400);
    for (char c: messageI4) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
    }
    string messageI5 = "Click anywhere to begin";
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(80, 420);
    for (char c: messageI5) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

/***************** GAME ****************/
void displayGame() {
    color c1 = {1.0,1.0,0.0};
    for (int i = 0; i < coins.size(); i++) {
        if (isOverlappingCirRect(coins[i], myRectangle)) {
            //if (coins[i].getFill() == c1){
            //  money +=10;
            //}
            coins[i].setColor(0.02, 0.02, 0.17);
            money +=10;
        }
    }

    for (int i = 0; i < stars2.size(); i++) {
        stars2[i].draw();
    }
    for (int i = 0; i < coins.size(); i++) {
        coins[i].draw();
    }
    myRectangle.draw();
    p2.draw();
    p1.draw();

    // Draw words
    string message = "$: ";
    glColor3f(1.0, 1.0, 0.0);
    glRasterPos2i(400, 20);
    for (char c: message) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    string message1 = "Score: ";
    glColor3f(1.0, 1.0, 0.0);
    glRasterPos2i(355, 50);
    for (char c: message1) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }


    glColor3f(1.0, 1.0, 0.0);
    glRasterPos2i(420, 50);
    for (char c: to_string(score)) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    glColor3f(1.0, 1.0, 0.0);
    glRasterPos2i(420, 20);
    for (char c: to_string(money)) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    //draw objects
    //myCircle.draw();

}

void displayEnd() {}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */


//    glBegin(GL_QUADS);
//    glVertex2i(10, 10);
//    glVertex2i(890, 10);
//    glVertex2i(890, 490);
//    glVertex2i(10, 490);
//    glEnd();

    switch (screen) {
        case start:
            displayStart();
            break;
        case info:
            displayInfo();
            break;
        case game:
            displayGame();
            break;
        case endgame:
            displayEnd();
            break;

    }

    glFlush();  // Render now
}

/*********** OVERLAPPING STUFF ****************/

bool isOverlapping(const point &p, const Rect &r) {
    return (p.x >= (r.getCenter().x - (r.getWidth() / 2.0)) && // left side
            p.x <= (r.getCenter().x + (r.getWidth() / 2.0)) && // right side
            p.y >= (r.getCenter().y - (r.getHeight() / 2.0)) && // top
            p.y <= (r.getCenter().y + (r.getHeight() / 2.0))); // bottom
}

bool isOverlappingRects(const Rect &r1, const Rect &r2) {
    // if one rectangle is to the left of the other
    // or above the other, then they are not overlapping.
    return !((r1.getCenter().x + (r1.getWidth() / 2.0) < r2.getCenter().x - (r2.getWidth() / 2.0)) ||
             // r1 is left of r2
             (r2.getCenter().x + (r2.getWidth() / 2.0) < r1.getCenter().x - (r1.getWidth() / 2.0)) ||
             // r2 is left of r1
             (r1.getCenter().y - (r1.getHeight() / 2.0) > r2.getCenter().y + (r2.getHeight() / 2.0)) ||
             // r1 is below r2
             (r2.getCenter().y - (r2.getHeight() / 2.0) > r1.getCenter().y + (r1.getHeight() / 2.0))); // r2 is below r1
}

double distance(const point &p1, const point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool isOverlapping(const point &p, const Circle &c) {
    return distance(p, c.getCenter()) <= c.getRadius();
}

bool isOverlappingCircles(const Circle &c1, const Circle &c2) {
    return distance(c1.getCenter(), c2.getCenter()) <= c1.getRadius();
}

bool isOverlappingCirRect(const Circle &c, const Rect &r) {
    return ((c.getRadius() + r.getWidth() / 2.0) > distance({r.getCenter().x, c.getCenter().y}, r.getCenter()) &&
            (c.getRadius() + r.getHeight() / 2.0) > distance({r.getCenter().x, c.getCenter().y}, c.getCenter()));
}

/************** KEY ASSIGNMENTS ************/

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {
    // escape ascii code

    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    //Registers a space bar pressed
    //used for boost, each press reduces remaining fuel (out of 5) by 1.


    if (screen == game) {
        if (screen == game) {
            if (key == 32) {
                f1.useFuel();
            }
            switch (key) {
                case 'r':
                    myRectangle.setColor(1.0, 0.0, 0.0); // this won't work yet without global variables
                    break;
                case 'p':
                    myRectangle.setColor(0.4, 0.0, 0.8);
                    break;
                case 'w':
                    myRectangle.setColor(1.0, 1.0, 1.0);
            }
        }
        glutPostRedisplay();

        return;
    }
}

    void kbdS(int key, int x, int y) {
        if (screen == game) {
            switch (key) {
                /* case GLUT_KEY_DOWN:
                     myRectangle.move(0, 30);
                     if (myRectangle.getCenter().y > height-20){
                         myRectangle.setPoint(myRectangle.getCenter().x, height-20);
                     }
                     for (int i = 0;i<stars2.size();i++){
                         stars2[i].move(0, stars2[i].getRadius());
                         if (stars2[i].getCenter().y > height){
                             //stars is moving off the bottom of the screen, which is bad
                             stars2[i].setPoint(stars2[i].getCenter().x, 0);
                         }
                         if (stars2[i].getCenter().x > width){
                             //stars is moving off the bottom of the screen, which is bad
                             stars2[i].setPoint(0, stars2[i].getCenter().y);
                         }
                     }
                     break;
                     */
                case GLUT_KEY_LEFT:

                    myRectangle.rotate(15);
                    //myRectangle.move(-20, 0);
                    if (myRectangle.getCenter().x < 0) {
                        myRectangle.setPoint(width, myRectangle.getCenter().y);
                    }
                    for (int i = 0; i < stars2.size(); i++) {
                        stars2[i].move(stars2[i].getRadius() * 2, 0);
                        if (stars2[i].getCenter().y > height) {
                            //stars is moving off the bottom of the screen, which is bad
                            stars2[i].setPoint(stars2[i].getCenter().x, 0);
                        }
                        if (stars2[i].getCenter().x > width) {
                            //stars is moving off the bottom of the screen, which is bad
                            stars2[i].setPoint(0, stars2[i].getCenter().y);
                        }
                    }
                    for (int i = 0; i < coins.size(); i++) {
                        coins[i].move(20, 0);
                        if (coins[i].getCenter().x > width) {
                            coins[i].setColor(1.0, 1.0, 0.0);
                            coins[i].setPoint(0, coins[i].getCenter().y);
                        }
                    }
                    p2.move(10, 0);
                    break;
                case GLUT_KEY_RIGHT:
                    //myRectangle.move(30,0);
                    myRectangle.rotate(15);
                    if (myRectangle.getCenter().x > width) {
                        myRectangle.setPoint(0, myRectangle.getCenter().y);
                    }
                    for (int i = 0; i < stars2.size(); i++) {
                        stars2[i].move(-(stars2[i].getRadius()) * 2, 0);
                        if (stars2[i].getCenter().y > height) {
                            //stars is moving off the bottom of the screen, which is bad
                            stars2[i].setPoint(stars2[i].getCenter().x, 0);
                        }
                        if (stars2[i].getCenter().x < 0) {
                            //stars is moving off the bottom of the screen, which is bad
                            stars2[i].setPoint(width, stars2[i].getCenter().y);
                        }
                    }
                    for (int i = 0; i < coins.size(); i++) {
                        coins[i].move(-20, 0);
                        if (coins[i].getCenter().x == 0) {
                            coins[i].setColor(1.0, 1.0, 0.0);
                            //stars is moving off the bottom of the screen, which is bad
                            coins[i].setPoint(width, coins[i].getCenter().y);
                        }
                    }
                    p2.move(-10, 0);
                    break;
                case GLUT_KEY_UP:
                    myRectangle.move(0, -20);

                    p2.move(0, 10);
                    score++;
                    glColor3f(1.0, 1.0, 0.0);
                    glRasterPos2i(365, 50);
                    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score);
                    if (myRectangle.getCenter().y < height / 2 + 40) {
                        myRectangle.setPoint(myRectangle.getCenter().x, height / 2 + 40);
                    }
                    p1.move(0, 20);
                    for (int i = 0; i < coins.size(); i++) {
                        coins[i].move(0, 20);
                        if (coins[i].getCenter().y > height) {
                            //stars is moving off the bottom of the screen, which is bad
                            coins[i].setColor(1.0, 1.0, 0.0);
                            coins[i].setPoint(coins[i].getCenter().x, height * -2);
                        }
                    }
                    for (int i = 0; i < stars2.size(); i++) {
                        stars2[i].move(0, stars2[i].getRadius() * 2);
                        if (stars2[i].getCenter().y > height) {
                            //stars is moving off the bottom of the screen, which is bad
                            stars2[i].setPoint(stars2[i].getCenter().x, 0);
                        }
                        if (stars2[i].getCenter().x > width) {
                            //stars is moving off the bottom of the screen, which is bad
                            stars2[i].setPoint(0, stars2[i].getCenter().y);
                        }

                    }
                    break;
            }
        }
        glutPostRedisplay();
        return;
    }

    void cursor(int x, int y) {
        //move circle with mouse
        /* if (screen == game) {
             myCircle.setPoint(x, y);
         }
         */
        glutPostRedisplay();
    }

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
    void mouse(int button, int state, int x, int y) {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == start) {
            screen = info;
        } else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && screen == info) {
            screen = game;
        }
        glutPostRedisplay();
    }


    void timer(int extra) {
//make the stars fall
        for (int i = 0; i < stars.size(); i++) {
            stars[i].move(0, stars[i].getRadius());
            if (stars[i].getCenter().y > height) {
                //stars is moving off the bottom of the screen, which is bad
                stars[i].setPoint(stars[i].getCenter().x, 0);
            }
        }
        glutPostRedisplay();
        //glutTimerFunc waits for 40 milliseconds before it calls itself.
        glutTimerFunc(40, timer, 0);
    }
    void timer1(int extra1) {
        if (extra1 == 0) {
            rad--;
            for (int i = 0; i < coins.size(); i++) {
                coins[i].setRadius(rad);
                if (rad == 1) {
                    glutTimerFunc(40, timer1, 1);
                } else {
                    glutTimerFunc(40, timer1, 0);
                }
            }
        } else if (extra1 == 1) {
            rad++;
            for (int i = 0; i < coins.size(); i++) {
                coins[i].setRadius(rad);
                if (rad == 20) {
                    glutTimerFunc(40, timer1, 0);
                } else {
                    glutTimerFunc(40, timer1, 1);
                }
            }
        }

        glutPostRedisplay();
        //glutTimerFunc waits for 40 milliseconds before it calls itself.
        glutTimerFunc(40, timer1, 0);
    }

/* Main function: GLUT runs as a console application starting at main()  */
    int main(int argc, char **argv) {

        init();

        glutInit(&argc, argv);          // Initialize GLUT

        glutInitDisplayMode(GLUT_RGBA);

        glutInitWindowSize((int) width, (int) height);
        glutInitWindowPosition(200, 200); // Position the window's initial top-left corner
        /* create the window and store the handle to it */
        wd = glutCreateWindow("Fun with Drawing!" /* title */ );

        // Register callback handler for window re-paint event
        glutDisplayFunc(display);

        // Our own OpenGL initialization
        initGL();

        // register keyboard press event processing function
        // works for numbers, letters, spacebar, etc.
        glutKeyboardFunc(kbd);

        // register special event: function keys, arrows, etc.
        glutSpecialFunc(kbdS);

        // handles mouse movement
        glutPassiveMotionFunc(cursor);

        // handles mouse click
        glutMouseFunc(mouse);

        // handles timer

        glutTimerFunc(0, timer, 0);
        //  glutTimerFunc(0, timer1, 0);


        // Enter the event-processing loop
        glutMainLoop();
        return 0;

    }

