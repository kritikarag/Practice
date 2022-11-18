#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int quer;
    cin>>quer;
    while(quer--){
        int tag;
        cin>>tag;
        if(tag==1){
            int pos,val;
            cin>>pos>>val;
            vec[pos-1] = val;
        }
        else{
            int req,count=0;
            cin>>req;
            for(int i=0;i<n;i++){
                if(vec[i]%m==req)count++;
            }
            cout<<count<<endl;
        }
    }
}