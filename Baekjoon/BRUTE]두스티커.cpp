#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int height, width, n;
    cin >> height >> width >> n;
    vector<pair<int, int>> sticker;
    for (int i = 0; i < n; i++)
    {
        int h, w;
        cin >> h >> w;
        sticker.push_back(make_pair(h, w));
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int first_h = sticker[i].first;
        int first_w = sticker[i].second;
        for (int j = i + 1; j < n; j++)
        {
            int second_h = sticker[j].first;
            int second_w = sticker[j].second;
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    int temp = (first_h * first_w) + (second_h * second_w);

                    if ((first_h + second_h <= height) && (max(first_w, second_w) <= width))
                    {
                        if (ans < temp)
                            ans = temp;
                    }
                    if ((first_w + second_w <= width) && (max(first_h, second_h) <= height))
                    {
                        if (ans < temp)
                            ans = temp;
                    }
                    swap(second_h, second_w);
                }
                swap(first_h, first_w);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
