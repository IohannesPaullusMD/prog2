#include <stdio.h>
#include <math.h>

#define ORIGIN 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4
#define X_AXIS 5
#define Y_AXIS 6

typedef struct 
{
    int x;
    int y;
} Point;

Point createPoint(int x, int y);
void displayPoint(Point *point);
int getPosition(Point *point);
double getDistance(Point *p1, Point *p2);

int main()
{
    Point p1 = createPoint(-4, -3);
    Point p2 = createPoint(0, 0);

    displayPoint(&p1);
    displayPoint(&p2);

    printf("p1 pos: %d\n", getPosition(&p1));
    printf("p2 pos: %d\n", getPosition(&p2));

    printf("distance: %lf\n", getDistance(&p1, &p2));
}

Point createPoint(int x, int y)
{
    return (Point) {x, y};
}

void displayPoint(Point *point)
{
    printf("x: %d\n", point->x);
    printf("y: %d\n", point->y);
}

int getPosition(Point *point)
{
    if (point->y == 0) 
    {
        return (point->x == 0) ? ORIGIN : X_AXIS; 
    }
    else if (point->x == 0) 
    {
        return Y_AXIS;
    }
    else if (point->x > 0)
    {
        return (point->y > 0) ? Q1 : Q4;
    }
    else
    {
        return (point->y > 0) ? Q2 : Q3;
    }

}

double getDistance(Point *p1, Point *p2)
{
    int dx =  abs(p2->x - p1->x);
    int dy = abs(p2->y - p1->y);
    return sqrt((dx*dx) + (dy*dy));
}
