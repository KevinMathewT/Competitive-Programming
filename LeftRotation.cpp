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

ll n, r, a[100010];

void solve(){
	cin >> n >> r;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	//First Swap
	for(ll i=0;i<r/2;i++)
		swap(a[i], a[r-i-1]);

	// for(ll i=0;i<n;i++)
	// 	cout << a[i] << " ";
	// cout << "\n";

	//Second Swap
	for(ll i=r;i<(n+r)/2;i++)
		swap(a[i], a[n+r-i-1]);

	// for(ll i=0;i<n;i++)
	// 	cout << a[i] << " ";
	// cout << "\n";

	//Final Swap
	for(ll i=0;i<n/2;i++)
		swap(a[i], a[n-i-1]);

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