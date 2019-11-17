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

ll n, k, a[100010], b[100010];

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> b[i];
	for(ll i=0;i<n;i++)
		cin >> a[i];
	sort(a, a + n);
	sort(b, b + n);

	ll i = 0, j = 0, c = 0;

	while(i < n && j < n){
		if(a[i] > b[j]){
			c++;
			i++;
			j++;
		}
		else
			i++;
	}

	if(c >= k)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}