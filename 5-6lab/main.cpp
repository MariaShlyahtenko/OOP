//lab 3
/*#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace sf;
using namespace std;

class points
{
private:
    int x;
    int y;
    int directionx = 0;
    int directiony = 0;
    int BreakPoint;
    int r;
    int g;
    int c = 0;
    int b;

public:
    void input()
    {
        BreakPoint = rand() % 500;

        x = rand() % 400;
        y = rand() % 400;

        directionx = -1 + rand() % (1 - -1 + 1);

        directiony = -1 + rand() % (1 - -1 + 1);
        r = rand() % 256;
        g = rand() % 256;
        b = rand() % 256;
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

    void LineMove()
    {
        while ((directionx == 0) && (directiony == 0))
        {
            directionx = -1 + rand() % (1 - -1 + 1);
            directiony = -1 + rand() % (1 - -1 + 1);
        }

        if ((x == 400) || (x == 0))
        {
            directionx *= -1;
            directiony = -1 + rand() % 3;
        }

        if ((y == 400) || (y == 0))
        {
            directiony *= -1;
            directionx = -1 + rand() % 3;
        }
        x += directionx;

        y += directiony;
    }

    void RandomMove()
    {

        while ((directionx == 0) && (directiony == 0))
        {

            directionx = -1 + rand() % (1 - -1 + 1);
            directiony = -1 + rand() % (1 - -1 + 1);
        }

        if ((x == 400) || (x == 0))
        {
            directionx *= -1;
            directiony = -1 + rand() % 3;
        }

        if ((y == 400) || (y == 0))
        {
            directiony *= -1;
            directionx = -1 + rand() % 3;
        }
        if (c == BreakPoint)
        {

            directiony = -1 + rand() % 3;
            directionx = -1 + rand() % 3;

            c = 0;
        }
        c++;
        x += directionx;

        y += directiony;
    }
};

void RandPointMove();
void RenderPoints();
void PointsMove();

int main()
{

    srand(time(NULL));
    // RenderPoints();
    //PointsMove();
    RandPointMove();
    return 0;
}

void RenderPoints()
{

    points ArrPoint[100] = {};

    int r = rand() % 256, g = rand() % 256, b = rand() % 256;

    for (int i = 0; i < 100; i++)
    {
        //r = rand() % 256, g = rand() % 256, b = rand() % 256;
        ArrPoint[i].input();
    }

    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(400, 400), "SFML Works!");

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }

        window.clear(Color(0, 0, 0, 0));

        for (int i = 0; i < 100; i++)
        {

            CircleShape circle(3.f);
            circle.setFillColor(Color(ArrPoint[i].getr(), ArrPoint[i].getg(), ArrPoint[i].getrb()));
            circle.move((ArrPoint[i].getX()), (ArrPoint[i].getY()));
            ArrPoint[i].LineMove();
            window.draw(circle);
        }

        // Отрисовка окна
        window.display();
        sleep(milliseconds(1000 / 500));
    }
}

void PointsMove()
{
    points MPoint;
    MPoint.input();
    int r = rand() % 256, g = rand() % 256, b = rand() % 256;
    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(400, 400), "SFML Works!");

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            //  закрыть окно
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color(0, 0, 0, 0));

        // Создаем фигуру - круг радиусом 3
        CircleShape circle(3.f);

        // Закрашиваем наш круг
        circle.setFillColor(Color(r, g, b));

        circle.move((MPoint.getX()), (MPoint.getY()));

        // Отрисовка круга
        window.draw(circle);

        // Отрисовка окна
        window.display();

        sleep(milliseconds(1000 / 500));

        MPoint.LineMove();
    }
}

void RandPointMove()
{

    points ArrPoint[100] = {};

    int r = rand() % 256, g = rand() % 256, b = rand() % 256;

    for (int i = 0; i < 100; i++)
    {
        //r = rand() % 256, g = rand() % 256, b = rand() % 256;
        ArrPoint[i].input();
    }

    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(400, 400), "SFML Works!");

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }

        window.clear(Color(0, 0, 0, 0));

        for (int i = 0; i < 100; i++)
        {

            CircleShape circle(3.f);
            circle.setFillColor(Color(ArrPoint[i].getr(), ArrPoint[i].getg(), ArrPoint[i].getrb()));

            ArrPoint[i].RandomMove();
            circle.move((ArrPoint[i].getX()), (ArrPoint[i].getY()));

            window.draw(circle);
        }

        // Отрисовка окна
        window.display();
        sleep(milliseconds(1000 / 500));
    }
}*/













