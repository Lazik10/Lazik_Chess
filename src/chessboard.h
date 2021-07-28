#pragma once
#include <qstring>
#include <qdebug>
#include <qvector>
#include <vector>

#include "utilities.h"
#include "piece.h"

class Chessboard
{
public:
    Chessboard();
    ~Chessboard();

    bool Initialize();
    void DefaultPosition();
    void LoadPosition(QString position);

    Piece* AddPiece(qint8& column, qint8& row, Ranks rank, Color color, Position position);
    void DeletePiece(Piece* piece);
    
    bool GetLoadedPieceInfo(const QChar& notation, Color& color, Ranks& rank);

    void PrintChessboard(Color color);

private:
    Piece* chessboard[MAX_COLUMNS][MAX_ROWS];
};