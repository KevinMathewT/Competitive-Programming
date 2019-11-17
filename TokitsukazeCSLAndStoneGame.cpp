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

	sort(a, a + n);

	ll c = 0;

	if(n >= 2){
		for(ll i=1;i<n;i++)
			if(a[i] == a[i-1])
				c++;

		if(c > 1){
			cout << "cslnb\n";
			return;
		}
	}

	if(n >= 3){
		for(ll i=2;i<n;i++)
			if(a[i] == a[i-1] && a[i-1] == a[i-2]){
				cout << "cslnb\n";
				return;
			}
	}

	ll tot = 0;

	for(ll i=0;i<n;i++){
		if(i != 0){
			if(a[i] <= a[i-1])
				break;
		}

		tot += (a[i] - i);
		a[i] = i;
	}

	// cout << tot << "\n";

	if(tot % 2 == 0)
		cout << "cslnb\n";
	else
		cout << "sjfnb\n";
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