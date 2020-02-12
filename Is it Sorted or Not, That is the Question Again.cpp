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
ll n, k, a[N], id, b[N], dp[N][N], f[N], fact[N];

ll power(ll a, ll x){
	a = a % M;
	if(x == 0) return 1LL;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * power((a * a) % M, x / 2)) % M;
}

ll inverse(ll x){ return power(x, M - 2); }

ll nCr(ll n, ll r){
	if(r == 0) return 1LL;
	if(r == 1) return n;
	if(r == n) return 1LL;
	if(r == n - 1) return n;
	return (fact[n] * ((inverse(fact[r]) * inverse(fact[n-r])) % M)) % M;
}

void solve(){
	id = 1;
	cin >> n >> k;
	for(ll i=1;i<=n;i++) cin >> a[i];
	sort(a, a + n);
	b[1] = 1;
	for(ll i=2;i<=n;i++)
		if(a[i] == a[i - 1]) b[i] = id;
		else b[i] = ++id;
	fill(f, f + n + 1, 0LL);
	for(ll i=1;i<=n;i++) f[b[i]]++;

	ll r = b[n];

	for(ll i=0;i<=k;i++) fill(dp[i], dp[i] + r + 1, 0LL);

	dp[0][0] = 1;

	for(ll i=0;i<=k;i++){
		for(ll j=1;j<=r;j++){
			if(i == 0) dp[i][j] = 1;
			else{
				dp[i][j] = dp[i][j-1];
				for(ll k1=1;k1<=min(f[j], i);k1++)
					dp[i][j] = (dp[i][j] + (dp[i - k1][j - 1] * ((nCr(f[j], k1) * fact[k1]) % M)) % M) % M;
			}
		}
	}

	for(ll i=0;i<=k;i++){
		for(ll j=0;j<=r;j++) cout << dp[i][j] << ' ';
		cout << "\n";
	}

	cout << dp[k][r] << "\n";
	cout << (dp[k][r] * inverse((nCr(n, k) * fact[k]) % M)) % M << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fact[0] = 1;
	for(ll i=1;i<N;i++)
		fact[i] = (fact[i-1] * i) % M;

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}