vector<int> solve(vector<int> &arr, int n)
{
    vector<int> ans(n);
    map<int, int> first, last;
    for (int i = 0; i < arr.size(); i++)
    {
        int id = arr[i];
        id--;
        if (first.count(id) == 0)
        {
            first[id] = i;
        }
        else
        {
            last[id] = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = (last[i] - first[i]) / 2;
        ans[i]++;
    }
    return ans;
}