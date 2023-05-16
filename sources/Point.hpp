#pragma once

namespace ariel 
{
    class Point
    {
        private:
            double _point_x;
            double _point_y;

        public:
            Point();
            Point(double point_x = 0.0, double point_y = 0.0) : _point_x(point_x), _point_y(point_y) {}
    
            double getX() const { return _point_x; }
            double getY() const { return _point_y; }
            
            double distance(Point point) const;
    
            void print() const;
    
            static Point moveTowards(Point source, Point dest, double dis);
    };
}