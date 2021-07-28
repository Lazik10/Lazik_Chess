#include <qapplication>
#include <qgraphicsscene>
#include <qgraphicsview>
#include <qdebug>

#include "window.h"
#include "piece.h"
#include "chessboard.h"

ChessWindow::ChessWindow()
{
}

ChessWindow::~ChessWindow()
{
}

bool ChessWindow::Initialize()
{
    // Create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    // Visualize the scene
    QGraphicsView* view = new QGraphicsView(scene);
    // we can change the scene to different one
    // view->setScene(scene);
    // 
    // View is a widget (by default it is hidden) - we need to show it
    view->show();

    // Create an item to put into the scene
    Piece* piece = new Piece(Ranks::PAWN, Color::BLACK, {0,0});
    // 1st and 2nd scene positions, 3rd and 4th width and height
    piece->setRect(0, 0, 100, 100);
    // Add item to the scene
    scene->addItem(piece);

    // Make the item focusable
    piece->setFlag(QGraphicsItem::ItemIsFocusable);
    piece->setFocus();



    // Create a chessboard
    Chessboard chessboard;

    return true;
}
