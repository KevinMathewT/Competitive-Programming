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


const ll N = 110, M = 1e9 + 7;
ll n, m, a[N][N], dp[N][N];
vector<vector<ll> > s;

void solve(){
	s.clear();
	cin >> m;
	fi(0, n - 1) fj(0, m - 1) cin >> a[i][j];
	fi(0, n - 1) dp[i][0] = a[i][0];
	fi(1, m - 1) fj(0, n - 1)	dp[j][i] = a[j][i] + min(dp[(j - 1 + n) % n][i - 1], min(dp[j][i - 1], dp[(j + 1) % n][i - 1]));

	ll ans = LLONG_MAX;
	fi(0, n - 1) ans = min(ans, dp[i][m - 1]);

	fi(0, n - 1) if(dp[i][m - 1] == ans) {
		vector<ll> v;
		ll curr = i;
		v.push_back(i);

		fjd(m - 2, 0) {
			if(dp[(curr - 1 + n) % n][j] + a[curr][j + 1] == dp[curr][j + 1]) curr = (curr - 1 + n) % n;
			else if(dp[(curr + 1) % n][j] + a[curr][j + 1] == dp[curr][j + 1]) curr = (curr + 1) % n;
			v.push_back(curr);
		}

		reverse(v.begin(), v.end());
		s.push_back(v);
	}

	sort(s.begin(), s.end());
	fi(0, s[0].size() - 1) cout << s[0][i] + 1 << ' ';
	cout << '\n';
	cout << ans << '\n';
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	while(cin >> n)
		solve();

	return 0;
}