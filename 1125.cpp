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

ll arr[202], dp[202][22][12];
ll n, d, m, q;

ll call(ll x, ll mod_d, ll taken)
{
    if(x == n)
    {
        if(mod_d == 0 && taken == m) return 1;
        else return 0;
    }
    else if(taken == m) {
        if(mod_d == 0) return 1;
        else return 0;
    }
    else if(dp[x][mod_d][taken] != -1) return dp[x][mod_d][taken];

    ll ret1 = call(x+1, mod_d, taken);
    ll ret2 = call(x+1, (((mod_d+arr[x])%d)+d)%d, taken+1);

    return dp[x][mod_d][taken] = ret1+ret2;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++)
    {
        scanf("%lld %lld", &n, &q);

        for(int i = 0; i < n; i++)
            scanf("%lld", &arr[i]);

        printf("Case %d:\n", t);
        while(q--)
        {
            memset(dp, -1, sizeof dp);
            scanf("%lld %lld", &d, &m);
            printf("%lld\n", call(0, 0, 0));
        }
    }
}
