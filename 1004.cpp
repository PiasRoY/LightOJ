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

ll N;
ll arr[205][105], dp[205][105];

ll call(ll x, ll y)
{
    if(y < 1 || y > 2*N-x) return 0;
    if(x == 2*N-1) return arr[x][y];
    if(dp[x][y] != -1) return dp[x][y];

    if(x < N)
        return dp[x][y] = arr[x][y] + max(call(x+1, y), call(x+1, y+1));

    else
       return dp[x][y] = arr[x][y] + max(call(x+1, y-1), call(x+1, y));
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++)
    {
        memset(dp, -1, sizeof dp);
        scanf("%lld", &N);
        for(ll i = 1; i <= N; i++) {
            for(ll j = 1; j <= i; j++) {
                scanf("%lld", &arr[i][j]);
            }
        }
        for(ll i = N+1; i < 2*N; i++) {
            for(ll j = 1; j <= 2*N-i; j++) {
                scanf("%lld", &arr[i][j]);
            }
        }

        printf("Case %d: %lld\n", t, call(1, 1));
    }
}
