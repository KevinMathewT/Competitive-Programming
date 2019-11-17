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

ll n, x;

void solve(){
	cin >> n >> x;
	// x--;
	ll curr = 1;
	ll i;

	for(i=0;i<n;i++){
		if(x == curr){
			cout << i << "\n";
			return;
		}
		if(x > curr + pow(2, n-i-1) - 1)
			curr += pow(2, n-i-1);
		else
			curr++;
	}

	cout << i << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}