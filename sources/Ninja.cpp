#include "Ninja.hpp"
using namespace std;

namespace ariel
{
    Ninja::Ninja(string name, Point location, int hp, int speed):
     Character(name, location, hp), _speed(speed) {}
    
    void Ninja::move(Character *other)
    {
        return;
    }

    void Ninja::slash(Character *other)
    {
        return;
    }
}
