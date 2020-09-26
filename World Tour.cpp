// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll j=(a);j>=b;j--)

// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp> 
// #include <functional> // for less 
// #include <iostream> 
// using namespace __gnu_pbds; 
// using namespace std; 
// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// find_by_order(k) : Value at kth index in sorted array. 
// order_of_key(k) : Index of the value k.

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
    os << "[ ";
    for(auto v : V) os << v << " ";
    os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class T> ostream& operator<<(ostream &os, multiset<T> S){
    os << "{ ";
    for(auto s:S) os<<s<<" ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}
template<class L, class R> ostream& operator<<(ostream &os, unordered_map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}


const ll N = 3010, M = 1e9 + 7;
ll n, m, f[N][3][2], d[N], r[N][3][2], adj[N][N];
vector<ll> G[N], R[N];

void getFarthest(ll u) {
	fi (0, 2) fj (0, 1) f[u][i][j] = r[u][i][j] = -1;

	queue<pair<ll, ll> > q;
	q.push({u, 0});
	fi (0, n - 1) d[i] = -1;
	d[u] = 0;

	while (!q.empty()) {
		auto top = q.front(); q.pop();
		d[top.F] = top.S;

		for (ll v : G[top.F])
			if (d[v] == -1) {
				d[v] = top.S + 1;
				q.push({v, d[v]});
			}
	}

	vector<pair<ll, ll> > v;
	fi (0, n - 1) v.push_back({d[i], i});
	fi (0, n - 1) adj[u][i] = d[i];
	sort(v.begin(), v.end());

	fi (0, 2) f[u][i][0] = v[n - i - 1].S, f[u][i][1] = v[n - i - 1].F;

	q.push({u, 0});
	fi (0, n - 1) d[i] = -1;
	d[u] = 0;

	while (!q.empty()) {
		auto top = q.front(); q.pop();
		d[top.F] = top.S;

		for (ll v : R[top.F])
			if (d[v] == -1) {
				d[v] = top.S + 1;
				q.push({v, d[v]});
			}
	}

	v.clear();
	fi (0, n - 1) v.push_back({d[i], i});
	sort(v.begin(), v.end());

	fi (0, 2) r[u][i][0] = v[n - i - 1].S, r[u][i][1] = v[n - i - 1].F;
}

void solve(){
	cin >> n >> m;

	fi(0, m - 1) {
		ll u, v;
		cin >> u >> v; u--; v--;
		G[u].push_back(v);
		R[v].push_back(u);
	}

	fi (0, n - 1) getFarthest(i);

	// fi (0, n - 1) {
	// 	fj (0, n - 1) cout << adj[i][j] << ' ';
	// 	cout << "\n";
	// }

	ll mx = 0, a, b, c, d;

	fi (0, n - 1) fj (0, n - 1) {
		if (i == j) continue;
		if (adj[i][j] != -1) {
			for (ll x=0;x<3;x++)
				for (ll y=0;y<3;y++) {
					if (r[i][x][0] == i || r[i][x][0] == j || r[i][x][0] == f[j][y][0] || f[j][y][0] == i || f[j][y][0] == j) continue;
					else if ((r[i][x][1] + adj[i][j] + f[j][y][1]) > mx) {
						mx = (r[i][x][1] + adj[i][j] + f[j][y][1]);
						a = r[i][x][0];
						b = i;
						c = j;
						d = f[j][y][0];
					}
				}
		} 

		if (adj[j][i] != -1) {
			for (ll x=0;x<3;x++)
				for (ll y=0;y<3;y++) {
					if (r[j][x][0] == i || r[j][x][0] == j || r[j][x][0] == f[i][y][0] || f[i][y][0] == i || f[i][y][0] == j) continue;
					else if ((r[j][x][1] + adj[j][i] + f[i][y][1]) > mx) {
						mx = (r[j][x][1] + adj[j][i] + f[i][y][1]);
						a = r[j][x][0];
						b = j;
						c = i;
						d = f[i][y][0];
					}
				}
		}
	}

	cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}