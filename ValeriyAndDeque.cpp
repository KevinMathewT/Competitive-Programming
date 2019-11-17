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

ll n, q, a[100010], b[100010], queries[100010][2];

void solve(){
	cin >> n >> q;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll mx = *max_element(a, a + n);

	deque<ll> d;

	for(ll i=0;i<n;i++){
		d.push_back(a[i]);
	}

	ll lim = n;

	for(ll i=0;i<n;i++){
		if(d.front() == mx){
			lim = i + 1;
			break;
		}

		queries[i + 1][0] = d.front();
		queries[i + 1][1] = d.at(1);

		d.pop_front();
		d.pop_front();
		d.push_front(max(queries[i + 1][0], queries[i + 1][1]));
		d.push_back(min(queries[i + 1][0], queries[i + 1][1]));
	}

	// cin >> q;
	while(q--){
		ll z;
		cin >> z;
		if(z == 1){
			cout << a[0] << " " << a[1] << "\n";
			continue;
		}
		if(z < lim){
			cout << queries[z][0] << " " << queries[z][1] << "\n";
			continue;
		}

		cout << mx << " " << d.at(1 + ((z - lim) % (n - 1))) << "\n";
	}
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