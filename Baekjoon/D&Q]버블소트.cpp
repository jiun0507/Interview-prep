// 1517
// baekjoon 버블소트

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long cnt = 0;
int num[500000];
int buf[500000];

void bubble(int start, int end)
{
    if (start == end)
    {
        return;
    }
    int middle = (start + end) / 2;
    // cout<<start<<" "<<middle<<" "<<end<<"\n";
    bubble(start, middle);
    bubble(middle + 1, end);
    int second = middle + 1;
    int i = start;
    int j = start;
    int k = middle + 1;
    while (j <= middle && k <= end)
    {
        if (num[j] > num[k])
        {
            cnt += middle + 1 - j;
            buf[i] = num[k];
            k++;
        }
        else if (num[j] <= num[k])
        {
            buf[i] = num[j];
            j++;
        }
        i++;
    }
    while (j <= middle)
    {
        buf[i++] = num[j++];
    }
    while (k <= end)
    {
        buf[i++] = num[k++];
    }
    for (int l = start; l <= end; l++)
    {
        num[l] = buf[l];
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    bubble(0, n - 1);
    cout << cnt << endl;

    return 0;
}
