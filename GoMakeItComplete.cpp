#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define F first
#define S second
 
// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?
 
ll n, m, d[1000], c[1000], adj[1000][1000], adjc[1000][1000], p;
vector<ll> graph[1000], gc[1000];
vector<vector<ll> > g;
 
ll goforit(ll k, vector<vector<ll> > gr){
	// cout << "------------\n";
	// cout << k << "\n";
	fill(c, c + 510, 0);
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			// cout << gr[i][j] << " ";
			if((i > j) && gr[i][j] == 1){
				c[i]++;
				c[j]++;
			}
		}
		// cout << "\n";
	}
 
	// for(ll i=0;i<n;i++)
	// 	cout << c[i] << " ";
	// cout << "\n";
 
	ll bef = accumulate(c, c + n, (ll) 0);
	// cout << bef << " " << ((n * (n - 1))) << "-\n";
	if(bef == ((n * (n - 1)))){
		// cout << "Returning 1\n";
		return 1LL;
	}
 
	// cout << '\n';
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if((i > j) && (gr[i][j] == 0) && (((c[i]) + (c[j])) >= k)){
				gr[i][j] = 1;
				c[i]++;
				c[j]++;
			}
		}
		// cout << "\n";
	}
 
	// for(ll i=0;i<n;i++){
	// 	for(ll j=0;j<n;j++){
	// 		cout << gr[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// for(ll i=0;i<n;i++)
	// 	cout << c[i] << " ";
	// cout << "\n";
 
 
	ll aft = accumulate(c, c + n, (ll) 0);
 
	// cout << "------------\n";
	if(bef == aft)
		return 0;
	return goforit(k, gr);
}
 
void solve(){
	cin >> n >> m;
	for(ll i=0;i<510;i++)
		for(ll j=0;j<510;j++)
			adj[i][j] = 0;
	fill(d, d + 510, 0);
	for(ll i=0;i<510;i++)
		g.push_back(vector<ll>(510, 0));
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		u--; v--;
		g[u][v] = 1;
		g[v][u] = 1;
	}
 
	ll l = 0, r = (2 * n) - 4, best = 0;
 
	while(l <= r){
		// cout << l << " " << r << "////////////\n";
		ll mid = (l + r) / 2;
		// cout << goforit(mid, g) << "///\n";
		if(goforit(mid, g) == 1){
			best = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
 
	cout << best << "\n";
}
 
int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
 
	solve();
 
	return 0;
}