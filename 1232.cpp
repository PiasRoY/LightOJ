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

#define mod 100000007
ll dp[10005], coins[105];
ll coinchange(ll N, ll K)
{
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(ll n = 1; n <= N; n++)
        for(ll k = 1; k <= K; k++) {
            if(coins[n] <= k)
                dp[k] = (dp[k] % mod + dp[k-coins[n]] % mod) % mod;
        }

    return dp[K];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test;
    scanf("%d", &test);

    ll n, k;
    for(int t = 1; t <= test; t++)
    {
        scanf("%lld %lld", &n, &k);

        for(ll i = 1; i <= n; i++)
            scanf("%lld", &coins[i]);

        printf("Case %d: %lld\n", t, coinchange(n, k));
    }
}
