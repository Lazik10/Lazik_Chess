#pragma once

#include <QString>

class Player
{
public:
    Player();
    Player(QString name, qint8 age, qint8 m_rating);
    ~Player();

private:
    QString m_name;
    qint8 m_age;
    qint8 m_rating;
};
