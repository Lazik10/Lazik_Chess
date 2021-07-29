#include <QApplication>
#include <QDebug>

#include "window.h"
#include "piece.h"

const qint16 MAX_SCREEN_WIDTH = 1200;
const qint16 MAX_SCREEN_HEIGHT = 800;
const qint8 PIXEL_OFFSET = 10;

ChessWindow::ChessWindow() :
    m_scene(nullptr), m_view(nullptr), m_chessboard(nullptr)
{

}

ChessWindow::~ChessWindow()
{
    delete m_scene;
    delete m_view;
    delete m_chessboard;
}

bool ChessWindow::Initialize()
{
    // Create a scene
    QGraphicsScene* m_scene = new QGraphicsScene(0,0,MAX_SCREEN_WIDTH, MAX_SCREEN_HEIGHT);

    // Visualize the scene
    QGraphicsView* m_view = new QGraphicsView(m_scene);
    // For some reason when m_scene size == m_view size we can still scroll a little bit, 
    // so making the view a little bit bigger solves the problem
    m_view->setFixedSize(MAX_SCREEN_WIDTH + PIXEL_OFFSET, MAX_SCREEN_HEIGHT + PIXEL_OFFSET);
    m_view->setWindowTitle("Lazik's Chess");
    // View is a widget (by default it is hidden) - we need to show it
    m_view->show();
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // we can change the view to different scene
    // view->setScene(scene);

    // Create a chessboard
    m_chessboard = new Chessboard(m_scene, m_view);

    return true;
}
