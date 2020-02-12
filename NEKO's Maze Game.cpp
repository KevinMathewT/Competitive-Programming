#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second

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

const ll N = 100010, M = 1e9 + 7;
ll n, q, a[3][N], dp[N];

void solve(){
	cin >> n;
	for(ll i=0;i<=n;i++) dp[i] = a[2][i] = a[1][i] = 0;

	ll t = 0;
	cin >> q;
	while(q--){
		ll x, y; cin >> x >> y;
		if(a[x][y] == 0){
			a[x][y] = 1;
			if(y > 1) {
				dp[y]++;
				if(dp[y] >= 2) t++;
			}
			if(y < n){
				dp[y + 1]++;
				if(dp[y + 1] >= 2) t++;
			}
		}

		else{
			a[x][y] = 0;
			if(y > 1) {
				dp[y]--;
				if(dp[y] < 2) t--;
			}
			if(y < n){
				dp[y + 1]--;
				if(dp[y + 1] < 2) t--;
			}
		}

		if(t == 0) cout << "Yes\n";
		else cout << "No\n";
	}	
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}