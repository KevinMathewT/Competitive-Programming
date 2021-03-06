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
		ll *A, *FC;
		SumFenwickTree ST;
	};
	TreeNode null_node;
	TreeNode *T;
	ll n, *m, *arr;

	DragonDenRightSegmentTree(ll *_a,  ll *_m, ll _n) {
		arr = _a;
		n = _n;
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
		ret.A = new ll[ret.size];
		ret.FC = new ll[ret.size];

		ll i = 0, j = 0, k = 0;
    while (i < a.size && j < b.size) {
      if (a.P[i] < b.P[j]) ret.P[k++] = a.P[i++], ret.FC[k - 1] = i - 1;
      else ret.P[k++] = b.P[j++], ret.FC[k - 1] = j - 1;
    }
    while (i < a.size) ret.P[k++] = a.P[i++], ret.FC[k - 1] = i - 1;
    while (j < b.size) ret.P[k++] = b.P[j++], ret.FC[k - 1] = j - 1;


		fi (0, (ll) ret.size - 1) ret.A[i] = ret.P[i].S.S;
		ret.ST = SumFenwickTree(ret.A, ret.size);
		ret.ST.init();

    // fi (0, ret.size - 1) cout << ret.A[i] << ' ';
    // cout << "\n";
    // fi (0, ret.size - 1) cout << ret.FC[i] << ' ';
    // cout << "\n";
    // fi (0, a.size - 1) cout << a.A[i] << ' ';
    // cout << "\n";
    // fi (0, b.size - 1) cout << b.A[i] << ' ';
    // cout << "\n";
		return ret;
	}

	void initNullNode() {
		null_node.size = 0;
		null_node.A = new ll[0];
		null_node.FC = new ll[0];
		null_node.P = new pair<ll, pair<ll, ll> >[0];
		null_node.ST = SumFenwickTree(null_node.A, null_node.size);
		// Random Values for null node
	}

	void build() {  // build the tree
  	fid(n - 1, 1) T[i] = merge(T[i<<1], T[i<<1|1]);
	}

	ll query_merge(ll x, ll y) {
		return x + y;
	}

	ll query(ll l, ll r) {  // sum on interval [l, r)
		ll l_o = l, r_o = r;
		r += 1;
	  ll res = 0;
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) {
	    	ll i = l;

				ll low = 0, high = T[i].size - 1, p = T[i].size;
				while (low <= high) {
					ll mid = (low + high) / 2;
					if (T[i].P[mid].F > r_o) {
						p = mid;
						high = mid - 1;
					} else {
						low = mid + 1;
					}
				}

				if (p == T[i].size) res += 0;
				else res += T[i].ST.query(1, 0, T[i].ST.n - 1, p, T[i].ST.n - 1);

	    	l++;
	    }
	    if (r&1) {
	    	ll i = r - 1;

				ll low = 0, high = T[i].size - 1, p = T[i].size;
				while (low <= high) {
					ll mid = (low + high) / 2;
					if (T[i].P[mid].F > r_o) {
						p = mid;
						high = mid - 1;
					} else {
						low = mid + 1;
					}
				}

				if (p == T[i].size) res += 0;
				else res += T[i].ST.query(1, 0, T[i].ST.n - 1, p, T[i].ST.n - 1);

	    	--r;
	    }
	  }

	  return res;
	}

	ll query(ll i, ll l, ll r, ll a, ll b) {
		return query(a, b);
	}

	ll m_l, ox, p, x;

	void modify(ll i, ll value) { 
		i += n;
		// cout << i << "--\n";

  	for (; i > 1; i >>= 1) {
  		// if (pos == -1) {
			ll low = 0, high = T[i].size - 1, mid, pos;
			while (low <= high) {
				mid = (low + high) >> 1;
				if (T[i].P[mid].F < m_l) low = mid + 1;
				else if (T[i].P[mid].F == m_l) {
					if (T[i].P[mid].S.F < p) low = mid + 1;
					else if (T[i].P[mid].S.F == p) { pos = mid; break; }
					else high = mid - 1;
				}
				else high = mid - 1;
			}
			// }

			// cout << make_pair(m_l, make_pair(p, ox)) << "\n";
			// fj (0, T[i].size - 1) cout << T[i].P[j] << " ";
			// cout << "\n";

			assert(T[i].P[pos] == make_pair(m_l, make_pair(p, ox)));
			T[i].P[pos].S.S = x;
			T[i].A[pos] = x;
			T[i].ST.update(1, 0, T[i].ST.n - 1, pos, x - ox);
  	}
	}

	void update(ll i, ll l, ll r, ll pos) {
		modify(p, x);
		// ll pos = lower_bound(T[i].P, T[i].P + T[i].size, make_pair(m_l, make_pair(p, 0LL))) - T[i].P;
		// if (pos == -1) {
		// 	ll low = 0, high = T[i].size - 1, mid;
		// 	while (low <= high) {
		// 		mid = (low + high) >> 1;
		// 		if (T[i].P[mid].F < m_l) low = mid + 1;
		// 		else if (T[i].P[mid].F == m_l) {
		// 			if (T[i].P[mid].S.F < p) low = mid + 1;
		// 			else if (T[i].P[mid].S.F == p) { pos = mid; break; }
		// 			else high = mid - 1;
		// 		}
		// 		else high = mid - 1;
		// 	}
		// }
		// assert(T[i].P[pos] == make_pair(m_l, make_pair(p, ox)));
		// T[i].P[pos].S.S = x;
		// T[i].A[pos] = x;
		// T[i].ST.update(1, 0, T[i].ST.n - 1, pos, x - ox);
		// // cout << pos << " ";
		// pos = T[i].FC[pos];
		// // cout << pos << "\n";
		// // pos = -1;

		// if (l == r) return;

		// ll m = (l + r) >> 1;
		// if (p <= m) update(i << 1, l, m, pos);
		// else update((i << 1) + 1, m + 1, r, pos);
	}

	void update(ll i, ll l, ll r, ll m_l, ll ox, ll p, ll x) {
		this->m_l = m_l;
		this->ox = ox;
		this->p = p;
		this->x = x;
		update(1, l, r, -1);
	}

	void init() {
		fi (0, n - 1) {
			T[n + i].size = 1;
			T[n + i].A = new ll[1];
			T[n + i].FC = new ll[1];
			T[n + i].A[0] = arr[i];
			T[n + i].FC[0] = 0;
			T[n + i].P = new pair<ll, pair<ll, ll> >[T[n + i].size];
			T[n + i].P[0] = {m[i], {i, arr[i]}};
			T[n + i].ST = SumFenwickTree(T[n + i].A, T[n + i].size);
			T[n + i].ST.init();
			// fj (0, T[n + i].size - 1) cout << T[n + i].P[j] << " ";
			// cout << "\n";
		}
		initNullNode();
		build();
		// fi (1, 2 * n) {
		// 	fj (0, T[i].size - 1) cout << T[i].P[j] << ' ';
		// 	cout << "\n";
		// }
	}
};

