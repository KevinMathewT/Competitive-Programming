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

class SegmentTree {
public:
	struct node {

	};
	node null_node;
	vector<node> T;
	vector<ll> arr;
	ll n;

	SegmentTree(vector<ll> _a) {
		arr = _a;
		n = _a.size();
		T = vector<node>(4 * n);
	}

	// Check if two nodes are equal
	bool isEqual(node a, node b) {
		// Logic
		return true;
	}

	// Merge two nodes
	node merge(node a, node b) {
		if (isEqual(a, null_node)) return b;
		if (isEqual(b, null_node)) return a;
		node ret;

		// Logic

		return ret;
	}

	void initNullNode() {
		// Random Values for null node
	}

	void build(ll i, ll l, ll r) {
		if (l == r) {
			// Logic for arr[l]

			return;
		}

		ll m = (l + r) / 2;
		build(2 * i, l, m);
		build((2 * i) + 1, m + 1, r);
		T[i] = merge(
			T[2 * i], 
			T[2 * i + 1]
		);
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
			// Logic for a[l]

			return;
		}

		ll m = (l + r) / 2;
		if (p <= m) update(2 * i, l, m, p, x);
		else update(2 * i + 1, m + 1, r, p, x);
		T[i] = merge(T[2 * i], T[2 * i + 1]);
	}

	void init() {
		initNullNode();
		build(1, 0, n - 1);
	}
};

ll n, m;
vector<ll> a, b;

void solve() {
	cin >> n >> m;
	a = vector<ll> (n, 0);
	b = vector<ll> (m, 0);
	fi (0, n - 1) cin >> a[i];
	fi (0, m - 1) cin >> b[i];

	SegmentTree S(a);
	S.init();

	
}

int main(){
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