#include<bits/stdc++.h>
using namespace std;

bool is_shuffled_palindrome(const string &s)
{
    vector<int> occurrence(26, 0);
    int odd_count = 0;
    for (char i : s)
    {
        occurrence[i - 'a']++;
    }
    for (int value : occurrence)
    {
        if (value % 2 != 0)
        {
            odd_count++;
        }
    }
    return odd_count <= 1;
}

int main(){
    string s;
    cin>>s;
    int s_size = s.size();
    int result = 0;
    int start = 0, end = s_size - 1;

    // if string is empty or it is not a palindrome return -1
    if ((s_size == 0) || (!is_shuffled_palindrome(s)))
    {
        return -1;
    }

    while (end > start)
    { 
        if (s[start] != s[end])
        {
            int i = end; 
            while (i > start && s[i] != s[start])
            {
                --i;
            } 
            if (i == start)
            {
                swap(s[start], s[start + 1]);
                ++result;
            } 
            else
            {
                while (i < end)
                {
                    swap(s[i], s[i + 1]);
                    ++result;
                    ++i;
                }
                ++start;
                --end;
            }
        } 
        else
        {
            ++start;
            --end;
        }
    }
    cout<<result<<endl;

    return 0;
}