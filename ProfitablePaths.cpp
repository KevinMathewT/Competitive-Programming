// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/dp/KevinMathewT/
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
// find_by_order(k) : Value at kth index dp sorted array. 
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

const ll N = 300010, M = 1e9 + 7;
ll n, a[N], dp[N], d[N], leaves;
vector<ll> T[N], paths;

ll dfs(ll u, ll p) {
	if (d[u] == 1) {
		dp[u] = 1;
		return dp[u];
	}

	dp[u] = 0;
	for (ll v : T[u])
		if (v != p)
			dp[u] += dfs(v, u);

	return dp[u];
}

void dfs1(ll u, ll p) {
	ll sum = dp[u] * (leaves - dp[u]);

	ll add = 0;
	for (ll v : T[u])
		if (v != p)
			add += dp[v] * (dp[u] - dp[v]);

	sum += add / 2;
	paths.push_back(sum);

	for (ll v : T[u])
		if (v != p)
			dfs1(v, u);
}

void solve(){
	cin >> n;
	fi (0, n - 1) cin >> a[i];
	fi (1, n) {
		T[i].clear();
		d[i] = 0;
		dp[i] = 0;
	}
	paths.clear();
	leaves = 0;

	fi (1, n - 1) {
		ll u, v; cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
		d[u]++; d[v]++;
	}

	if (n == 1) {
		cout << 0 << "\n";
		return;
	} else if (n == 2) {
		cout << a[0] + a[1] << "\n";
		return;
	}

	ll root;
	fi (1, n) if (d[i] > 1) {
		root = i;
		break;
	}

	dfs(root, 0);
	leaves = dp[root];
	dfs1(root, 0);

	sort(paths.begin(), paths.end());
	sort(a, a + n);

	ll ans = 0;
	fi (0, n - 1)
		ans = (ans + (((paths[i] % M) * (a[i] % M)) % M)) % M;
	cout << ans << "\n";
}

int main(){
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