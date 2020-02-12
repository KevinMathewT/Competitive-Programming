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

const ll N = 200010, M = 998244353;
ll n, m;
string s, t;

void solve(){
	cin >> n >> m;
	cin >> s >> t;

	n = s.size();
	m = t.size();

	reverse(s.begin(), s.end());
	for(ll i=0;i<max(0LL, m - n);i++) s.push_back('0');
	reverse(s.begin(), s.end());

	n = s.size();
	m = t.size();

	reverse(t.begin(), t.end());
	for(ll i=0;i<max(0LL, n - m);i++) t.push_back('0');
	reverse(t.begin(), t.end());

	n = s.size();
	m = t.size();
	
	ll tot = 0, sum = 0, p = 1, p1 = s.size() - 1, p2 = t.size() - 1;

	while(p1 >= 0 && p2 >= 0){
		if(s[p1] == '1') sum = (sum + p) % M;
		if(t[p2] == '1') tot = (tot + sum) % M;
		p = (p * 2) % M;
		p1--;
		p2--;
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