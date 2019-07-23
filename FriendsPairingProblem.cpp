/*firends pairing problem in DP
  Time Complexity: O(n)
  Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int friendsPair(int n)
{
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        if(i<=2)
            dp[i]=i;
        else
            dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }
    return dp[n];
}

int main()
{
      int n;
      cin>>n;
      cout<<friendsPair(n);
    return 0;
}
