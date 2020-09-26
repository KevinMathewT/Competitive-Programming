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
ll n, x, a[N], b[N], d[N], c[N];
string s;

void solve(){
	cin >> n >> x;
	cin >> s;

	a[0] = 0;
	b[0] = 0;
	if(s[0] == '0') a[0] = 1; else b[0] = 1;

	for(ll i=1;i<n;i++){
		if(s[i] == '0') a[i] = a[i-1] + 1, b[i] = b[i - 1];
		else a[i] = a[i-1], b[i] = b[i - 1] + 1;
	}

	for(ll i=0;i<n;i++) d[i] = a[i] - b[i];
	c[0] = d[0];
	for(ll i=1;i<n;i++) c[i] = c[i - 1] + d[i];

	ll tot = 0;
	ll full = d[n - 1];
	if(x == 0) tot++;

	for(ll i=0;i<n;i++){
		ll curr = a[i] - b[i];
		// curr + k * full == x

		if(curr == x && full == 0){
			cout << "-1\n";
			return;
		}

		if(full != 0 && (x - curr) % full == 0 && (x - curr) / full >= 0) tot++; 
	}

	cout << tot << "\n";
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