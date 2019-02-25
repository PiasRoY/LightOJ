#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf 1e+10
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll, ll> pll;

ll bigmod (ll b, ll p, ll m ) {
    ll res = 1 % m, x = b % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}

ll dg(char ch)
{
	if(ch >= '0' && ch <= '9')
		return ch - '0';

	return (ch - 'A') + 10;
}

ll dp[65540][22], base, k, l, endd;
string s;
ll call(int mask, ll mod_k)
{
	// cout<<mask<<" "<<mod_k<<endl;
	if(mask == endd)
		return mod_k == 0;

	if(dp[mask][mod_k] != -1)
		return dp[mask][mod_k];

	ll ret = 0, exp = __builtin_popcount(mask);
	for(int i = 0; i < l; i++) {
		int x = 1<<i;
		if((mask & x) == 0) {
			ret += call(mask|x, (mod_k % k + ((dg(s[i]) % k) * bigmod(base, exp, k)) % k) % k);
		}
	}

	return dp[mask][mod_k] = ret;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++) {
    	scanf("%lld %lld", &base, &k);

    	cin>>s;
    	l = s.size();
    	endd = (1 << l)-1;

    	memset(dp, -1, sizeof dp);
    	printf("Case %d: %lld\n", t, call(0, 0));
    }
}
