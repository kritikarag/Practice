int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int i = 0, j = 0, k = 0;
    int l1 = A.size(), l2 = B.size(), l3 = C.size();
    int ans = INT_MAX;
    while (i < l1 and j < l2 and k < l3)
    {
        int temp_ans = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});
        if (temp_ans < ans)
            ans = temp_ans;
        if (A[i] <= B[j] and A[i] <= C[k])
            i++;
        else if (B[j] <= A[i] and B[j] <= C[k])
            j++;
        else
            k++;
    }
    return ans;
}