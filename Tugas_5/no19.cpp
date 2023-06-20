#include <iostream>
#include <vector>
using namespace std;
const int N = 8;

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
