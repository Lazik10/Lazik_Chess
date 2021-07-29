//#include <iostream>
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsView>

#include "piece.h"

Piece::Piece() :
    m_pointer(this), m_rank(Ranks::PAWN), m_color(Color::WHITE), m_position{ 0, 0 }
{

}

Piece::Piece(Ranks rank, Color color, Position position, QGraphicsScene* scene) :
    m_pointer(this), m_rank(rank), m_color(color), m_position(position)
{
    if (rank == Ranks::QUEEN)
    {
        //setRect(position.posX + 50, position.posY + 50, 50, 50);
        setPixmap(QPixmap(":/pictures/graphics/Black_Queen.png"));

        this->setPos(position.posX, position.posY);
        scene->addItem(this);
        // Make the item focusable
        //this->setFlag(QGraphicsItem::ItemIsFocusable);
        //this->setFocus();
    }

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
