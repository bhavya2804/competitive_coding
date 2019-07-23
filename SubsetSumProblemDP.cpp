/*Subset sum problem (Dp)
  Time Complexity: O(n^2)
  Space Complexity: O(2*n)
*/
#include <bits/stdc++.h>
using namespace std;

bool subset(vector<int> &v, int sum)
{
    int n=v.size();
    bool sub[n+1][sum+1];
    
    //No elements in vector and sum_required is 0
    for(int i=1;i<=sum;i++)
        sub[0][i]=false;
    //Required sum is 0
    for(int i=0;i<=n;i++)
        sub[i][0]=true;
        
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<v[i-1])
                sub[i][j]=sub[i-1][j];
            if(j>=v[i-1])
                sub[i][j]= (sub[i-1][j] || sub[i-1][j-v[i-1]]);
            
        }

    }
    return sub[n][sum];
    
}

int main()
{
    int n;
    cin>>n;
    vector <int> v;
    int x,sum;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cin>>sum;
    cout<<subset(v,sum);
    return 0;
}