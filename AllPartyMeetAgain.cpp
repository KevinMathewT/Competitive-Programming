#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

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

ll n, a, b, vis[100010];
unordered_map<ll, unordered_map<ll, ll> > fren, notf;
vector<ll> friends[100010], sol;
vector<ll> nonenem[100010];

void dfs(ll u){
	vis[u] = 1;
	
}

void solve(){
	cin >> n >> a >> b;

	for(ll i=0;i<a;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		fren[u][v] = 1;
		fren[v][u] = 1;
		friends[u].push_back(v);
		friends[v].push_back(u);
	}

	for(ll i=0;i<b;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		notf[u][v] = 1;
		notf[v][u] = 1;
	}

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++){
			if(fren[i][j] == 0 && notf[i][j] == 0 && i != j)
				nonenem[i].push_back(j);
		}

	for(ll i=0;i<n;i++){
		sort(friends[i].begin(), friends[i].end());
		sort(nonenem[i].begin(), nonenem[i].end());
		cout << friends[i] << "\n";
		cout << nonenem[i] << "\n";
	}

	sol = vector<ll>(1, 0);
	dfs(0, a);
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}