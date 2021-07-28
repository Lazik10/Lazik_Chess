#pragma once
#include <QGraphicsRectItem>

#include "utilities.h"

class Piece : public QGraphicsRectItem
{
public:
    Piece();
    Piece(Ranks rank, Color color, Position position);
    ~Piece();

    inline Ranks GetRank() { return m_rank; }
    inline Position GetPosition() { return m_position; }
    QString PrintRank();
    QString PrintPositon();

    inline Piece* GetPointer() { return m_pointer; }

    void keyPressEvent(QKeyEvent* event) override;

private:
    Piece* m_pointer;
    Ranks m_rank;
    Color m_color;
    Position m_position;
};