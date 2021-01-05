//baekjoon 16924
//십자가 찾기
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char board[100][100];
int check[100][100];
int n, m;

int main(void)
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string buf;
        cin >> buf;
        for (int j = 0; j < buf.length(); j++)
        {
            board[i][j] = buf.at(j);
            // cout<<board[i][j]<<" ";
        }
        // cout<<"\n";
    }
    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != '*')
                continue;
            for (int k = 1; k <= max(n, m); k++)
            {
                if (j - k >= 0 && j + k < m && i - k >= 0 && i + k < n)
                {
                    if (board[i][j - k] == '*' && board[i][j + k] == '*' && board[i - k][j] == '*' && board[i + k][j] == '*')
                    {
                        ans.push_back(make_tuple(i, j, k));
                        check[i][j] = 1;
                        check[i][j - k] = 1;
                        check[i][j + k] = 1;
                        check[i - k][j] = 1;
                        check[i + k][j] = 1;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '*' && check[i][j] == 0)
            {
                cout << "-1"
                     << "\n";
                return 0;
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        int y, x, z;
        tie(y, x, z) = ans[i];
        cout << y + 1 << " " << x + 1 << " " << z << "\n";
    }
}