/*#include <SFML/Graphics.hpp>
#include "Classes4.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace sf;
using namespace std;

void RandPointMove();
void RenderPoints();
void PointsMove();
void RenderLine();
void RenderTriangle();

int main()
{

    srand(time(NULL));
    // RenderPoints();
    // RenderTriangle();

    RenderLine();
    //PointsMove();
    // RandPointMove();
    return 0;
}

void RenderLine()
{

   line Mline;
    int r = rand() % 256, g = rand() % 256, b = rand() % 256;
   
    point Mpoint;
    r = rand() % 256, g = rand() % 256, b = rand() % 256;  

    triangle Mtriangle;
    r = rand() % 256, g = rand() % 256, b = rand() % 256;
   
    phombus Mphombus;
    r = rand() % 256, g = rand() % 256, b = rand() % 256;
   
    rectangle Mrectangle;
    r = rand() % 256, g = rand() % 256, b = rand() % 256;

    circle Mcircle;
    r = rand() % 256, g = rand() % 256, b = rand() % 256;

    ellipse Mellipse;
    r = rand() % 256, g = rand() % 256, b = rand() % 256;
   
     // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(400, 400), "SFML Works!");

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }

        window.clear(Color(0, 0, 0, 0));

        RectangleShape line(Vector2f(Mline.getsize()*2, Mline.gettops()));
        CircleShape point((Mpoint.getsize()));
        CircleShape triangle(Mtriangle.getsize(), Mtriangle.gettops());
        CircleShape phombus(Mphombus.getsize(), Mphombus.gettops());
        RectangleShape rectangle(Vector2f(Mrectangle.getsize(), Mrectangle.gettops()));
        CircleShape circle(Mcircle.getsize());
        CircleShape ellipse(Mellipse.gettops());


        triangle.setOrigin(triangle.getGlobalBounds().width / 2, triangle.getGlobalBounds().height / 2);
        rectangle.setOrigin(rectangle.getGlobalBounds().width / 2, rectangle.getGlobalBounds().height / 2);
        line.setOrigin(line.getGlobalBounds().width / 2, line.getGlobalBounds().height / 2);
        phombus.setOrigin(phombus.getGlobalBounds().width / 2, phombus.getGlobalBounds().height / 2);
        circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
        ellipse.setOrigin(ellipse.getGlobalBounds().width / 2, ellipse.getGlobalBounds().height / 2);
        point.setOrigin(point.getGlobalBounds().width / 2, point.getGlobalBounds().height / 2);

        ellipse.setScale(Mellipse.getscale(), 1);

        line.setFillColor(Color(Mline.getr(), Mline.getg(), Mline.getrb()));
        point.setFillColor(Color(Mpoint.getr(), Mpoint.getg(), Mpoint.getrb()));
        triangle.setFillColor(Color(Mtriangle.getr(), Mtriangle.getg(), Mtriangle.getrb()));
        phombus.setFillColor(Color(Mphombus.getr(), Mphombus.getg(), Mphombus.getrb()));
        rectangle.setFillColor(Color(Mrectangle.getr(), Mrectangle.getg(), Mrectangle.getrb()));
        circle.setFillColor(Color(Mcircle.getr(), Mcircle.getg(), Mcircle.getrb()));
        ellipse.setFillColor(Color(Mellipse.getr(), Mellipse.getg(), Mellipse.getrb()));

        line.move((Mline.getX()), (Mline.getY()));
        point.move((Mpoint.getX()), (Mpoint.getY()));
        triangle.move((Mtriangle.getX()), (Mtriangle.getY()));
        phombus.move((Mphombus.getX()), (Mphombus.getY()));
        rectangle.move((Mrectangle.getX()), (Mrectangle.getY()));
        circle.move((Mcircle.getX()), (Mcircle.getY()));
        ellipse.move((Mellipse.getX()), (Mellipse.getY()));
        
        Mline.LineMove();
        Mline.moves();
        Mpoint.LineMove();
        Mpoint.moves();
        Mtriangle.LineMove();
        Mtriangle.moves();
        Mphombus.LineMove();
        Mphombus.moves();
        Mrectangle.LineMove();
        Mrectangle.moves();
        Mcircle.LineMove();
        Mcircle.moves();
        Mellipse.LineMove();
        Mellipse.moveel();
       
        triangle.rotate(Mtriangle.rotate());
        rectangle.rotate(Mrectangle.rotate());
        line.rotate(Mline.rotate());
        phombus.rotate(Mphombus.rotate());
        ellipse.rotate(Mellipse.rotate());


        window.draw(line);
        window.draw(point);
        window.draw(triangle);
        window.draw(phombus);
        window.draw(rectangle);
        window.draw(circle);
        window.draw(ellipse);

        // Отрисовка окна
        window.display();
        sleep(milliseconds(1000 / 500));
    }
}*/






