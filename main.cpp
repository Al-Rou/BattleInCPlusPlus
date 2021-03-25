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

class Human : public Player
{
private:
    int life;
    bool loseStatus;
    int mana;
    string choiceOfWeapon;
public:
    Human(int a = 100, int b = 35);
    int getLife();
    bool getStatus();
    int getMana();
    string getWeapon()
    {
        return choiceOfWeapon;
    }
    void setWeapon(string w)
    {
        choiceOfWeapon = w;
    }
    int damage() override
    {
        if (choiceOfWeapon == "Sword")
        {
            cout << "Weapon is Sword";
        }
        else if (choiceOfWeapon == "Fireball")
        {
            cout << "Weapon is Fireball";
        }
    }
    void printData(int life, int mana, bool status);
};
Human::Human(int a, int b):
    life(a),
    mana(b),
    loseStatus(false)
    {}
int Human::getLife()
{
    return life;
}
int Human::getMana()
{
    return mana;
}
bool Human::getStatus()
{
    return loseStatus;
}
void Human::printData(int life, int mana, bool status)
{
    if (status == false)
    {
        cout << "The life is " << life << " and the mana is " << mana << " and the lose status is false" << endl;
    }
    else
    {
        cout << "The life is " << life << " and the mana is " << mana << " and the lose status is true" << endl;
    }
}

int main()
{
    Monster* monCheck = new Monster();
    Human* humanCheck = new Human();
    cout << monCheck->damage() << endl;
    monCheck->printData(monCheck->getLife(), monCheck->getStatus());
    humanCheck->printData(humanCheck->getLife(), humanCheck->getMana(), humanCheck->getStatus());
    cout << "What weapon?";
    string answer;
    cin >> answer;
    humanCheck->setWeapon(answer);
    humanCheck->damage();
}
