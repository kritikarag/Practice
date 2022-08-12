#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;

    cin >> n;

    vector<int> a(n);

    for (auto &i : a)
    {

        cin >> i;
    }

    int avg = accumulate(a.begin(), a.end(), 0) / n;

    int ans = 0;

    for (auto i : a)
    {

        ans += abs(avg - i);
    }

    cout << ans / 2;
}