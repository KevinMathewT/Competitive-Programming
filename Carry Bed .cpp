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

const ll N = 5010, M = 1e9 + 7, INF = 5e16;
ll n, k, a[N], m[N][N], dp[N][N];

void rec(ll l, ll r) {
	ll mid = m[l][r];
	ll len = r - l + 1;

	if (l != r) {
		if (mid == l) rec(mid + 1, r);
		else if (mid == r) rec(l, mid - 1);
		else {
			rec(l, mid - 1);
			rec(mid + 1, r);
		}
	}

	if (l == r) {
		dp[mid][0] = 0;
		dp[mid][1] = a[mid];
		return;
	}

	if (mid == l || mid == r) {
		ll cl, cr;
		if (mid == l) cl = l + 1, cr = r;
		if (mid == r) cl = l, cr = r - 1;
		ll cm = m[cl][cr];

		dp[mid][0] = 0;
		fi (1, r - l)	
			dp[mid][i] = min(
				dp[cm][i], 
				dp[cm][i - 1] + a[mid] * i
			);

		dp[mid][len] = dp[cm][len - 1] + a[mid] * len;
		return;
	}

	ll llen = mid - l, rlen = r - mid;

	fi (0, llen) {
		ll ml = m[l][mid - 1], mr = m[mid + 1][r];
		if (i != len) {
			fj (0, rlen) {
				if (j > llen || (i - j) > rlen) continue;

				dp[mid][i] = min(dp[mid][i], min(
						dp[ml][j] + dp[mr][i - j] + a[mid] * (j * (i - j)),
						dp[ml][j] + dp[mr][i - j - 1] + a[mid] * ((j * (i - j - 1)) + i)
					));
			}
		} else {
			ll j = llen;
			dp[mid][i] = dp[ml][j] + dp[mr][i - j - 1] + a[mid] * (j * (i - j - 1) + i);
		}

		if (dp[mid][i] == INF) dp[mid][i] = -1;
	}
}

void solve(){
	cin >> n >> k;
	fi (0, n - 1) cin >> a[i];
	fi (0, n - 1) m[i][i] = i;
	fi (0, n - 1) fj (0, n) dp[i][j] = INF;
	fi (0, n - 1) fj (i + 1, n - 1) {
		if (a[j] > a[m[i][j - 1]])
			m[i][j] = j;
		else m[i][j] = m[i][j - 1];
	}

	rec(0, n - 1);

	// fi (0, n - 1) {
	// 	fj (0, n) cout << dp[i][j] << ' ';
	// 	cout << "\n";
	// }

	cout << dp[m[0][n - 1]][k] << "\n";
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