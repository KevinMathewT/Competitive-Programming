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
ll n, m, a[N], p[N];

void solve(){
	cin >> n >> m;
	fill(p, p + n + 1, 0);
	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(a, a + n);

	multiset<pair<pair<ll, ll>, pair<ll, ll> > > ms;
	ms.insert({{0, 0}, {300000, a[0]}});
	ms.insert({{0, 1}, {300000, a[n-1]}});

	for(ll i=0;i<n-1;i++){
		if((a[i+1] - a[i] - 1) % 2 == 0){
			ms.insert({{0, 1}, {(a[i+1] - a[i]) / 2, a[i]}});
			ms.insert({{0, 0}, {(a[i+1] - a[i]) / 2, a[i + 1]}});
		}
		else{
			ms.insert({{0, 1}, {(a[i+1] - a[i]) / 2, a[i]}});
			ms.insert({{0, 0}, {(a[i+1] - a[i]) / 2 - 1, a[i + 1]}});	
		}
	}

	vector<pair<pair<ll, ll>, pair<ll, ll>>> v;

    for(auto it : ms)
    	if(it.S.F == 0)
    		v.push_back(it);

	ll tot = 0;

	for(auto pll : v) 
		ms.erase(ms.lower_bound(pll));

	// cout << ms << "\n";
	// cout << v << "\n";

	for(ll i=0;i<m;i++){
		pair<pair<ll, ll>, pair<ll, ll> > pll = *ms.begin();

		ms.erase(ms.lower_bound(pll));

		tot += pll.F.F + 1;
		ll d = pll.F.F + 1;
		if(pll.F.S == 0)
			p[i] = pll.S.S - d;
		else
			p[i] = pll.S.S + d;

		pll.F.F++;
		pll.S.F--;

		if(pll.S.F != 0)
			ms.insert(pll);
	}

	sort(p, p + m);

	cout << tot << "\n";
	for(ll i=0;i<m;i++) cout << p[i] << ' ';
		cout << "\n";
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