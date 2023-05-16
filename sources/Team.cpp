#include "Team.hpp"
using namespace std;

namespace ariel
{
    Team::Team(Character * leader): _leader(leader), _sizeOfTeam(1)
    {
        _team.push_back(leader);
    }

    Team::~Team()
    {
        return;
    }

    void Team::add(Character * member)
    {
        if(_sizeOfTeam == 10) throw runtime_error("The team is full!");
        _team.push_back(member);
        _sizeOfTeam++;

    }

    void Team::attack(Team * other)
    {
        
    }

    int Team::stillAlive() const
    {
        int isAlive = 0;
        for(unsigned long int i = 0; i < _sizeOfTeam; i++)
        {
            if(_team[i]->isAlive()) isAlive++;
        }

        //return isAlive;
        return 0;
    }

    void Team::print()
    {

    }

}