#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}

int largestpf(int n){
    int p=0,i=2;
    while(n!=1){
        if(n%i==0){
            p=i;
            n/=i;
        }
        else i++;
    }

    return p;
}

int main(){
    int n;
    cin>>n;
    int steps=0;
    while(n!=0){
        if(isPrime(n)){
            n--;
            steps++;
        }
        else{
            n=largestpf(n);
            steps++;
        }
    }

    cout<<steps<<endl;
}