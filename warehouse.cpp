#include <bits/stdc++.h>
using namespace std;
int bfs(vector<int>adj[],int ind,int n){
    int count=0;
    queue<int>q;
    vector<bool>vis(n+1,false);
    q.push(ind);
    vis[ind] = true;
    while(!q.empty()){
        int temp = q.front();
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
        int n,m;
        cin>>n>>m;
        vector<int>vec[n+1];
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            vec[x].push_back(y);
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans,bfs(vec,i,n));
        }
        cout<<(n-ans+1)<<endl;
    }
}