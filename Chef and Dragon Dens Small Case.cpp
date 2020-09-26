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

class MaxSegmentTree {
public:
	struct node {
		ll val;
	};
	node null_node;
	node *T;
	ll n, *arr;

	MaxSegmentTree(ll *_a, ll _n) {
		arr = _a;
		n = _n;
		T = new node[4 * n];
	}

	// Check if two nodes are equal
	bool isEqual(node a, node b) {
		// Logic
		if (a.val == b.val) return true;
		return false;
	}

	// Merge two nodes
	node merge(node a, node b) {
		if (isEqual(a, null_node)) return b;
		if (isEqual(b, null_node)) return a;
		node ret;

		ret.val = max(a.val, b.val);

		return ret;
	}

	void initNullNode() {
		null_node.val = LLONG_MIN;
	}

	void build(ll i, ll l, ll r) {
		if (l == r) {
			T[i].val = arr[l];
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

	ll query(ll a, ll b) {
		return query(1, 0, n - 1, a, b).val;
	}

	void init() {
		initNullNode();
		build(1, 0, n - 1);
	}
};

const ll N = 1010, M = 1e9 + 7;
ll n, q, h[N], a[N], m_r[N], m_l[N];

void solve(){
	cin >> n >> q;
	fi (0, n - 1) cin >> h[i];
	fi (0, n - 1) cin >> a[i];

	// stack<pair<ll, ll>> s;
	// s.push({h[n - 1], n - 1});
	// m_r[n - 1] = n;
	// fid (n - 2, 0) {
	// 	while (s.size() > 0 && s.top().F < h[i]) s.pop();
	// 	if (s.size() == 0) m_r[i] = n;
	// 	else m_r[i] = s.top().S;
	// 	s.push({h[i], i});
	// }

	// s = stack<pair<ll, ll>>();
	// s.push({h[0], 0});
	// m_l[0] = n;
	// fi (1, n - 1) {
	// 	while (s.size() > 0 && s.top().F < h[i]) s.pop();
	// 	if (s.size() == 0) m_l[i] = n;
	// 	else m_l[i] = s.top().S;
	// 	s.push({h[i], i});
	// }

	m_l[0] = -1;
	fi (1, n - 1) {
		m_l[i] = -1;
		fjd (i - 1, 0)
			if (h[j] > h[i]) {
				m_l[i] = j;
				break;
			}
	}

	m_r[n - 1] = n;
	fid (n - 2, 0) {
		m_r[i] = n;
		fj (i + 1, n - 1)
			if (h[j] > h[i]) {
				m_r[i] = j;
				break;
			}
	}

	// fi (0, n - 1) cout << m_l[i] << " "; cout << "\n";
	// fi (0, n - 1) cout << m_r[i] << " "; cout << "\n";

	MaxSegmentTree MST(h, n);
	MST.init();

	while (q--) {
		ll ch;
		cin >> ch;
		if (ch == 1) {
			ll b, k; cin >> b >> k; b--;
			a[b] = k;
		} 
		else if (ch == 2) {
			ll b, c; cin >> b >> c; b--; c--;
			if (b != c && h[c] >= h[b]) {
				cout << "-1\n";
				continue;
			}

			if (b != c && b != c - 1 && b != c + 1 && MST.query(min(b, c) + 1, max(b, c) - 1) >= h[b]) {
				cout << "-1\n";
				continue;
			}

			ll currI = c;
			ll taste = 0;
			if (b <= c) {
				while (currI >= b && currI <= c) {
					taste += a[currI], currI = m_l[currI];
				}
			} else {
				while (currI >= c && currI <= b) {
					taste += a[currI], currI = m_r[currI];
				}
			}

			cout << taste << "\n";
		}
	}
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