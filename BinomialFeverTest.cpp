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

ll n, p, r, fact[1000010], M = 998244353;

ll power(ll a, ll x){
	if(x == 0) return 1;
	if(x == 1) return (a % M);
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * (power((a * a) % M, x / 2))) % M;
}

ll inverse(ll x){
	return power(x, M - 2);
}

ll nCr(ll n, ll r){
	if(r > n) return 0;
	ll k1 = n % M, k2 = r % M;

	for(ll i=1;i<r;i++)
		k1 = (k1 * (n - i)) % M, k2 = (k2 * i) % M;

	return (k1 * inverse(k2)) % M;
}

ll nCrModpDP(ll n, ll r, ll p){
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;

    for (ll i = 1; i <= n; i++){
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
}

ll nCrModpLucas(ll n, ll r, ll p){ 
   if (r==0) 
      return 1;
   ll ni = n % p, ri = r % p;
   return (nCrModpLucas(n / p, r / p, p) * nCrModpDP(ni, ri, p)) % p;
} 

void solve(){
	cin >> n >> p >> r;

	ll tot = 0;
	for(ll i=0;i<=n;i++)
		tot = (tot + nCr(power(p % M, i), r)) % M;

	cout << tot << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fact[0] = 1;
	for(ll i=1;i<1000010;i++)
		fact[i] = (i * fact[i-1]) % M;

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}