#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
#define fi(a, b) for(ll i=(a);i<=b;i++)
#define fj(a, b) for(ll j=(a);j<=b;j++)
#define fid(a, b) for(ll i=(a);i>=b;i--)
#define fjd(a, b) for(ll j=(a);j>=b;j--)

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

const ll N = 100, M = 1e9 + 7;
ll n, st[N], en[N];
string s[N];

void solve(ll cs){
	cin >> n;
	fi(0, n - 1) cin >> s[i];

	string lp = "", ls = "";
	ll csp = 0, css = 0;

	fi(0, n - 1) {
		string p = "";
		fj(0, s[i].size() - 1) if(s[i][j] != '*') p.push_back(s[i][j]); else { st[i] = j; break; }
		fj(0, min((ll) p.size() - 1, (ll) lp.size() - 1)) if(p[j] != lp[j]) {
			cout << "Case #" << cs << ": " << "*\n";
			return;
		}
		if(p.size() > lp.size()) lp = p;
	}

	fi(0, n - 1) {
		string p = "";
		fjd(s[i].size() - 1, 0) if(s[i][j] != '*') p.push_back(s[i][j]); else { en[i] = j; break; }
		fj(0, min((ll) p.size() - 1, (ll) ls.size() - 1)) if(p[j] != ls[j]) {
			cout << "Case #" << cs << ": " << "*\n";
			return;
		}
		if(p.size() > ls.size()) ls = p;
	}

	reverse(ls.begin(), ls.end());

	string ns = "";
	fi(0, n - 1) {
		fj(st[i] + 1, en[i] - 1) if(s[i][j] != '*') ns.push_back(s[i][j]);
	}

	cout << "Case #" << cs << ": " << lp << ns << ls << "\n";
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	fi(1, T)
		solve(i);

	return 0;
}