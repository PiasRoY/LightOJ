#include <bits/stdc++.h>
using namespace std;

string str;
bool substr_pal[1002][1002];
int min_cut[1002];
int build(int n)
{
    for(int i = 0; i < n; i++)
        substr_pal[i][i] = true;

    for(int l = 2; l <= n; l++) {
        for(int i = 0; i+l <= n; i++) {
            int j = i+l-1;
            if(l == 2)
                substr_pal[i][j] = (str[i] == str[j]);
            else
                substr_pal[i][j] = (str[i] == str[j]) ? substr_pal[i+1][j-1] : 0;
        }
    }

    for(int i = 0; i < n; i++) {
        if(substr_pal[0][i])
            min_cut[i] = 0;
        else {
            min_cut[i] = INT_MAX;
            for(int j = 0; j < n; j++) {
                if(substr_pal[j+1][i] && 1+min_cut[j] < min_cut[i])
                    min_cut[i] = 1+min_cut[j];
            }
        }
    }

    return min_cut[n-1];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++) {
        cin>>str;

        printf("Case %d: %d\n", t, build(str.size())+1);
    }
}
