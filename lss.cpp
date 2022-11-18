#include <bits/stdc++.h>
using namespace std;
#define f(i, a, n) for (int i = a; i < n; i++)
#define vv  vector<int>
#define civ(v, n) f(i, 0, n) cin >> v[i]
#define cov(v, n) f(i, 0, n) cout << v[i] << " "
#define intlong long
#define pb push_back
#define po pop_back
#define mp make_pair
#define sab(x) x.begin(), x.end()
#define rsab(x)x.rbegin(), x.rend()
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define el "\n"

int n;
vv v;
vector<int> dp;

int fun(int x)
{
    if (x <= 0) return 0;
    if (dp[x] != -1) return dp[x];
    int z = 1, o = 1;
    int zi = -1, oi = -1;
    dp[x] = 0;
    for (int i = x - 2; i >= 0; i--)
    {
        
    if (v[i] + 1 == v[x - 1] || v[i] == v[x - 1]) z++;
        
    else break;
    }
    for (int i = x - 2; i >= 0; i--)
    {
        
    if (v[i] + 1 == v[x - 1] + 1 || v[i] == v[x - 1] + 1) o++;
        
    else break;
            }
    dp[x] = max(dp[x], max(z, fun(zi + 1)));
    dp[x] = max(dp[x], max(o, fun(oi + 1)));
    dp[x] = max(dp[x], fun(x - 1));
    // cout << dp[x] <<" " << x << el;
return dp[x];
}

void solve()
{
    cin >> n;
    v.assign(n, 0);
    dp = vector<int>(n + 1, -1);
    civ(v, n);
    cout << fun(n) << el;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)solve();   
return 0;
}