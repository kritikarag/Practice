#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> numbers(n);
        for(long long i=0;i<n;i++) cin >> numbers[i];
        long long start = 1, end = 1,result = 1;

        for (long long i = 1; i < n; i++)
        {
            if (numbers[i] == numbers[i - 1])
            {
                start++;
                end++;
            }
            else if (abs(numbers[i] - numbers[i - 1]) == 1)
            {
                swap(start, end);
                if(numbers[i]>numbers[i-1]){
                    start++;
                    end = 1;
                }
                else{
                    start = 1;
                    end++;
                }
            } 
            else
            {
                start = 1;
                end = 1;
            }
            long long req = max(start, end);
            result = max(result, req);
        }
        long long curr_max = max(start, end);
        result = max(result, curr_max);
        cout << result << endl;
    }
    return 0;
}