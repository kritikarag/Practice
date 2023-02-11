typedef long long int ll;
int solve(vector<ll> &nums)
{
    ll tot = 0;
    for (auto num : nums)
        tot += num;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (2 * nums[i] >= (tot - nums[i]))
            ans++;
    }
    return ans;
}