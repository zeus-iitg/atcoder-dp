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
    int n,k;
    cin>>n>>k;
    int arr[n+1];
    ll dp[n+1];
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
        dp[i]=LLONG_MAX;
    dp[n]=0;
    for(int i=n;i>1;i--)
    {
        int lim=max(0,i-k);
        for(int j=i-1;j>=lim;j--)
            dp[j]=min(dp[j],abs(arr[i]-arr[j])+dp[i]);
    }
    cout<<dp[1];
    return 0;
}
