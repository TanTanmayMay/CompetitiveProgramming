#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll get_mex(vector<ll> &a) {ll m = 0; set<ll> st(a.begin(), a.end()); while(st.count(m)) ++m; return m;}

void tantanmaymay()
{
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(ll i=0; i<n; i++)
	{
		cin >> v[i];
	}
	ll mx = get_mex(v);
	cout << mx << endl;
	while(1)
	{
		ll inp;
		cin >> inp;
		if(inp == -1)
		{
			break;
		}
		cout << inp << endl;
	}
	return;
}

int main()
{
	ll _ = 1;
	cin >> _;
	while(_--) tantanmaymay();
	return 0;
}
