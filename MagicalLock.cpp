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

ll n, m, vis[20010];

void solve(){
	cin >> n >> m;
 
	queue<pair<ll, ll> > q;
	q.push({n, 0});

	ll c = 0;
	fill(vis, vis + 20010, 0);

	while(!q.empty()){
		// if(c > 20) break;
		pair<ll, ll> pll = q.front();
		q.pop();

		// cout << pll.F << " " << pll.S << "\n";

		if(pll.F == m){
			cout << pll.S << "\n";
			return;
		}

		if((pll.F - 1) > 0 && vis[pll.F - 1] == 0){
			vis[pll.F - 1] = 1;
			q.push({pll.F - 1, pll.S + 1});
		}

		if((2 * pll.F) > 0 && ((2 * pll.F) < ((ll)(20010))) && vis[2 * pll.F] == 0){
			vis[2 * pll.F] = 1;
			q.push({2 * pll.F, pll.S + 1});
		}
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}