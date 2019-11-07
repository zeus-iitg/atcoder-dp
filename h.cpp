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
    int r,c;
    cin>>r>>c;
    cin.ignore();
    char a[r][c];
    ll dp[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++){
            cin>>a[i][j];
            if(a[i][j]=='#')
                dp[i][j]=0;
        }
        cin.ignore();
    }
    if(a[r-1][c-2]=='.')
        dp[r-1][c-2]=1;
    if(a[r-2][c-1]=='.')
        dp[r-2][c-1]=1;
    for(int j=c-3;j>=0;j--)
    {
        if(a[r-1][j]=='.')
            dp[r-1][j]=dp[r-1][j+1];
    }
    for(int j=r-3;j>=0;j--)
    {
        if(a[j][c-1]=='.')
            dp[j][c-1]=dp[j+1][c-1];
    }
    for(int i=r-2;i>=0;i--)
        for(int j=c-2;j>=0;j--)
            if(a[i][j]=='.')
                dp[i][j]=(dp[i+1][j]+dp[i][j+1])%hell;
    cout<<dp[0][0]<<"\n";
    return 0;
}
