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

string s;

void solve(){
	cin >> s;
	for(ll i=0;i<s.size();i++){
		if(s[i] == '?'){
			if(i == 0)
				s[i] = 'a';
			else
				if(s[i-1] == 'a') s[i] = 'b';
				else if(s[i-1] == 'b') s[i] = 'c';
				else s[i] = 'a';

			if(i != s.size() - 1){
				if(s[i + 1] == '?')
					continue;
				if(i == 0)
					if(s[i+1] == 'a') s[i] = 'b';
					else if(s[i+1] == 'b') s[i] = 'c';
					else s[i] = 'a';
				else{
					if(s[i-1] == s[i+1])
						if(s[i+1] == 'a') s[i] = 'b';
						else if(s[i+1] == 'b') s[i] = 'c';
						else s[i] = 'a';
					else
						s[i] = 'a' + 'b' + 'c' - s[i-1] - s[i+1];
				}
			}
		}
	}

	for(ll i=0;i<s.size() - 1;i++)
		if(s[i] == s[i+1]){
			cout << -1 << "\n";
			return;
		}

	cout << s << "\n";
}

int main()
{
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