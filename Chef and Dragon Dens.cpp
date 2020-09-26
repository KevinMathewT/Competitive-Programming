// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

#include <bits/stdc++.h>
#include <assert.h> 
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

clock_t start;
double duration;

class MaxSegmentTree {
public:
	struct node {
		ll val;
	};
	node null_node;
	node *T;
	ll *arr;
	ll n;

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

	SumFenwickTree() {

	}

	SumFenwickTree(ll n) {
		this->n = n;
    T = new ll[n];
    fi (0, n - 1) T[i] = 0;
	}

	SumFenwickTree(ll *a, ll n) : SumFenwickTree(n) {
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

  ll query(ll i, ll l, ll r, ll a, ll b) {
  	return query(a, b);
  }

  void update(ll idx, ll delta) {
    for (; idx < n; idx = idx | (idx + 1))
      T[idx] += delta;
  }

  void update(ll i, ll l, ll r, ll p, ll x) {
  	update(p, x);
  }

	void init() {
	}
};

class DragonDenRightSegmentTree {
public:
	struct TreeNode {
		ll size;
		pair<ll, pair<ll, ll> > *P;
		ll *A;
		SumFenwickTree ST;
	};
	TreeNode null_node;
	TreeNode *T;
	vector<ll> arr;
	ll n, *m;

	DragonDenRightSegmentTree(vector<ll>& _a, ll *_m) {
		arr = _a;
		n = _a.size();
		m = _m;
		T = new TreeNode[4 * n];
	}

	// Check if two nodes are equal
	bool isEqual(TreeNode a, TreeNode b) {
		if (a.size == b.size) return true;
		return false;
	}

	// Merge two nodes
	TreeNode merge(TreeNode a, TreeNode b) {
		if (isEqual(a, null_node)) return b;
		if (isEqual(b, null_node)) return a;
		TreeNode ret;

		ret.size = a.size + b.size;
		ret.P = new pair<ll, pair<ll, ll> >[ret.size];
		std::merge(a.P, a.P + a.size, b.P, b.P + b.size, ret.P);
		ret.A = new ll[ret.size];
		fi (0, (ll) ret.size - 1) ret.A[i] = ret.P[i].S.S;
		ret.ST = SumFenwickTree(ret.A, ret.size);
		ret.ST.init();

		return ret;
	}

	void initNullNode() {
		null_node.size = 0;
		null_node.A = new ll[0];
		null_node.P = new pair<ll, pair<ll, ll> >[0];
		null_node.ST = SumFenwickTree(null_node.A, null_node.size);
		// Random Values for null node
	}

