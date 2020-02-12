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

const ll N = 20, M = 1e9 + 7;
ll n;
ld a[N][N], dp[(1 << N)], p[N];

ld DP(ll mask, ll pr){
	// cout << mask << "\n";
	if(dp[mask] != -1) return dp[mask];
	if(__builtin_popcount(mask) == 1) return 1;

	ld ret = 0;

	for(ll i=0;i<20;i++)
		if((mask & (1 << i)))
			for(ll j=0;j<20;j++)
				if((i != j) && (mask & (1 << j)))
					ret += a[i][j] * DP(mask ^ (1 << j));

	ld tem = __builtin_popcount(mask);
	ret /= tem * (tem - 1);

	return dp[mask] = ret;
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++) cin >> a[i][j];

	for(ll i=0;i<(1 << N);i++) dp[i] = -1;

	cout << DP((1 << n) - 1) << "\n";
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