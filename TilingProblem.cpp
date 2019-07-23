/*Tiling problem using DP
	TIME COMPLEXITY: O(n)
	Space COMPLEXITY: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll tiles(ll n)
{
    ll dp[n+1]={};
    for(int i=1;i<=n;i++)
    {
        if(i==1 || i==2)
            dp[i]=i;
        else
            dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main()
{
    ll n;
    cin>>n;
    cout<<tiles(n)<<endl;
}