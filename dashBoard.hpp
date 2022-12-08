#include <iostream>
#include <vector>
using namespace std;

class user
{
public:
    int uid;
    user() {}
    user(int uid)
    {
        this->uid = uid;
    }
};

class DashBoard : public user
{
private:
    int n;
    int dash[1][1];

public:
    DashBoard(int size)
    {
        this->n = size;
        this->dash[size][size];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dash[i][j] = 0;
    }
    void move(const user &u, int x, int y);
    void resetGame();
    bool isemptyCell(int x, int y);
    bool isDahFull();
    bool isWinner(const user &u);
};
