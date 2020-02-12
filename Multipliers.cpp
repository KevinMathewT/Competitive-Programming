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
ll n, p[N];

ll power(ll a, ll x, ll m = M){
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % m, x / 2);
	return (a * (power((a * a) % m, x / 2))) % m;
}

ll inverse(ll x){ return power(x, M - 2); }
ll inverse1(ll x){ return power(x, M - 3, M - 1); }

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> p[i];
	sort(p, p + n);
	
	vector<pair<ll, ll> > V;
	V.push_back({p[0], 1});

	for(ll i=1;i<n;i++)
		if(p[i] == V.back().F) V.back().S++;
		else V.push_back({p[i], 1});

	ll nof = 1, num = 1;
	for(auto pll : V)
		nof = (nof * (pll.S + 1LL)) % (M - 1);
	cout << nof << "\n";

	ll tot = 1;
	for(auto pll : V){
		for(ll i=0;i<=pll.S;i++){
			cout << nof << " ";
			cout << (pll.S + 1) << " ";
			cout << (nof * inverse1(pll.S + 1)) % (M - 1) << "\n";
			tot = (tot * (power(power(pll.F, i), (nof * inverse1(pll.S + 1)) % (M - 1)))) % M;
		}
	}

	cout << tot << '\n';
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