#define int int64_t
int ans = INT_MIN;
bool dfs(int src, int par, int target, int t, vector<int> graph[], vector<int> &timeTaken)
{
    if (src == target)
    {
        timeTaken[src] = t;
        return true;
    }

    for (auto c : graph[src])
    {

        if (src != par)
        {

            if (dfs(c, src, target, t + 1, graph, timeTaken))
            {
                timeTaken[c] = t + 1;
                return true;
            }
        }
    }

    return false;
}
void dfs2(int src, int par, int t, int sum, vector<int> graph[], vector<int> &timeTaken, vector<int> &coins)
{
    if (t < timeTaken[src])
    {
        sum += coins[src];
    }
    if (t == timeTaken[src])
    {
        sum += (coins[src] / 2);
    }
    // cout<<src<<' ';
    int child = 0;
    for (auto c : graph[src])
    {

        if (par != c)
        {

            child++;

            dfs2(c, src, t + 1, sum, graph, timeTaken, coins);
        }
    }
    if (child == 0)
    {
        ans = max(ans, sum);
    }

    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int mod = 998244353;
    int n;
    cin >> n;
    int R;
    cin >> R;

    vector<int> graph[n + 1];

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> coins[i];
    vector<int> timeTaken(n + 1, INT_MAX);
    timeTaken[R] = 0;
    dfs(R, -1, 1, 0, graph, timeTaken);
    dfs2(1, -1, 0, 0, graph, timeTaken, coins);

    cout << ans << endl;
    return 0;
}



// Another Approach

vector<vector<int>> adj;
vector<int> disFromBob;
int bobNode;
int dfs(int u, int par, int depth, vector<int> &amount)
{
    int ret = 0;
    if (u == bobNode)
        disFromBob[u] = 0;
    else
        disFromBob[u] = amount.size();
    int maxChild = -INT_MAX;
    for (int v : adj[u])
    {
        if (v == par)
            continue;
        maxChild = max(maxChild, dfs(v, u, depth + 1, amount));
        disFromBob[u] = min(disFromBob[u], disFromBob[v] + 1);
    }
    if (disFromBob[u] > depth)
        ret += amount[u];
    else if (disFromBob[u] == depth)
        ret += amount[u] / 2;
    if (maxChild == -INT_MAX)
        return ret;
    else
        return ret + maxChild;
}
int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
{
    int n = amount.size();
    bobNode = bob;
    adj.resize(n, vector<int>());
    for (auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    disFromBob.resize(n);
    return dfs(0, 0, 0, amount);
}