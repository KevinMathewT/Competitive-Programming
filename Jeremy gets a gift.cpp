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

void solve(){
	ll n, m; cin >> n >> m;
	char a[n + 10][m + 10];
	ll vis[n + 10][m + 10];
	fi (0, n - 1) fj (0, m - 1) cin >> a[i][j];
	fid (n - 2, 0) if (a[i + 1][m - 1] == '#') a[i][m - 1] = '#';
	fid (m - 2, 0) if (a[n - 1][i + 1] == '#') a[n - 1][i] = '#';
	fid (n - 2, 0) fjd (m - 2, 0) if (a[i + 1][j] == '#' && a[i][j + 1] == '#') a[i][j] = '#';

	fi (0, n - 1) fj (0, m - 1) vis[i][j] = 0;

	vector<pair<ll, ll>> v, t;
	v.push_back({0, 0});
	string s = "";
	while (true) {
		assert(v.size() > 0);
		s.push_back(a[v[0].F][v[0].S]);
		if (s.size() == n + m - 1) break;
		t.clear();
		fi (0, v.size() - 1) {
			ll x = v[i].F, y = v[i].S;
			if (x + 1 < n && vis[x + 1][y] == 0) vis[x + 1][y] = 1, t.push_back({x + 1, y});
			if (y + 1 < m && vis[x][y + 1] == 0) vis[x][y + 1] = 1, t.push_back({x, y + 1});
		}

		char mn = 'z';
		fi (0, t.size() - 1)
			if (a[t[i].F][t[i].S] != '#') mn = min(mn, a[t[i].F][t[i].S]);

		v.clear();
		fi (0, t.size() - 1)
			if (a[t[i].F][t[i].S] == mn) v.push_back(t[i]);
		t.clear();
	}

	cout << s << "\n";
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