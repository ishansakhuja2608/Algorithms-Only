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
    int sumx = 0, sumy = 0, sumz = 0;
    while (n--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        sumx += x;
        sumy += y;
        sumz += z;
    }
    if (sumx == 0 && sumy == 0 && sumz == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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