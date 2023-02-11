#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        }
        int k;
        cin >> k;
        int ans = 0;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int row = (j + 1) * (m - j), col = (i + 1) * (n - i) - 1;
                int topLeft = i * j, topRight = (m - j - 1) * i;
                int bottomLeft = j * (n - i - 1), bottomRight = (n - i - 1) * (m - j - 1);
                int left = j * i * (n - i - 1), right = (m - j - 1) * i * (n - i - 1);
                int top = i * j * (m - j - 1), bottom = (n - i - 1) * j * (m - j - 1);
                int d1 = topLeft * bottomRight, d2 = topRight * bottomLeft;
                int total = row + col + topLeft + topRight + bottomLeft + bottomRight + left + right + top + bottom + d1 + d2;
                v.push_back({total * a[i][j], a[i][j]});
            }
        }
        sort(v.rbegin(), v.rend());
        for (int i = 0; i < n * m; i++)
        {
            // cout<<v[i].first<<" "<<v[i].second<<endl;
            int ele = v[i].second;
            if (k >= ele)
                v[i].second = 0, k -= ele;
            else if (k >= 0)
            {
                v[i].second -= k;
                k = 0;
            }
            if (ele != 0)
            {
                int occ = v[i].first / ele;
                ans += occ * v[i].second;
            }
        }
        cout << ans << endl;
    }
    return 0;
}