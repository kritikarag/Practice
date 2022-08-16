#include<bits/stdc++.h>
using namespace std;

string encodeString(string str)
{
    int hashEven[CHAR_MAX] = {0};
    int hashOdd[CHAR_MAX] = {0};

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (i & 1)
            hashOdd[c - 'a']++;
        else
            hashEven[c - 'a']++;
    }

    string encoding = "";

    for (int i = 0; i < CHAR_MAX; i++)
    {
        encoding += to_string(hashEven[i]);
        encoding += to_string('-');
        encoding += to_string(hashOdd[i]);
        encoding += to_string('-');
    }
    return encoding;
} 

int countDistinct(string input[], int n)
{
    int countDist = 0;  
    unordered_set<string> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(encodeString(input[i])) == s.end())
        {
            s.insert(encodeString(input[i]));
            countDist++;
        }
    }
    return countDist;
}

int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<countDistinct(arr,n)<<endl;
    return 0;
}