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

const ll N = 100000, M = 1e9 + 7;
ll n, x, d[N], dp[N];
char y[N];
string s;

ll power(ll a, ll x){
	a %= M;
	if(x == 0) return 1;
	if(x == 1) return a;
	if(x % 2 == 0) return power((a * a) % M, x / 2);
	return (a * (power((a * a) % M, x / 2))) % M;
}

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++) cin >> d[i];
	cin >> s;

	if(n == 0) { cout << "No\n"; return; }
	if(n >= 1){
		sort(y, y + n);
		unordered_map<char, ll> m;
		for(ll i=0;i<n;i++) y[i] = to_string(d[i])[0], m[y[i]] = 1;
		for(ll i=0;i<s.size();i++) if(m.find(s[i]) == m.end()) { cout << "No\n"; return; }
		m.clear();
		vector<char> v;
		for(ll i=0;i<n;i++) if(m.find(y[i]) == m.end()) v.push_back(y[i]), m[y[i]] = 1;
		for(ll i=0;i<v.size();i++) y[i] = v[i];
		n = v.size();

		sort(y, y + n);
		for(ll i=0;i<n;i++) m[y[i]] = i;
		
		ll rank = 0;
		if(y[0] == '0'){
			for(ll i=0;i<s.size() - 1;i++) rank = (rank + (power(n, i) * ((n - (i == 0 ? 0 : 1) + M) % M)) % M) % M;
			for(ll i=0;i<s.size();i++) rank = (rank + (((m[s[i]] + ((i == 0  && s.size() != 1) ? -1 : 0) + M) % M) * power(n, s.size() - i - 1)) % M) % M;
			rank++;
		}

		else{
			for(ll i=0;i<s.size() - 1;i++) rank = (rank + power(n, i + 1)) % M;
			for(ll i=0;i<s.size();i++) rank = (rank + (m[s[i]] * power(n, s.size() - i - 1)) % M) % M;
			rank++;
		}

		cout << "Yes\n";
		cout << (rank % M) << "\n";
	}
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