#include <bits/stdc++.h>
using namespace std;

int magicstick(int a[],int l[], int n){
    if(n==1)return 0;
    int sum =INT_MAX;
    for(int i=0;i<n;i++){
        int curr=l[i];
        int temp=0;
        for(int j=0;j<n;j++){
            temp=temp+a[j]*abs(curr-l[j]);
        }
        sum=min(sum,temp);
    }

    return sum;
}
int main(){
    int n;

    cin >> n;

    int a[n], l[n];
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout<<magicstick(a,l,n);
    return 0;
}