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

const ll N = 500010, M = 1e9 + 7;
ll n, a[N];
string s;

void solve(){
	cin >> s;
	n = s.size();

	s = "$" + s;

	// cout << "  ";
	// fi(1, n) cout << s[i] << ' ';
	// cout << "\n";
	fi(0, n) a[i] = -1;
	if(s[1] == '<') a[0] = 0;
	if(s[n] == '>') a[n] = 0;

	fi(1, n - 1) if(s[i] == '>' && s[i + 1] == '<') a[i] = 0;
	fi(1, n - 1) if(s[i] == '<' && s[i + 1] == '<') a[i] = a[i - 1] + 1;
	fid(n, 2) if(s[i] == '>' && s[i - 1] == '>') a[i - 1] = a[i] + 1;
	fi(1, n - 1) if(s[i] == '<' && s[i + 1] == '>') a[i] = max(a[i - 1], a[i + 1]) + 1;

	if(s[1] == '>') a[0] = a[1] + 1;
	if(s[n] == '<') a[n] = a[n - 1] + 1;

	// fi(0, n) cout << a[i] << ' ';
	// cout << '\n';
	cout << accumulate(a, a + n + 1, 0LL) << "\n";
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