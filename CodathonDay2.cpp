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

const ll N = 1010, M = 1e9 + 7;
ll n, q, a[N][N], q1[N], q2[N];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) 
		for(ll j=0;j<n;j++) 
			cin >> a[i][j];
	cin >> q;
	fill(q1, q1 + N, 0);
	fill(q2, q2 + N, 0);
	while(q--){
		ll t;
		cin >> t;
		if(t == 1){
			ll p, q, r; cin >> p >> q >> r; p--; q--;
			q1[p] ^= r;
			q1[q + 1] ^= r;
		}
		else{
			ll p, q, r; cin >> p >> q >> r; p--; q--;
			q2[p] ^= r;
			q2[q + 1] ^= r;
		}
	}

	for(ll i=1;i<n;i++) q1[i] ^= q1[i-1];
	for(ll i=1;i<n;i++) q2[i] ^= q2[i-1];

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			a[i][j] ^= q1[i];

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			a[i][j] ^= q2[j];

	ll tot = 0;
	for(ll i=0;i<n;i++) tot += a[i][i];

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