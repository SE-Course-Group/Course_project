#ifndef GAME_H
#define GAME_H

/*
游戏类：
数据成员：棋盘、落子信息.....
成员函数：
*/
#include<vector>
#include<stack>
#include<iostream>
#include<iomanip>
using namespace std;

#define EDGES 9
//围棋路数定为9

class Game
{
private:
    int board[EDGES][EDGES]; //取值为0、-1、1,2;0表示未落子，1表示先手落子，-1表示后手落子
    int visited[EDGES][EDGES]; //用于记录是否有气，如果有，则为1，没有为-1，未访问过为0

public:
    Game();

    bool check_location(int row,int col);
    //检测是否可以落子，可以返回true,否则返回false
    int& get_situation(int row,int col){
        return board[row][col];
    }

    void print(){
        for(int i=0;i<EDGES;i++){
            for(int j=0;j<EDGES;j++)
                cout << setw(3) << board[i][j];
            cout << endl;
        }
    }

    bool move(int player,int row,int col);
    //落子[row,col]处，棋手未player(取值为-1/1)

    bool check_qi_unrecord(int row,int col);
    //检测落子处[row,col]是否有气，使用不记录的方式

    bool check_qi(int row,int col);
    //判断[row,col]是否有气，使用记录的方式，并且在updata_board中调用

    void update_board();
    // 更新整个棋盘，把没有气的子提走

    int judge_victor();
    //在双方都确认结束的情况下，判断获胜者

    bool search(int color,int row,int col);
    //搜索[row,col]是否能搜索到color

};
#endif
