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

ll n, a, b;
unordered_map<ll, unordered_map<ll, ll> > fren, notf;

void solve(){
	cin >> n >> a >> b;

	for(ll i=0;i<a;i++){
		ll u, v;
		cin >> u >> v;
		fren[u][v] = 1;
		fren[v][u] = 1;
	}

	for(ll i=0;i<a;i++){
		ll u, v;
		cin >> u >> v;
		notf[u][v] = 1;
		notf[v][u] = 1;
	}

	for(ll i=1;i<=n;i++){
		vector<ll> sol(n + 1, i);
		vector<ll> vis(n + 1, 0);
		vis[i] = 1;
		for(ll j=2;j<=n;j++){
			cout << sol << "\n";
			ll sz = sol.size();
			for(ll k=1;k<=n;k++)
				if(fren[sol.back()][k] == 1 && vis[k] == 0){
					vis[k] = 1;
					sol[j] = k;
					break;
				}

			if(sol.size() == sz)
				for(ll k=1;k<=n;k++)
					if(vis[k] == 0 && notf[sol.back()][k] == 0){
						vis[k] = 1;
						sol[j] = k;
						break;
					}
		}
		if(sol.size() == n + 1){
			cout << sol << "\n";
			return;
		}
	}

	cout << -1 << "\n";
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