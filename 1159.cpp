#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string s1, s2, s3;
long long lcs[52][52][52];

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

 	int test;
 	cin>>test;

 	for(int t = 1; t <= test; t++) {
 		cin>>s1>>s2>>s3;

 		int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
 		for(int i = 0; i <= l1; i++) {
 			for(int j = 0; j <= l2; j++) {
 				for(int k = 0; k <= l3; k++) {
 					if(i == 0 || j == 0 || k == 0)
 						lcs[i][j][k] = 0;
 					else if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
 						lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
 					else
 						lcs[i][j][k] = max(max(lcs[i-1][j][k], lcs[i][j-1][k]), lcs[i][j][k-1]);
 				}
 			}
 		}

 		printf("Case %d: %lld\n", t, lcs[l1][l2][l3]);
 	}
}
