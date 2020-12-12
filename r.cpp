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

static const int matrixRemainder = 1000000007;

class matrix{
public:

    // Attributes
    int row, col;
    std::vector<std::vector<ll>> num;

    // Constructor
    matrix(int row, int col, int defaultValue = 0){
        this->num = std::vector<std::vector<ll>>(row, std::vector<ll>(col, defaultValue));
        this->row = row, this->col = col;
    }
    matrix(std::vector<std::vector<ll>> num){
        this->num = num;
        this->row = this->num.size();
        this->col = this->num[0].size();
    }

    // Operator
    matrix operator *(matrix &another){
        if(this->col != another.row){
            printf("Wrong size: %d*%d X %d*%d\n", this->row, this->col, another.row, another.col);
            throw "Wrong size";
        }
        matrix newone(this->row, another.col);
        for(int r=0; r<newone.row; r++) for(int c=0; c<newone.col; c++){
            for(int k=0; k<this->col; k++){
                newone.num[r][c] += this->num[r][k] * another.num[k][c];
                newone.num[r][c] %= matrixRemainder;
            }
        } return newone;
    }

    // Power
    matrix operator ^(ll x){
        if(x==0){
            makeiden();
            return *this;
        }
        else if(x==1) return *this;
        else{
            matrix halfpower = (*this) ^ (x/2);
            if(x%2 == 0) return halfpower * halfpower;
            else return halfpower * halfpower * (*this);
        }
    }

    void reset(){
        this->num.assign(this->row,std::vector<ll>(this->col,0));
    }

    void makeiden(){
        reset();
        for(int i=0;i<this->row;i++)
        {
            this->num[i][i]=1;
        }
    }
};

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
        ll k;
        cin>>n>>k;
        matrix mat(n, n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>mat.num[i][j];
            }
        }
        mat=mat^k;
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=ans+mat.num[i][j];
                ans%=matrixRemainder;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
