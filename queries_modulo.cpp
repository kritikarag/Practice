#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>vec(n);
    vector<int>store(m,0);
    for(int i=0;i<n;i++){
        cin>>vec[i];
        store[vec[i]%m]+=1;
    }
    int queries;
    cin>>queries;
    while(queries--){
        int label;
        cin>>label;
        if (label==1){
            int position,value;
            cin>>position>>value;
            store[vec[position-1]%m] -= 1;
            vec[position-1] = value;
            store[value%m]+=1;
        }
        else{
            int x;
            cin>>x;
            cout<<store[x]<<endl;
        } 
    }
    return 0;
}

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> vec(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> vec[i];
//     }
//     int queries;
//     cin >> queries;
//     while (queries--)
//     {
//         int label;
//         cin >> label;
//         if (label == 1)
//         {
//             int position, value;
//             cin >> position >> value;
//             vec[position - 1] = value;
//         }
//         else
//         {
//             int req, count = 0;
//             cin >> req;
//             for (int i = 0; i < n; i++)
//             {
//                 if (vec[i] % m == req)
//                     count++;
//             }
//             cout << count << endl;
//         }
//     }
// }