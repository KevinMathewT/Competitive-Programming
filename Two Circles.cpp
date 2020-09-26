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


const ll N = 1, M = 1e9 + 7;
ld x[2], y[2], r[2];

ll d(ll x1, ll y1, ll x2, ll y2) {
	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}

void solve(){
	fi (0, 1) cin >> x[i] >> y[i] >> r[i];

	if (x[0] == x[1] && y[0] == y[1]) {
		if (r[0] <= r[1]) {
			cout << "NO\n";
			return;
		} else {
			cout << "YES\n";
			cout << x[0] << " " << y[0] + r[0] << "\n";
			return;
		}
	}

	ld c_dist = abs(sqrt(d(x[0], y[0], x[1], y[1])));
	if (c_dist + r[0] - r[1] <= 1e-7) {
		cout << "NO\n";
		return;
	} else {
		cout << "YES\n";
		ld sind = (y[1] - y[0] + 0.0) / c_dist;
		ld cosd = (x[1] - x[0] + 0.0) / c_dist;

		cout << x[0] - ((r[0] - 1e-6) * sind) << " " << y[0] - ((r[0] - 1e-6) * cosd) << "\n";
		return;
	}
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << fixed << setprecision(30);

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}