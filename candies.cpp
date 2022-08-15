#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    
    int count = 0; 
    int ind = 1; 
    int arr[k];

    memset(arr, 0, sizeof(arr));

    int low = 0, high = n;

    while (low <= high)
    {

        int mid = (low + high) >> 1;
        int sum = (mid * (mid + 1)) >> 1;

        if (sum <= n)
        { 
            count = mid / k; 
            low = mid + 1;
        }
        else
        { 
            high = mid - 1;
        }
    } 
    int last = (count * k); 
    n -= (last * (last + 1)) / 2;

    int i = 0; 
    int term = (count * k) + 1;

    while (n)
    {
        if (term <= n)
        {
            arr[i++] = term;
            n -= term;
            term++;
        }
        else
        {
            arr[i] += n;
            n = 0;
        }
    }

    // Count the total candies
    for (int i = 0; i < k; i++)
        arr[i] += (count * (i + 1)) + (k * (count * (count - 1)) / 2);

    // Print the total candies
    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";
    return 0;
}