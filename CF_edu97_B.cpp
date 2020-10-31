//I am Doge
#include <bits/stdc++.h>

using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("-ffloat-store")

#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
//#define int long long
#define ll long long
#define endl "\n"
#define inf ULLONG_MAX
#define gcd __gcd
#define deb(x) cout << #x << " " << x << endl;
#define pr(x) cout << x << endl;

#define sz(a) ((ll)(a).size())
#define all(v) (v).begin(), (v).end()
#define tr(c, it) for (auto(it) = (c).begin(); (it) != (c).end(); it++)
#define pres(c, val) ((c).find(val) != (c).end())
#define cpres(c, val) (find(all(c), val) != (c).end())
#define dec greater<ll>()
#define sortv(x) sort(all(x))
#define revsortv(x) sort(all(x), dec)
#define com(x) (((x) * (x -1)) / 2)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define ed end()
#define bs binary_search // to find if an element is present or not in Ologn time, return a boolean
#define ub upper_bound   // to find an element strictly greater than the given no.
#define lb lower_bound   // lb(v,begin(), v.end(), n) gives the iterator

#define fo(n) for (ll i = 0; i < n; i++)
#define fo1(n) for (ll i = 1; i < n; i++)
#define fo2(i, n) for (ll i = 0; i < n; i++)
#define fo3(i, a, b) for (ll i = a; i < b; i++)
#define fors(a) cin >> a[i]
#define forp(a) cout << a[i] << " "
#define prv(a, n)  \
    fo(n) forp(a); \
    cout << endl;
#define fob(i, a, b) for (ll i = (b); i >= (a); i--)

typedef pair<ll, ll> pll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ll> vl;
typedef vector<pll> vll;
typedef set<ll> sl;
typedef map<string, ll> msl;
typedef unordered_map<string, ll> umsl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;

#define scan(v, n)   \
     vl v; \
     fo(n)            \
    {                \
        ll item;     \
        cin >> item; \
        v.pb(item);  \
    }
const ll N = 2000005;
struct subarr{
    ll l;
    ll r;
    ll len=r-l+1;
    subarr(ll l,ll r) 
        : l(l), r(r)
    { 
    }
};
struct comp { 
    bool operator()(subarr const& p1, subarr const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        if(p1.len==p2.len)return p1.l>p2.l;
        return p1.len<p2.len; 
    } 
};
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

void solve()
{
ll n;
cin>>n;
string s;
cin>>s;
ll ans=0;

ll k=1;
vl p,q;
fo(n-1){
    if(s[i]=='1' && s[i]==s[i+1])k++;
    else if(s[i]!=s[i+1]){
        p.pb(k);
        k=1;
    }
}
if(k>1 && s[n-1]=='1')p.pb(k);
if(k>1 && s[n-1]!='1')p.pb(k);
fo(p.size())ans=ans+p[i]-1;
k=1;
fo(n-1){
    if(s[i]=='0' && s[i]==s[i+1])k++;
    else if(s[i]!=s[i+1]){
        q.pb(k);
        k=1;
    }
}
if(k>1 && s[n-1]=='0')q.pb(k);
if(k>1 && s[n-1]!='0')q.pb(k);
ll ans1=0;
fo(q.size())ans1=ans1+q[i]-1;
cout<<max(ans,ans1)<<endl;
}
int32_t main(int32_t argc, char **argv)
{
    ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    /*#ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif*/

    ll t;
    t=1;
 cin >> t;

   while (t--)
        solve();

    cerr << endl
         << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

    return 0;
}
