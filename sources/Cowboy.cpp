#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(string name, Point location): Character(name, location, 110), _bullets(6)
    {}

    bool Cowboy::hasboolets()
    {
        return _bullets > 0;
    }

    void Cowboy::reload()
    {
        if(!isAlive()) throw runtime_error("Cowboy is dead!!");
        _bullets += 6;
    }

    void Cowboy::shoot(Character * other)
    {
        if(isAlive() && hasboolets())
        {
            other->hit(10);
            _bullets -= 1;
        }
    }

    int Cowboy::getBullets() const
    {
        return _bullets;
    }
}