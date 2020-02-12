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

const ll N = 10010, M = 1e9 + 7;
ll n, is_prime[N * 100], lazy[4 * N], T[4 * N], a[N];

void build(ll i, ll l, ll r){
	if(l == r){
		T[i] = is_prime[a[l]];
		return;
	}

	ll m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
}

void push(ll i){
	if(lazy[i] != 0){
		if(lazy[i] == 1)
	}
}

void update(ll i, ll l, ll r, ll a, ll b, ll v){

}

void solve(){
	cin >> n >> q;
	for(ll i=0;i<n;i++) cin >> a[i];
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	fill(is_prime, is_prime + (N * 100), 1LL);
	is_prime[0] = 0;
	is_prime[1] = 0;

	for(ll i=2;i*i<(N * 100);i++)
		if(is_prime[i] == 1)
			for(ll j=i*i;j<(N * 100);j+=i)
				is_prime[i] = 0;

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}