#include <iostream>
#include <stdlib.h>

using namespace std;

class Player
{
public:
    virtual int damage() = 0;
};

class Monster : public Player
{
private:
    int life;
    bool loseStatus;
public:
    Monster(int a = 100);
    int getLife();
    bool getStatus();
    int damage() override
    {
        int d = 0;
        do{
            d = rand() % 100;
        }while((d < 3) || (d > 14));
        return d;
    }
    void printData(int life, bool loseStatus);
};
Monster::Monster(int a):
    life(a),
    loseStatus(false)
    {}
int Monster::getLife()
{
    return life;
}
bool Monster::getStatus()
{
    return loseStatus;
}
void Monster::printData(int life, bool loseStatus)
{
    if (loseStatus == false)
    {
        cout << "The life is " << life << " and the lose status is false" << endl;
    }
    else
    {
        cout << "The life is " << life << " and the lose status is true" << endl;
    }
}

int main()
{
    Monster* monCheck = new Monster();
    cout << monCheck->damage() << endl;
    monCheck->printData(monCheck->getLife(), monCheck->getStatus());
}
