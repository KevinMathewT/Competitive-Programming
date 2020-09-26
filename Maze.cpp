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

const ll N = 510, M = 1e9 + 7;
ll n, m, k, vis[N][N];
char a[N][N];
vector<pair<ll, ll> > v, kaam;

void dfs(ll x, ll y, ll want) {
	if(vis[x][y] == 1) return;
	if(want == kaam.size()) return;

	vis[x][y] = 1;
	kaam.push_back({x, y});

	if(x + 1 >= 0 && x + 1 < n && y >= 0 && y < m && a[x + 1][y] == '.')
		dfs(x + 1, y, want);

	if(x - 1 >= 0 && x - 1 < n && y >= 0 && y < m && a[x - 1][y] == '.')
		dfs(x - 1, y, want);

	if(x >= 0 && x < n && y + 1 >= 0 && y + 1 < m && a[x][y + 1] == '.')
		dfs(x, y + 1, want);

	if(x >= 0 && x < n && y - 1 >= 0 && y - 1 < m && a[x][y - 1] == '.')
		dfs(x, y - 1, want);
}

void solve(){
	cin >> n >> m >> k;
	fi(0, n - 1) fj(0, m - 1) cin >> a[i][j];
	fi(0, n - 1) fj(0, m - 1) if(a[i][j] == '.') v.push_back({i, j});
	fi(0, n - 1) fj(0, m - 1) vis[i][j] = 0;

	dfs(v[0].F, v[0].S, v.size() - k);

	fi(0, n - 1) fj(0, m - 1) if(vis[i][j] == 0 && a[i][j] == '.') a[i][j] = 'X';
	fi(0, n - 1) {
		fj(0, m - 1) cout << a[i][j];
		cout << "\n";
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