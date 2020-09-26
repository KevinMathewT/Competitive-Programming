#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll i=(a);i>=b;j--)

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

const ll N = 300010, M = 1e9 + 7;
ll n, m;
string s, t, s0, s1, s2;
char c0, c1;

void solve(){
	cin >> s >> t;

	if(s.size() != t.size()) {
		cout << "IMPOSSIBLE";
		return;
	}

	if(s.compare(t) == 0) {
		cout << s << 'a' << "";
		return;
	}

	if(s.size() == 1) {
		cout << s << t << "";
		return;
	}

	ll cr1 = -1;
	fi(0, s.size() - 1)
		if(s[i] != t[i]) {
			cr1 = i;
			break;
		}

	if(cr1 == -1) {
		cout << "IMPOSSIBLE";
		return;
	}

	s0 = s.substr(0, cr1);

	ll cr2 = -1;
	fid(s.size() - 1, 0) {
		if(s[i] != t[i]) {
			cr2 = i;
			break;
		}
	}

	if(cr2 == -1) {
		cout << "IMPOSSIBLE";
		return;
	}

	s1 = s.substr(cr2 + 1);

	string che1, che2, che3, che4;
	if(cr1 == cr2) {
		che1 = "";
		che2 = "";
		che2.push_back(s[s0.size()]);
		che3 = "";
		che3.push_back(t[t.size() - s1.size() - 1]);
		che4 = "";
	} else { 
		che1 = s.substr(cr1 + 1, cr2 - cr1);
		che2 = s.substr(cr1, cr2 - cr1);
		che3 = t.substr(cr1 + 1, cr2 - cr1);
		che4 = t.substr(cr1, cr2 - cr1);
	}

	if(che1 != che4 && che2 != che3) {
		cout << "IMPOSSIBLE";
		return;
	}

	if(che1 == che4) {
		cout << s0 << che2[0] << che1 << che3[che3.size() - 1] << s1 << "";
		return;
	}

	if(che2 == che3) {
		cout << s0 << che4[0] << che2 << che1[che1.size() - 1] << s1 << "";
		return;
	}
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}