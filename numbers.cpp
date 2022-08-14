#include <bits/stdc++.h>
using namespace std;

// Checking if a number is prime or not
bool isprime(int x)
{ 
    if (x==1)return false;
    
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main(){
    int sum,n;
    cin>>sum>>n;

    int count = 0, num = 1;

    vector<int> primes;

    while (count < n)
    {
        if (isprime(num))
        {
            primes.push_back(num);
            count++;
        }
        num++;
    }

    int table[sum+1];
    table[0] = 0;

    // Initialize all table values as Infinite
    for (int i = 1; i <= sum; i++)
        table[i] = INT_MAX;

    for (int i = 1; i <= sum; i++)
    {
        // Go through all primes smaller than i
        for (int j = 0; j < n; j++)
            if (primes[j] <= i)
            {
                int sub_res = table[i - primes[j]];
                if (sub_res != INT_MAX && sub_res + 1 < table[i])
                    table[i] = sub_res + 1;
            }
    }

    if (table[sum] == INT_MAX)cout<<-1<<endl;
    else cout<<table[sum]<<endl;
    
}