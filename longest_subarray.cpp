#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long int> arr(n);
        map<long long int, int> mp;
        long long int mxele = 0, ele = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
            if (mxele < mp[arr[i]] || (mxele == mp[arr[i]] && ele < arr[i]))
            {
                mxele = mp[arr[i]];
                ele = arr[i];
            }
        }
        long long int i = 0, j = 0, mx = 0, cnt = 0;
        while (j < n)
        {
            if (arr[j] == ele)
            {
                cnt++;
            }
            else if ((arr[j] + 1) == ele)
            {
                cnt++;
            }
            else
            {
                //        cout<<arr[j]<<"** ";
                mx = max(cnt, mx);
                cnt = 0;
                //  i=j+1;
            }
            j++;
        }
        j = 0;
        while (j < n)
        {
            if (arr[j] == ele)
            {
                cnt++;
            }
            else if ((arr[j] - 1) == ele)
            {
                cnt++;
            }
            else
            {
                //        cout<<arr[j]<<"** ";
                mx = max(cnt, mx);
                cnt = 0;
                //  i=j+1;
            }
            j++;
        }
        mx = max(cnt, mx);
        cout << mx << endl;
    }
    return 0;
}