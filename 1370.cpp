#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf 1e+10
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;

ll power(ll b, ll p) {
    if(p == 0) return 1;
    if(p%2 == 0) {
        ull temp = power(b, p/2);
        return temp*temp;
    }
    return b*power(b, p-1);
}

#define MX 1000101
int tot[MX];
int ans[MX];

void phi()
{
    for(int i = 1; i < MX; i++)
    {
        tot[i] = i, ans[i] = -1;
        if(i%2==0) tot[i] -= tot[i]/2;
    }

    for(int i = 3; i < MX; i+=2) {
        if(tot[i]==i) {
            for(int j = i; j < MX; j+=i) {
                tot[j] -= tot[j]/i;
            }
        }
    }

    tot[1] = 0;

    for(int i = 1; i < MX; i++) {
        if(ans[tot[i]] == -1)
            ans[tot[i]] = i;
    }

    for(int i = 1000098-1; i >= 0; i--) {
        if(ans[i] == -1) ans[i] = ans[i+1];
        else if(ans[i] > ans[i+1]) ans[i] = ans[i+1];
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    phi();

    int test;
    scanf("%d", &test);

    int n, q;
    ll sum;
    for(int t = 1; t <= test; t++) {
        scanf("%d", &n);

        sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &q);
            sum += ans[q];
        }
        printf("Case %d: %lld Xukha\n", t, sum);
    }
}
