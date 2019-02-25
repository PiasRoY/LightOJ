#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define MX 100005
#define pi acos(-1)
#define inf 1000000000
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pii pair<int, int>
#define mod 100000007

int l, endd;
int dp[16][65536];
pair <int, int> st;
vector <pair<int, int> > gold;

bool check(int n, int pos)
{
	return (bool) (n & (1<<pos));
}

int dist(pii a, pii b)
{
	return max(abs(a.ff-b.ff), abs(a.ss-b.ss));
}

int call(int pos, int mask)
{
	if(mask == endd) {
		return dist(gold[pos], st);
	}
	if(dp[pos][mask] != -1) return dp[pos][mask];

	int ret = inf;
	for(int i = 0; i < l; i++) {
		if(!check(mask, i)) {
			ret = min(ret, dist(gold[pos], gold[i]) + call(i, mask | (1<<i)));
		}
	}

	return dp[pos][mask] = ret;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int test;
	cin>>test;

	int r, c;
	for(int t = 1; t <= test; t++) {
		cin>>r>>c;

		char ch;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				cin>>ch;

				if(ch == 'g') gold.pb(mk(i, j));
				else if(ch == 'x') st.ff = i, st.ss = j;
			}
		}

		memset(dp, -1, sizeof dp);

		int ans = inf;
		l = gold.size(), endd = (1<<l)-1;
		for(int i = 0; i < gold.size(); i++) {
			ans = min(ans, dist(st, gold[i]) + call(i, 1<<i));
		}

		if(ans == inf) printf("Case %d: %d\n", t, 0);
		else printf("Case %d: %d\n", t, ans);

		//clearing
		gold.clear();
	}
}
