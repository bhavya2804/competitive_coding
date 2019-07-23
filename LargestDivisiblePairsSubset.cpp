/*Largest divisible pairs subset with DP
  Time Complexity: O(n^2)
  Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n+1]={};
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    //Building Table
   int dp[n+1]={};
   dp[n-1]=1;
   for(int i=n-2;i>=0;i--)
   {
       int x=0;
       for(int j=i+1;j<n;j++)
       {
            if(a[j]%a[i]==0)
                x=max(x,dp[j]);
       }
       dp[i]=1+x;
   }
   cout<<*max_element(dp,dp+n)<<endl;
    return 0;
}
