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
ll n, m, tot;

void solve(){
	cin >> n >> m;
	tot = 0;
	ll a[n][m];
	for(ll i=0;i<n;i++) 
		for(ll j=0;j<m;j++)
			cin >> a[i][j];
	ll rot[n];

	for(ll i=0;i<m;i++){
		fill(rot, rot + n, 0LL);
		for(ll j=0;j<n;j++){
			ll val = a[j][i];
			if((val - 1) % m != i || (val - 1) < i || (val - 1) > (n - 1) * (m) + i) continue;
			rot[((j - ((val - (i + 1)) / m)) + n) % n]++;
		}

		// for(ll j=0;j<n;j++)
		// 	cout << rot[j] << " ";
		// cout << "\n";

		ll mn = n;

		for(ll j=0;j<n;j++){
			ll curr = rot[j];
			ll moves = j + (n - rot[j]);
			mn = min(mn, moves);
		}

		// cout << mn << "\n";

		tot += mn;
	}

	cout << tot << "\n";
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