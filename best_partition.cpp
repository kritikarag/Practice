#include<bits/stdc++.h>
using namespace std;

int largestSumOfAverages(vector<int> &A, int K)
{
    int n = A.size();

    // storing prefix sums
    int pre_sum[n + 1];
    pre_sum[0] = 0;
    for (int i = 0; i < n; i++)
        pre_sum[i + 1] = pre_sum[i] + A[i];

    // for each i to n storing averages
    int dp[n] = {0};
    int sum = 0;
    for (int i = 0; i < n; i++)
        dp[i] = (pre_sum[n] - pre_sum[i]);

    for (int k = 0; k < K - 1; k++)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                dp[i] = min(dp[i], (pre_sum[j] - pre_sum[i])+ dp[j]);

    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main()
{
    vector<int> A = {5,6,6,8};
    int K = 4; // atmost partitioning size
    cout << largestSumOfAverages(A, K) << endl;
    return 0;
}