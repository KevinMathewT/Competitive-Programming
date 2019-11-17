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

ll n, a[200010], diff[200010];

void solve(){
	cin >> n;

	if(n == 2 || n == 3){
		cout << 1 << "\n";
		return;
	}

	map<ll, ll> pos;

	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=n-1;i>=0;i--)
		pos[a[i]] = i + 1;

	sort(a, a + n);

	if(n == 4){
		for(ll i=0;i<n;i++){
			vector<ll> v(0);
			for(ll j=0;j<n;j++)
				if(i != j)
					v.push_back(a[j]);
			vector<ll> diff(0);
			for(ll i=1;i<3;i++)
				diff.push_back(v[i] - v[i-1]);

			if(diff[0] == diff[1]){
				cout << pos[a[i]] << "\n";
				return;
			}
		}
	}

	for(ll i=1;i<n;i++)
		diff[i] = a[i] - a[i - 1];

	map<ll, ll> mp;
	for(ll i=1;i<n;i++)
		mp[diff[i]]++;

	ll mx =  diff[0], freq = 1;

	for(ll i=1;i<n;i++)
		if(mp[diff[i]] > freq){
			mx = diff[i];
			freq = mp[diff[i]];
		}

	cout << mx << " " << freq << "\n";

	if(freq == n - 1){
		cout << pos[a[0]] << "\n";
		return;
	}
	if(freq < n - 3){
		cout << -1 << "\n";
		return;
	}
	else{
		if(diff[1] != mx && diff[2] == mx && freq >= n-2){
			cout << pos[a[0]] << "\n";
			return;
		}
		if(diff[n-1] != mx && diff[n-2] == mx && freq >= n-2){
			cout << pos[a[n - 1]] << "\n";
			return;
		}
		for(ll i=1;i<n-1;i++){
			// cout << diff[i] << " ";
			if(diff[i] != mx && diff[i] + diff[i + 1] ==  && a[i+1] - a[i-1] == mx){
				cout << pos[a[i]] << "\n";
				return;
			}
		}
		// cout << "\n";
	}

	cout << -1 << "\n";
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