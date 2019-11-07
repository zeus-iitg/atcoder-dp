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
 
int dp[100001];
 
vvi adj;
 
vector<bool> visited;
 
void dfs(int node)
{
    // Mark as visited
    visited[node] = true;
 
    // Traverse for all its children
    for (int i = 0; i < adj[node].size(); i++) {
 
        // If not visited
        if (!visited[adj[node][i]])
            dfs(adj[node][i]);
 
        // Store the max of the paths
        dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
    }
}
 
int main()
{
    IOS
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        visited[i]=false;
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            dfs(i);
    }
    int maxi=0;
    for(int i=1;i<=n;i++)
    {
        maxi=max(maxi,dp[i]);
    }
    cout<<maxi;
    return 0;
}
