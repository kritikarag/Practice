#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>vec;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vec.push_back(make_pair(x,y));
    }

    sort(vec.begin(),vec.end());

    int count=1;
    for(int i=1;i<n;i++){
        if(vec[i].first>vec[i-1].second)count++;
    }

    cout<<count<<endl;
}