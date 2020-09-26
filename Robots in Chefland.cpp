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

const ll N = 200010, M = 1e9 + 7, PI = 3.141592653589793238;
ll n, q, rt[N];
ld x[N], y[N];
string s;

ld sind(ld z) { return sin((z * 3.141592653589793238) / 180.0); }
ld cosd(ld z) { return cos((z * 3.141592653589793238) / 180.0); }

void solve(){
	cin >> n >> q;
	cin >> s;

	ld sx = 0.0, sy = 0.0;
	ll d = 0;


	fi (0, n - 1) {
		d = (d + (s[i] - '0')) % 6;
		sx += cosd(d * 60);
		sy += sind(d * 60);
		x[i] = sx;
		y[i] = sy;
	}

	rt[0] = s[0];
	fi (1, n - 1) rt[i] = (rt[i - 1] + (s[i] - '0')) % 6;

	while (q--) {
		ll l, r; cin >> l >> r; l--; r--;
		sx = 0.0, sy = 0.0;

		if (l == 0) {
			sx = x[r], sy = y[r];
		} else {
			ld dx = x[r] - x[l - 1], dy = y[r] - y[l - 1];
			ld rot = (6 - rt[l - 1]);
			ld x1 = dx * cosd(rot * 60);
			ld x2 = dy * cosd(rot * 60 + 90);
			ld y1 = dx * sind(rot * 60);
			ld y2 = dy * sind(rot * 60 + 90);

			sx += (x1 + x2);
			sy += (y1 + y2);
		}

		cout << sx << ' ' << sy << '\n';
	}
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	cout << fixed << setprecision(8);

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}