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
ll n, m;
ll a[N][N];

ll power(ll a, ll x){
	if(x == 0) return 1LL;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * (power((a * a) % M, x / 2))) % M;
}

ll inverse(ll a){
	return power(a % M, M - 2);
}

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++) for(ll j=0;j<m;j++) cin >> a[i][j];

	ll num = 0, den;

	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++){
			ll l = i + 1;
			ll r = n - i;
			ll u = j + 1;
			ll d = m - j;
			a[i][j] %= M;

			num += (((((l * r) % M) * ((u * d) % M)) % M) * a[i][j]) % M;
		}

	num = (num * 4) % M;
	den = (((n * (n + 1)) % M) * ((m * (m + 1)) % M)) % M;
	ll ans = (num * inverse(den)) % M;

	cout << ans << "\n";
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