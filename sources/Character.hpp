#pragma once
#include <iostream>
#include <cmath>
#include "Point.hpp"

namespace ariel
{
    class Character
    {
        private:
            Point _location;
            int _health;
            std::string _name;
        
        public:
            Character(const std::string& name, Point &location, int health):
            _name(name), _location(location), _health(health) {}
            
            bool isAlive() const;
            double distance(Character *other);
            void hit(int dmg);
            std::string getName() const;
            Point getLocation() const;
            virtual std::string print();

    };
}

