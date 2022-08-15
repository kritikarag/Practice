#include<bits/stdc++.h>
using namespace std;

int reverseint(int i){
    int r=0;
    while(i){
        r=r*10+i%10;
        i/=10;
    }

    return r;
}
bool isspecial(string k){
    //int n=k;
    int n=stoi(k);
    for(int i=1;i<=n;i++){
        if(i+reverseint(i)==n)return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    int count=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(isspecial(v[i]))count++;
    }

    cout<<count<<endl;
    return 0;
}