#include<bits/stdc++.h>
using namespace std;

int label(int n,int p){
    vector<vector<int>> dp(50, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[0][i] = 5000 * (i + 1);
    for (int i = 1; i < 50; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + 5000 + i;
            if (dp[i][j] == p)
                return j+1;
        }
    }

    return -1;
}
int main(){
    int n,p;
    cin>>n>>p;
    cout<<label(n,p)<<endl;

    return 0;
}
