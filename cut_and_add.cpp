#include<bits/stdc++.h>
using namespace std;

int findmin(string s, int m, int n)
{

    int len = s.length();
    int count = 1;
    string q = s.substr(len - m, m) + s.substr(0, len - m);
    int cut = n;
    while (q != s)
    {
        q = q.substr(len - cut, cut) + q.substr(0, len - cut);
        if (cut == m)
        {
            cut = n;
        }
        else
        {
            cut = m;
        }
        count++;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int m, n;
        cin >> m >> n;
        cout << findmin(s, m, n) << "\n";
    }
}