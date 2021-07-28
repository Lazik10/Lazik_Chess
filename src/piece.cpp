//#include <iostream>
#include <qdebug>
#include <qkeyevent>

#include "piece.h"

Piece::Piece() :
    m_pointer(this), m_rank(Ranks::PAWN), m_color(Color::WHITE), m_position{ 0, 0 }
{

}

Piece::Piece(Ranks rank, Color color, Position positions) :
    m_pointer(this), m_rank(rank), m_color(color), m_position(positions)
{
    if (DEBUG)
        qDebug() << "Creating new piece";
}

Piece::~Piece()
{
    if (DEBUG)
        qDebug() << "Deleting piece";
}

QString Piece::PrintRank()
{
    for (qint8 i = 0; i < MAX_NOTATIONS; i++)
    {
        if (this->m_color == FEN_Notation[i].color && this->m_rank == FEN_Notation[i].rank)
        {
            return FEN_Notation[i].notation + ' ';
        }
    }
    return "Failed to print rank";
}

QString Piece::PrintPositon()
{
    QString position;
    position = "PositionX: " + QString().setNum(this->m_position.posX) + ' ' + "PositionY: " + QString().setNum(this->m_position.posY);
    return position;
}

void Piece::keyPressEvent(QKeyEvent* event)
{
    //if (event->key() == Qt::Key_Left)
    //{
    //    setPos(x() - OFFSET, y());
    //}
    //else if (event->key() == Qt::Key_Right)
    //{
    //    setPos(x() + OFFSET, y());
    //}
    //else if (event->key() == Qt::Key_Up)
    //{
    //    setPos(x(), y()+ OFFSET);
    //}
    //else if (event->key() == Qt::Key_Down)
    //{
    //    setPos(x() + 10, y() - OFFSET);
    //}

    if (DEBUG)
        qDebug() << "Moving to position X: " << this->x() << " Y: " << this->y() ;
}
