// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <class T> 
using godset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Functions:
// 1. No. of elements smaller than x (Note: smaller when comparator is less/less_equal else greater)
//    (Returns index like lower_bound function)
//    p.order_of_key(x)
// 2. Element present at index x
//    *p.find_by_order(x)

// Comparator:
// 1. less              - Set
// 2. less_equal        - Multi set
// 3. greater           - Set       (descending order)
// 4. greater_equal     - Multi set (descending order)

    // Lambda
    auto good = [&] (ll m) -> ll
    {

    };
// ASCII of 'a'-97,'z'-123,'A'-65,'Z'-90,'0'-48,'9'-57

//********** UTILITIES
const ld PI = 3.141592653589793238462;

string DecimaltoBinary(ll n) {string res = ""; while(n) {if((n&1)==1){res = "1" + res;} else{res="0"+res;} n=n>>1;} return res;}
ll BinarytoDecimal(string bin) {ll base = 1; ll res = 0; for (ll i = bin.size() - 1; i >= 0; i--) {if (bin[i] == '1') {res += base;} base *= 2;} return res;}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a/b : a/b + 1;}
bool isPrime(ll a) {if(a < 2) return false; for(ll fac = 2; fac*fac<=a; fac++) if(a%fac == 0) return false; return true;}
bool isPow2(ll n) {if(n == 0){ return 0; } return (n && (!(n & (n - 1))));}
ll modInv(ll n, ll p=ModPrime) {return binpow(n, (p-2));}
ll ncr(ll n, ll r, ll p=ModPrime) {if(n < r) return 0; if(r == 0) return 1; vector<ll> fac(n+1, 0); fac[0] = 1; for(ll i=1; i<=n; i++) fac[i] = (fac[i-1] * i) % p; return (fac[n] * modInv(fac[r], p) % p * modInv(fac[n-r], p) % p) % p;}
ll get_mex(vector<ll> &a) {ll m = 0; set<ll> st(a.begin(), a.end()); while(st.count(m)) ++m; return m;}
ll countSetBits(ll n) {return __builtin_popcountll(n);}
ll factorial(ll n) {if(n==1) return 1; return ((n)%ModPrime*(factorial(n-1))%ModPrime)%ModPrime; }
ll modadd(ll a, ll b, ll p=ModPrime) {a = a % p; b = b % p; return (((a + b) % p) + p) % p;}
ll modsub(ll a, ll b, ll p=ModPrime) {a = a % p; b = b % p; return (((a - b) % p) + p) % p;}
ll modmul(ll a, ll b, ll p=ModPrime) {a = a % p; b = b % p; return (((a * b) % p) + p) % p;}
ll moddiv(ll a, ll b, ll p=ModPrime) {a = a % p; b = modInv(b, p); return ((a%p * b%p) % p);}
ll accumulate(const vector<ll> &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
vector<ll> drow = {-1, 1, 0, 0}, dcol = {0, 0, -1, 1};


/*
bool sortt(pair<pair<ll,ll>,ll>&p1,pair<pair<ll,ll>,ll>&p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    if(p1.first.first==p2.first.first){
        return p1.first.second<p2.first.second;
    }
    else{ 
        return p1.first.first>p2.first.first;
    }
}
*/

//**************************SEIEVE OF ERATHOSTENE**********************************

vector<bool> seive(ll n)
{
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}


//**************** PRIME FACTORS IN log(n) ******************************

void sieve_for_primeFactorization_in_logn(ll n, vector<ll> &spf)
{
    spf[1] = 1;
    for(ll i=2; i<n; i++)
    {
        spf[i] = i;
    }

    for(ll i=4; i<n; i+=2)
    {
        spf[i] = 2;
    }
 
    for(ll i=3; (i*i)<n; i++) 
    {
        if(spf[i] == i) 
        {
            for(ll j=i*i; j<n; j+=i)
            {
                if(spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<ll> get_prime_factors(ll n, vector<ll> &spf)
{
    vector<ll> ds;
    while(n != 1)
    {
        ds.po(spf[n]);
        n /= spf[n];
    }
    return ds;
}

//************Hashing String**********************
ll hash_string(string const& s) 
{
    const int p = 31;
    const int m = 1e9 + 9;
    ll hash_value = 0;
    ll p_pow = 1;
    for (char c : s) 
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

//****************************Precomputer primes Trial Division***********************************
// GIVES PRIME FACTORIZATION
vector<long long> primes;

vector<long long> trial_division4(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}



//**************FERMATS FACTORIZATION -> Works when prime factors of a number are close to each others
int fermat(int n) {
    int a = ceil(sqrt(n));
    int b2 = a*a - n;
    int b = round(sqrt(b2));
    while (b * b != b2) {
        a = a + 1;
        b2 = a*a - n;
        b = round(sqrt(b2));
    }
    return a - b;
}   



//************************* VERY BASIC SEGMENT TREE ****************************
void buildSegTree(vector<ll> &v, ll indx, ll left, ll right, vector<ll> &segTree)
{
    if(left == right)
    {
        segTree[indx] = v[left];
        return;
    }
    ll mid = ((left + right) >> 1);
    buildSegTree(v, ((2 * indx) + 1), left, mid, segTree);
    buildSegTree(v, ((2 * indx) + 2), (mid + 1), right, segTree);

    segTree[indx] = (segTree[(2 * indx) + 1] & segTree[(2 * indx) + 2]);
}

ll queryRange(ll indx, ll low, ll high, ll l, ll r, vector<ll> & segTree)
{
    if(l <= low && r >= high)
    {
        return segTree[indx];
    }

    if(high < l || low > r)
    {
        return identityAnd;
    }

    ll mid = ((low + high) >> 1);
    ll ans1 = queryRange(((2 * indx) + 1), low, mid, l, r, segTree);
    ll ans2 = queryRange(((2 * indx) + 2), (mid + 1), high, l, r, segTree);

    return (ans1 & ans2);
}

void updPoint(ll indx, ll left, ll right, vector<ll> &segTree, ll reqIndx, ll updVal)
{
    if((left == right) && (left == reqIndx))
    {
        segTree[indx] = updVal;
        return;
    }
 
    ll mid = ((left + right) >> 1);
 
    if(reqIndx <= mid) // left
    {
        updPoint(((2 * indx) + 1), left, mid, segTree, reqIndx, updVal);
    }
    else
    {
        updPoint(((2 * indx) + 2), (mid + 1), right, segTree, reqIndx, updVal);
    }
 
    segTree[indx] = min(segTree[(2 * indx) + 1], segTree[(2 * indx) + 2]);
}

// ********* IMP -> Remaining the Range update using lazy propagation __ Do it asap and with utmost prioriryt

// CUSTOM HASH FOR UNORDERED MAP
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
