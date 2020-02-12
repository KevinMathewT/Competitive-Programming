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
ll n, a[N], d[N];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> a[i];

	fill(d, d + n + 1, 0);
	for(ll i=0;i<n;i++){
		d[a[i]]++;
	}

	set<pair<ll, ll> > s;

	for(ll i=1;i<=n;i++)
		s.insert({d[i], i});

	vector<pair<ll, ll> > v;
	ll st = -1;

	for(ll i=0;i<n-1;i++){
		auto pll1 = *s.begin();
		auto pll2 = *s.rbegin();

		s.erase(s.lower_bound(pll1));
		s.erase(s.lower_bound(pll2));

		if(pll1.F != 0 || pll2.F == 0){
			cout << -1 << "\n";
			return;
		}

		// cout << pll2.S << "\n";

		if(i == n-2)
			st = pll2.S;

		v.push_back({pll1.S, pll2.S});
		pll2.F--;
		s.insert(pll2);
	}

	cout << st << "\n";
	for(ll i=0;i<v.size();i++)
		cout << v[i].F << ' ' << v[i].S << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while()
		solve();

	return 0;
}