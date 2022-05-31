#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb emplace_back
#define vii vector<vector<int>>
#define vi vector<int>
#define mii map<int, int>

void solve()
{
    // Code Here
    int n, m;
    cin >> n >> m;
    int arr[n][m], preSum[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // create the prefix array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            preSum[i][j] = arr[i][j];
            if (i - 1 >= 0)
                preSum[i][j] += preSum[i - 1][j];
            if (j - 1 >= 0)
                preSum[i][j] += preSum[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)
                preSum[i][j] -= preSum[i - 1][j - 1];
        }
    }
    int q;
    cin >> q;
    int sum;
    while (q--)
    {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        sum += preSum[i2][j2];
        if (i1 - 1 >= 0)
            sum -= preSum[i1 - 1][j2];
        if (j1 - 1 >= 0)
            sum -= preSum[i2][j1 - 1];
        if (i1 - 1 >= 0 && j1 - 1 >= 0)
            sum += preSum[i1 - 1][j1 - 1];
    }
    cout << sum << endl;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    return 0;
}