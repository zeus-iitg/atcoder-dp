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

const int maxn = 100000;

vi adj[maxn];

const int mod = 1e9 + 7;

int mul(int a, int b) {
    return (ll) a * b % mod;
}

// returns a pair {black, white}
pii dfs(int a, int parent) {
    int all_white = 1; // means: my vertex can be painted black
    int sth_is_black = 0;
    for(int b : adj[a]) {
        if(b != parent) {
            pair<int,int> p = dfs(b, a);
            // p.first is the number of ways to color the subtree
            // such that 'b' is black
            int memo_all_white = all_white;
            all_white = mul(all_white, p.second);
            sth_is_black = (mul(memo_all_white, p.first)
                + mul(sth_is_black, p.first + p.second)) % mod;
        }
    }
    return make_pair(all_white, (all_white + sth_is_black) % mod);
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
        int n;
        cin>>n;
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin>>u>>v;
            u--;v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        pii p = dfs(1, -1);
        int ans = (p.first + p.second) % mod;
        cout<<ans<<"\n";
    }
    return 0;
}
