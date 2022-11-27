#include<bits/stdc++.h>
using namespace std;
struct Elements
{
    int weight, value;
    Elements(int x,int y)
    { 
        weight = x;
        value = y;
    }
}; 

int main(){
    int n,W;
    cin>>n>>W;
    vector<Elements*>item[n+1];
    for(int i=0;i<n;i++){
        int t,w,v; 
        cin>>t>>w>>v;
        Elements *temp = new Elements(w,v); 
        item[t].push_back(temp);
    } 
    vector<vector<int>> DP(n, vector<int>(W + 1, 0));
    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j < item[0].size(); j++)
        {
            if (i >= item[0][j]->weight)
            {
                DP[0][i] = max(DP[0][i], item[0][j]->value);
            }
        } 
    }  

    for (int k = 0; k <= W; k++)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < item[i].size(); j++)
            {
                if (k >= item[i][j]->weight)
                {
                    DP[i][k] = max(DP[i][k], DP[i - 1][k - item[i][j]->weight] + item[i][j]->value);
                }
            }

            DP[i][k] = max(DP[i][k], DP[i - 1][k]); 
        } 
    }
    cout<< DP[n - 1][W];
    return 0;
}

// int calculate(vector<vector<int>> &item)
// {
//     int n = item.size();
//     vector<vector<int>> dp(n, vector<int>(W + 1, 0));
//     for (int i = 0; i <= W; i++)
//     {
//         for (int j = 0; j < item[0].size(); j++)
//         {
//             if (i >= item[0][j].weight)
//             {
//                 DP[0][i] = max(DP[0][i], item[0][j].value);
//             }
//         }
//     }

//     // Actual DP

//     for (int k = 0; k <= W; k++)
//     {

//         for (int i = 0; i < n; i++)
//         {

//             for (int j = 0; j < item[i].size(); j++)
//             {
//                 if (k >= item[i][j].weight)
//                 {
//                     DP[i][k] = max(DP[i][k], DP[i - 1][k - item[i][j].weight] + item[i][j].value);
//                 }
//             }

//             DP[i][k] = max(DP[i][k], DP[i - 1][k]);
//         }
//     }

//     return dp[n - 1][W];
// }