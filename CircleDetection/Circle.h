#ifndef CIRCLE_H
#define CIRCLE_H
  class Circle {
      int origin_x;
      int origin_y;;
      int radius;
    public:
      Circle(int x, int y, int rad);
      ~Circle();                           //destructor
      Circle(const Circle & circ);            //copy constructor
      Circle & operator=(const Circle & circ); //assignment
      int getOriginX();
      int getOriginY();
      int getRadius();
    private:
      void init(int x, int y, int rad);
  };
#endif
