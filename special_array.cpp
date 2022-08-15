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
bool isspecial(int n){
    for(int i=1;i<=n/2;i++){
        int req = n-i;
        if(req==reverseint(i))return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<string>v;
    int count=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]=stoi(v[i]);
        if(isspecial(v[i]))count++;
    }

    cout<<count<<endl;
    return 0;
}