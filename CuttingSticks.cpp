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

const ll N = 1010, M = 1e9 + 7;
ll l, n, a[N], dp[N][N];

ll DP(ll s, ll e){
	if(dp[s][e] != -1) return dp[s][e];

	ll mn = LLONG_MAX;

	for(ll i=0;i<n;i++)
		if(a[i] > s && a[i] < e)
			mn = min(mn, (e - s) + DP(s, a[i]) + DP(a[i], e));

	if(mn == LLONG_MAX) return dp[s][e] = 0;
	else return dp[s][e] = mn;
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];
	sort(a, a + n);
	for(ll i=0;i<N;i++) for(ll j=0;j<N;j++) dp[i][j] = -1;

	cout << "The minimum cutting is " << DP(0, l) << ".\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	while(cin >> l){
		if(l == 0) break;
		solve();
	}

	return 0;
}