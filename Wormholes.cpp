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

ll n, x, y, s[100010], e[100010], v[100010], w[100010];

void solve(){
	cin >> n >> x >> y;
	for(ll i=0;i<n;i++)
		cin >> s[i] >> e[i];
	for(ll i=0;i<x;i++)
		cin >> v[i];
	for(ll i=0;i<y;i++)
		cin >> w[i];

	sort(v, v + x);
	sort(w, w + y);
	
	ll ans = LLONG_MAX;

	for(ll i=0;i<n;i++){
		ll enter = LLONG_MIN, exit = LLONG_MAX;
		ll l = 0, r = x - 1, mid;
		
		while(l <= r){
			mid = l + ((r - l) / 2);
			if(v[mid] <= s[i]){
				enter = max(v[mid], enter);
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}

		l = 0, r = y - 1, mid;
		
		while(l <= r){
			mid = l + ((r - l) / 2);
			if(w[mid] >= e[i]){
				exit = min(w[mid], exit);
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}

		ans = min(ans, exit - enter + 1);
	}

	cout << ans << "\n";
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