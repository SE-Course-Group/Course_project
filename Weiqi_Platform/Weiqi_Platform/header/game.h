#ifndef GAME_H
#define GAME_H

/*
游戏类：
数据成员：棋盘、落子信息.....
成员函数：
*/
#include<vector>
using namespace std;

#define EDGES 9
//围棋路数定为9

class Game
{
private:
    int board[EDGES][EDGES]; //取值为0、-1、1，0表示未落子，1表示先手落子，-1表示后手落子
    vector<vector<int,int>> first_record; //先手记录,格式为[[row,col],....,[row,col]]
    vector<vector<int,int>> second_record; //后手记录,格式为[[row,col],....,[row,col]]
public:
    Game();

    bool check_location(int row,int col);
    //检测是否可以落子，可以返回true,否则返回false

    bool move(int player,int row,int col);
    //落子[row,col]处，棋手未player(取值为-1/1)

    bool judge_end(int& victor);
    //判断是否结束，若结束通过victor返回获胜者信息

};

#endif // GAME_H
