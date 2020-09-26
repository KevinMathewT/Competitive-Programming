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

const ll N = 110, M = 1e9 + 7;
ll n, d[N], o;
string s, t;
vector<pair<ll, ll> > v;

void solve(ll cs){
	cin >> s;
	n = s.size();
	v.clear();
	t = "";
	o = 0;

	v.push_back({s[0] - '0', 1});

	fi(1, s.size() - 1)
		if((s[i] - '0') == v.back().F) v.back().S++;
		else v.push_back({s[i] - '0', 1});

	fill(d, d + N, 0LL);

	n = v.size();

	fi(1, v[0].F) t.push_back('(');
	o = v[0].F;

	fi(0, n - 2){
		fj(1, v[i].S) t.push_back(to_string(v[i].F)[0]);
		ll temp = o;
		fj(1, temp - v[i + 1].F) t.push_back(')'), o--;
		temp = o;
		fj(1, v[i + 1].F - temp) t.push_back('('), o++;
	}

	fi(1, v.back().S) t.push_back(to_string(v.back().F)[0]);
	fi(1, v.back().F) t.push_back(')');

	cout << "Case #" << cs << ": " << t << "\n";
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