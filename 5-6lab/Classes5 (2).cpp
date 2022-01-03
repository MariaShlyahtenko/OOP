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


};

class point : public figure
{

public:
    point()
    {
        s = 3;
    }
    void moves()
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
    }

    virtual CircleShape draw_figure()
    {
        CircleShape point((getsize()));
        point.setFillColor(Color(getr(), getg(), getrb()));
        point.move((getX()), (getY()));
        LineMove();
        moves();
        return point;
    }

};
class line : public point
{

public:
    line()
    {
        s = 30;
        t = 2;
    }

     RectangleShape Recdraw_figure() 
    {
        RectangleShape line(Vector2f(getsize()*2, gettops()));
        
        line.setOrigin(line.getGlobalBounds().width / 2, line.getGlobalBounds().height / 2);
        line.setFillColor(Color(getr(),getg(),getrb()));
        line.move((getX()), (getY()));
        LineMove();
        moves();
        line.rotate(rotate());
        return line;
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

    CircleShape draw_figure() override
    {
        CircleShape triangle(getsize(), gettops());
        triangle.setOrigin(triangle.getGlobalBounds().width / 2, triangle.getGlobalBounds().height / 2);
        triangle.setFillColor(Color(getr(), getg(), getrb()));
        triangle.move((getX()), (getY()));
        LineMove();
        moves();
        triangle.rotate(rotate());
        return triangle;
    }
};

class phombus : public line
{
public:
    phombus()
    {
        s = 30; //60
        t = 4;
    }

    CircleShape draw_figure() override
    {
        CircleShape phombus(getsize(), gettops());;
        phombus.setOrigin(phombus.getGlobalBounds().width / 2, phombus.getGlobalBounds().height / 2);
        //phombus.setOrigin(getsize() / 2, getsize() / 2);
        phombus.setFillColor(Color(getr(), getg(), getrb()));
        phombus.move((getX()), (getY()));
        LineMove();
        moves();
        phombus.rotate(rotate());
        return phombus;
    }
};

class rectangle : public line
{
public:

    rectangle()
    {
        s = 35;
        t = 70;
    }

    virtual RectangleShape Recdraw_figure()
    {
        RectangleShape rectangle(Vector2f(getsize(), gettops()));
        rectangle.setOrigin(rectangle.getGlobalBounds().width / 2, rectangle.getGlobalBounds().height / 2);
        rectangle.setFillColor(Color(getr(), getg(), getrb()));
        rectangle.move((getX()), (getY()));
        LineMove();
        moves();
        rectangle.rotate(rotate());
        return rectangle;
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
    CircleShape draw_figure() override
    {
        CircleShape circle(getsize());
        circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
        circle.setFillColor(Color(getr(), getg(), getrb()));
        circle.move((getX()), (getY()));
        LineMove();
        moves();
        return circle;
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

    CircleShape draw_figure() override
    {
        CircleShape ellipse(getsize() - 5, gettops());
        ellipse.setOrigin(ellipse.getGlobalBounds().width / 2, ellipse.getGlobalBounds().height / 2);

        ellipse.scale(2, 1);
        //ellipse.setScale(getscale(), 1);
        ellipse.setFillColor(Color(getr(), getg(), getrb()));
        ellipse.move((getX()), (getY()));
        ellipse.rotate(rotate());
        LineMove();
        moves();
        return ellipse;
    }
};