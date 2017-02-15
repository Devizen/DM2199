#include "player.h"

Player::Player()
{
    health = 100;
    damage = 1;
}
   
Player::~Player()
{
  
}

//Getter
unsigned Player::getHealth()
{
    return health;
}


int Player::getDamage()
{
    return damage;
}


//Setter
void Player::setHealth(unsigned health)
{
    this->health = health;
}

void Player::setDamage(int damage)
{
    this->damage = damage;
}