#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int s[10], m, n;
ll dp[12][12];
ll solve(ll pos, ll ld)
{
    // cout<<pos<<" "<<ld<<endl;
    if(pos == n) return 1;

    ll &ret = dp[pos][ld];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < m; i++) {
        if((pos == 0) || (abs(s[i]-ld) <= 2)) {
            ret += solve(pos+1, s[i]);
        }
    }

    return ret;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++) {
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; i++)
            scanf("%d", &s[i]);

        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n", t, solve(0, 0));
    }
}
