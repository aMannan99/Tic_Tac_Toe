#include <iostream>
#include "dashBoard.hpp"

bool DashBoard::isemptyCell(int x, int y)
{
    if (dash[x][y] != 0)
        return false;

    return true;
}
void DashBoard::resetGame()
{
   for(int i=0;i<3;i++)
   for(int j=0;j<3;j++)
   dash[i][j]=0;

   std::cout<<" Board has resetted \n";
}

bool DashBoard::isDahFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            if (dash[i][j] == 0)
                return false;
    }
    return true;
}

void DashBoard::move(const user &u, int x, int y)
{
    if (DashBoard::isemptyCell(x, y) && !DashBoard::isDahFull())
        dash[x][y] = u.uid;

    if(isWinner(u))
    {
        std::cout<<" congratulations : user "<<u.uid<<" is Winner \n";
        std::cout<<" Restarting game \n";
        DashBoard::resetGame();
    }
}

bool DashBoard::isWinner(const user &u)
{
    bool win = false;

    if (dash[0][0] == u.uid && dash[0][1]==u.uid && dash[0][2]==u.uid)  //1st row
    {
        win=true;
    }
    if (dash[1][0] == u.uid && dash[1][1]==u.uid && dash[1][2]==u.uid)  //2nd row
    {
        win=true;
    }
    if (dash[2][0] == u.uid && dash[2][1]==u.uid && dash[2][2]==u.uid)  //3rd row
    {
        win=true;
    }

    return win;
}


int main()
{
    user player1(1);
    user player2(2);

    DashBoard *Board = new DashBoard(3);
    Board->move(player1,0,0);
    Board->move(player2,2,0);
    Board->move(player1,1,2);
    Board->move(player2,2,2);
    Board->move(player1,0,1);
    Board->move(player2,2,1);
    
    return 0;
}