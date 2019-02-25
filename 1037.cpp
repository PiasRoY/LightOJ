#include <bits/stdc++.h>
using namespace std;

int health[18], dp[1<<18];
int n, endd, ans;
string hit[18];

int sol(int mask)
{
    if(mask == endd) return 0;

    int &ret = dp[mask];
    if(ret != -1) return ret;

    ret = 0x7f7f7f7f;
    int ans, i, j, k;
    for(i = 0; i < n; i++) {
        if(!(mask&(1<<i))) {
            ans = health[i];
            for(j = 0; j < n; j++) {
                if((mask&(1<<j)) && (k = hit[j][i]-'0')) {
                    ans = min(ans, (health[i]+k-1) / k);
                }
            }
            ret = min(ret, ans + sol(mask|(1<<i)));
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
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &health[i]);
        for(int i = 0; i < n; i++)
            cin>>hit[i];

        endd = (1<<n)-1;
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", t, sol(0));
    }
}
