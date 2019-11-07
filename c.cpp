#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>
#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
#define clr(x) x.clear()
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vi>
#define mp make_pair
#define hell 1000000007
 
using namespace std;
 
int main()
{
    IOS
    int n;
    cin>>n;
    int arr[n][3];
    int dp[n][3]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            cin>>arr[i][j];
    }
    for(int j=0;j<3;j++)
        dp[0][j]=arr[0][j];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(k!=j)
                        dp[i+1][k]=max(dp[i+1][k],dp[i][j]+arr[i+1][k]);
                }
            }
    }
    int maxi=INT_MIN;
    for(int j=0;j<3;j++)
        maxi=max(maxi,dp[n-1][j]);
    cout<<maxi<<"\n";
    return 0;
}
