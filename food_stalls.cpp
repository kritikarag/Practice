#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q, result = 0, p, s, flag;
    //cout << "Enter number of friends" << endl;
    cin >> n; // input1
    //cout << "Enter number of stalls" << endl;
    cin >> m; // input2
    int person[n][10];
    int stall[m][10];
    for (int i = 0; i < m; i++)
    {
        //cout << "Enter 1 for colors that is accepted by stall " << i + 1 << endl;
        for (int j = 0; j < 10; j++)
        { // loop for input3
            cin >> stall[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        //cout << "Enter 1 for the color that person " << i + 1 << " has" << endl;
        for (int j = 0; j < 10; j++)
        { // loop for input4
            cin >> person[i][j];
        }
    }

    //cout << "Enter number of queries" << endl;
    cin >> q; // input5

    int query[q][2];

    for (int i = 0; i < q; i++)
    { // loop for input 6
        cout << "Enter query " << i + 1 << endl;
        cin >> query[i][0];
        cin >> query[i][1];
    }

    for (int i = 0; i < q; i++)
    { // loop to check for customer served or not
        p = query[i][0];
        s = query[i][1];
        //cout << p << endl;
        //cout << s << endl;
        flag = 0;
        for (int j = 0; j < 10; j++)
        {
            if (person[p - 1][j] == stall[s - 1][j] && person[p - 1][j] == 1)
            {
                flag = 1;
            }
        }
        result = result + flag; // total result
    }
    cout << result << endl; // printing the result
    return 0;
}