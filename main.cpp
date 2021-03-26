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
    void setLife(int newLife);
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
void Monster::setLife(int newLife)
{
    this.life = newLife;
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
    void setLife(int newLife);
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
        int d = 0;
        if (choiceOfWeapon == "Sword")
        {
            do{
                d = rand() % 100;
            } while((d < 7) || (d > 9));
            return d;
        }
        else if (choiceOfWeapon == "Fireball")
        {
            if (mana > 9)
            {
                do{
                    d = rand() % 100;
                } while ((d < 1) || (d > 18));
                mana = mana - 10;
                return d;
            }
            else
            {
                cout << "You don't have enough mana!" << endl;
                do{
                    d = rand() % 100;
                } while ((d < 7) || (d > 9));
                return d;
            }
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

class GoPlaying
{
private:
    Human* h = new Human();
    Monster* m = new Monster();
public:
    GoPlaying();
};
GoPlaying::GoPlaying()
{
    while((h->getLife() > 0) && (m->getLife() > 0))
    {
        cout << "Choose your weapon between Sword and Fireball: ";
        string ans;
        cin >> ans;
        h->setWeapon(ans);
        m->
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
    humanCheck->printData(humanCheck->getLife(), humanCheck->getMana(), humanCheck->getStatus());
}
