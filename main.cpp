#include <iostream>
#include <math.h>

using namespace std;

class Player
{
private:
    int life;
    bool loseStatus;
public:
    int damage();
};

class Monster : public Player
{
public:
    int damage() override
    {

    }
};
