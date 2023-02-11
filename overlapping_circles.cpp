#include <bits/stdc++.h>
using namespace std;

static bool fun(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}
int circles(vector<int> &v)
{
    vector<vector<int>> m(n);
    for (int i = 0; i < n; i++)
    {
        m[i].push_back(i);
        for (int j = 0; j < n; j++)
        {
            float d = sqrt(((v[i][0] - v[j][0]) * (v[i][0] - v[j][0])) + ((v[i][1] - v[j][1]) * (v[i][1] - v[j][1])));
            if (d <= (v[i][2] + v[j][2]) && i != j)
            {
                m[i].push_back(j);
            }
        }
    }
    int ans = 0;
    sort(m.begin(), m.end(), fun);
    while (m.size() > 0 && m[m.size() - 1].size() != 1)
    {
        ans++;
        for (int i = 1; i < m[m.size() - 1].size(); i++)
        {
            int j = m[m.size() - 1][i];
            m[j].erase(find(m[j].begin(), m[j].end(), m[m.size() - 1][0]));
        }
        m.pop_back();
        sort(m.begin(), m.end(), fun);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    int i = n;
    while (i--)
    {
        int x;
        cin >> x;
        int y;
        cin >> y;
        int r;
        cin >> r;
        v.push_back({x, y, r});
    }
    cout << circles(v);
}