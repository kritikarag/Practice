#include <bits/stdc++.h>
using namespace std;
long long bfs(vector<long long>adj[],long long ind,long long n){
    long long count=0;
    queue<long long>q;
    vector<bool>vis(n+1,false);
    q.push(ind);
    vis[ind] = true;
    while(!q.empty()){
        long long temp = q.front();
        q.pop();
        count++;
        for(auto it:adj[temp]){
            if(!vis[it]){
                q.push(it);
                vis[it] = true;
            }
        }
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        vector<long long>vec[n+1];
        for(long long i=0;i<m;i++){
            long long x,y;
            cin>>x>>y;
            vec[x].push_back(y);
        }

        long long ans = 0;
        for(long long i=1;i<=n;i++){
            ans = max(ans,bfs(vec,i,n));
        }
        cout<<(n-ans+1)<<endl;
    }
}