#include<bits/stdc++.h>
using namespace std;

vector<int>countPairs(vector<int> &nums, vector<int>&queries)
{
    vector<int>res;
    for(int j=0;j<queries.size();j++){
        unordered_map<int, int> gcdCount;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int currgcd = __gcd(nums[i], queries[j]);
            for (auto it: gcdCount)
                if ((currgcd * it.first)% queries[j] == 0)
                    ans += it.second;
            gcdCount[currgcd]++;
        }
        res.push_back(ans);
    }

    return res;
}

int main(){
    int n,q;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cin>>q;
    vector<int>queries(q);
    for(int i=0;i<q;i++){
        cin>>queries[i];
    }

    vector<int>ans(q);
    ans = countPairs(nums,queries);

    for(int i=0;i<q;i++){
        cout<<ans[i]<<" ";
    }
}