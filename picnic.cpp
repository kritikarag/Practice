#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,x,y,sum=0;
    cin>>n;
    map<int,int>mp;
    vector<int>a(n,0);

    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }

    for (auto &it:mp){
        ans+= (it.second/2);
    }

    cout<<ans<<endl;
}