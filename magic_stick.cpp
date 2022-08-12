#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b)
{

    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pair<int, int> p[100];
    for (int i = 0; i < n; i++)
    {
        p[i] = make_pair(a[i], i+1);
    }
    sort(p, p + n, compare);
    long long int ans = INT_MAX;
    int startingLenght = p[0].first;
    int endingLenght = p[n - 1].first;
    for (int i = startingLenght; i <= endingLenght; i++)
    {
        long long int mincost = 0;
        for (int j = 0; j < n; j++)
        {
            long long int M = abs(p[j].first - i);
            mincost += (M * p[j].second);
        }
        ans = min(ans, mincost);
    }
    cout << ans;
    return 0;
}