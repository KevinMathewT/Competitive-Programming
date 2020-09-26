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


const ll N = 200010, M = 1e9 + 7;
ll n, a[N]; 

class SegmentTreeLazy {
public:
	ll lazy[4 * N], T[4 * N];
	
	SegmentTreeLazy(ll n) {
		// fi (0, n - 1) this->a[i] = arr[i];
		// fi (0, n - 1) cout << arr[i] << " "; cout << "\n";
		build(1, 0, n - 1);
	}

	void build(ll i, ll l, ll r) {
		lazy[i] = 0;
		if (l == r) {
			T[i] = 0;
			return;
		}

		ll m = (l + r) / 2;
		build(2 * i, l, m);
		build(2 * i + 1, m + 1, r);
		T[i] = T[2 * i] + T[2 * i + 1];
	}

	void push(ll i, ll l, ll r) {
		T[i] += lazy[i] * (r - l + 1);
		if (l != r) {
			lazy[2 * i] += lazy[i];
			lazy[2 * i + 1] += lazy[i];
		}
		lazy[i] = 0;
	}

	void update(ll i, ll l, ll r, ll a, ll b, ll v) {
		push(i, l, r);
		if (r < a || l > b) return;
		if (l >= a && r <= b) {
			lazy[i] += v;
			push(i, l, r);
			return;
		}

		ll m = (l + r) / 2;
		update(2 * i, l, m, a, b, v);
		update(2 * i + 1, m + 1, r, a, b, v);
		T[i] = T[2 * i] + T[2 * i + 1];
	}

	ll query(ll i, ll l, ll r, ll a, ll b) {
		push(i, l, r);
		if (r < a || l > b) return 0;
		if (l >= a && r <= b) return T[i];

		ll m = (l + r) / 2;
		return query(2 * i, l, m, a, b) + query(2 * i + 1, m + 1, r, a, b);
	}

	void pop(ll i, ll l, ll r, ll p, ll v) {
		push(i, l, r);
		if (p < l || p > r) return;
		T[i] -= v;
		if (l == r) return;
		ll m = (l + r) / 2;
		if (p <= m) pop(2 * i, l, m, p, v);
		else pop(2 * i + 1, m + 1, r, p, v);
	}

	ll z = 0;

	void insert(ll i, ll l, ll r, ll p, ll v) {
		push(i, l, r);
		if (p < l || p > r) return;
		T[i] += v;
		if (l == r) return;
		ll m = (l + r) / 2;
		if (p <= m) insert(2 * i, l, m, p, v);
		else insert(2 * i + 1, m + 1, r, p, v);	
	}
};

void printArr(SegmentTreeLazy STL) {
	fi (0, n) cout << STL.query(1, 0, n, i, i) << " "; cout << "\n";
	fi (0, 4 * n) cout << STL.T[i] << " "; cout << "\n";
	fi (0, 4 * n) cout << STL.lazy[i] << " "; cout << "\n";
}

void solve() {
	cin >> n;
	fi (0, n) a[i] = 0;
	SegmentTreeLazy STL(n + 1);

	ll i = 1;
	ll temp = n;
	while (temp--) {
		ll t; cin >> t;
		if (t == 1) {
			ll a, x; cin >> a >> x;
			STL.update(1, 0, n, 0, min(i - 1, a - 1), x);
			ld tot = STL.query(1, 0, n, 0, i - 1);
			cout << tot / i << "\n";
		} else if (t == 2) {
			ll k; cin >> k;
			STL.insert(1, 0, n, i, k);
			i++;
			ld tot = STL.query(1, 0, n, 0, i - 1);
			cout << tot / i << "\n";
		} else if (t == 3) {
			STL.pop(1, 0, n, i - 1, STL.query(1, 0, n, i - 1, i - 1));
			i--;
			ld tot = STL.query(1, 0, n, 0, i - 1);
			cout << tot / i << "\n";
		}
	}
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << fixed << setprecision(10);

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}