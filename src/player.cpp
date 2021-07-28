#include "player.h"

Player::Player()
{
}

Player::Player(QString name, qint8 age, qint8 rating) :
    m_name(name), m_age(age), m_rating(rating)
{
}

Player::~Player()
{
}