#include <bits/stdc++.h>
using namespace std;


string maximizer(string s, int swapsAllowed){
    int i = 0;

    int max = -1;
    //string ch=s;
    int indexOfMax;

    while (i < s.length() && swapsAllowed > 0)

    {

        int j = i;

        indexOfMax = i;

        for (; j <= i + swapsAllowed && j < s.length(); j++)

        {

            if (s[j] - '0' > max)

            {

                max = s[j] - '0';

                indexOfMax = j;
            }
        }

        if (indexOfMax == s.length() - 1 && j == s.length())

        {

            return s;
        }

        for (int o = indexOfMax - 1; o >= i; o--) // Move the maximum number to front

        {
            char temp = s[o + 1];

            s[o + 1] = s[o];

            s[o] = temp;
        }

        max = -1;

        swapsAllowed = swapsAllowed - indexOfMax - i;

        i++;
    }

    return s;
}
int main(){
    string s;
    int swapsAllowed;
    cin>>s;
    cin>>swapsAllowed;

    cout<<maximizer(s,swapsAllowed)<<endl;
    return 0;
}