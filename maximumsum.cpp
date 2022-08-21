#include<bits/stdc++.h>
using namespace std;
int findmaxsum(vector<int>&stock,int n, int k){
    int sum=-1;
    for(int i=0;i<n-k+1;i++){
        map<int,int>mp;
        int curr=0;
        bool flag=true;
        for(int j=i;j<i+k;j++){
            if(mp[stock[j]]>1){
                flag=false;
                break;
                //i=j;
            }
           else{
             mp[stock[j]]++;
            curr+=stock[j];
            }
        }
        if(flag)sum=max(sum,curr);
        mp.clear();
        // set<int>s;
        // for(int j=i;j<i+k;j++){
        //     s.insert(stock[i]);
        // }
        // if(s.size()==k){
        //     int curr = 0;
        //     for(int x: s){
        //         curr+=x;
        //     }
        //     sum=max(sum,curr);
        // }
    }

    return sum;
}
int main(){
    int n,k;
    cin>>n;
    vector<int>stock(n);
    for(int i=0;i<n;i++){
        cin>>stock[i];
    }
    cin>>k;
    cout<<"Result: "<<findmaxsum(stock,n,k)<<endl;
}