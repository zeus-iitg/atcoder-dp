#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vi>
#define mt make_tuple
#define mp make_pair
#define hell 1000000007
#define mod 998244353
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()
#define ign cin.ignore();
#define g(a,b) get<a>(b)
#define vt(a) vector<a>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repi(i,a,b) for(ll i=b-1;i>=a;i--)
#define fi first
#define se second

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//to delete an element
//s.erase(s.find_by_order(s.order_of_key(ele)));
//where s is the name of the ordered_set
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

using namespace std;
using namespace __gnu_pbds;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll dp[1<<16];

ll a[16][16];

ll calc[1<<16];

int n;

void pre(){
    for(int i=0;i<(1<<n);i++){
        vi v;
        calc[i]=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                v.pb(j);
            }
        }
        for(int j=0;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
                calc[i]=calc[i]+a[v[j]][v[k]];
            }
        }
    }
}

int main()
{
    IOS
    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    ll ntc=1;
    //cin>>ntc;
    rep(tc,1,ntc+1)
    {
        //cout<<"Case #"<<tc<<": ";
        memset(dp, -1, sizeof dp);
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        pre();
        dp[0]=0;
        for(int i=0;i<n;i++){
            dp[1<<i]=0;
        }
        for(int i=0;i<(1<<n);i++){
            if(dp[i]!=-1)
                continue;
            /*vi v;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    v.pb(j);
                }
            }
            int num=v.size();
            dp[i]=LLONG_MIN;
            for(int j=1;j<(1<<num);j++){
                int new_mask=i;
                for(int k=0;k<num;k++){
                    if(j&(1<<k)){
                        new_mask^=(1<<v[k]);
                    }
                }
                dp[i]=max(dp[i], calc[i^new_mask] + dp[new_mask]);
            }*/
            int taken=i;
            dp[i]=LLONG_MIN;
            while(taken){
                dp[i]=max(dp[i], calc[taken] + dp[i^taken]);
                taken=(taken-1)&i;
            }
        }
        cout<<dp[(1<<n)-1]<<"\n";
    }
    return 0;
}
