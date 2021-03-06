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
ll n, x, a[N], l[N], h[N];
vector<pair<ll, ll>> v;
vector<ll> s, e;

ll power(ll a, ll x) {
	if (x == 0) return 1;
	if (x == 1) return a;
	if (x % 2 == 0) return power(a * a, x / 2);
	return a * (power(a * a, x / 2));
}

void solve(){
	cin >> n >> x;
	fi (0, n - 1) cin >> a[i];
	sort(a, a + n);
	v.clear();
	s.clear();
	e.clear();

	v.push_back({0, 0});
	fi (1, n - 1) if (a[i] <= (2 * a[i - 1])) v.back().S = i; else v.push_back({i, i});
	fi (0, v.size() - 1) s.push_back(a[v[i].F]), e.push_back(a[v[i].S]);

	auto pt = prev(e.end());

	fi (0, v.size() - 1)
		if ((2 * e[i]) >= x) {
			pt = e.begin() + i;
			break;
		}

	ll st = pt - e.begin();
	if (st == v.size()) st = v.size() - 1;

	ll moves = 0;

	fi (st, v.size() - 1) {
		if (x < s[i]) moves += (ll) (ceil(log2l(((ld) s[i]) / ((ld) x))));
		moves += v[i].S - v[i].F + 1;
		x = 2 * e[i];
	}

	moves += v[st].F;

	cout << moves << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}