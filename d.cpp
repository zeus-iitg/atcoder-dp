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
 
ll dp[100001][101];
 
ll knapsack(ll wt[],ll val[],ll w,ll n,ll cur_index)
{
    if(dp[w][cur_index]!=-1)
        return dp[w][cur_index];
    if(cur_index==n)
        return (ll)0;
    if(wt[cur_index]<=w)
        return dp[w][cur_index] = max(val[cur_index]+knapsack(wt,val,w-wt[cur_index],n,cur_index+1)
                                      ,knapsack(wt,val,w,n,cur_index+1));
    else
        return dp[w][cur_index] = knapsack(wt,val,w,n,cur_index+1);
}
 
int main()
{
    IOS
    memset(dp,-1,sizeof(dp));
    ll n,w;
    cin>>n>>w;
    ll wt[n],val[n];
    for(ll i=0;i<n;i++)
        cin>>wt[i]>>val[i];
    cout<<(ll)knapsack(wt,val,w,n,0);
    return 0;
}
