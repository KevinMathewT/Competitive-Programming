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

ll n, h, a[100010];

void solve(){
	cin >> n >> h;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll current = 0, box = 0;

	ll cont = true;

	while(cont){
		ll move;
		cin >> move;

		if(move == 0){
			cont = false;
			continue;
		}

		if(move == 1){
			current = max((ll)0, current - 1);
			continue;
		}

		if(move == 2){
			current = min(n - 1, current + 1);
			continue;
		}

		if(move == 3){
			if(a[current] > 0 && box != 1){
				a[current]--;
				box = 1;
			}
			continue;
		}

		if(move == 4){
			if(a[current] < h && box == 1){
				a[current]++;
				box = 0;
			}
			continue;
		}
	}

	for(ll i=0;i<n;i++)
		cout << a[i] << " ";
	cout << "\n";
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