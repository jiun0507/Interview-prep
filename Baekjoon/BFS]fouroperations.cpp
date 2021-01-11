//4연산
//baekjoon 14395
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
#include <set>
#include <algorithm>
const long long limit = 1000000000LL;
using namespace std;

long long n, m;

int main()
{
    cin >> n >> m;
    vector<string> ans;
    queue<pair<long long, string>> q;
    q.push(make_pair(n, ""));
    set<long long> check;
    check.insert(n);
    while (!q.empty())
    {
        long long y;
        string path;
        tie(y, path) = q.front();
        q.pop();
        if (y == m)
        {
            if (path == "")
            {
                cout << "0";
            }
            else
            {
                cout << path;
            }
            return 0;
        }
        if (m == 0)
        {
            cout << "-";
            return 0;
        }
        if (y * y <= limit && check.count(y * y) == 0)
        {
            q.push(make_pair(y * y, path + '*'));
            check.insert(y * y);
        }
        if (y + y <= limit && check.count(y + y) == 0)
        {
            q.push(make_pair(y + y, path + '+'));
            check.insert(y + y);
        }

        if (check.count(0) == 0)
        {
            q.push(make_pair(0, path + '-'));
            check.insert(0);
        }
        if (y != 0 && check.count(1) == 0)
        {
            q.push(make_pair(1, path + '/'));
            check.insert(1);
        }
    }
    cout << -1 << "\n";
    return 0;
}