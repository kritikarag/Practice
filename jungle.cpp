#include <bits/stdc++.h>
using namespace std;

int collatzLenUtil(int n, unordered_map<int, int> &collLenMap)
{

    // If value already
    // computed, return it
    if (collLenMap.find(n) != collLenMap.end())
        return collLenMap[n];

    // Base case
    if (n == 1)
        collLenMap[n] = 1;

    // Even case
    else if (n % 2 == 0)
    {
        collLenMap[n] = 1 + collatzLenUtil(n / 2, collLenMap);
    }

    // Odd case
    else
    {
        collLenMap[n] = 1 + collatzLenUtil(3 * n + 1, collLenMap);
    }

    return collLenMap[n];
}

pair<int, int> collatzLen(int n)
{

    // Declare empty Map / Dict
    // to store collatz lengths
    unordered_map<int, int> collLenMap;

    collatzLenUtil(n, collLenMap);

    // Initialise ans and
    // its collatz length
    int num = -1, l = 0;

    for (int i = 1; i < n; i++)
    {

        // If value not already computed,
        // pass Dict to Helper function
        // and calculate and store value
        if (collLenMap.find(i) == collLenMap.end())
            collatzLenUtil(i, collLenMap);

        int cLen = collLenMap[i];
        if (l < cLen)
        {
            l = cLen;
            num = i;
        }
    }

    // Return ans and
    // its collatz length
    return {num, l};
}

int main()
{
    int n;
    cin>>n;
    //Prints the starting point and length
    cout << "(" << collatzLen(n+1).first << ", " << collatzLen(n+1).second << ")" << endl;
}