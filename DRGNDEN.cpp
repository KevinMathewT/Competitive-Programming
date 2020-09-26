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
			// Logic for arr[l]
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

	void update(ll i, ll l, ll r, ll p, ll x) {
		if (l == r) {
			// Logic for a[l]
			T[i].val = x;
			arr[p] = x;
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

class SumFenwickTree {
public:
	ll *T;
	ll n;

	SumFenwickTree(ll n) {
		this->n = n;
		T = new ll[n];
		fi (0, n - 1) T[i] = 0;
	}

	SumFenwickTree(vector<ll> &a) : SumFenwickTree(a.size()) {
		for (ll i = 0; i < n; i++)
    	update(i, a[i]);
	}

	ll query(ll r) {
    ll ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
      ret += T[r];
    return ret;
  }

  ll query(ll l, ll r) {
    return query(r) - query(l - 1);
  }

  void update(ll idx, ll delta) {
    for (; idx < n; idx = idx | (idx + 1))
      T[idx] += delta;
  }

  void update(ll i, ll l, ll r, ll p, ll x) {
  	update(p, x);
  }
};

const ll N = 200010, M = 1e9 + 7;
ll n, q;
ll h[N], a[N], m_r[N], m_l[N], indLO[N], indLC[N], indRO[N], indRC[N];
vector<ll> TR[N], TL[N], dfs_l, dfs_r, TLO, TLC, TRO, TRC;

void dfsl(ll u, ll p) {
	dfs_l.push_back(u);
	indLO[u] = TLO.size();
	TLO.push_back(a[u]);
	TLC.push_back(0);

	for (ll v : TL[u]) if (v != p) dfsl(v, u);

	dfs_l.push_back(u);
	indLC[u] = TLC.size();
	TLO.push_back(0);
	TLC.push_back(a[u]);
}

void dfsr(ll u, ll p) {
	dfs_r.push_back(u);
	indRO[u] = TRO.size();
	TRO.push_back(a[u]);
	TRC.push_back(0);

	for (ll v : TR[u]) if (v != p) dfsr(v, u);

	dfs_r.push_back(u);
	indRC[u] = TRC.size();
	TRO.push_back(0);
	TRC.push_back(a[u]);
}

void solve() {
	cin >> n >> q;
	fi (0, n - 1) cin >> h[i];
	fi (0, n - 1) cin >> a[i];
	a[n] = 0;
	fi (0, n) {
		indLO[i] = -1;
		indLC[i] = -1;
		indRO[i] = -1;
		indRC[i] = -1;
		TL[i].clear();
		TR[i].clear();
	}
	dfs_l.clear();
	dfs_r.clear();
	TLO.clear();
	TLC.clear();
	TRO.clear();
	TRC.clear();

	stack<pair<ll, ll>> s;
	s.push({h[n - 1], n - 1});
	m_r[n - 1] = n;
	fid (n - 2, 0) {
		while (s.size() > 0 && s.top().F <= h[i]) s.pop();
		if (s.size() == 0) m_r[i] = n;
		else m_r[i] = s.top().S;
		s.push({h[i], i});
	}

	s = stack<pair<ll, ll>>();
	s.push({h[0], 0});
	m_l[0] = n;
	fi (1, n - 1) {
		while (s.size() > 0 && s.top().F <= h[i]) s.pop();
		if (s.size() == 0) m_l[i] = n;
		else m_l[i] = s.top().S;
		s.push({h[i], i});
	}

	fi (0, n - 1) {
		TL[(m_l[i] + n + 1) % (n + 1)].push_back(i);
		TL[i].push_back((m_l[i] + n + 1) % (n + 1));
	}
	fi (0, n - 1) {
		TR[(m_r[i] + n + 1) % (n + 1)].push_back(i);
		TR[i].push_back((m_r[i] + n + 1) % (n + 1));
	}

	dfsl(n, -1);
	dfsr(n, -1);

	assert(dfs_l.size() == 2 * n + 2);
	assert(dfs_r.size() == 2 * n + 2);
	assert(TLO.size() == 2 * n + 2);
	assert(TLC.size() == 2 * n + 2);
	assert(TRO.size() == 2 * n + 2);
	assert(TRC.size() == 2 * n + 2);
	fi (0, n) {
		assert(indLO[i] != -1);
		assert(indLC[i] != -1);
		assert(indRO[i] != -1);
		assert(indRC[i] != -1);
	}

	MaxSegmentTree MST(h, n);
	MST.init();
	SumFenwickTree LFTO(TLO);
	SumFenwickTree LFTC(TLC);
	SumFenwickTree RFTO(TRO);
	SumFenwickTree RFTC(TRC);

	while (q--) {
		ll ch;
		cin >> ch;
		if (ch == 1) {
			ll b, k; cin >> b >> k; b--;
			LFTO.update(indLO[b], k - a[b]);
			LFTC.update(indLC[b], k - a[b]);
			RFTO.update(indRO[b], k - a[b]);
			RFTC.update(indRC[b], k - a[b]);
			a[b] = k;
		} 
		else if (ch == 2) {
			ll b, c; cin >> b >> c; b--; c--;
			if (b == c) {
				cout << a[b] << "\n";
			} else if (b < c) {
				if (h[b] <= h[c]) cout << "-1\n";
				else if (b != c && b != c - 1 && MST.query(1, 0, n - 1, b + 1, c - 1).val >= h[b]) cout << "-1\n";
				else cout << LFTO.query(indLO[b], indLO[c]) - LFTC.query(indLO[b], indLO[c]) << "\n";
			} else {
				if (h[b] <= h[c]) cout << "-1\n";
				else if (b != c && b != c + 1 && MST.query(1, 0, n - 1, c + 1, b - 1).val >= h[b]) cout << "-1\n";
				else cout << RFTO.query(indRO[b], indRO[c]) - RFTC.query(indRO[b], indRO[c]) << "\n";
			}
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