/*#include <SFML/Graphics.hpp>
#include "Classes5.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace sf;
using namespace std;

void RandPointMove();
void RenderPoints();
void PointsMove();
void RenderLine();
void RenderTriangle();

int main()
{

    srand(time(NULL));
    // RenderPoints();
    // RenderTriangle();

    RenderLine();
    //PointsMove();
    // RandPointMove();
    return 0;
}

void RenderLine()
{
    point ArrPoint[2] = {};
 
    circle ArrCircle[2] = {};

    triangle ArrTriangle[2] = {};

    rectangle ArrRectangle[2] = {};
 
    line ArrLine[2] = {};

    phombus ArrRhombus[2] = {};
 
    ellipse ArrEllipse[2] = {};


    

     // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(400, 400), "SFML Works!");

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }

        window.clear(Color(0, 0, 0, 0));
           
        for (int i = 0; i < 2; i++)
        {
            window.draw(ArrPoint[i].draw_figure());
            window.draw(ArrCircle[i].draw_figure());
            window.draw(ArrTriangle[i].draw_figure());
            window.draw(ArrRectangle[i].Recdraw_figure());
            window.draw(ArrLine[i].Recdraw_figure());
            window.draw(ArrRhombus[i].draw_figure());
            window.draw(ArrEllipse[i].draw_figure());
        }
        

        // Отрисовка окна
        window.display();
        sleep(milliseconds(1000 / 500));
    }
}*/



  

#include <SFML/Graphics.hpp>
#include "Classes5.1.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace sf;
using namespace std;

void RandPointMove();
void RenderPoints();
void PointsMove();
void RenderLine();
void RenderTriangle();

int main()
{

    srand(time(NULL));
    // RenderPoints();
    // RenderTriangle();

    RenderLine();
    //PointsMove();
    // RandPointMove();
    return 0;
}

