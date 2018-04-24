#ifndef CIRCLE_H
#define CIRCLE_H
class Circle {
    double origin_x;
    double origin_y;;
    double radius;
public:
    Circle(double x, double y, double rad);
    ~Circle();                           //destructor
    Circle(const Circle & circ);            //copy constructor
    Circle & operator=(const Circle & circ); //assignment
    double getOriginX();
    double getOriginY();
    double getRadius();
private:
    void init(double x, double y, double rad);
};
#endif
