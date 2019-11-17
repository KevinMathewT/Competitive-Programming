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

ll n, a[1000010];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	if(n == 1){
		cout << "-1\n";
		return;
	}

	stack<pair<ll, ll> > s;
	s.push({a[n-1], n - 1});
	ll p = -1;

	for(ll i=n-2;i>=0;i--){
		if(a[i] < a[i+1]){
			ll mn = a[i+1];
			ll pos = i + 1;
			for(ll j=i+1;j<n;j++){
				if(a[j] > a[i] && a[j] < mn){
					mn = a[j];
					pos = j;
				}
			}
			p = pos;
			swap(a[i], a[pos]);
			break;
		}
	}

	if(p == -1){
		cout << -1 << "\n";
		return;
	}

	sort(a + p + 1, a + n);
	for(ll i=0;i<n;i++)
		cout << a[i];
	cout << "\n";
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