#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, ti[510], to[510], a[510][4], g[510][510], flow, s, t, p[510];
pair<ll, ll> pll[510];
vector<ll> graph[510];
string st;

ll bfs(){
	fill(p, p + n + 2, -1);
	queue<ll> q;
	q.push(s);

	while(!q.empty()){
		ll u = q.front(); q.pop();

		for(ll i=0;i<=n+1;i++)
			if(g[u][i] == 1 && p[i] == -1){
				q.push(i), p[i] = u;
				if(i == t)
					return 1;
			}
	}

	return 0;
}

void solve(){
	flow = 0;
	cin >> n;

	s = n;
	t = n + 1;

	cin.ignore(256, '\n');

	for(ll i=0;i<n;i++){
		cin >> st;
		// cout << s << "\n";
		pll[i].F = stoll(st.substr(0, 2)) * 60 + stoll(st.substr(3, 2));

		cout << pll[i].F << " ";

		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];

		pll[i].S = pll[i].F + abs(a[i][2] - a[i][0]) + abs(a[i][1] - a[i][3]);
		cout << pll[i].S << "\n";
	}

	sort(pll, pll + n);
	for(ll i=0;i<=n+1;i++)
		for(ll j=0;j<=n+1;j++)
			g[i][j] = 0;

	for(ll i=0;i<n;i++)
		for(ll j=i+1;j<n;j++){
			if((pll[i].S + abs(a[i][2] - a[j][0]) + abs(a[i][3] - a[j][1])) < (pll[j].F))
				graph[i].push_back(j);
				g[i][j] = 1;
				g[s][i] = 1;
				g[j][t] = 1;
		}

	for(ll i=0;i<=n+1;i++){
		for(ll j=0;j<=n+1;j++)
			cout << g[i][j] << ' ';
		cout << "\n";
	}

	while(bfs()){
		flow++;
		ll v = t;
		while(v != s){
			g[p[v]][v]--;
			g[v][p[v]]++;
			v = p[v];
		}
	}

	cout << flow << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}