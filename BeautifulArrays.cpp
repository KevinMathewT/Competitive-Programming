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

	if(n == 1){
		cout << "yes\n";
		return;
	}

	sort(a, a + n);
	unordered_map<ll, ll> m;

	for(ll i=0;i<n;i++)
		m[a[i]] = 1;

	for(ll i=1;i<n;i++){
		ll mul = a[i] * a[i-1];
		if(m[mul] == 0){
			cout << "no\n";
			return;
		}
	}

	ll mul = a[0] * a[n-1];
	if(m[mul] == 0){
		cout << "no\n";
		return;
	}

	cout << "yes\n";
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