	void build(ll i, ll l, ll r) {
		if (l == r) {
			// Logic for a[l]
			
			T[i].size = 1;
			T[i].A = new ll[T[i].size];
			T[i].A[0] = arr[l];
			T[i].P = new pair<ll, pair<ll, ll> >[T[i].size];
			T[i].P[0] = {m[l], {l, arr[l]}};
			T[i].ST = SumFenwickTree(T[i].A, T[i].size);
			T[i].ST.init();
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

	ll query_merge(ll x, ll y) {
		return x + y;
	}

	ll query(ll i, ll l, ll r, ll a, ll b) {
		if (r < a || l > b) return 0LL;
		if (l >= a and r <= b) {
			ll low = 0, high = T[i].size - 1, p = T[i].size;
			while (low <= high) {
				ll mid = (low + high) / 2;
				if (T[i].P[mid].F > b) {
					p = mid;
					high = mid - 1;
				} else {
					low = mid + 1;
				}
			}

			if (p == T[i].size) return 0;
			return T[i].ST.query(1, 0, T[i].ST.n - 1, p, T[i].ST.n - 1);
		}

		ll m = (l + r) / 2;
		return query_merge(
			query(2 * i, l, m, a, b),
			query(2 * i + 1, m + 1, r, a, b)
		);
	}

	ll m_l, ox, p, x;

	void update(ll i, ll l, ll r) {
		ll pos = find(T[i].P, T[i].P + T[i].size, make_pair(m_l, make_pair(p, ox))) - T[i].P;
		assert(T[i].P[pos] == make_pair(m_l, make_pair(p, ox)));
		T[i].P[pos].S.S = x;
		T[i].A[pos] = x;
		T[i].ST.update(1, 0, T[i].ST.n - 1, pos, x - ox);

		if (l == r) return;

		ll m = (l + r) >> 1;
		if (p <= m) update(i << 1, l, m);
		else update((i << 1) + 1, m + 1, r);
	}

	void update(ll i, ll l, ll r, ll m_l, ll ox, ll p, ll x) {
		this->m_l = m_l;
		this->ox = ox;
		this->p = p;
		this->x = x;
		update(1, l, r);
	}

	void init() {
		initNullNode();
		build(1, 0, n - 1);
	}
};

class DragonDenLeftSegmentTree {
public:
	struct TreeNode {
		ll size;
		pair<ll, pair<ll, ll> > *P;
		ll *A;
		SumFenwickTree ST;
	};
	TreeNode null_node;
	TreeNode *T;
	vector<ll> arr;
	ll n, *m;

	DragonDenLeftSegmentTree(vector<ll>& _a, ll *_m) {
		arr = _a;
		n = _a.size();
		m = _m;
		T = new TreeNode[4 * n];
	}

	// Check if two nodes are equal
	bool isEqual(TreeNode a, TreeNode b) {
		if (a.size == b.size) return true;
		return false;
	}

	// Merge two nodes
	TreeNode merge(TreeNode a, TreeNode b) {
		if (isEqual(a, null_node)) return b;
		if (isEqual(b, null_node)) return a;
		TreeNode ret;

		ret.size = a.size + b.size;
		ret.P = new pair<ll, pair<ll, ll> >[ret.size];
		std::merge(a.P, a.P + a.size, b.P, b.P + b.size, ret.P);
		ret.A = new ll[ret.size];
		fi (0, (ll) ret.size - 1) ret.A[i] = ret.P[i].S.S;
		ret.ST = SumFenwickTree(ret.A, ret.size);
		ret.ST.init();

		return ret;
	}

	void initNullNode() {
		null_node.size = 0;
		null_node.A = new ll[0];
		null_node.P = new pair<ll, pair<ll, ll> >[0];
		null_node.ST = SumFenwickTree(null_node.A, null_node.size);
		// Random Values for null node
	}

	void build(ll i, ll l, ll r) {
		if (l == r) {
			// Logic for a[l]
			T[i].size = 1;
			// T[i].A = new ll[T[i].size];
			T[i].A[0] = arr[l];
			T[i].P = new pair<ll, pair<ll, ll> >[T[i].size];
			T[i].P[0] = {m[l], {l, arr[l]}};
			T[i].ST = SumFenwickTree(T[i].A, T[i].size);
			T[i].ST.init();

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

	ll query_merge(ll x, ll y) {
		return x + y;
	}

	ll query(ll i, ll l, ll r, ll a, ll b) {
		if (r < a || l > b) return 0LL;
		if (l >= a and r <= b) {
			ll low = 0, high = T[i].size - 1, p = -1;
			while (low <= high) {
				ll mid = (low + high) / 2;
				if (T[i].P[mid].F < a) {
					p = mid;
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}

			if (p == -1) return 0;
			return T[i].ST.query(1, 0, T[i].ST.n - 1, 0, p);
		}

		ll m = (l + r) / 2;
		return query_merge(
			query(2 * i, l, m, a, b),
			query(2 * i + 1, m + 1, r, a, b)
		);
	}

	ll m_l, ox, p, x;

	void update(ll i, ll l, ll r) {
		ll pos = find(T[i].P, T[i].P + T[i].size, make_pair(m_l, make_pair(p, ox))) - T[i].P;
		assert(T[i].P[pos] == make_pair(m_l, make_pair(p, ox)));
		T[i].P[pos].S.S = x;
		T[i].A[pos] = x;
		T[i].ST.update(1, 0, T[i].ST.n - 1, pos, x - ox);

		if (l == r) return;

		ll m = (l + r) >> 1;
		if (p <= m) update(i << 1, l, m);
		else update((i << 1) + 1, m + 1, r);
	}

	void update(ll i, ll l, ll r, ll m_l, ll ox, ll p, ll x) {
		this->m_l = m_l;
		this->ox = ox;
		this->p = p;
		this->x = x;
		update(1, l, r);
	}

	void init() {
		initNullNode();
		build(1, 0, n - 1);
	}
};

const ll N = 200010, M = 1e9 + 7;
ll n, q;
ll h, a, m_r, m_l;

void solve() {
	cin >> n >> q;	
	fi (0, n - 1) cin >> h[i];
	fi (0, n - 1) cin >> a[i];

	stack<pair<ll, ll>> s;
	s.push({h[n - 1], n - 1});
	m_r[n - 1] = n;
	fid (n - 2, 0) {
		while (s.size() > 0 && s.top().F < h[i]) s.pop();
		if (s.size() == 0) m_r[i] = n;
		else m_r[i] = s.top().S;
		s.push({h[i], i});
	}

	s = stack<pair<ll, ll>>();
	s.push({h[0], 0});
	m_l[0] = -1;
	fi (1, n - 1) {
		while (s.size() > 0 && s.top().F < h[i]) s.pop();
		if (s.size() == 0) m_l[i] = -1;
		else m_l[i] = s.top().S;
		s.push({h[i], i});
	}

  // start = clock();

  DragonDenRightSegmentTree RST(a, m_r);
	RST.init();

	DragonDenLeftSegmentTree LST(a, m_l);
	LST.init();

	MaxSegmentTree MST(h);
	MST.init();
	
	// duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	// cout << "Time: "<< duration <<'\n';
	// start = clock();

	while (q--) {
		ll ch;
		cin >> ch;
		if (ch == 1) {
			ll b, k; cin >> b >> k; b--;
			RST.update(1, 0, n - 1, m_r[b], a[b], b, k);
			LST.update(1, 0, n - 1, m_l[b], a[b], b, k);
			a[b] = k;
		} else if (ch == 2) {
			ll b, c; cin >> b >> c; b--; c--;
			if (b == c) {
				cout << a[b] << "\n";
			} else if (b < c) {
				if (h[b] <= h[c]) cout << "-1\n";
				else if (b != c && b != c - 1 && MST.query(1, 0, n - 1, b + 1, c - 1).val >= h[b]) cout << "-1\n";
				else cout << RST.query(1, 0, n - 1, b, c) << "\n";
			} else {
				if (h[b] <= h[c]) cout << "-1\n";
				else if (b != c && b != c + 1 && MST.query(1, 0, n - 1, c + 1, b - 1).val >= h[b]) cout << "-1\n";
				else cout << LST.query(1, 0, n - 1, c, b) << "\n";
			}
		}
	}

	// duration = (clock() - start) / (double) CLOCKS_PER_SEC;
 //  cout << "Time: "<< duration <<'\n';
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