#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll i=(a);i>=b;j--)

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

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// LinkedIn - https://www.linkedin.com/in/KevinMathewT/
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

const ll N = 2010, M = 1e9 + 7;
ll n, a[N][N], dp1[N][N], dp2[N][N], dp3[N][N];

void solve(){
	cin >> n;
	fi(0, n - 1) fj(0, n - 1) cin >> a[i][j];
	fi(0, n - 1) dp1[i][0] = a[i][0], dp1[0][i] = a[0][i], dp2[i][n - 1] = a[i][n - 1], dp2[0][n - i - 1] = a[0][n - i - 1];
	fi(1, n - 1) fj(1, n - 1) dp1[i][j] = a[i][j] + dp1[i - 1][j - 1];
	fi(1, n - 1) fj(0, n - 2) dp2[i][j] = a[i][j] + dp2[i - 1][j + 1];
	
	fi(0, n - 1) fj(0, n - 1) {
		ll i1 = i + min(n - i - 1, n - j - 1);
		ll j1 = j + min(n - i - 1, n - j - 1);
		ll i2 = i + min(n - i - 1, j);
		ll j2 = j - min(n - i - 1, j);

		dp3[i][j] = dp1[i1][j1] + dp2[i2][j2] - a[i][j];
	}

	ll ans1 = LLONG_MIN, ans2 = LLONG_MIN, posx1, posy1, posx2, posy2;
	
	// fi(0, n - 1) {
	// 	fj(0, n - 1) cout << dp3[i][j] << ' ';
	// 	cout << "\n";
	// }

	fi(0, n - 1) fj(0, n - 1) {
		if((i + j) % 2 == 0 && dp3[i][j] > ans1) {
			ans1 = max(ans1, dp3[i][j]);
			posx1 = i + 1;
			posy1 = j + 1;
		}	else if ((i + j) % 2 == 1 && dp3[i][j] > ans2){
			ans2 = max(ans2, dp3[i][j]);
			posx2 = i + 1;
			posy2 = j + 1;
		}
	}

	cout << ans1 + ans2 << "\n";
	cout << posx1 << ' ' << posy1 << ' ' << posx2 << " " << posy2 << "\n";
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