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

ll n, a[100010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll out = 0;

	ll i = 0, j = 0, last = -1;

	for(ll k=0;k<32;k++){
		i = 0; j = 0, last = -1;
		while(i < n && j < n && i <= j){
			// cout << i << "\n";
			if((a[i] & (1 << k)) != 0){
				// cout << a[i] << " " << (1 << k) << "\n";
				out += ((i + 1) * (1 << k));
				last = i;
			}
			else{
				if(last != -1)
					// cout << a[i] << " " << (1 << k) << "-\n";
				out += ((last + 1) * (1 << k));
				// last = i;
			}
			i++; j++;
		}
	}

	cout << out << "\n";
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