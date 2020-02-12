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

const ll N = 1, M = 1e9 + 7;
ll y;
vector<ll> x, final;
unordered_map<ll, ll> mp;

ll f(ll x){
	if(x == 0) return 0;
	if(x % 2 == 0) return (x / 2) + f(x / 2);
	return (x * (x - 1)) / 2;
}

void solve(){
	cin >> y;
	for(ll i=0;i<64;i++){
		ll l = 0, r = 1e8;

		while(l <= r){
			ll z = (l + r) >> 1;
			ll _y = ((1LL << i) - 1) * z + ((z * (z - 1)) / 2);

			// cout << z << ' ' << _y << ' ' << i << "\n";

			if(_y == y){
				x.push_back(z * (1LL << i));
				break;
			}

			if(_y < y)
				l = z + 1;
			else
				r = z - 1;
		}
	}

	final = x;
	x.clear();

	for(ll i : final){
		if(mp.find(i) == mp.end() && f(i) == y)
			x.push_back(i), mp[i] = 1;
	}

	sort(x.begin(), x.end());

	for(ll a : x) cout << a << " ";
	cout << "\n";
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