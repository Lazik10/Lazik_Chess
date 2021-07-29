#pragma once
#include <QGraphicsScene>
#include <QGraphicsView>
#include "chessboard.h"

class ChessWindow
{
public:
    ChessWindow();
    ~ChessWindow();

    bool Initialize();

private:
    QGraphicsScene* m_scene;
    QGraphicsView* m_view;
    Chessboard* m_chessboard;
};

