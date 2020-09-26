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
ll n, a[N], f[N][210], ind[N], t[N], pos1[200][N];
pair<ll, ll> T[2 * N];
set<pair<ll, ll> > s;
map<ll, ll> m;



void solve(){
	cin >> n;
	fi(0, n - 1) cin >> a[i];

	if(n == 1) {
		cout << 1 << '\n';
		return;
	}

	if(n == 2) {
		if(a[0] == a[1]) cout << 2 << "\n";
		else cout << 1 << "\n";
		return;
	}

	fi(0, n - 1) m[a[i]]++;
	ll ans = m[a[0]];
	fi(0, n - 1) ans = max(ans, m[a[i]]);
	fi(0, n - 1) fj(0, 200) f[i][j] = 0;

	fi(0, n - 1) f[i][a[i]]++;
	fi(1, 200) fj(1, n - 1) f[j][i] += f[j - 1][i];
	fi(1, 200) t[i] = 0;
	fi(1, 200) fj(0, n - 1) t[i] = max(t[i], f[j][i]), pos1[i][j] = -1;
	fi(1, 200) fj(0, n - 1) if(pos1[i][f[j][i]] == -1) pos1[i][f[j][i]] = j;

	fi(1, 3) {

		ll l = 1, r = t[i] / 2, p = 0;
		while(l <= r) {
			ll x1 = l + (r - l) / 3;
			ll x2 = r - (r - l) / 3;

			ll p1 = pos1[i][x1], p2 = pos1[i][t[i] - x1 + 1] - 1;
			ll mx1 = 0;
			fj(1, 200) mx1 = max(mx1, f[p2][j] - f[p1][j]);
			mx1 += 2 * x1;

			ll p3 = pos1[i][x2], p4 = pos1[i][t[i] - x2 + 1] - 1;
			ll mx2 = 0;
			fj(1, 200) mx2 = max(mx2, f[p4][j] - f[p3][j]);
			// cout << mx2 << '\n';
			mx2 += 2 * x2;
			// cout << x1 << ' ' << x2 << ' ' << p3 << ' ' << p4 << "\n";

			p = max(p, max(mx1, mx2));

			if(mx1 >= mx2) r = x2 - 1;
			else if(mx1 < mx2) l = x1 + 1;
		}

		ans = max(ans, p);
	}

	cout << ans << "\n";
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