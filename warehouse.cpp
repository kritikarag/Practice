#include <bits/stdc++.h>
using namespace std;
// long long bfs(vector<long long>adj[],long long ind,long long n){
//     long long count=0;
//     queue<long long>q;
//     vector<bool>vis(n+1,false);
//     q.push(ind);
//     vis[ind] = true;
//     while(!q.empty()){
//         long long temp = q.front();
//         q.pop();
//         count++;
//         for(auto it:adj[temp]){
//             if(!vis[it]){
//                 q.push(it);
//                 vis[it] = true;
//             }
//         }
//     }
//     return count;
// }
// int main()
// {
//     int t;
//     cin>>t;
//     while(t--){
//         long long n,m;
//         cin>>n>>m;
//         vector<long long>vec[n+1];
//         for(long long i=0;i<m;i++){
//             long long x,y;
//             cin>>x>>y;
//             vec[x].push_back(y);
//         }

//         long long ans = 0;
//         for(long long i=1;i<=n;i++){
//             ans = max(ans,bfs(vec,i,n));
//         }
//         cout<<(n-ans+1)<<endl;
//     }
// }

void dfs(vector<vector<long long>> &graph, int ind, vector<bool> &vis)
{
    vis[ind] = true;
    for (auto &it : graph[ind])
    {
        if (!vis[it])
            dfs(graph, it, vis);
    }
}

void topo(vector<vector<long long>>&graph, vector<bool>&vis, int ind, stack<long long>&st){
    vis[ind] = true;
    for(auto &it: graph[ind]){
        if(!vis[it])topo(graph,vis,it,st);
    }
    st.push(ind);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        vector<vector<long long>>graph(n+1);
        int result = 0;
        vector<bool> vis(n + 1, false);
        stack<long long> st;
        for (long long i = 0; i < m; i++)
        {
            long long x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }
         for(long long i=1;i<=n;i++){
            if(!vis[i]){
                topo(graph,vis,i,st);
            }
         }

        vector<bool>visit(n+1,false);
        while(!st.empty()){
            long long top = st.top();
            st.pop();
            if(!visit[top]){
                dfs(graph,top,visit);
                result++;
            }
        } 
        cout<<result<<endl; 
    }
    return 0;
}