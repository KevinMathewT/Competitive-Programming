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
ll n, c[N], inc[N], decr[N];
vector<ll> T[N];
vector<pair<ll, ll> > leaves;

void getAnswer(ll u, ll p) {
	if (T[u].size() == 1 && T[u][0] == p) {
		inc[u] = 0;
		decr[u] = 0;

		if (c[u] > 0) decr[u] = abs(c[u]);
		else inc[u] = abs(c[u]);
		return;
	}

	inc[u] = 0;
	decr[u] = 0;
	ll ret = 0;
	for (ll v : T[u]) if (v != p) getAnswer(v, u);
	for (ll v : T[u]) if (v != p) inc[u] += inc[v], decr[u] += decr[v];

	c[u] += inc[u];
	c[u] -= decr[u];

	if (c[u] > 0) decr[u] += abs(c[u]);
	else inc[u] += abs(c[u]);
	ret += abs(c[u]);
}

void solve(){
	cin >> n;
	fi (1, n - 1) {
		ll u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	fi (1, n) cin >> c[i];

	getAnswer(1, -1);
	cout << abs(c[1]) + inc[1] + decr[1] << "\n";
}

int main() {
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}