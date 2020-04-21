// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int a, b, c;
int check[1501][1501];
int s;

bool go2(int a, int b)
{
    check[a][b] = 1;
    int c = s - a - b;
    if (a == b && b == c)
        return true;
    int rocks[3] = {a, b, c};
    int newa, newb;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
                continue;
            if (rocks[i] > rocks[j])
            {
                newa = rocks[i] - rocks[j];
                newb = rocks[j] * 2;
                if (!check[newa][newb])
                {
                    if (go2(newa, newb))
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> a >> b >> c;
    s = a + b + c;
    cout << go2(a, b) << "\n";
    return 0;
}