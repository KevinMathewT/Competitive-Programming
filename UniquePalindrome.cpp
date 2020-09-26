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

const ll N = 110, M = 1e9 + 7, P = 23;
ll x, n;
string s;
unordered_map<ll, ll> m;

ll power(ll a, ll x){
	a %= M;
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	else return (a * power((a * a) % M, x / 2)) % M;
}

ll checkPalin(ll l, ll r){
	while(l < r)
		if(s[l] != s[r]) return 0;
		else l++, r--;
	return 1;
}

void solve(){
	m.clear();
	cin >> s >> x;
	n = s.size();

	ll t1 = 0, z = 0;
	ll hash = 0;

	for(ll i=n-1;i>=n-x;i--)
		hash = (((hash * P) % M) + (s[i] - 'a')) % M;
	hash = (hash + M) % M;

	for(ll i=n-x-1;i>=-1;i--){
		if(checkPalin(i + 1, i + x)){
			if(m.find(hash) == m.end()) {
				t1++, m[hash] = 1;
			}
		}
		if(i == -1) break;
		hash = (hash - (((s[i + x] - 'a') * power(P, x - 1)) % M) + M) % M;
		hash = ((hash * P) % M + (s[i] - 'a')) % M;
	}

	ll t2 = 0;
	x = n - x;
	hash = 0;

	for(ll i=n-1;i>=n-x;i--)
		hash = (((hash * P) % M) + (s[i] - 'a')) % M;
	hash = (hash + M) % M;

	for(ll i=n-x-1;i>=-1;i--){
		if(checkPalin(i + 1, i + x)){
			if(m.find(hash) == m.end()) t2++, m[hash] = 1;
		}
		if(i == -1) break;
		hash = (hash - (((s[i + x] - 'a') * power(P, x - 1)) % M) + M) % M;
		hash = ((hash * P) % M + (s[i] - 'a')) % M;
	}

	cout << t1 + t2 << "\n";
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