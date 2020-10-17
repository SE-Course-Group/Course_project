#include "game.h"
#include<vector>
#include<stack>
using namespace std;

//Game类实现文件
Game::Game(int edges)
{
    EDGES=edges;
    board=new int*[EDGES];
    for(int i=0;i<EDGES;i++){
        board[i]=new int[EDGES];
        for(int j=0;j<EDGES;j++)
            board[i][j]=0;
    }
    visited=new int*[EDGES];
    for(int i=0;i<EDGES;i++){
        visited[i]=new int[EDGES];
        for(int j=0;j<EDGES;j++)
            visited[i][j]=0;
    }
}

bool Game::check_location(int row,int col)
{
    return !board[row][col];//仅检查是否可下
}

bool Game::move(int player,int row,int col)
{
    if(!check_location(row,col))return false;
    board[row][col]=player; //落子
    for(int i=0;i<EDGES;i++)
        for(int j=0;j<EDGES;j++)
            visited[i][j]=0;
    visited[row][col]=-2;
    if(check_qi(row,col))//表示该子有气
        return true;
    //该子无气的情况：
    for(int i=0;i<EDGES;i++)
        for(int j=0;j<EDGES;j++)
            visited[i][j]=0;
    int remove_player=(player==1)? -1:1; //待删除棋子颜色与落子相反
    stack<vector<int>> remove;//记录要提取的落子
    for(int i=0;i<EDGES;i++)
        for(int j=0;j<EDGES;j++)
            if(board[i][j]==remove_player&&!check_qi(i,j))remove.push({i,j});
    if(remove.empty()){
        board[row][col]=0; //表示该落子为自杀，无法落下
        return false;
    }
    while(!remove.empty()){
        auto temp=remove.top();
        remove.pop();
        board[temp[0]][temp[1]]=0; //提取该子，记为0
    }
    return true;
}

bool Game::check_qi(int row,int col)
{
    if(visited[row][col]==1)return true;
    if(visited[row][col]==-1)return false;
    vector<vector<int>> direction{{row-1,col},{row+1,col},{row,col+1},{row,col-1}};

    //检测四周是否有空子
    for(auto item:direction)
        if(item[0]>=0&&item[0]<EDGES&&item[1]>=0&&item[1]<EDGES&&!board[item[0]][item[1]]){
            visited[row][col]=1;
            return true;
        }
    for(auto item:direction){
        // 旁边的棋子颜色一致且有气
        if((item[0]>=0&&item[0]<EDGES&&item[1]>=0&&item[1]<EDGES)
           &&board[item[0]][item[1]]==board[row][col]
           &&visited[item[0]][item[1]]!=-2){//表示未搜索过
            visited[item[0]][item[1]]=-2;  //表示已经搜索过
            if(check_qi(item[0],item[1])){
                visited[row][col]=1;
                return true;
            }
            visited[item[0]][item[1]]=0;
        }
    }
    visited[row][col]=-1;
    return false;
}

void Game::update_board()
{
    stack<vector<int>> remove;//记录要提取的落子
    for(int i=0;i<EDGES;i++)
        for(int j=0;j<EDGES;j++)
            visited[i][j]=0;
    for(int i=0;i<EDGES;i++)
        for(int j=0;j<EDGES;j++)
            if(board[i][j]&&!check_qi(i,j))remove.push({i,j});
    while(!remove.empty()){
        auto temp=remove.top();
        remove.pop();
        board[temp[0]][temp[1]]=0; //提取该子，记为0
    }
}

int Game::judge_victor()
{
    //分别计算黑方和白方的
    double sum_black=0,sum_white=0;
    for(int i=0;i<EDGES;i++)
        for(int j=0;j<EDGES;j++){
            if(board[i][j]==1)sum_black++;
            else if(board[i][j]==-1)sum_white++;
            else{
                bool flag1,flag2;//深度优先搜索，看是否能搜索到黑色或者白色
                //只搜到黑色棋子则sum_black++,只能搜到白色棋子则sum_white++,都能搜到则各加0.5
                flag1=search(1,i,j);//搜索黑子
                flag2=search(-1,i,j);//搜索白子
                if(flag1&&flag2){sum_black+=0.5;sum_white+=0.5;}
                else if(flag1)sum_black++;
                else if(flag2)sum_white++;
            }
        }
    if(sum_black==sum_white)return 0; //和棋
    else if(sum_black>sum_white)return 1; //黑棋获胜
    else return -1; //白棋获胜
}

bool Game::search(int color,int row,int col)
{
    // 搜索该空子与黑子还是白子相连接
    // [row,col]一定在棋盘上且为空
    vector<vector<int>> direction{{row-1,col},{row+1,col},{row,col+1},{row,col-1}};
    for(auto item:direction){
        if(item[0]>=0&&item[0]<EDGES&&item[1]>=0&&item[1]<EDGES){
            if(board[item[0]][item[1]]==color)return true;
            else if(!board[item[0]][item[1]]&&search(color,item[0],item[1]))return true;
        }
    }
    return false;
}


