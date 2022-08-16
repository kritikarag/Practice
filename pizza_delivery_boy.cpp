#include<bits/stdc++.h>
using namespace std;

int dist(int p1[2],
          int p2[2])
{
    int x0 = p1[0] - p2[0];
    int y0 = p1[1] - p2[1];
    return x0 * x0 + y0 * y0;
}

double maxDist(int p[][2], int n)
{
    double Max = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            Max = max(Max, (double)dist(p[i],p[j]));
        }
    }
    return sqrt(Max);
}


int main(){
    int s,x;
    cin>>s>>x;
    int arr[x][2];
    for(int i=0;i<x;i++){
        cin>>arr[i][0]>>arr[i][1];
    }

    cout<<fixed<<setprecision(6)<<maxDist(arr,x)/s<<endl;
}
