#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()
#define ign cin.ignore();
 
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
#ifdef MY_PROJECT
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
inline int fast_expo(int base,int power,int modulo=hell){
    base%=modulo;
    if (base<0) base+=modulo;
    ll x=base,cnt=power,ans=1;
    while(cnt){
        if (cnt&1) ans=(ans*x)%modulo;
        x=(x*x)%modulo;
        cnt>>=1;
    }
    return ans;
}
inline int inv(int base,int modulo=hell){
    return fast_expo(base,modulo-2,modulo);
}
 
static int fact[2000000];
static int inv_fact[2000000];
 
void init(){
    fact[0]=1;
    inv_fact[0]=1;
    for(int i=1;i<2000000;i++)
    {
        fact[i]=((ll)i*(ll)fact[i-1])%hell;
        inv_fact[i]=inv(fact[i]);
    }
}
 
int main()
{
    IOS
    init();
    int n,m,q;
    cin>>n>>m>>q;
    q++;
    vpii v;
    v.pb(mp(n,m));
    int dp[q];
    for(int i=1;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    sort(all(v));
    for(int i=0;i<q;i++)
    {
        int r=v[i].first;
        int c=v[i].second;
        dp[i]=((((ll)fact[r+c-2]*(ll)inv_fact[r-1])%hell)*(ll)inv_fact[c-1])%hell;
        for(int j=0;j<i;j++)
        {
            if((v[j].first<=r)&&(v[j].second<=c)){
                ll minuss=((ll)dp[j]*(ll)fact[r-v[j].first+c-v[j].second])%hell;
                minuss=(minuss*(ll)inv_fact[r-v[j].first])%hell;
                minuss=(minuss*(ll)inv_fact[c-v[j].second])%hell;
                dp[i]=dp[i]+hell-minuss;
                dp[i]%=hell;
            }
        }
    }
    cout<<dp[q-1];
    return 0;
}
