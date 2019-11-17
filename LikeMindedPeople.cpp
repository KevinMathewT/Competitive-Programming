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

ll n, dp[5010][5010], a[5010][5010], sums[5010];

void solve(){
	ll tot = 0;
	cin >> n;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			cin >> a[i][j];

	for(ll i=0;i<=n;i++)
		for(ll j=0;j<=n;j++)
			dp[i][j] = 0;

	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			dp[i][j] = a[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];

	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++){
			if(a[i][j] != 1)
				continue;

			ll l = 0, r = min(n - i, n - j), best = 0;

			while(l <= r){
				ll mid = (l + r) / 2;
				if((dp[i + mid][j + mid] - dp[i - 1][j + mid] - dp[i + mid][j - 1] + dp[i - 1][j - 1]) == pow(mid + 1, 2)){
					best = mid;
					l = mid + 1;
				}
				else
					r = mid - 1;
			}


			tot += best + 1;
		}

	cout << tot << "\n";
}

int main()
{
	freopen("output.txt", "r", stdin);		//Comment
	freopen("input.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	sums[0] = 0;
	for(ll i=1;i<5010;i++)
		sums[i] = sums[i-1] + (i * i);

	solve();

	return 0;
}