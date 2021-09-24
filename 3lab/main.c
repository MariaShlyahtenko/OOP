#include <SFML/Graphics.hpp>
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
    int directionx;
    int directiony;
    int BreakPoint;
    int r;
    int g;
    int b;

public:
    void input()
    {

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

    int RandomMove()
    {

        BreakPoint = 500;
        directionx = -1 + rand() % (1 - -1 + 1);
        directiony = -1 + rand() % (1 - -1 + 1);

        return BreakPoint;
    }
};

void RandPointMove();
void RenderPoints();
void PointsMove();

int main()
{

    srand(time(NULL));
    RenderPoints();
    //PointsMove();
    //RandPointMove();
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
    RenderWindow window(VideoMode(1920, 1080), "SFML Works!");

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
    points MRPoint;
    MRPoint.input();

    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(1920, 1080), "SFML Works!");

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

        int BreakPoint = MRPoint.RandomMove();
        for (int i = 0; i < BreakPoint; i++)
        {
            int r = rand() % 256, g = rand() % 256, b = rand() % 256;
            window.clear(Color(0, 0, 0, 0));

            // Создаем фигуру - круг радиусом 3
            CircleShape circle(3.f);

            // Закрашиваем наш круг
            circle.setFillColor(Color(r, g, b));

            circle.move((MRPoint.getX()), (MRPoint.getY()));

            // Отрисовка круга
            window.draw(circle);

            // Отрисовка окна
            window.display();

            sleep(milliseconds(1000 / 500));

            MRPoint.LineMove();
        }
    }
}