/*void RenderLine()
{
    point ArrPoint[2] = {};

    circle ArrCircle[2] = {};

    triangle ArrTriangle[2] = {};

    rectangle ArrRectangle[2] = {};

    line ArrLine[2] = {};

    phombus ArrRhombus[2] = {};

    ellipse ArrEllipse[2] = {};
    

    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(400, 400), "SFML Works!");

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }

        window.clear(Color(0, 0, 0, 0));

        for (int i = 0; i < 2; i++) {

            RectangleShape line(Vector2f(ArrLine[i].getsize() * 2, ArrLine[i].gettops()));
            CircleShape point((ArrPoint[i].getsize()));
            CircleShape triangle(ArrTriangle[i].getsize(), ArrTriangle[i].gettops());
            CircleShape phombus(ArrRhombus[i].getsize(), ArrRhombus[i].gettops());
            RectangleShape rectangle(Vector2f(ArrRectangle[i].getsize(), ArrRectangle[i].gettops()));
            CircleShape circle(ArrCircle[i].getsize());
            CircleShape ellipse(ArrEllipse[i].getsize() - 5, ArrEllipse[i].gettops());
            //CircleShape ellipse(ArrEllipse[i].gettops());


            triangle.setOrigin(triangle.getGlobalBounds().width / 2, triangle.getGlobalBounds().height / 2);
            rectangle.setOrigin(rectangle.getGlobalBounds().width / 2, rectangle.getGlobalBounds().height / 2);
            line.setOrigin(line.getGlobalBounds().width / 2, line.getGlobalBounds().height / 2);
            phombus.setOrigin(phombus.getGlobalBounds().width / 2, phombus.getGlobalBounds().height / 2);
            circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
            ellipse.setOrigin(ellipse.getGlobalBounds().width / 2, ellipse.getGlobalBounds().height / 2);
            point.setOrigin(point.getGlobalBounds().width / 2, point.getGlobalBounds().height / 2);

            ellipse.setScale(2, 1);

            line.setFillColor(Color(ArrLine[i].getr(), ArrLine[i].getg(), ArrLine[i].getrb()));
            point.setFillColor(Color(ArrPoint[i].getr(), ArrPoint[i].getg(), ArrPoint[i].getrb()));
            triangle.setFillColor(Color(ArrTriangle[i].getr(), ArrTriangle[i].getg(), ArrTriangle[i].getrb()));
            phombus.setFillColor(Color(ArrRhombus[i].getr(), ArrRhombus[i].getg(), ArrRhombus[i].getrb()));
            rectangle.setFillColor(Color(ArrRectangle[i].getr(), ArrRectangle[i].getg(), ArrRectangle[i].getrb()));
            circle.setFillColor(Color(ArrCircle[i].getr(), ArrCircle[i].getg(), ArrCircle[i].getrb()));
            ellipse.setFillColor(Color(ArrEllipse[i].getr(), ArrEllipse[i].getg(), ArrEllipse[i].getrb()));

            line.move((ArrLine[i].getX()), (ArrLine[i].getY()));
            point.move((ArrPoint[i].getX()), (ArrPoint[i].getY()));
            triangle.move((ArrTriangle[i].getX()), (ArrTriangle[i].getY()));
            phombus.move((ArrRhombus[i].getX()), (ArrRhombus[i].getY()));
            rectangle.move((ArrRectangle[i].getX()), (ArrRectangle[i].getY()));
            circle.move((ArrCircle[i].getX()), (ArrCircle[i].getY()));
            ellipse.move((ArrEllipse[i].getX()), (ArrEllipse[i].getY()));

            ArrLine[i].LineMove();
            ArrLine[i].moves();
            ArrPoint[i].LineMove();
            ArrPoint[i].moves();
            ArrTriangle[i].LineMove();
            ArrTriangle[i].moves();
            ArrRhombus[i].LineMove();
            ArrRhombus[i].moves();
            ArrRectangle[i].LineMove();
            ArrRectangle[i].moves();
            ArrCircle[i].LineMove();
            ArrCircle[i].moves();
            ArrEllipse[i].LineMove();
            ArrEllipse[i].moves();

            triangle.rotate(ArrTriangle[i].rotate());
            rectangle.rotate(ArrRectangle[i].rotate());
            line.rotate(ArrLine[i].rotate());
            phombus.rotate(ArrRhombus[i].rotate());
            ellipse.rotate(ArrEllipse[i].rotate());


            window.draw(line);
            window.draw(point);
            window.draw(triangle);
            window.draw(phombus);
            window.draw(rectangle);
            window.draw(circle);
            window.draw(ellipse);
        }

        // Отрисовка окна
        window.display();
        sleep(milliseconds(1000 / 500));
    }
}*/

