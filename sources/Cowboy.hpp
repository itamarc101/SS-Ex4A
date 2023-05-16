#pragma once
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        private:
            int _bullets;

        public:
            Cowboy(std::string name, Point location);
            void shoot(Character *other);
            bool hasboolets();
            void reload();
            
            int getBullets() const;
    };
}
