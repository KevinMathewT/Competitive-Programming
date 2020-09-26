#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll i=(a);i>=b;j--)

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

const ll N = 10, M = 1e9 + 7;
ll a[N], c[N][N], mn;
vector<vector<ll> > config;

void recur(ll pos, ll ind, vector<ll> v){
	// cout << pos << ' ' << ind << "\n"; 
	for(ll i=1;i<v.size();i++)
		if(abs(pos - i) == abs(ind - v[i]) || ind == v[i])
			return;

	v.push_back(ind);
	// cout << v << "\n";

	if(pos < 8){
		for(ll i=1;i<=8;i++)
			recur(pos + 1, i, v);
		return;
	}

	config.push_back(v);
}

void solve(ll cs){
	for(ll i=2;i<=8;i++) cin >> a[i];
	mn = LLONG_MAX;

	for(ll i=0;i<config.size();i++){
		ll tot = 0;
		for(ll j=1;j<=8;j++) 
			if(a[j] != config[i][j])
				tot++;
		mn = min(mn, tot);
	}

	cout << "Case " << cs << ": " << mn << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	ll t = 0;
	for(ll i=1;i<=8;i++) recur(1, i, vector<ll>(1));
	while(cin >> a[1])
		solve(++t);

	return 0;
}