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

ll power(ll b, ll p) {
    ll res = 1, x = b;
    while(p) {
        if(p & 1) res = res * x;
        x = x*x, p >>= 1;
    }
    return res;
}

string s;
int dp[55][4][6], l;
int call(int pos, int vow, int cont)
{
	// cout<<pos<<" "<<vow<<" "<<cont<<endl;
	if(vow == 3 || cont == 5) return 0;
	if(pos == l) return 1;
	if(dp[pos][vow][cont] != -1) return dp[pos][vow][cont];

	int ret;
	if(s[pos] == 'A' || s[pos] == 'E' || s[pos] == 'I' || s[pos] == 'O' || s[pos] == 'U') {
		ret = call(pos+1, vow+1, 0);
	}
	else if(s[pos] == '?') {
		int ret1 = call(pos+1, 0, cont+1);
		int ret2 = call(pos+1, vow+1, 0);
		// cout<<"Double "<<pos<<" "<<ret1<<" "<<ret2<<endl;
		if(ret1 == 0 && ret2 == 0) ret = 0;
		else if(ret1 == 1 && ret2 == 1) ret = 1;
		else ret = 2;
	}
	else {
		ret = call(pos+1, 0, cont+1);
	}

	return dp[pos][vow][cont] = ret;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++) {
    	cin>>s;
    	l = s.size();

    	memset(dp, -1, sizeof dp);
	    int ret = call(0, 0, 0);

	    printf("Case %d: ", t);
	    if(ret == 0) printf("BAD\n");
	    else if(ret == 1) printf("GOOD\n");
	    else printf("MIXED\n");
    }
}
