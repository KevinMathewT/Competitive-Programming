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

ll n, a[100010], dp[100010][2];

void solve(){
	cin >> n;
	for(ll i=1;i<=n;i++)
		cin >> a[i];

	sort(a + 1, a + n + 1);

	a[0] = -999;
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for(ll i=2;i<=n;i++){
		if(a[i] - a[i-1] == 1)
			dp[i][0] = dp[i-1][0];
		if(a[i] - a[i-1] == 2)
			dp[i][0] = min(min(1 + dp[i-2][1], 1 + dp[i-2][0]), dp[i-1][1]);
		else
			dp[i][0] = 1 + min(dp[i-1][0], dp[i-1][1]);

		dp[i][1] = 1 + min(dp[i-1][1], dp[i-1][0]);
	}

	cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main()
{
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