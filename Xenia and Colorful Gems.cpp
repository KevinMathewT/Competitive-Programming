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
ll x, y, z, t, a[N], b[N], c[N];

ll power(ll a, ll x) {
	if (x == 0) return 1;
	if (x == 1) return a;
	if (x % 2 == 0) return power(a * a, x / 2);
	else return (a * power(a * a, x / 2));
}

ll f(ll x, ll y, ll z) {
	return power(x - y, 2) + power(y - z, 2) + power(z - x, 2);
}

void fixer(ll *p, ll *q, ll *r, ll l, ll m, ll n) {
	fi (0, m - 1) {
		vector<ll> v1, v2;
		ll p1 = lower_bound(p, p + l, q[i]) - p;
		ll p2 = lower_bound(r, r + n, q[i]) - r;

		ll w = 2;
		fj (p1 - w, p1 + w)
			if (j >= 0 && j < l) v1.push_back(p[j]);
		fj (p2 - w, p2 + w)
			if (j >= 0 && j < n) v2.push_back(r[j]);

		fj (0, (ll) v1.size() - 1)
			for (ll k = 0; k < v2.size(); k++)
				t = min(t, f(v1[j], q[i], v2[k]));
	}
}

void solve(){
	cin >> x >> y >> z;
	fi (0, x - 1) cin >> a[i];
	fi (0, y - 1) cin >> b[i];
	fi (0, z - 1) cin >> c[i];
	sort(a, a + x);
	sort(b, b + y);
	sort(c, c + z);

	t = LLONG_MAX;
	fixer(a, b, c, x, y, z);
	fixer(b, c, a, y, z, x);
	fixer(c, a, b, z, x, y);
	fixer(a, c, b, x, z, y);
	fixer(b, a, c, y, x, z);
	fixer(c, b, a, z, y, x);

	cout << t << "\n";
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