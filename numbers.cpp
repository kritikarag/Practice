#include <bits/stdc++.h>
using namespace std;

// Checking if a number is prime or not
bool isprime(int x)
{ 
    if (x==1)return false;
    if(x==2)return true;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

vector<int>primenums(vector<int>&arr,int n){
    int count = 0, num = 1;

    vector<int>res;

    while (count < n)
    {
        if (isprime(num))
        {
            res.push_back(num);
            count++;
        }
        num++;
    }
    return res;
}

int main(){
    int sum,n;
    cin>>sum>>n;

    vector<int>primes(n);
    primenums(primes,n);
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= sum; i++)
        dp[0][i] = INT_MAX - 1;

    for (int i = 1; i <= sum; i++)
    {
        if (i % primes[0] != 0)
            dp[1][i] = INT_MAX - 1;
        else
            dp[1][i] = i / primes[0];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (primes[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - primes[i - 1]], dp[i][j]);
        }
    }

    cout<<dp[n][sum]<<endl;
}