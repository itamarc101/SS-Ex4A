#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;

namespace ariel
{
    Point::Point(): _x(0.0), _y(0.0) {}

    double Point::distance(Point point) const
    {
        return(sqrt((pow(this->_x - point._x, 2))+ pow(this->_y - point._y, 2)));
    }

    Point Point::moveTowards(Point source, Point dest, double dis)
    {
        if(dis < 0) throw invalid_argument("Distance can't be negative!");

        double disX = dest._x - source._x;
        double disY = dest._y - source._y;
        double curDist = source.distance(dest);
        if( curDist <= dis ) return dest;
        else
        {
            double flag = dis / curDist;
            double newX = source._x + (disX * flag);
            double newY = source._y + (disY * flag);
            return Point(newX, newY);
        }
    }

    void Point::print() const
    {
        cout << "(" << _x << ',' << _y << ")";
    }
}