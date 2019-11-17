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

ll n, m, a[200010];

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	cout << 0 << " ";
	ll curr = a[0];

	for(ll i=1;i<n;i++){
		sort(a, a + i);
		curr += a[i];
		// cout << curr << "-\n";
		ll t = curr;

		ll count = 0;

		if(t > m)
			for(ll j=i-1;j>=0;j--){
				t -= a[j];
				count++;
				if(t <= m)
					break;
			}

		cout << count << " ";
	}
	// cout << "\n";
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