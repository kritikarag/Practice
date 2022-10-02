#include <bits/stdc++.h>
using namespace std;
// int dp[101][101];

int maxMergingScore(int A[], int N, vector<vector<int>> &dp)
{
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
    int N = 6;
    int A[] = {1, 3, 1, 5, 8, 1};
    vector<vector<int>> dp(N, vector<int>(N));
    cout << maxMergingScore(A, N, dp) << endl;

    return 0;
}