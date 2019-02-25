#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf 1e+10
typedef unsigned long long llu;

#define MX 3000005
llu tot[MX], res[MX];
void phi_sieve()
{
    for(int i = 1; i < MX; i++) {
        tot[i] = i;
        if(i%2==0) tot[i] -= tot[i]/2;
    }

    for(int i = 3; i < MX; i+=2) {
        if(tot[i] == i) {
            for(int j = i; j < MX; j+=i) {
                tot[j] -= tot[j]/i;
            }
        }
    }

    for(int i = 1; i < MX; i++)
        for(int j = i; j < MX; j += i)
            res[j] += (i*tot[i]);

    for(int i = 1; i < MX; i++)
        res[i]--, res[i] /= 2, res[i] *= i;

    for(int i = 2; i < MX; i++)
        res[i] += res[i-1];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    phi_sieve();

    int test;
    scanf("%d", &test);

    llu n;
    for(int t = 1; t <= test; t++) {
        scanf("%llu", &n);

        printf("Case %d: %llu\n", t, res[n]);
    }
}
