#include <iostream>
#include <vector>

using namespace std;

/*
Consider points (m, n) in the usual Cartesian coordinate system where m and n are positive
integers. In a north-east path from point A to point B, one can move only up and only right
(no down or left movements are allowed). Write a function that, given the coordinates of any
two points A and B, returns the number of north-east paths from A to B.
*/

bool isValid(int x, int y, int m, int n) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int countPaths(int i, int j, int n, int m,vector<vector<int>> &grid) {
    if(!isValid(i, j, n, m)) return 0;
    if(grid[i][j] == 1) return 1;
    
    //north-east from A, but south-west from B
    int path = countPaths(i+1, j, n, m, grid) + countPaths(i, j-1, n, m, grid);
    return path;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    int a, b;
    cin>>a>>b;
    grid[a][b] = 1;

    cin>>a>>b;
    grid[a][b] = 2;

    cout << countPaths(a, b, m, n, grid)<<endl;
    for (auto x : grid)
    {
        for (auto y : x)
        {
            // cout<<y<<" ";
            if(y==2) cout<<"B ";
            else if(y==1)cout<<"A ";
            else cout<<y<<" ";
        }
        cout<<endl;
        
    }
    
    return 0;
}