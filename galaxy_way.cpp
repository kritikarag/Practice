#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,g,count=0;
    cin>>n>>m>>g;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if(vec[i]<=m && vec[i]%g==0)count++;
    }
    cout<<count<<endl;
}