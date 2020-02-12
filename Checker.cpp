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

ll m[510][510], r, c;

void solve(){
	cin >> r >> c;
	for(ll i=0;i<r;i++)
		for(ll j=0;j<c;j++)
			cin >> m[i][j];

	for(ll i=0;i<r;i++){
		ll g = m[i][0];
		for(ll j=1;j<c;j++)
			g = __gcd(g, m[i][j]);
		cout << g << "\n";
	}

	for(ll i=0;i<c;i++){
		ll g = m[0][i];
		for(ll j=1;j<r;j++)
			g = __gcd(g, m[j][i]);
		cout << g << "\n";
	}
}

int main()
{
	freopen("output.txt", "r", stdin);		//Comment
	freopen("input.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// solve();

	ll x;
	vector<ll> v;
	while(cin >> x){
		v.push_back(x);
	}

	for(ll i=0;i<v.size();i++)
		if(v[i] != i + 1)
			cout << i << "\n";

	return 0;
}