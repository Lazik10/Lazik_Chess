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
};

const ForsythEdwardNotation FEN_Notation[MAX_NOTATIONS] =
{
    // WHITE
    { 'P', Ranks::PAWN, Color::WHITE },
    { 'B', Ranks::BISHOP, Color::WHITE },
    { 'N', Ranks::KNIGHT, Color::WHITE },
    { 'R', Ranks::ROOK, Color::WHITE },
    { 'Q', Ranks::QUEEN, Color::WHITE },
    { 'K', Ranks::KING, Color::WHITE },
    // BLACK
    { 'p', Ranks::PAWN, Color::BLACK },
    { 'b', Ranks::BISHOP, Color::BLACK },
    { 'n', Ranks::KNIGHT, Color::BLACK },
    { 'r', Ranks::ROOK, Color::BLACK },
    { 'q', Ranks::QUEEN, Color::BLACK },
    { 'k', Ranks::KING, Color::BLACK },
};

// Forsyth Edwards Notation
// Upper case letter represents white pieces and lower case letter represents black pieces
// Numeric values represent how many empty positions we will find between last piece and the next
const QString DEFAULT_POS = { "RNBQKBNR\\PPPPPPPP\\8\\8\\8\\8\\pppppppp\\rnbkqbnr" };
// Random test position
//const QString DEFAULT_POS = { "1N1KQ2R\\PP2P1P1\\8\\8\\2nRPP2\\2pppp2\\pp4pp\\rnbkqbnr" };

struct Position
{
    qint8 posX;
    qint8 posY;
};
