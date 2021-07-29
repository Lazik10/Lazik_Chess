#pragma once
#include <QString>
#include <QDebug>
#include <QVector>
#include <vector>

#include "utilities.h"
#include "piece.h"

class Chessboard : public QGraphicsPixmapItem
{
public:
    Chessboard(QGraphicsScene* scene, QGraphicsView* view, Position position = { 0, 0 });
    ~Chessboard();

    bool Initialize();
    void DefaultPosition();
    void LoadPosition(QString position);

    Piece* AddPiece(qint8& column, qint8& row, Ranks rank, Color color, Position position, QGraphicsScene* scene);
    void DeletePiece(Piece* piece);
    
    bool GetLoadedPieceInfo(const QChar& notation, Color& color, Ranks& rank);

    void PrintChessboard(Color color);

private:
    Piece* m_chessboard[MAX_COLUMNS][MAX_ROWS];
    QGraphicsScene* m_scene;
    QGraphicsView* m_view;
    Position m_position;
    Position m_piece_coordinates[MAX_COLUMNS][MAX_ROWS];
};
