#include <bits/stdc++.h>
using namespace std;
// int dp[101][101];

int maxMergingScore(vector<int>&A)
{
    A.insert(A.begin(),1);
    A.push_back(1);
    int N = A.size();
    vector<vector<int>> dp(N, vector<int>(N));
    for (int len = 1; len < N; ++len)
    {
        for (int i = 0; i + len < N; ++i)
        {
            int j = i + len;
            dp[i][j] = 0;
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
    // int N = 6;
    // int A[] = {1, 3, 1, 5, 8, 1};
    cout << maxMergingScore(A) << endl;

    return 0;
}