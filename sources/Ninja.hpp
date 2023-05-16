#pragma once
#include "Character.hpp"

namespace ariel
{
    class Ninja: public Character
    {
        private:
            int _speed;
        
        public:
            Ninja(std::string name, Point location, int health, int speed);
            void move(Character *other);
            void slash(Character *other);
    };
}