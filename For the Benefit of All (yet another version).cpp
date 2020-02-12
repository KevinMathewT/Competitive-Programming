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
ll n;
pair<ll, ll> a[N];
vector<pair<ll, ll> > sol;
set<pair<ll, ll> > s;

void solve(){
	sol.clear();
	s.clear();
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i].F, a[i].S = i + 1;
	
	for(ll i=0;i<n;i++) s.insert({a[i].F, i + 1});
	sort(a, a + n);

	for(ll i=0;i<n;i++){
		pair<ll, ll> pll = a[i];
		s.erase(s.lower_bound(pll));
		if(s.lower_bound({(ll)ceil(a[i].F / 2.0), 0}) == s.end()){
			s.insert(pll);
			continue;
		}
		auto ele = *s.lower_bound({(ll)ceil(a[i].F / 2.0), 0});
		if(ele.F > pll.F || ele.F == pll.F && ele.S > pll.S){
			s.insert(pll);
			continue;
		}
		s.erase(s.lower_bound(ele));
		sol.push_back({(ll) ele.S, pll.S});
	}

	cout << sol.size() * 2 << "\n";
	for(ll i=0;i<sol.size();i++)
		cout << sol[i].F << ' ' << sol[i].S << "\n";
}

int main(){
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}