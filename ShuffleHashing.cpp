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

string s, t;

void solve(){
	cin >> s >> t;

	ll f1[26];
	fill(f1, f1 + 26, 0);

	for(ll i=0;i<s.size();i++)
		f1[s[i] - 'a']++;

	ll f2[26];

	for(ll i=0;i<t.size();i++){
		fill(f2, f2 + 26, 0);

		for(ll j=0;j<s.size();j++){
			if((i + j) > t.size()) break;

			f2[t[i + j] - 'a']++;
		}

		ll flag = 1;
		for(ll j=0;j<26;j++)
			if(f1[j] != f2[j])
				flag = 0;

		if(flag){
			cout << "YES\n"; return;
		}
	}

	cout << "NO\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}