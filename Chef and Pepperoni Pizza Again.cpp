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


const ll N = 160, M = 1e9 + 7;
ll n, a[N][2], dp[N][N * N], back[N][N * N], s[N], b[N][N];

void solve(){
	cin >> n;
	ll t = 0;
	fi (0, n - 1) s[i] = 0, a[i][0] = a[i][1] = 0;
	fi (0, n - 1) fj (0, n - 1) b[i][j] = 0;
	fi (0, n - 1) fj (0, n - 1) {
		char c; cin >> c;
		if (c == '1') b[i][j] = 1; else b[i][j] = 0;
		if (c == '1' && j <= ((n / 2) - 1)) a[i][0]++, t++;
		if (c == '1' && j > ((n / 2) - 1)) a[i][1]++, t++;
	}

	// fi (0, n - 1) {
	// 	fj (0, n - 1) cout << b[i][j] << ' ';
	// 	cout << '\n'; 
	// }

	// fi (0, n - 1) cout << a[i][0] << ' ' << a[i][1] << "\n";

	fi (0, N - 1) fj (0, (N * N) - 1) dp[i][j] = 0, back[i][j] = -1;

	dp[0][a[0][0]] = 1;
	back[0][a[0][0]] = a[0][0];
	dp[0][a[0][1]] = 1;
	back[0][a[0][1]] = a[0][1];

	fi (1, n - 1)
		fj (0, (N * N) - 1) 
			if (dp[i - 1][j] == 1) {
				dp[i][j + a[i][0]] = 1;
				back[i][j + a[i][0]] = a[i][0];
				dp[i][j + a[i][1]] = 1;
				back[i][j + a[i][1]] = a[i][1];
			}

	ll best = LLONG_MAX;
	ll left;
	fi (0, (N * N) - 1)
		if (dp[n - 1][i] == 1) {
			if (abs(t - (2 * (i))) < best) {
				best = min(best, abs(t - (2 * (i))));
				left = i;
			}
		}

	// cout << left << '\n';

	// fi (0, n - 1) {
	// 	fj (0, 8) cout << dp[i][j] << ' ';
	// 	cout << "\n";
	// }
	// fi (0, n - 1) {
	// 	fj (0, 8) cout << back[i][j] << ' ';
	// 	cout << "\n";
	// }

	fid (n - 1, 0) {
		if (back[i][left] == a[i][1]) s[i] = 1;
		left = left - back[i][left];
	}

	// fi (0, n - 1) cout << s[i] << ' ';
	// cout << "-----\n";

	fi (0, n - 1) 
		if (s[i] == 1)
			fj (0, (n / 2) - 1) swap(b[i][j], b[i][n - j - 1]);

	fi (0, n - 1) {
		fj (0, n - 1) cout << b[i][j];
		cout << '\n'; 
	}
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