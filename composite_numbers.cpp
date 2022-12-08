#include<bits/stdc++.h>
using namespace std;

bool isComposite(long long n)
{
    
    // if (n <= 1)
    //     return false;
    if (n <= 3)
        return false; 
    if (n % 2 == 0 || n % 3 == 0)
        return true;

    for (long long i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return true;

    return false;
}
int main(){
    int N,K;
    cin>>N>>K;

    vector<long long int>dp(N+1,0);

    dp[1] = 1+K;
    for(int i=2;i<=N;i++){
        dp[i] = (dp[i-1]-K)*i + K;
        //cout<<dp[i]<<endl;
    }

    int count = 0;
    for(int i=1;i<=N;i++){
        if(isComposite(dp[i])){
            count++;
        }
        //cout<<dp[i]<<" ";
    }
    cout<<count<<endl;
}

