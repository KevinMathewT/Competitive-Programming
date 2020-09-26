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

#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <iostream> 
using namespace __gnu_pbds; 
using namespace std; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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


const ll N = 510, R = 200010, M = 1e9 + 7, INF = 1e18;
ll n, r, k, dp[N][R];

void precompute() {
	fi (0, N - 1) fj (0, R - 1) dp[i][j] = 0;
	
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;

	fi (3, N - 1) {
		ll lim = (i * (i - 1)) / 2;
		fj (0, min(R - 1, lim)) {
			dp[i][j] = 0;
			for (ll k = 1; k <= min(i, j + 1); k++) {
				if (dp[i - 1][j - k + 1] == -1) {
					dp[i][j] = -1;
					break;
				}
				dp[i][j] += dp[i - 1][j - k + 1];

				if (dp[i][j] > INF) {
					dp[i][j] = -1;
					break;
				}
			}
		}
	}	
}

void solve(){
	cin >> n >> r >> k;

	vector<ll> ans(0);
	ordered_set os;
	fi (1, n) os.insert(i);

	fid (n, 1) {
		ll ptot = 0;
		ll flag = 0;
		fj (1, min(n, r + 1)) {
			ll tot = ptot + dp[i - 1][r - j + 1];
			// cout << i << ' ' << tot << ' ' << ptot << ' ' << r << ' ' << j << ' ' << k << '\n';
			if (tot >= k || dp[i - 1][r - j + 1] == -1) {
				flag = 1;
				ans.push_back(*os.find_by_order(j - 1));
				os.erase(os.find_by_order(j - 1));
				r = r - j + 1;
				k -= ptot;
				break;
			}
			ptot = tot;
		}

		if (flag == 0) {
			cout << -1 << '\n';
			return;
		}
	}

	fi (0, ans.size() - 1) cout << ans[i] << ' ';
	cout << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	precompute();

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}