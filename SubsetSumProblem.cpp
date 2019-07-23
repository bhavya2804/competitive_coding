/*SUBSET SUM PROBLEM (Recursion)
  Time Complexity: Polynomial Time
*/
#include <bits/stdc++.h>
using namespace std;

bool subset(vector<int> v, int sum,int i)
{
    //cout<<i<<" "<<sum<<endl;
    if(sum==0)
        return 1;
    else if (sum<0 || i==v.size()) //Assuming no negative numbers
        return 0;
    else
        return (subset(v,sum-v[i],i+1) || subset(v,sum,i+1));
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
    cout<<subset(v,sum,0);
    return 0;
}
