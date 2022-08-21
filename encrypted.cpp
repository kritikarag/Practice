#include<bits/stdc++.h>
using namespace std;

string getEncryptionNumber(int a[], int n)
{
    // n-2th Pascal triangle line
    int prev = 1, t = n - 2;
    int f = a[0], e = a[n - 1];
    for (int i = 1; i <= t; i++)
    {
        int curr = (prev * (t - i + 1)) / i;
        prev = curr;
        f += (a[i] * curr);
        e += (a[n - i - 1] * curr);
    }
    return to_string(f % 10) + to_string(e % 10);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<getEncryptionNumber(arr,n)<<endl;
}