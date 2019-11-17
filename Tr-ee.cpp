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
	for(ll i=0;i<n;i++){
		char c;
		cin >> c;
		a[i] = c - '0';
	}

	if(a[n-1] == 1 || a[0] == 0){
		cout << -1 << "\n";
		return;
	}

	for(ll i=1;i<n-1;i++)
		if(a[i] ^ a[n - i - 1] == 1){
			cout << -1 << "\n";
			return;
		}

	vector<ll> comp;
	for(ll i=1;i<n;i++)
		if(a[i - 1] == 1 && (i <= (n - i)))
			comp.push_back(i);
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