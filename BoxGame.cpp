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

ll n, k, p, a[110];

void solve(){
	cin >> n >> k >> p;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll atry = *max_element(a, a + n);
	ll btry = *min_element(a, a + n);

	if(p == 0){
		if(k % 2 == 1 || n == 1){
			cout << atry << "\n";
			return;
		}

		ll x = LLONG_MIN;
		for(ll i=0;i<n;i++){
			if(a[i] == atry && i == 0)
				x = max(x, a[i + 1]);
			else if(a[i] == atry && i == n-1)
				x = max(x, a[i - 1]);
			else if(a[i] == atry)
				x = max(x, min(a[i + 1], a[i - 1]));
		}

		for(ll i=0;i<n;i++){
			if(i == 0)
				x = max(x, a[i + 1]);
			if(i == n-1)
				x = max(x, a[i - 1]);
			else
				x = max(x, min(a[i + 1], a[i - 1]));
		}

		cout << x << "\n";
	}
	else{
		if(k % 2 == 1 || n == 1){
			cout << btry << "\n";
			return;
		}

		ll x = LLONG_MAX;
		for(ll i=0;i<n;i++){
			if(a[i] == btry && i == 0)
				x = min(x, a[i + 1]);
			else if(a[i] == btry && i == n-1)
				x = min(x, a[i - 1]);
			else if(a[i] == btry)
				x = min(x, max(a[i + 1], a[i - 1]));
		}

		for(ll i=0;i<n;i++){
			if(i == 0)
				x = min(x, a[i + 1]);
			if(i == n-1)
				x = min(x, a[i - 1]);
			else
				x = min(x, max(a[i + 1], a[i - 1]));
		}

		cout << x << "\n";
	}
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