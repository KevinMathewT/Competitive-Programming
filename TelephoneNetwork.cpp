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
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
    os << "{ ";
    for(auto m:M) os<<"("<<m.F<<":"<<m.S<<") ";
    return os<<"}";
}

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, k, h[110][110];
vector<pair<ll, ll> > p[10010];

ll ham(pair<ll, ll> a, pair<ll, ll> b){
	return abs(a.F - b.F) + abs(a.S - b.S);
}

void solve(){
	cin >> n >> k;
	for(ll i=0;i<k + 10;i++) p[i].clear();
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			cin >> h[i][j];
			p[h[i][j]].push_back({i, j});
		}

	ll dp[k + 10][(n * n) - k + 10];

	for(ll i=0;i<p[1].size();i++)
		dp[1][i] = 0;

	for(ll i=2;i<=k;i++){
		for(ll j=0;j<p[i].size();j++) dp[i][j] = LLONG_MAX;
		for(ll j=0;j<p[i].size();j++)
			for(ll k=0;k<p[i-1].size();k++)
				dp[i][j] = min(dp[i][j], dp[i-1][k] + ham(p[i-1][k], p[i][j]));
	}

	ll mn = LLONG_MAX;

	for(ll i=0;i<p[k].size();i++) mn = min(mn, dp[k][i]);

	cout << mn << "\n";
}

int main()
{
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