#include <bits/stdc++.h>
using namespace std;
int topology(int n,int m,vector<int>&start,vector<int>&end){
    if(n==m)return 3;
    set<int>s,e;
    for(int i=0;i<m;i++){
        s.insert(start[i]);
        e.insert(end[i]);
    }

    if(s.size()==m && m==e.size())return 1;

    if(s.size()==1||e.size()==1)return 2;

    return -1;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>start(m);
    vector<int>end(m);
    for (int i = 0; i < m; i++)
        cin >> start[i];
    for (int i = 0; i < m; i++)
        cin >> end[i];

    cout<<topology(n,m,start,end)<<endl;

    return 0;
}