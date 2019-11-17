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

ll n, m, a[100010];

void solve(){
	while(cin >> n){
		cin >> m;
		for(ll i=0;i<n;i++)
			cin >> a[i];

		ll l = 0, r = 0, curr = a[0], flag = 1;

		while(l < n && r < n && l <= r){
			if(curr == m){
				cout << l + 1 << " " << r + 1 << "\n";
				flag = 0;
				break;
			}

			if(curr > m){
				if(l == r){
					curr = a[++l];
					r++;
					continue;
				}
				curr -= a[l++];
				continue;
			}
			if(curr < m){
				curr += a[++r];
				continue;
			}
		}

		if(flag)
			cout << -1 << "\n";
	}
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