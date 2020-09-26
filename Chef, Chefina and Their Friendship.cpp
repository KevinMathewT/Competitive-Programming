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


const ll N = 100010, M = 1e9 + 7, p = 29;
ll n, h[N];
string s;

ll power(ll a, ll x) {
	a = ((a % M) + M) % M;
	if (x == 0) return 1;
	if (x == 1) return a;
	if (x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * (power((a * a) % M, x / 2))) % M;
}

void solve(){
	cin >> s;
	n = s.size();	

	ll hash = 0;
	fi (0, n - 1) {
		h[i] = (((hash * p) % M) + (s[i] - 'a' + 1)) % M;
		hash = h[i];
	}

	ll c = 0;

	fi (1, n) {
		if (2 * i >= n) continue;
		// cout << 2 * i - 1 << "\n";
		ll j = ((n - (2 * i)) / 2) + (2 * i);
		// cout << j << '\n';

		ll p1 = i - 1;
		ll p2 = (2 * i) - 1;
		ll p3 = j - 1;
		ll p4 = n - 1;

		ll h1 = h[p1];
		ll h2 = (((h[p2] - ((h[p1] * power(p, p2 - p1)) % M)) % M) + M) % M;
		ll h3 = (((h[p3] - ((h[p2] * power(p, p3 - p2)) % M)) % M) + M) % M;
		ll h4 = (((h[p4] - ((h[p3] * power(p, p4 - p3)) % M)) % M) + M) % M;

		if (h1 == h2 && h3 == h4) c++;
	}

	cout << c << "\n";
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