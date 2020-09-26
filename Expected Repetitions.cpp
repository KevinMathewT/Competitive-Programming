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

const ll N = 2010, M = 998244353, P = 27;
string s;
ll n, f[26], p[N], lcs[N][N], h[N], dp[N][N];

ll power(ll a, ll x) {
	a %= M;
	if (x == 0) return 1;
	if (x == 1) return a;
	if (x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * power((a * a) % M, x / 2)) % M;
} 

ll calcHash() {
	h[0] = s[0] - 'a';
	fi (1, s.size() - 1) h[i] = ((h[i - 1] * P) % M + (s[i] - 'a')) % M;
}

ll getHash(ll s, ll e) {
	ll a = h[e];
	ll b = h[s] * power(P, e - s);
	ll c = (((a - b) % M) + M) % M;
}

void solve(){
	cin >> s;
	n = s.size();
	fi (0, 25) cin >> f[i];
	fi (0, n - 1) p[i] = f[s[i] - 'a'];
	fi (1, n - 1) p[i] += p[i - 1];
	fi (0, n - 1) fj (0, n - 1) lcs[i][j] = 0;
	fid (n, 0) fjd(n, 0)
		if (i == n || j == n) lcs[i][j] = 0;
		else if (s[i] == s[j]) lcs[i][j] = 1 + lcs[i + 1][j + 1];
		else lcs[i][j] = 0;

	ll tot = 0;

	fi (0, n) fj (0, n) dp[i][j] = 0;
	fi (1, n) {
		ll b = n - i;
		ll l = i;
		while (b >= 0) {
			dp[b][l] = 1;
			if (b + l < n)
				if (lcs[b][b + l] >= l) dp[b][l] = dp[b + l][l] + 1;

			ll c = b + l - 1;
			ll e = b + (dp[b][l] * l) + lcs[b][b + (dp[b][l] * l)] - 1;
			tot = (tot + (((e - c + 1) * (p[b + l - 1] - ((b - 1) >= 0 ? p[b - 1] : 0))) % M)) % M;

			b--;
		}
	}

	ll den = (((n * (n + 1)) % M) * power(2, M - 2)) % M;
	ll ans = (tot * power(den, M - 2)) % M;

	cout << ans << "\n";
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