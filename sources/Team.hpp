#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

namespace ariel
{
    class Team
    {
        private:
            Character *_leader;
            std::vector<Character *> _team;
            int _sizeOfTeam;
        
        public:
            Team(Character * leader);
            ~Team(); // destructor
            void add(Character * member);
            void attack(Team * other);
            int stillAlive() const;
            void print();
    };
}