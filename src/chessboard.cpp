#include <QGraphicsView>

#include "chessboard.h"
#include <iostream>

Chessboard::Chessboard(QGraphicsScene* scene, QGraphicsView* view, Position position) :
    m_scene(scene), m_view(view), m_position(position)
{
    //setRect(position.posX + 50, position.posY + 50, 50, 50);
    setPixmap(QPixmap(":/pictures/graphics/Chessboard.png"));
    scene->addItem(this);
    setPos(position.posX, position.posY);

    Initialize();
    DefaultPosition();
}

Chessboard::~Chessboard()
{
}

bool Chessboard::Initialize()
{
    for (qint8 i = 0; i < MAX_COLUMNS; i++)
    {
        for (qint8 j = 0; j < MAX_ROWS; j++)
        {
            m_chessboard[i][j] = nullptr;
            m_piece_coordinates[i][j] = { i * 56 + m_position.posX + 23, j * 56 + m_position.posY + 23};
        }
    }
    return true;
}

void Chessboard::DefaultPosition()
{
    LoadPosition(DEFAULT_POS);
}

void Chessboard::LoadPosition(QString position)
{
    // TO DO: make function IsValidStringPosition() ... check for length between \ \ and these two cases below 
    // also check if all chars are valid (no C, G etc)
    if (position.isEmpty() || position.length() > MAX_POSITIONS)
    {
        qDebug() << "Given string position is invalid";
        return;
    }

    qint8 column{ 0 }, row{ 0 };

    for (quint8 i = 0; i < position.length(); i++)
    {
        qDebug() << position[i];
        // Actual position when looping through our string which is storing our position

        // Start filling next row when we run into \ in a position string
        if (position.at(i) == '\\')
        {
            row++;
            column = 0;
            continue;
        }
        // or skip number of columns if we run into a digit
        else if (position[i].isDigit())
        {
            column += position[i].digitValue();
            if (DEBUG)
                qDebug() << "Skipped " << column << " position(s)";
            continue;
        }

        const QChar annotation = position.at(i);
        Color color;
        Ranks rank;
        Position position = m_piece_coordinates[column][row];
        if (GetLoadedPieceInfo(annotation, color, rank))
            AddPiece(column, row, rank, color, position, m_scene);

        column++;

        // Start filling next row if we filled all columns in this one
        if (column >= MAX_COLUMNS)
            column = 0;
    }

    PrintChessboard(Color::WHITE);

    if (DEBUG)
        qDebug() << "Chess position loaded sucessfully!";
}

Piece* Chessboard::AddPiece(qint8& column, qint8& row, Ranks rank, Color color, Position position, QGraphicsScene* scene)
{
    if (DEBUG)
        qDebug() << "Adding Pieces to Chessboard";

    Piece* piece = new Piece(rank, color, position, scene);
    if (piece)
    {
        this->m_chessboard[column][row] = piece;

        if (DEBUG)
            qDebug() << "Creating piece at position - Column: " << column << " Row: " << row << " and rank: " << piece->PrintRank() << piece->PrintPositon() << "\n";

        return piece;
    }
    else
    {
        if (DEBUG)
            qDebug() << "Failed to add new piece to chessboard";
        return nullptr;
    }
}

void Chessboard::DeletePiece(Piece* piece)
{

}

bool Chessboard::GetLoadedPieceInfo(const QChar& notation, Color& color, Ranks& rank)
{
    for (qint8 i = 0; i < MAX_NOTATIONS; i++)
    {
        if (notation == FEN_Notation[i].notation)
        {
            color = FEN_Notation[i].color;
            rank = FEN_Notation[i].rank;
            return true;
        }
    }
    return false;
}

void Chessboard::PrintChessboard(Color color)
{
    // Since we store string position from [0,0]...[0,7] to [0,7]...[7,7] 
    // we need to start printing from [0,7]...[7,7] to [0,0]...[7,0]
    // in short last row first -- This could change depending on view (from black or white)
    QString output;

    // White point of view
    for (qint8 i = MAX_ROWS - 1; i >= 0; i--)
    {
        for (qint8 j = 0; j < MAX_COLUMNS; j++)
        {
            if (m_chessboard[j][i] != nullptr)
                output += m_chessboard[j][i]->PrintRank();
            else
                output += "  ";
        }
        if (DEBUG)
            qDebug() << output;
        output = "";
    }
    qDebug() << "Chess printed on screen";
}
