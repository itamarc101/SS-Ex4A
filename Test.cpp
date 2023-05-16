#include "doctest.h"

#include "sources/Team.hpp" //no need for other includes
using namespace ariel;

TEST_CASE("Test Point distance function")
{
    SUBCASE("Test distance between two points")
    {
        Point p1(0, 0);
        CHECK(p1.getX() == 0);
        CHECK(p1.getY() == 0);
        Point p2(3, 4);
        double expected_dist = 5;
        CHECK(p1.distance(p2) == expected_dist);
    }

    SUBCASE("Test distance between a point and itself")
    {
        Point p1(0, 0);
        CHECK(p1.distance(p1) == 0);
    }

    SUBCASE("Test distance with negative coordinates")
    {
        Point p1(-3, -4);
        Point p2(0, 0);
        double expected_dist = 5;
        CHECK(p1.distance(p2) == expected_dist);
    }
}

TEST_CASE("Test Point moveTowards function")
{
    SUBCASE("Test moving towards a point with positive distance")
    {
        Point source(0, 0);
        Point dest(4, 3);
        double distance = 5;
        Point expected_point(3.2, 2.4);
        CHECK(source.moveTowards(source, dest, distance).distance(expected_point) > 0.001);// maybe should be <
    }

    SUBCASE("Test moving towards a point with zero distance")
    {
        Point source(0, 0);
        Point dest(1, 2);
        double distance = 0;
        CHECK(source.moveTowards(source, dest, distance).distance(source) == 0);
    }

    SUBCASE("Test moving towards a point with negative distance")
    {
        Point source(0, 0);
        Point dest(4, 3);
        double distance = -2;
        CHECK_THROWS(source.moveTowards(source, dest, distance));
    }

    SUBCASE("Test moving towards a point when already at the destination")
    {
        Point source{4, 3};
        Point dest{4, 3};
        double distance = 5;
        CHECK(source.distance(dest) == 0);
        CHECK(source.moveTowards(source, dest, distance).distance(dest) == 0);
    }
}

TEST_CASE("Character - isAlive")
{
    Point zero(0,0);
    SUBCASE("HP > 0")
    {

        Character c("mize", zero, 100);
        CHECK(c.isAlive() == true);
    }
    
    SUBCASE("HP < 0")
    {
        Character c("mi", zero, -10);
        CHECK(c.isAlive() == false);
    }
    
    SUBCASE("HP == 0")
    {
        Character c("ze", zero, 0);
        CHECK(c.isAlive() == false);
    }
}

TEST_CASE("Character - distance")
{
    Point p1(0,0);
    Point p2(3,4);
    Character c1("player 1", p1, 100);
    Character c2("player 2", p2, 100);
    CHECK(c1.distance(&c2) == 5);
    CHECK(c2.distance(&c1) == 5);
}

TEST_CASE("Character - hit")
{
    Point p(0,0);
    Character c("hit me", p, 100);
    CHECK_NOTHROW(c.hit(10));
    CHECK(c.isAlive() == true);
    CHECK_THROWS(c.hit(-10));
    CHECK(c.isAlive() == true);
    CHECK_NOTHROW(c.hit(110));
    CHECK(c.isAlive() == false);
}

TEST_CASE("Character - getName")
{
    Point p(0,0);
    Character c("Ninboy", p, 100);
    CHECK(c.getName() == "Ninboy");
}

TEST_CASE("Character - getLocation")
{
    Point p(1.2,3.4);
    Character c("Ninboy", p, 100);
    CHECK(c.getLocation().getX() == 1.2);
    CHECK(c.getLocation().getY() == 3.4);
}

TEST_CASE("Cowboy - hasboolets")
{
    Cowboy c("cowboy test", Point(0,0));
    Cowboy c2("cowboy2 test", Point(0,0));
    CHECK(c.getBullets() == 6);
    CHECK(c.hasboolets() == true);
    for(int i = 0; i < 6; i++)
        c.shoot(&c2);
    CHECK(c.hasboolets() == false);
    CHECK(c.getBullets() == 0);

    //c has 0 bullets so cant shoot anymore
    CHECK_THROWS(c.shoot(&c2));
    CHECK_NOTHROW(c.reload());
    CHECK(c.getBullets() == 6);
    CHECK(c.hasboolets() == true);
    CHECK_THROWS(c.shoot(&c));
    c.hit(110);
    // c is dead so c2 cant shoot dead player
    CHECK_THROWS(c2.shoot(&c));
}

TEST_CASE("Ninja ")
{
    Ninja n("Ishimoto", Point(2.7,7.2), 110, 14);
    CHECK(n.getLocation().getX() == 2.7);
    CHECK(n.getLocation().getY() == 7.2);
    CHECK(n.isAlive() == true);

    Ninja n1("Kiyosa", Point(7.2,2.7), 120, 14);
    n1.move(&n);
    CHECK(n1.getLocation().getX() == 2.7);
    CHECK(n1.getLocation().getY() == 7.2);

    n.hit(110);
    // n is dead so n1 cant attack ded player
    CHECK_THROWS(n1.slash(&n));
}

TEST_CASE("Adding characters to the team")
{
    Cowboy cowboy("Lucky Luk", Point(0,0));
    Team team(&cowboy);

    Ninja ninja1("Leii", Point(2,2), 120, 12);
    Ninja ninja2("Yokuza", Point(3,3), 120, 12);
    team.add(&ninja1);
    team.add(&ninja2);

    CHECK(team.stillAlive() == 3);
}

TEST_CASE("Maximum characters and try to add more")
{
    Cowboy c("Lucky Luk", Point(0,0));
    Team team(&c);

    for(int i = 0; i < 9; i++)
    {
        Ninja n("Shinobi", Point(i,i), 120, 12);
        team.add(&n);
    }
    CHECK(team.stillAlive() == 10);
    //try to add another ninja
    Ninja n2("Tengu", Point(2,7), 120, 12);
    CHECK_THROWS(team.add(&n2));
}

