#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;

namespace ariel
{
    Point::Point(): _point_x(0.0), _point_y(0.0) {}

    double Point::distance(Point point) const
    {
        return(sqrt((pow(this->_point_x - point._point_x, 2))+ pow(this->_point_y - point._point_y, 2)));
    }

    Point Point::moveTowards(Point source, Point dest, double dis)
    {
        if(dis < 0) throw invalid_argument("Distance can't be negative!");

        double disX = dest._point_x - source._point_x;
        double disY = dest._point_y - source._point_y;
        double curDist = source.distance(dest);
        if( curDist <= dis ) return dest;
        else
        {
            double flag = dis / curDist;
            double newX = source._point_x + (disX * flag);
            double newY = source._point_y + (disY * flag);
            return Point(newX, newY);
        }
    }

    void Point::print() const
    {
        cout << "(" << _point_x << ',' << _point_y << ")";
    }
}