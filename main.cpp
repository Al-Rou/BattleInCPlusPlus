#include <iostream>
#include <stdlib.h>

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
        int d = 0;
        do{
            d = rand() % 100;
        }while((d < 3) || (d > 14));
        return d;
    }
};

int main()
{
    Monster* monCheck = new Monster();
    cout << monCheck->damage();
}
