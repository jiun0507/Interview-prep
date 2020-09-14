//baekjoon 2263
//트리의 순회
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int position[100001];
int inorder[100000];
int postorder[100000];
void preorder(int inorder_start, int inorder_end, int postorder_start, int postorder_end)
{
    if (inorder_start > inorder_end || postorder_end < postorder_start)
    {
        return;
    }
    int root = postorder[postorder_end];
    int inorder_mid = position[root];
    int left = inorder_mid - 1 - inorder_start;
    cout << root << " ";
    preorder(inorder_start, inorder_mid - 1, postorder_start, postorder_start + left);
    preorder(inorder_mid + 1, inorder_end, postorder_start + left + 1, postorder_end - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        position[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    preorder(0, n - 1, 0, n - 1);

    return 0;
}
