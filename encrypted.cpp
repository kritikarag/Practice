#include<bits/stdc++.h>
using namespace std;

string getEncryptionNumber(int a[], int n)
{
    // n-2th Pascal triangle line
    int prev = 1, total = n - 2;
    int start = a[0], end = a[n - 1];
    for (int i = 1; i <= total; i++)
    {
        int curr = (prev * (total - i + 1)) / i;
        prev = curr;
        start += (a[i] * curr);
        end += (a[n - i - 1] * curr);
    }
    return to_string(start % 10) + to_string(end % 10);
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