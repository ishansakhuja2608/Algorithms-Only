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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int preSum[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            preSum[i] = arr[i];
        }
        else
        {
            preSum[i] = preSum[i - 1] + arr[i];
        }
    }
    int q;
    cin >> q;
    int sum;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        sum = preSum[r];
        if (l - 1 >= 0)
        {
            sum = sum - preSum[l - 1];
        }
        cout << sum << endl;
    }
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