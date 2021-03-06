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
    void setStatus(bool s);
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
    life = newLife;
}
bool Monster::getStatus()
{
    return loseStatus;
}
void Monster::setStatus(bool s)
{
    loseStatus = s;
}
void Monster::printData(int life, bool loseStatus)
{
    if (loseStatus == false)
    {
        cout << "Monster's life is " << life << " and its lose status is false" << endl;
    }
    else
    {
        cout << "Monster's life is " << life << " and its lose status is true" << endl;
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
    void setStatus(bool s);
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
void Human::setLife(int newLife)
{
    life = newLife;
}
int Human::getMana()
{
    return mana;
}
bool Human::getStatus()
{
    return loseStatus;
}
void Human::setStatus(bool s)
{
    loseStatus = s;
}
void Human::printData(int life, int mana, bool status)
{
    if (status == false)
    {
        cout << "Human's life is " << life << " and his mana is " << mana << " and his lose status is false" << endl;
    }
    else
    {
        cout << "Human's life is " << life << " and his mana is " << mana << " and his lose status is true" << endl;
    }
}

class GoPlaying
{
private:
    Human* h = new Human();
    Monster* m = new Monster();
public:
    GoPlaying();
    ~GoPlaying();
    GoPlaying(Human* chosenHuman, Monster* chosenMonster);
};
GoPlaying::GoPlaying()
{
    h->printData(h->getLife(), h->getMana(), h->getStatus());
    m->printData(m->getLife(), m->getStatus());
    while((h->getLife() > 0) && (m->getLife() > 0))
    {
        cout << "Choose your weapon between Sword and Fireball: ";
        string ans;
        cin >> ans;
        while((ans != "Sword") && (ans != "Fireball"))
        {
            cout << "Your choice of weapon is not valid!" << endl;
            cout << "Choose your weapon between Sword and Fireball: ";
            cin >> ans;
        }
        h->setWeapon(ans);
        m->setLife(m->getLife()-h->damage());
        m->printData(m->getLife(), m->getStatus());
        h->setLife(h->getLife()-m->damage());
        h->printData(h->getLife(), h->getMana(), h->getStatus());
    }
    if (h->getLife() <= 0)
        {
            h->setStatus(true);
            cout << "Human lost with below results: " << endl;
            h->printData(h->getLife(), h->getMana(), h->getStatus());
            cout << "Monster won!" << endl;
            m->printData(m->getLife(), m->getStatus());
        }
    else
        {
            m->setStatus(true);
            cout << "Monster lost with below results: " << endl;
            m->printData(m->getLife(), m->getStatus());
            cout << "Human won!" << endl;
            h->printData(h->getLife(), h->getMana(), h->getStatus());
        }
}
GoPlaying::~GoPlaying()
{
    cout << "Finished!" << endl;
}
GoPlaying::GoPlaying(Human* chosenHuman, Monster* chosenMonster)
{
    h = chosenHuman;
    m = chosenMonster;
    h->printData(h->getLife(), h->getMana(), h->getStatus());
    m->printData(m->getLife(), m->getStatus());
    while((h->getLife() > 0) && (m->getLife() > 0))
    {
        cout << "Choose your weapon between Sword and Fireball: ";
        string ans;
        cin >> ans;
        while((ans != "Sword") && (ans != "Fireball"))
        {
            cout << "Your choice of weapon is not valid!" << endl;
            cout << "Choose your weapon between Sword and Fireball: ";
            cin >> ans;
        }
        h->setWeapon(ans);
        m->setLife(m->getLife()-h->damage());
        m->printData(m->getLife(), m->getStatus());
        h->setLife(h->getLife()-m->damage());
        h->printData(h->getLife(), h->getMana(), h->getStatus());
    }
    if (h->getLife() <= 0)
        {
            h->setStatus(true);
            cout << "Human lost with below results: " << endl;
            h->printData(h->getLife(), h->getMana(), h->getStatus());
            cout << "Monster won!" << endl;
            m->printData(m->getLife(), m->getStatus());
        }
    else
        {
            m->setStatus(true);
            cout << "Monster lost with below results: " << endl;
            m->printData(m->getLife(), m->getStatus());
            cout << "Human won!" << endl;
            h->printData(h->getLife(), h->getMana(), h->getStatus());
        }
}

int main()
{
    GoPlaying* goPlaying1 = new GoPlaying();
    cout << "New Game: " << endl;
    Human* hum = new Human(60, 20);
    Monster* mon = new Monster(20);
    GoPlaying* goPlaying = new GoPlaying(hum, mon);
}
