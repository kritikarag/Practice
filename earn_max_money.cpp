#include <bits/stdc++.h>
using namespace std;

int maxMergingScore(vector<int>&A)
{
    A.insert(A.begin(),1);
    A.push_back(1);
    int N = A.size();
    vector<vector<int>> dp(N, vector<int>(N,0));
    for (int len = 1; len < N; ++len)
    {
        for (int i = 0; i + len < N; ++i)
        {
            int j = i + len;
            //dp[i][j] = 0;
            for (int k = i + 1; k < j; ++k)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
            }
        }
    }
    return dp[0][N - 1];
}

int main()
{
    int N;
    cin>>N;
    vector<int>A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    } 
    cout << maxMergingScore(A) << endl;
    return 0;
}