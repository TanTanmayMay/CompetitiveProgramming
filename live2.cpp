//@author :  Tanmay Kokate  

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld double
#define lf float
#define po push_back

using namespace std;

const ll INF = 1e18 + 500;
const ll NEG_INF = (-1) * 1e18; 
const ll MOD = 998244353;
const ll ModPrime = 1000000007;
const ll MAX = 1e5 + 5;
const ll identityAnd = 4294967295;
const ld PI = 3.141592653589793238462;

void tantanmaymay()
{
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp2.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    freopen("err2.txt", "w", stderr);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll _ = 1;
    cin >> _;
    
    while (_--) tantanmaymay();
    return 0;
}

#ifndef ONLINE_JUDGE
    #define lien(x) cerr<<#x<<" :: "; eout(x); cerr<<"\n";
#else
    #define lien(x)
#endif

void eout(int a) {cerr<<a;}
void eout(ll a) {cerr<<a;}
void eout(string a) {cerr<<a;}
void eout(bool a) {cerr<<a;}
void eout(char a) {cerr<<a;}
void eout(double a) {cerr<<a;}
void eout(ull a) {cerr<<a;}

template<class T, class V> void eout(pair<T, V> pr) {cerr<<"{"; eout(pr.first); cerr<<", "; eout(pr.second); cerr<<"}";}
template<class T> void eout(vector<T> v) {cerr<<"[ "; for(T i: v){eout(i); cerr<<" ";} cerr<<"]";}
template<class T> void eout(set<T> s) {cerr<<"[ "; for(T i: s){eout(i); cerr<<" ";} cerr<<"]";}
template<class T> void eout(unordered_set<T> s) {cerr<<"[ "; for(T i: s){eout(i); cerr<<" ";} cerr<<"]";}
template<class T> void eout(multiset<T> s) {cerr<<"[ "; for(T i: s){eout(i); cerr<<" ";} cerr<<"]";}
template<class T, class V> void eout(map<T, V> mpp) {cerr<<"\n[\n"; for(auto i: mpp){cerr<<"\t"; eout(i); cerr<<"\n";} cerr<<"]";}
template<class T, class V> void eout(unordered_map<T, V> mpp) {cerr<<"\n[\n"; for(auto i: mpp){cerr<<"\t"; eout(i); cerr<<"\n";} cerr<<"]";}
template<class T, class V> void eout(multimap<T, V> mpp) {cerr<<"\n[\n"; for(auto i: mpp){cerr<<"\t"; eout(i); cerr<<"\n";} cerr<<"]";}
template<class T> T binpow(T a, T b, ll p = ModPrime) { T ans = 1; while(b) {if(b&1)ans=(ans*a)%p; a=(a*a)%p; b>>=1;} return ans;}
template<class T> T gzd(T a, T b) {return b ? gzd (b, a%b) : a;}
template<class T> T lzm(T a, T b) {return (a*b)/gzd(a, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a/b : a/b + 1;}