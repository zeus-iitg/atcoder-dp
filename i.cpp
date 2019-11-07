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
    double dp[3000];
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        double p;
        cin>>p;
        for(int j=i;j>0;j--)
        {
            dp[j]=dp[j]*(1-p)+dp[j-1]*p;
        }
        dp[0]=dp[0]*(1-p);
    }
    double res=0;
    for(int i=0;i<=n;i++)
    {
        int heads=i;
        int tails=n-i;
        if(heads>tails)
            res=res+dp[i];
    }
    cout<<fixed<<setprecision(10)<<res;
    return 0;
}
