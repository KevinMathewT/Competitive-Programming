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

const ll M = 1e9 + 7;
ll x, l, tot, lim;
string s;

void solve(){
	cin >> x;
	cin >> s;
	// cout << s.size() << '\n';

	l = 1;
	tot = s.size();

	while(true){
		// cout << l << ' ' << tot << '\n';
		lim = s.size();
		tot = (tot + ((s[l-1] - '0' - 1) * (tot - l))) % M;
		if(l >= s.size() || l >= x) break;
		for(ll i=0;i<s[l-1] - '0' -1;i++){
			for(ll j=l;j<lim;j++){
				s.push_back(s[j]);
				if(s.size() >= x){
					for(ll k=l + 1;k<=x;k++)
						tot = (tot + ((s[k-1] - '0' - 1) * (tot - k))) % M;
					cout << ((tot % M) + M) % M << "\n";
					return;
				}
			}
		}

		l++;
	}

	cout << ((tot % M) + M) % M << "\n";
}

int main()
{
	// freopen("input.txt", "r", - stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}