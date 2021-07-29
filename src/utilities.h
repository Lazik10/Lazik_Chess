#pragma once

#include <QtGlobal>
#include <QString>

#define DEBUGGER 1;
constexpr auto DEBUG        = 1;

const qint8 MAX_POSITIONS   = 64;
const qint8 MAX_ROWS        = 8;
const qint8 MAX_COLUMNS     = 8;

const qint8 MAX_NOTATIONS = 12;

const qint8 MIN_ASCII_NUM   = 48;
const qint8 MAX_ASCII_NUM   = 57;

const qint8 MAX_PAWNS       = 8;
const qint8 MAX_RKB_PIECES  = 2;

const int OFFSET        = 10;

enum class Ranks
{
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING,
    MAX_RANKS
};

enum class Color
{
    WHITE,
    BLACK,
    NOT_SPECIFIED = -1
};

enum class Evaluation
{
    FAILED,
    SUCCESS
};

struct ForsythEdwardNotation
{
    QChar notation;
    Ranks rank;
    Color color;
    QString image_string;
};

const ForsythEdwardNotation FEN_Notation[MAX_NOTATIONS] =
{
    // WHITE
    { 'P', Ranks::PAWN, Color::WHITE, ":/pictures/graphics/White_Pawn.png" },
    { 'B', Ranks::BISHOP, Color::WHITE, ":/pictures/graphics/White_Bishop.png" },
    { 'N', Ranks::KNIGHT, Color::WHITE, ":/pictures/graphics/White_Knight.png" },
    { 'R', Ranks::ROOK, Color::WHITE, ":/pictures/graphics/White_Rook.png" },
    { 'Q', Ranks::QUEEN, Color::WHITE, ":/pictures/graphics/White_Queen.png" },
    { 'K', Ranks::KING, Color::WHITE, ":/pictures/graphics/White_King.png" },
    // BLACK
    { 'p', Ranks::PAWN, Color::BLACK, ":/pictures/graphics/Black_Pawn.png" },
    { 'b', Ranks::BISHOP, Color::BLACK, ":/pictures/graphics/Black_Bishop.png" },
    { 'n', Ranks::KNIGHT, Color::BLACK, ":/pictures/graphics/Black_Knight.png" },
    { 'r', Ranks::ROOK, Color::BLACK, ":/pictures/graphics/Black_Rook.png" },
    { 'q', Ranks::QUEEN, Color::BLACK, ":/pictures/graphics/Black_Queen.png" },
    { 'k', Ranks::KING, Color::BLACK, ":/pictures/graphics/Black_King.png" },
};

// Forsyth Edwards Notation
// Upper case letter represents white pieces and lower case letter represents black pieces
// Numeric values represent how many empty positions we will find between last piece and the next
const QString DEFAULT_POS = { "RNBQKBNR\\PPPPPPPP\\8\\8\\8\\8\\pppppppp\\rnbkqbnr" };
// Random test position
//const QString DEFAULT_POS = { "1N1KQ2R\\PP2P1P1\\8\\8\\2nRPP2\\2pppp2\\pp4pp\\rnbkqbnr" };

struct Position
{
    qint16 posX;
    qint16 posY;
};
