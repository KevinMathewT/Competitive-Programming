#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll r, c, forest[1010][1010], dist[1010][1010], vis[1010][1010], sx, sy, ex, ey;
vector<pair<ll, pair<ll, ll> > > monsters;

void solve(){
	cin >> r >> c;
	for(ll i=0;i<r;i++){
		for(ll j=0;j<c;j++){
			dist[i][j] = LLONG_MAX;
			vis[i][j] = 0;
			char c;
			cin >> c;
			// cout << c << " ";
			if(!(c == 'T'))
				forest[i][j] = 0;
			else
				forest[i][j] = 1;
			if(c == 'S'){
				sx = i; sy = j;
			}
			if(c == 'E'){
				ex = i; ey = j;
			}
			if(1 <= (c - '0') && (c - '0') <= 9){
				monsters.push_back(make_pair((c - '0'), make_pair(i, j)));
			}
		}
		// cout << "\n";
	}

	queue<pair<ll, pair<ll, ll> > > q;
	q.push(make_pair(0, make_pair(ex, ey)));

	// cout << ex << " " << ey << "\n";
	// cout << sx << " " << sy << "\n";

	while(!q.empty()){
		pair<ll, pair<ll, ll> > p = q.front(); q.pop();
		ll d = p.first;
		ll x = p.second.first, y = p.second.second;
		if(vis[x][y] == 1)
			continue;
		vis[x][y] = 1;
		dist[x][y] = d;

		for(ll i=0;i<2;i++)
			for(ll j=0;j<2;j++){
				ll xadd, yadd;
				if(i == 0){
					xadd = 0;
					if(j == 0)
						yadd = -1;
					else
						yadd = 1;
				}
				else{
					yadd = 0;
					if(j == 0)
						xadd = -1;
					else
						xadd = 1;
				}
				if((x + xadd) < 0 || (x + xadd) >= r || (y + yadd) < 0 || (y + yadd) >= c || forest[x+xadd][y+yadd] == 1 || vis[x+xadd][y+yadd] == 1)
					continue;
				q.push(make_pair(d + 1, make_pair(x + xadd, y + yadd)));
			}
	}

	ll travel = dist[sx][sy];

	// for(ll i=0;i<r;i++){
	// 	for(ll j=0;j<c;j++)
	// 		cout << dist[i][j] << "-";
	// 	cout << "\n";
	// }

	// cout << travel << "\n";
	ll fights = 0;
	for(ll i=0;i<monsters.size();i++){
		// cout << monsters[i].first << " " << monsters[i].second.first << " " << monsters[i].second.second << " " << dist[monsters[i].second.first][monsters[i].second.second] << "\n";
		if(dist[monsters[i].second.first][monsters[i].second.second] <= travel)
			fights += monsters[i].first;
	}

	cout << fights << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}