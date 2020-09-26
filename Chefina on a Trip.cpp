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

const ll N = 100010, M = 1e9 + 7;
ll n, q, a[N], p[N][40], incr[N], decr[N], d[N]; 
vector<ll> T[N];

void dfs(ll u, ll parent, ll dist) {
	p[u][0] = parent;
	d[u] = dist;

	if (parent == 0) incr[u] = u, decr[u] = u;
	else {
		ll val = a[p[u][0]];
		if (val > a[u]) incr[u] = incr[p[u][0]], decr[u] = u;
		else if (val < a[u]) decr[u] = decr[p[u][0]], incr[u] = u;
		else incr[u] = u, decr[u] = u;
	}

	for (ll v : T[u])
		if (v != parent)
			dfs(v, u, dist + 1);
}

ll raise(ll x, ll h) {
	fid (39, 0) if ((1LL << i) <= h) {
		x = p[x][i];
		h -= (1LL << i);
	}

	return x;
}

ll getLCA(ll x, ll y) {
	if (d[x] > d[y]) swap(x, y);
	y = raise(y, d[y] - d[x]);
	if (x == y) return x;

	fid (39, 0) if (p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
	return p[x][0];
}

// parent of x is y
bool isParent(ll x, ll y) {
	return getLCA(x, y) == y;
}

bool getAnswer(ll x, ll y) {
	ll lca = getLCA(x, y);
	ll n1 = incr[x];
	if (isParent(lca, n1)) {
		ll n2 = incr[y];
		if (isParent(lca, n2)) return true;
		ll n3 = decr[n2];
		if (isParent(lca, n3)) return true;
		return false;
	} else {
		if (isParent(lca, decr[n1]) && isParent(lca, incr[y])) return true;
		return false;
	}
}

void solve(){
	cin >> n >> q;
	fi (1, n) T[i].clear();
	fi (1, n - 1) {
		ll u, v; cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	fi (1, n) cin >> a[i];
	fi (0, N - 1) fj (0, 30) p[i][j] = 0;
	fill (incr, incr + n + 1, 0LL);
	fill (decr, decr + n + 1, 0LL);
	fill (d, d + n + 1, 0LL);
	dfs(1, 0, 1);
	fi (1, 39) fj (1, n) p[j][i] = p[p[j][i - 1]][i - 1];
	// fi (1, n) {
	// 	fj (0, 39) cout << p[i][j] << " ";
	// 	cout << '\n';
	// }

	while (q--) {
		ll x, y;
		cin >> x >> y;
		cout << getAnswer(x, y);
	}
	cout << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}