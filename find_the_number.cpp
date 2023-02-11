string Find_It(int X, long long K, string S, int N)
{
    S = " " + S;
    // int cnt=0;
    vector<set<char>> v;
    for (int i = 1; i <= N; i += X)
    {
        // cnt++;
        set<char> temp;
        for (int j = i; j <= min(N, X + i - 1); j++)
        {
            temp.insert(S[j]);
        }
        v.push_back(temp);
    }
    int blocks = v.size();
    int ind = 0;
    vector<vector<ll>> value(blocks, vector<ll>(X));
    // for(int i=0;i<blocks;i++)sort(v[i].begin(),v[i].end());
    ll val = 1;
    string b = "";
    bool flag = 0;
    for (int i = blocks - 1; i >= 0 && !flag; i--)
    {
        set<char>::iterator it;
        int j = 0;
        for (it = v[i].begin(); it != v[i].end() && !flag; it++, j++) // int j=0;j<v[i].size();j++)
        {
            value[i][j] = val * (j + 1);
            if (value[i][j] >= K)
            {
                ind = i;
                b += *it;
                if (K == value[i][j])
                    K = 0;
                else if (j)
                    K -= value[i][j - 1];
                flag = 1;
            }
        }
        if (!flag)
            val = value[i][v[i].size() - 1];
    }
    string a = "", c = "";
    for (int i = 0; i < ind; i++)
        a += *v[i].begin();
    for (int i = ind + 1; i < blocks; i++)
    {
        // cout<<"hello\n";
        // if(blocks-1==i)cout<<v[i][v[i].size()-1]<<"\n";
        if (K == 0)
        {
            c += *v[i].rbegin();
            continue;
        }
        set<char>::iterator it;
        int j = 0;
        for (it = v[i].begin(); it != v[i].end(); it++, j++) // int j=0;j<v[i].size();j++)
        {
            if (value[i][j] >= K)
            {
                c += *it;
                if (K == value[i][j])
                    K = 0;
                else if (j)
                    K -= value[i][j - 1];
                break;
            }
        }
    }
    return a + b + c;
    // Write your code here
}