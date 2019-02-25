#include <bits/stdc++.h>
using namespace std;

#define MX 50
#define pb push_back
typedef long long ll;

int main()
{
	int test;
	cin>>test;

	int occupied[MX];
	bool vis[MX][MX];
	deque <int> rem;
	int x, n, m, time, seat, temp;

	for(int t = 1; t <= test; t++) {
		cin>>n>>m;

		time = 5;

		rem.clear();
		memset(vis, false, sizeof vis);

		for(int i = 1; i <= n; i++) {
			if(i <= m) {
				time += 5;
				vis[i][i] = true;
				occupied[i] = i;
			}
			else rem.pb(i);
		}


		for(seat = 1, time+=5; ; seat++, time+=5) {
			if(seat > m) seat = 1;

			rem.pb(temp = occupied[seat]);

			while(1) {
				x = rem.front();
				rem.pop_front();

				if(!vis[x][seat]) {
					vis[x][seat] = true;
					occupied[seat] = x;
					break;
				}
				else {
					for(int i = 1; i <= m; i++) {
						if(!vis[x][i]) {
							rem.pb(i);
							break;
						}
					}
				}

				if(x == temp) break;
			}

			if(rem.empty()) break;
		}

		printf("Case %d: %d\n", t, time);
	}
}
