# 16956
#늑대와양
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    queue<pair<int, int>> wolves;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        board[i] = line;
    }
    bool installed = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'W')
            {
                for (int k = 0; k < 4; k++)
                {
                    int y = i + dy[k];
                    int x = j + dx[k];
                    if (y >= 0 && y < n && x >= 0 && x < m)
                    {
                        if (board[y][x] == 'S')
                        {
                            cout << '0' << endl;
                            return 0;
                        }
                        else if (board[y][x] == 'W')
                            continue;
                        else
                        {
                            board[y][x] = 'D';
                            installed = true;
                        }
                    }
                }
            }
        }
    }
    cout << '1' << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!installed && board[i][j] == '.')
            {
                board[i][j] = 'D';
                installed = true;
            }
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
