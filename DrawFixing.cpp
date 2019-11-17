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

ll n, b[50010];
vector<pair<ll, ll> > a;

void solve(){
	cin >> n; 
	for(ll i=0;i<n;i++){
		ll x; cin >> x;
		a.push_back({x, i});
	}

	for(ll i=0;i<n;i++) 
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b, b + n);

	vector<ll> ans(n);
	ll l = 0, r = n - 1;
	ll tot = 0;

	for(ll i=0;i<n;i++){
		if(a[i].F < b[l])
			ans[a[i].S] = r-- + 1;
		else
			tot++, ans[a[i].S] = l++ + 1;
	}

	cout << tot << "\n";
	for(ll i=0;i<n;i++)
		cout << ans[i] << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}