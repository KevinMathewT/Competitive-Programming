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
ll n, k, a[N], dp[N][N], m[N * N], b[N], f[N], fact[N * N];

ll power(ll a, ll x){
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	else return (a * power((a * a) % M, x / 2)) % M;
}

ll inverse(ll x){ return power(x, M - 2); }

ll nCr(ll n, ll r){
	// cout << n << ' ' << r << "--\n";
	if(r == 0) return 1;
	if(r == 1) return n;
	if(r == n) return 1;
	return (fact[n] * inverse((fact[n - r] * fact[r]) % M)) % M;
}

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++) cin >> a[i];
	sort(a, a + n);
	fill(m, m + (N * N), (ll) -1);
	fill(f, f + N, (ll) 0);
	ll id = 0;
	for(ll i=0;i<n;i++)
		if(m[a[i]] == -1)
			m[a[i]] = id++, b[i] = m[a[i]];
		else b[i] = m[a[i]];

	for(ll i=0;i<n;i++) f[b[i]]++;

	// for(ll i=0;i<n;i++) cout << b[i] << ' ';
	// cout << '\n';

	// for(ll i=0;i<=b[n-1];i++) cout << f[i] << ' ';
	// cout << '\n';

	for(ll i=0;i<N;i++) fill(dp[i], dp[i] + N, 0);

	ll p = 0;

	for(ll i=0;i<=b[n-1];i++) dp[0][i] = 1;

	for(ll i=1;i<=k;i++){
		for(ll j=0;j<=b[n-1];j++){
			if(i == 1){
				if(j == 0) dp[i][j] = f[j];
				else dp[i][j] = f[j] + dp[i][j-1];
				continue;
			}

			// cout << i << ' ' << j << ' ' << "-\n";

			for(ll l=0;l<=min(i, f[j]);l++)
				if(j == 0){
					dp[i][j] = (((nCr(f[j], i) * fact[i]) % M)) % M;
					break;
				}
				else dp[i][j] = (dp[i][j] + (dp[i-l][j-1] * (nCr(f[j], l) * fact[l]) % M)) % M;
		}
	}

	for(ll i=0;i<=k;i++){
		for(ll j=0;j<=b[n-1];j++)
			cout << dp[i][j] << ' ';
		cout << "\n";
	}

	cout << dp[k][b[n-1]] << "\n";

	cout << (dp[k][b[n-1]] * inverse((nCr(n, k) * fact[k]) % M)) % M << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fact[0] = 1;
	for(ll i=1;i<=N*N;i++)
		fact[i] = (i * fact[i - 1]) % M;

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}