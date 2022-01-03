#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
class figure
{
protected:
    int x;
    int y;
    int directionx = 0;
    int directiony = 0;
    int BreakPoint;
    int r;
    int g;
    int c = 0;
    int b;
    int n = 0;
    int m = 0;
    int s;
    int t;
    int w;
    int h;
    int rad;
    int scale;
    int rot = 0;
public:
    figure()
    {
        x = 100 + rand() % 220;
        y = 100 + rand() % 220;

        directionx = -1 + rand() % (1 - -1 + 1);

        directiony = -1 + rand() % (1 - -1 + 1);
        r = rand() % 256;
        g = rand() % 256;
        b = rand() % 256;
    }


    void LineMove()
    {
        while ((directionx == 0) && (directiony == 0))
        {
            directionx = -1 + rand() % (1 - -1 + 1);
            directiony = -1 + rand() % (1 - -1 + 1);
        }


        x += directionx;

        y += directiony;


    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }
    int getr()
    {
        return r;
    }
    int getg()
    {
        return g;
    }
    int getrb()
    {
        return b;
    }
    int getrm(int m)
    {
        return m;
    }
    int getrn(int n)
    {
        return n;
    }
    int rotate()
    {
        rot++;
        return rot;
    }

    int getsize()
    {
        return s;
    }
    int gettops()
    {
        return t;
    }

    /*void moveel()
    {
        if ((x == getsize()) || (x > (400 - this->getsize())))
        {
            directionx *= -1;
            directiony = -1 + rand() % 3;
        }

        if ((y == gettops() + 5) || (y > (400 - this->gettops())))
        {
            directiony *= -1;
            directionx = -1 + rand() % 3;
        }
    }*/
  virtual void moves()
    {

        if ((x == getsize()) || (x == gettops()) || (x == (400 - this->getsize())) || (x == (400 - this->gettops() /2)))
        {
            directionx *= -1;
            directiony = -1 + rand() % 3;
        }

        if ((y == getsize()) || (y == gettops()) || (y == (400 - this->getsize())) || (y == (400 - this->gettops()/2 )))
        {
            directiony *= -1;
            directionx = -1 + rand() % 3;
        }
    }

};

class point : public figure
{

public:
    point()
    {
        s = 3;
    }
   /* virtual void moves()
    {

        if ((x == getsize()) || (x == gettops()) || (x == (400 - this->getsize())) || (x == (400 - this->gettops() / 2)))
        {
            directionx *= -1;
            directiony = -1 + rand() % 3;
        }

        if ((y == getsize()) || (y == gettops()) || (y == (400 - this->getsize())) || (y == (400 - this->gettops() / 2)))
        {
            directiony *= -1;
            directionx = -1 + rand() % 3;
        }
    }*/

};
class line : public point
{

public:
    line()
    {
        s = 30;
        t = 2;
    }
};

class triangle : public line
{
public:
    triangle()
    {
        s = 30; //60
        t = 3;
    }
};

class phombus : public line
{
public:
    phombus(int s = 30)
    {
        this->s = s;
       // s = 30; //60
        t = 4;
    }
};

class rectangle : public line
{
public:

    /*rectangle(int s = 70, int t = 35)
    {
        this->s = s;
        this->t = t;
    }*/
    rectangle()
    {
        s = 35;
        t = 70;
    }
    
};

class circle : public point
{
public:
    int getrad()
    {
        return rad;
    }

    circle()
    {
        s = 30; //40
    } 
    circle(int radius)
    {
        s = radius; //40
    }
};

class ellipse : public circle
{
public:
    int getscale()
    {
        return scale;
    }

    ellipse()
    {
        s = 20;
        t = 20;

        scale = 2;

    }
    void moves() override
    {

        if ((x == getsize()) || (x == gettops()) || (x == (399 - this->getsize())) || (x == (399 - this->gettops() / 2)))
        {
            directionx *= -1;
            directiony = -1 + rand() % 3;
        }

        if ((y == getsize()) || (y == gettops()) || (y == (399 - this->getsize())) || (y == (399 - this->gettops() / 2)))
        {
            directiony *= -1;
            directionx = -1 + rand() % 3;
        }
    }
};