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

struct TrieNode 
{
    vector<TrieNode*> next;
    bool isLast;

    TrieNode()
    {
        next.resize(26, NULL);
        isLast = 0;
    }
};

class Trie
{
private:
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insertTrie(string s)
    {
        ll n = s.size();
        TrieNode* cur = root;
        for(ll i=0; i<n; i++)
        {
            if(cur->next[s[i] - 'a'] == NULL)
            {
                cur -> next[s[i] - 'a'] = new TrieNode();
            }

            cur = cur -> next[s[i] - 'a'];
        }
        cur -> isLast = 1;
    }

    bool searchTrie(string s)
    {
        ll n = s.size();
        TrieNode* cur = root;
        for(ll i=0; i<n; i++)
        {
            if(cur->next[s[i] - 'a'] == NULL)
            {
                return 0;
            }

            cur = cur -> next[s[i] - 'a'];
        }
        return (cur -> isLast == 1);
    }
};

void tantanmaymay()
{
    Trie obj;
    ll n;
    cin >> n;
    vector<string> v(n);
    for(ll i=0; i<n; i++)
    {
        cin >> v[i];
        obj.insertTrie(v[i]);
    }

    ll m;
    cin >> m;
    for(ll i=0; i<m; i++)
    {
        string s;
        cin >> s;
        (obj.searchTrie(s)) ? cout << "Present\n" : cout << "Absent\n";
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inp1.txt", "r", stdin);
    freopen("out1.txt", "w", stdout);
    freopen("err1.txt", "w", stderr);
#endif

    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll _ = 1;
    // cin >> _;
    
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