void RenderLine()
{
    point ArrPoint;
    circle ArrCircle(50);
    triangle ArrTriangle;
    rectangle ArrRectangle;
    line ArrLine;
    phombus ArrRhombus(50);
    ellipse ArrEllipse;

    int size = 7;
    figure** arr = new figure * [size];
    arr[0] = &ArrCircle;
    arr[1] = &ArrTriangle;
    arr[2] = &ArrRectangle;
    arr[3] = &ArrLine;
    arr[4] = &ArrRhombus;
    arr[5] = &ArrEllipse;
    arr[6] = &ArrPoint;


    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(400, 400), "SFML Works!");

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }

        window.clear(Color(0, 0, 0, 0));

            RectangleShape line(Vector2f(arr[3]->getsize() * 2, arr[3]->gettops()));
            CircleShape point((arr[6]->getsize()));
            CircleShape triangle(arr[1]->getsize(), arr[1]->gettops());
            CircleShape phombus(arr[4]->getsize(), arr[4]->gettops());
            RectangleShape rectangle(Vector2f(arr[2]->getsize(), arr[2]->gettops()));
            CircleShape circle(arr[0]->getsize());
            CircleShape ellipse(arr[5]->getsize() - 5, arr[5]->gettops());
            //CircleShape ellipse(ArrEllipse[i].gettops());


            triangle.setOrigin(triangle.getGlobalBounds().width / 2, triangle.getGlobalBounds().height / 2);
            rectangle.setOrigin(rectangle.getGlobalBounds().width / 2, rectangle.getGlobalBounds().height / 2);
            line.setOrigin(line.getGlobalBounds().width / 2, line.getGlobalBounds().height / 2);
            phombus.setOrigin(phombus.getGlobalBounds().width / 2, phombus.getGlobalBounds().height / 2);
            circle.setOrigin(circle.getGlobalBounds().width / 2, circle.getGlobalBounds().height / 2);
            ellipse.setOrigin(ellipse.getGlobalBounds().width / 2, ellipse.getGlobalBounds().height / 2);
            point.setOrigin(point.getGlobalBounds().width / 2, point.getGlobalBounds().height / 2);

            ellipse.setScale(2, 1);

            line.setFillColor(Color(arr[3]->getr(), arr[3]->getg(), arr[3]->getrb()));
            point.setFillColor(Color(arr[6]->getr(), arr[6]->getg(), arr[6]->getrb()));
            triangle.setFillColor(Color(arr[1]->getr(), arr[1]->getg(), arr[1]->getrb()));
            phombus.setFillColor(Color(arr[4]->getr(), arr[4]->getg(), arr[4]->getrb()));
            rectangle.setFillColor(Color(arr[2]->getr(), arr[2]->getg(), arr[2]->getrb()));
            circle.setFillColor(Color(arr[0]->getr(), arr[0]->getg(), arr[0]->getrb()));
            ellipse.setFillColor(Color(arr[5]->getr(), arr[5]->getg(), arr[5]->getrb()));

            line.move((arr[3]->getX()), (arr[3]->getY()));
            point.move((arr[6]->getX()), (arr[6]->getY()));
            triangle.move((arr[1]->getX()), (arr[1]->getY()));
            phombus.move((arr[4]->getX()), (arr[4]->getY()));
            rectangle.move((arr[2]->getX()), (arr[2]->getY()));
            circle.move((arr[0]->getX()), (arr[0]->getY()));
            ellipse.move((arr[5]->getX()), (arr[5]->getY()));

            arr[3]->LineMove();
            arr[3]->moves();
            arr[6]->LineMove();
            arr[6]->moves();
            arr[1]->LineMove();
            arr[1]->moves();
            arr[4]->LineMove();
            arr[4]->moves();
            arr[2]->LineMove();
            arr[2]->moves();
            arr[0]->LineMove();
            arr[0]->moves();
            arr[5]->LineMove();
            arr[5]->moves();

            triangle.rotate(arr[1]->rotate());
            rectangle.rotate(arr[2]->rotate());
            line.rotate(arr[3]->rotate());
            phombus.rotate(arr[4]->rotate());
            ellipse.rotate(arr[5]->rotate());


            window.draw(line);
            window.draw(point);
            window.draw(triangle);
            window.draw(phombus);
            window.draw(rectangle);
            window.draw(circle);
            window.draw(ellipse);

        // Отрисовка окна
        window.display();
        sleep(milliseconds(1000 / 500));
    }
}