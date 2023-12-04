#if !defined(GAME_H)
#define GAME_H

#include <tuple>

class Game
{
    static const int k_nGridRowsDefault = 4;
    static const int k_nGridColumnsDefault = 5;
    static const int k_nMaxTorpedoes = (k_nGridRowsDefault * k_nGridColumnsDefault) / 2;

private:
    char a_cGrid[k_nGridRowsDefault][k_nGridColumnsDefault];
    int m_nGridRows;
    int m_nGridColumns;
    int m_iRowBoat;
    int m_iColumnBoat;
    int m_nTorpedoes;

public:
    Game();
    void play();

private:
    void initializeGrid();
    void reset();
    void displayGrid(bool bDisplayBoat);
    std::tuple<int, int> fireTorpedo();
    void placeBoatRandomly();
    void placeBoat();
    bool isOnTarget(int iRow, int iColumn);
    bool isCloseToTarget(int iRow, int iColumn);
    void showSunk();
    std::tuple<int, int> promptForGridCoord();
};

#endif // !defined(GAME_H)
