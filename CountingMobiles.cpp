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

const ll N = 100010, M = 1e9 + 7, INF = 1e6;
ll n, a[N], w, f[N];
unordered_map<ll, ll> m;

ll power(ll a, ll x){
	a = a % M;
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * power((a * a) % M, x / 2)) % M;
}

ll inverse(ll x){
	return power(x, M - 2);
}

void init(){
	f[0] = 1;
	for(ll i=1;i<N;i++)
		f[i] = (i * f[i-1]) % M;
}

ll nCr(ll n, ll r){
	if(r == 0 || r == n) return 1;
	if(r == 1 || r == n - 1) return n;
	return (f[n] * inverse((f[n - r] * f[r]) % M)) % M;
}

void solve(){
	m.clear();
	w = 0;
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];

	ll gcd = 0, sum = 0;
	for(ll i=0;i<n;i++) gcd = __gcd(gcd, a[i]);
	for(ll i=0;i<n;i++) a[i] /= gcd, sum += a[i];
	for(ll i=0;i<n;i++) if(__builtin_popcountll(a[i]) != 1 || __builtin_popcountll(sum) != 1){
		cout << "0\n";
		return;
	}

	for(ll i=0;i<n;i++) m[a[i]]++;

	ll slots = 1;
	w = 1;
	while(sum > 0){
		slots = slots * 2; 
		sum /= 2;
		w = (w * nCr(slots, m[sum])) % M;
		slots -= m[sum];
	}

	cout << w << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	init();
	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}