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

ll n, k;

ll go(vector<ll> a, vector<ll> b){
	for(ll i=0;i<k;i++){
		if(a[i] > b[n-1-i])
			break;
		swap(a[i], b[n-i-1]);
	}

	return *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end());
}

void solve(){
	cin >> n >> k;
	vector<ll> a(n, 0), b(n, 0);
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<n;i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	cout << min(go(a, b), go(b, a)) << "\n";
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