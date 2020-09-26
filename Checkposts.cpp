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

const ll N = 100010, M = 1e9 + 7;
ll n, m, c[N], v[N];
vector<ll> G[N], GR[N], s;

ll dfs(ll u) {
	v[u] = 1;
	for(ll t : G[u]) 
		if(v[t] == 0)
			dfs(t);
	s.push_back(u);
}

ll dfs1(ll u, vector<ll> &vec) {
	vec.push_back(u);
	v[u] = 1;
	for(ll t : GR[u])
		if(v[t] == 0)
			dfs1(t, vec);
}

void solve(){
	cin >> n;
	fi(1, n) cin >> c[i];
	cin >> m;
	fi(1, m) {
		ll u, v; cin >> u >> v;
		G[u].push_back(v);
		GR[v].push_back(u);
	}

	fill(v, v + n + 1, 0LL);

	fi(1, n) if(v[i] == 0) dfs(i);

	// cout << s << "\n";

	reverse(s.begin(), s.end());
	vector<vector<ll> > vv;
	fill(v, v + n + 1, 0LL);

	fi(0, n - 1) 
		if(v[s[i]] == 0) {
			vv.push_back(vector<ll>(0));
			dfs1(s[i], vv.back());
		}

	// cout << s << "\n";
	// cout << vv << '\n';

	ll tot = 0, p = 1;
	fi(0, vv.size() - 1) {
		ll mn = LLONG_MAX, pp = 0;
		fj(0, vv[i].size() - 1) mn = min(mn, c[vv[i][j]]);
		fj(0, vv[i].size() - 1) if(c[vv[i][j]] == mn) pp= (pp + 1) % M;

		tot += mn;
		p = (p * pp) % M;
	}

	cout << tot << ' ' << p << "\n";
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