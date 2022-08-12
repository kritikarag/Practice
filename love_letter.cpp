#include <bits/stdc++.h>
using namespace std;

// In-place rotates s towards left by d
void leftrotate(string &s, int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}

// In-place rotates s towards right by d
int rightrotate(string &s, int d)
{
    string s1 = "";
    int i = 0, flag = 0;
    vector<string> str;
    while (s[i] != '\0')
    {
        if (s[i] != ' ')
        {
            s1 = s1 + s[i];
            i++;
        }
        else
        {
            if (s1 != "")
            { // checking for extra space
                str.push_back(s1);
                s1 = "";
                i++;
            }
            else
                i++;
        }
    }
    str.push_back(s1);
    vector<string> str2;
    for (int i = 0; i < str.size(); i++)
    {
        str2.push_back(str[i]);
    }
    for (int i = 0; i < str.size(); i++)
    {
        leftrotate(str[i], str[i].length() - d);
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == str2[i])
        {
            flag++;
        }
    }
    return flag;
}

int main()
{

    string str1;
    getline(cin, str1);
    int k;
    cin >> k;
    cout << rightrotate(str1, k);
    return 0;
}