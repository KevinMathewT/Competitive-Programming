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
ll n, q, k, d[N], x[N], s[N];

void solve(){
	cin >> n >> q >> k;
	fi (0, n - 1) cin >> d[i] >> x[i];

	ll cw = 0, ccw = 0;
	fi (0, n - 1) if (d[i] == 1) cw++; else ccw++;
	fi (0, n - 1) x[i] = x[i] % k;
	vector<ll> cwx, ccwx;
	fi (0, n - 1) if (d[i] == 1) cwx.push_back(x[i]); else ccwx.push_back(x[i]);

	sort(cwx.begin(), cwx.end());
	sort(ccwx.begin(), ccwx.end());

	while (q--) {
		ll x; cin >> x;

		ll ans = 0;
		ans += ((2 * x) / k) * cw * ccw;
		x = (2 * x) % k;

		if (x == 0) {
			cout << ans << "\n";
			continue;
		}

		// cout << x << '\n';

		fi (0, cwx.size() - 1) {
			ll l = cwx[i];
			ll r = (l + x) % k;
			ll contri = 0;

			if (r <= l) {
				contri += (upper_bound(ccwx.begin(), ccwx.end(), r) - ccwx.begin()
					+ ccwx.end() - lower_bound(ccwx.begin(), ccwx.end(), l));
			} else {
				contri += upper_bound(ccwx.begin(), ccwx.end(), r) - lower_bound(ccwx.begin(), ccwx.end(), l);
			}

			// cout << x << ' ' << l << ' ' << r << ' ' << contri << '\n';
			ans += contri;
		}

		cout << ans << '\n';
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