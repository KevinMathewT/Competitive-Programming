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

const ll N = 100010, M = 1e9 + 7;
ll n, a[N], dp[N];
vector<pair<ll, ll> > V;

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];
	for(ll i=0;i<n;i++) V.push_back({a[i], i});
	sort(V.begin(), V.end());
	set<ll> s;
	fill(dp, dp + N, 0LL);

	for(ll i=n-1;i>=0;i--){
		ll p = V[i].S;
		ll v = V[i].F;
		ll w = 0;

		for(ll j=p+v;j<n;j+=v){
			if(s.find(j) == s.end()) continue;
			w = w | dp[j];
		}

		for(ll j=p-v;j>=0;j-=v){
			if(s.find(j) == s.end()) continue;
			w = w | dp[j];
		}

		s.insert(p);
		dp[p] = 1 - w;
	}

	for(ll i=0;i<n;i++) cout << ((dp[i] == 0) ? 'A' : 'B') << "";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}