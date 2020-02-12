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

const ll N = 200010, M = 1e9 + 7;
ll n, a[N];
unordered_map<ll, ll> m;

void solve(){
	m.clear();
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];

	sort(a, a + n);
	
	ll mx = 0;

	for(ll i=0;i<n;i++){
		if(m.find(a[i] - 1) != m.end()){
			if(m.find(a[i]) != m.end()){
				if(m.find(a[i] + 1) != m.end()){
					continue;
				}
				else{
					mx++;
					m[a[i] + 1] = 1;
				}
			}
			else{
				mx++;
				m[a[i]] = 1;
			}
		}
		else{
			mx++;
			m[a[i] - 1] = 1;
		}
	}

	ll dp[n][3];
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;

	for(ll i=1;i<n;i++){
		if(a[i] - a[i-1] == 0){
			dp[i][0] = dp[i-1][0];
			dp[i][1] = min(dp[i-1][1], 1 + dp[i-1][0]);
			dp[i][2] = min(1 + dp[i-1][0], min(1 + dp[i-1][1], dp[i-1][2]));
		}

		else if(a[i] - a[i-1] == 1){
			dp[i][0] = min(1 + dp[i-1][0], min(1 + dp[i-1][2], dp[i-1][1]));
			dp[i][1] = min(1 + dp[i-1][1], min(1 + dp[i-1][0], dp[i-1][2]));
			dp[i][2] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
		}

		else if(a[i] - a[i - 1] == 2){
			dp[i][0] = min(1 + dp[i-1][0], min(dp[i-1][2], 1 + dp[i-1][1]));
			dp[i][1] = min(1 + dp[i-1][1], min(1 + dp[i-1][0], 1 + dp[i-1][2]));
			dp[i][2] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));	
		}

		else{
			dp[i][0] = min(1 + dp[i-1][0], min(1 + dp[i-1][2], 1 + dp[i-1][1]));
			dp[i][1] = min(1 + dp[i-1][1], min(1 + dp[i-1][0], 1 + dp[i-1][2]));
			dp[i][2] = 1 + min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));	
		}
	}

	cout << min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])) << " ";

	cout << mx << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while()
		solve();

	return 0;
}