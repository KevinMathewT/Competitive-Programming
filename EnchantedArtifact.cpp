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

const ll N = 0, M = 1e9 + 7;
string s;

void solve(){
	for(ll i=0;i<300;i++) cout << 'a';
	cout << endl;
	ll x; cin >> x;
	if(x == 0) exit(0);
	ll numa	= 300 - x;

	for(ll i=0;i<300;i++) cout << 'b';
	cout << endl;
	cin >> x;
	if(x == 0) exit(0);
	ll numb = 300 - x;

	if(numa == 0){
		for(ll i=0;i<numb;i++) cout << 'b';
		cout << endl;
		ll x; cin >> x;
		exit(0);
	}

	if(numb == 0){
		for(ll i=0;i<numa;i++) cout << 'a';
		cout << endl;
		ll x; cin >> x;
		exit(0);
	}

	string s = "";
	for(ll i=0;i<numa+numb;i++)
		s.push_back('a');

	ll c = numb;x
	for(ll i=0;i<numa+numb;i++){
		s[i] = 'b';
		cout << s << endl;
		cin >> x;
		if(x == 0) exit(0);
		if(x >= c) s[i] = 'a';
		else c = x;
	}

	cout << s << endl;
	cin >> x;
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