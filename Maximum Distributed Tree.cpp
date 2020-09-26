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
ll n, m, a[N], dp[N], assign[N];
vector<ll> T[N], z;

ll dfs(ll u, ll p) {
	ll t = 0;
	for (ll v : T[u]) if (v != p) t = (t + dfs(v, u));
	return dp[u] = (t + 1);
}

void dfs1(ll u, ll p) {
	for (ll v : T[u]) if (v != p) z.push_back(dp[v] * (n - dp[v]));
	for (ll v : T[u]) if (v != p) dfs1(v, u);
}

void solve(){
	cin >> n;
	z.clear();
	fi (0, n - 1) dp[i] = 0, T[i].clear(), assign[i] = 1;
	fi (0, n - 2) {
		ll u, v; cin >> u >> v; u--; v--;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	cin >> m;
	fi (0, m - 1) cin >> a[i];

	dfs(0, -1);
	dfs1(0, -1);

	sort(z.begin(), z.end());
	sort(a, a + m);

	if (m <= z.size()) {
		ll j = 0;
		fi (z.size() - m, z.size() - 1) assign[i] = a[j++];
	} else {
		ll j = 0;
		fi (0, (ll) z.size() - 2) assign[i] = a[j++];

		ll k = 1;
		fi (j, m - 1) k = (k * a[i]) % M;

		assign[z.size() - 1] = k;
	}

	ll tot = 0;
	fi (0, (ll) z.size() - 1) tot = (tot + ((assign[i] * z[i]) % M)) % M;

	cout << tot << "\n";
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