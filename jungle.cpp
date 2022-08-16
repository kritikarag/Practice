#include <bits/stdc++.h>
using namespace std;

int collatzLenUtil(int n, unordered_map<int, int> &mp)
{ 
    if (mp.find(n) != mp.end())
        return mp[n];
 
    if (n == 1)
        mp[n] = 1;
 
    else if (n % 2 == 0)
    {
        mp[n] = 1 + collatzLenUtil(n / 2, mp);
    }
 
    else
    {
        mp[n] = 1 + collatzLenUtil(3 * n + 1, mp);
    }

    return mp[n];
}

pair<int, int> collatzLen(int n)
{
 
    unordered_map<int, int> mp;

    collatzLenUtil(n, mp);
 
    int num = -1, l = 0;

    for (int i = 1; i < n; i++)
    { 
        if (mp.find(i) == mp.end())
            collatzLenUtil(i, mp);

        int cLen = mp[i];
        if (l < cLen)
        {
            l = cLen;
            num = i;
        }
    } 
    return {num, l};
}

int main()
{
    int n;
    cin>>n;
    //Prints the starting point and length
    cout << "(" << collatzLen(n+1).first << ", " << collatzLen(n+1).second << ")" << endl;
}