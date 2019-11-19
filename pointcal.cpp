#include <iostream>

class Point{
    private:
        int x,y;
    public:
        Point(int pos_x, int pos_y);
};

class Geometry{
    Point **point_array;

    public:
        Geometry(Point **point_list);
        Geometry();

        void Add_point(const Point &point);
        void Print_Distance();
        void Print_Num_meets();
};