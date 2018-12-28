#ifndef TicTacToe_h
#define TicTacToe_h
#include"Square.h"
#include<cstdlib>
#include<vector>
using std :: vector;

//game types
enum gameType{U = 0, HH = 1, HC = 2};

class TicTacToe {
     //neeeded variables for the game
    bool gameStart;
    bool gameEnd;
    gameType typeOfGame;
    shape gameResult;
    int clicks;
    int win1;
    int win2;
    int win3;
    //for PC moves
    int cornerOne;
    int cornerTwo;

    shape playerTurn();
    void CheckBoard(vector<Square*> &container);
    void CheckColRow(int start, int end, int off, vector<Square*> &container);
    bool ComputerCheckBoard(vector<Square*> &container);
    bool CheckXO(int start, int end, int off, vector<Square*> &container);

public:
    //Default Constructor
    TicTacToe();
    // Setters
    void setGameStart();
    void setGameType(gameType type);

    //Decision Makers
    void AI(vector<Square*> &container);
    bool POneturn(int index, vector<Square*> &container);

    //Getters
    bool getGameStarting();
    bool getGameEnding();
    shape getGameResult();
    gameType geTypeOfGame();
    int getWin1();
    int getWin2();
    int getWin3();

};

#endif