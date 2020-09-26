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
ll n, q, a[N];
struct node {
	ll pref, suff, max, tot;
};
node null_node;
node T[4 * N];

bool isEqual(node a, node b) {
	if (a.pref != b.pref) return false;
	if (a.suff != b.suff) return false;
	if (a.max != b.max) return false;
	if (a.tot != b.tot) return false;
	return true;
}

node merge(node a, node b) {
	if (isEqual(a, null_node)) return b;
	if (isEqual(b, null_node)) return a;
	node ret;
	ret.pref = max(a.pref, a.tot + b.pref);
	ret.suff = max(b.suff, a.suff + b.tot);
	ret.max = max(a.max, max(b.max, a.suff + b.pref));
	ret.tot = a.tot + b.tot;
	return ret;
}

void build(ll i, ll l, ll r) {
	if (l == r) {
		T[i].pref = a[l];
		T[i].suff = a[l];
		T[i].max = a[l];
		T[i].tot = a[l];
		return;
	}

	ll m = (l + r) / 2;
	build(2 * i, l, m);
	build((2 * i) + 1, m + 1, r);
	T[i] = merge(T[2 * i], T[2 * i + 1]);
}

node query(ll i, ll l, ll r, ll a, ll b) {
	if (r < a || l > b) return null_node;
	if (l >= a and r <= b) return T[i];
	ll m = (l + r) / 2;
	return merge(
		query(2 * i, l, m, a, b),
		query(2 * i + 1, m + 1, r, a, b)
	);
}

void update(ll i, ll l, ll r, ll p, ll x) {
	if (l == r) {
		T[i].pref = x;
		T[i].suff = x;
		T[i].max = x;
		T[i].tot = x;
		return;
	}

	ll m = (l + r) / 2;
	if (p <= m) update(2 * i, l, m, p, x);
	else update(2 * i + 1, m + 1, r, p, x);
	T[i] = merge(T[2 * i], T[2 * i + 1]);
}

void solve(){
	null_node.pref = -289374;
	null_node.suff = -289374;
	null_node.max = -289374;
	null_node.tot = -289374;

	cin >> n >> q;
	fi (0, n - 1) cin >> a[i];

	build(1, 0, n - 1);

	while (q--) {
		char c; cin >> c;
		if (c == 'Q') {
			ll l, r; cin >> l >> r; l--; r--;
			ll left = 0, mid = 0, right = 0;
			if (l != 0) left = query(1, 0, n - 1, 0, l - 1).suff;
			mid = query(1, 0, n - 1, l, r).tot;
			if (r != n - 1) right = query(1, 0, n - 1, r + 1, n - 1).pref;

			if (left > 0) mid += left;
			if (right > 0) mid += right;
			cout << mid << '\n';
		} else {
			ll p, v; cin >> p >> v; p--;
			update(1, 0, n - 1, p, v);
		}
	}
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