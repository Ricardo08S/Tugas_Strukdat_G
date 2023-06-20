#include <iostream>
#include <vector>
using namespace std;
const int N = 8;

/*
The eight-queens problem can be stated as follows: place 8 queens on a chess board so that
no two queens attack each other. Two queens attack each other if they are in the same row,
same column, or same diagonal. Clearly, any solution must have the queens in different rows
and different columns.
One approach to solving the problem is as follows. Place the first queen in the first column of the first
row. Next, place the second queen so that it does not attack the first. If this is not possible, go back and
place the first queen in the next column and try again.
After the first two queens have been placed, place the third queen so that it does not attack the first two.
If this is not possible, go back and place the second queen in the next column and try again.
At each step, try to place the next queen so that it does not conflict with those already placed. If you
succeed, try to place the next queen. If you fail, you must backtrack to the previously placed queen and
try the next possible column. If all columns have been tried, you must backtrack to the queen before this
queen and try the next column for that queen.
The idea is similar to finding a path through a maze. Write a program to solve the eight-queens problem.
Use recursion to implement the backtracking.
*/

vector<int> ld(30, 0);
vector<int> rd(30, 0);
vector<int> cl(30, 0);

void printSolution(vector<vector<int>>& board)
{
    for (auto& row : board)
    {
        for (int j : row)
        {
            cout << " " << j << " ";
        }
        cout << endl;
    }
}

bool util(vector<vector<int>>& board, int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (ld[i - col + N - 1] != 1 && rd[i + col] != 1 && cl[i] != 1) {
            board[i][col] = 1;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

            if (util(board, col + 1))
                return true;

            board[i][col] = 0;
            ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
        }
    }

    return false;
}

bool solveNQ()
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!util(board, 0)) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board);
    return true;
}

int main()
{
    solveNQ();
    return 0;
}
