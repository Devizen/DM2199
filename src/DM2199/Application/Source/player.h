#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"

class Player : public GameObject
{
public:
    Player();
    ~Player();

    //Getter
    unsigned getHealth();
    int getDamage();

    //Setter
    void setHealth(unsigned health);
    void setDamage(int damage);

protected:
private:
    unsigned health;
    int damage;

};

#endif