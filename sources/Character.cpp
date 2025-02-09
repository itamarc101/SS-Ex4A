#include "Character.hpp"

using namespace std;

namespace ariel
{
    bool Character::isAlive() const
    {
        return _health > 0;
    }

    double Character::distance(Character *other)
    {
        return _location.distance(other->_location);
    }

    void Character::hit(int dmg)
    {
        if(dmg < 0) throw invalid_argument("dmg can't be negative!");
        _health -= dmg;
    }

    string Character::getName() const
    {
        return _name;
    }

    Point Character::getLocation() const
    {
        return _location;
    }

    string Character::print() 
    {
        return " ";
        // ostringstream ostream;
        // ostream << "Name: " << _name << "HP: " << to_string(_hp) << "Location: " << getLocation().print(); 
        // return ostream.str();
    }

}