class DragonDenLeftSegmentTree {
public:
	struct TreeNode {
		ll size;
		pair<ll, pair<ll, ll> > *P;
		ll *A, *FC;
		SumFenwickTree ST;
	};
	TreeNode null_node;
	TreeNode *T;
	ll n, *m, *arr;

	DragonDenLeftSegmentTree(ll *_a, ll *_m, ll _n) {
		arr = _a;
		n = _n;
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

		ret.size = a.size + b.size;
		ret.P = new pair<ll, pair<ll, ll> >[ret.size];
		ret.A = new ll[ret.size];
		ret.FC = new ll[ret.size];

		ll i = 0, j = 0, k = 0;
    while (i < a.size && j < b.size) {
      if (a.P[i] < b.P[j]) ret.P[k++] = a.P[i++], ret.FC[k - 1] = i - 1;
      else ret.P[k++] = b.P[j++], ret.FC[k - 1] = j - 1;
    }
    while (i < a.size) ret.P[k++] = a.P[i++], ret.FC[k - 1] = i - 1;
    while (j < b.size) ret.P[k++] = b.P[j++], ret.FC[k - 1] = j - 1;


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

	void build() {  // build the tree
  	fid(n - 1, 1) T[i] = merge(T[i<<1], T[i<<1|1]);
	}

	ll query_merge(ll x, ll y) {
		return x + y;
	}

	ll query(ll l, ll r) {
		ll l_o = l, r_o = r;
		r += 1;
	  ll res = 0;
	  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
	    if (l&1) {
	    	ll i = l;

				ll low = 0, high = T[i].size - 1, p = -1;
				while (low <= high) {
					ll mid = (low + high) / 2;
					if (T[i].P[mid].F < l_o) {
						p = mid;
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				}

				if (p == -1) res += 0;
				else res += T[i].ST.query(1, 0, T[i].ST.n - 1, 0, p);
	    	l++;
	    }
	    if (r&1) {
	    	ll i = r - 1;

				ll low = 0, high = T[i].size - 1, p = -1;
				while (low <= high) {
					ll mid = (low + high) / 2;
					if (T[i].P[mid].F < l_o) {
						p = mid;
						low = mid + 1;
					} else {
						high = mid - 1;
					}
				}

				if (p == -1) res += 0;
				else res += T[i].ST.query(1, 0, T[i].ST.n - 1, 0, p);
	    	--r;
	    }
	  }
	  return res;
	}

	ll query(ll i, ll l, ll r, ll a, ll b) {
		return query(a, b);
	}

	ll m_l, ox, p, x;

	void modify(ll i, ll value) { 
  	for (i += n; i > 1; i >>= 1) {
			ll low = 0, high = T[i].size - 1, mid, pos;
			while (low <= high) {
				mid = (low + high) >> 1;
				if (T[i].P[mid].F < m_l) low = mid + 1;
				else if (T[i].P[mid].F == m_l) {
					if (T[i].P[mid].S.F < p) low = mid + 1;
					else if (T[i].P[mid].S.F == p) { pos = mid; break; }
					else high = mid - 1;
				}
				else high = mid - 1;
			}

			assert(T[i].P[pos] == make_pair(m_l, make_pair(p, ox)));
			T[i].P[pos].S.S = x;
			T[i].A[pos] = x;
			T[i].ST.update(1, 0, T[i].ST.n - 1, pos, x - ox);
  	}
	}

	void update(ll i, ll l, ll r, ll m_l, ll ox, ll p, ll x) {
		this->m_l = m_l;
		this->ox = ox;
		this->p = p;
		this->x = x;
		modify(p, x);
	}

	void init() {
		fi (0, n - 1) {
			T[n + i].size = 1;
			T[n + i].A = new ll[1];
			T[n + i].FC = new ll[1];
			T[n + i].A[0] = arr[i];
			T[n + i].FC[0] = 0;
			T[n + i].P = new pair<ll, pair<ll, ll> >[T[n + i].size];
			T[n + i].P[0] = {m[i], {i, arr[i]}};
			T[n + i].ST = SumFenwickTree(T[n + i].A, T[n + i].size);
			T[n + i].ST.init();
			// fj (0, T[n + i].size - 1) cout << T[n + i].P[j] << " ";
			// cout << "\n";
		}
		initNullNode();
		build();
		// fi (1, 2 * n) {
		// 	fj (0, T[i].size - 1) cout << T[i].P[j] << ' ';
		// 	cout << "\n";
		// }
	}
};

const ll N = 200010, M = 1e9 + 7;
ll n, q;
ll h[N], a[N], m_r[N], m_l[N];

void solve() {
  start = clock();
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

	// fi (0, n - 1) cout << m_l[i] << " ";
	// cout << "\n";

	// fi (0, n - 1) cout << m_r[i] << " ";
	// cout << "\n";

  DragonDenRightSegmentTree RST(a, m_r, n);
	RST.init();

	DragonDenLeftSegmentTree LST(a, m_l, n);
	LST.init();

	MaxSegmentTree MST(h, n);
	MST.init();
	
	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << "Time: "<< duration <<'\n';
	start = clock();

	while (q--) {
		ll ch;
		cin >> ch;
		if (ch == 1) {
			ll b, k; cin >> b >> k; b--;
			// if (a[b] == k) continue;
			RST.update(1, 0, n - 1, m_r[b], a[b], b, k);
			LST.update(1, 0, n - 1, m_l[b], a[b], b, k);
			a[b] = k;
		} 
		else if (ch == 2) {
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

	duration = (clock() - start) / (double) CLOCKS_PER_SEC;
	cout << "Time: "<< duration <<'\n';
}

int main(){
	freopen("input1.txt", "r", stdin);		//Comment
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