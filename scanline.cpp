/*Problem --> Given an integer n, which represents the total number of integers(array) and there are q queries, for every query, there are int l, int r and a value x

n = 5;
arr --> 2 3 2 3 5;

q = 3;
0 3 2
2 4 3
1 2 1

for the first query, we need to iterate from 0 to 3, and increase the elements of the array by 2
arr --> 4 5 4 5 5

after second query
arr --> 4 5 7 8 8

after last query
arr --> 4 6 8 8 8 (result)

Scanline --> create an array (pre[n+1]) of size n+1, initialize it with 0,
pre[l]  += x;
pre[r+1] -= x;

after all queries pre[n+1] = 2 1 3 -1 -2 -3

arr[0] += pre[0]; // 2
arr[1] += pre[1] + pre[0]; // 2+1
arr[2] += pre[2] + pre[1] + pre[0]; // 2+1+3
arr[3] += pre[3] + pre[2] + pre[1] + pre[0]; // 2+1+3-1
arr[4] += pre[4] + pre[3] + pre[2] + pre[1] + pre[0]; // 2+1+3-1-2


*/

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
    int prefix[n + 1];
    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        prefix[l] += x;
        prefix[r + 1] -= x;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += prefix[i];
        arr[i] += sum;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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