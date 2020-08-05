#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
int max(int a,int b)
{
    return a>b?a:b;
}
using namespace std;
vector<vector<int>> memo;
int dp(int i)
int main() 
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    //memo.resize(n,vector<int>(n+1,-1));
    map<int,int> c;
    cout<<dp(0,arr,c);
    return 0;
}