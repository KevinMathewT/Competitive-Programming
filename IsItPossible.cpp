#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll d, m, a[15], vis[1010];

void solve(){
	cin >> d >> m;
	for(ll i=0;i<d;i++) cin >> a[i];

	ll flag = 0;
	
	queue<ll> q;
	q.push(0);

	while(!q.empty()){
		ll x = q.front(); q.pop();
		vis[x] = 1;

		if(x == 0 && flag == 1){
			cout << "YES\n";
			return;
		}
		else if(x == 0) flag = 1, vis[x] = 0;

		for(ll i=0;i<d;i++){
			ll y = ((x * 10) + a[i]) % m;
			if(vis[y] != 1){
				if(y == 0 && flag == 1){
					cout << "YES\n";
					return;
				}
				else if(y == 0) flag = 1, vis[x] = 0;

				q.push(y);
			}
		}
	}

	cout << "NO\n";
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