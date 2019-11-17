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
vector<pair<pair<ll, ll>, ll> > v;
unordered_map<ll, ll> m;

void solve(){
	v.clear();
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n;i++)
		v.push_back(make_pair(make_pair(abs(a[i]), a[i]), i));

	ll c = 0;
	for(ll i=0;i<n;i++)
		if(a[i] < 0)
			c++;

	sort(v.begin(), v.end());

	ll l = 0, r = 0;
	while(l <= r && l < n && r < n){
		for(;l<n;l++)
			if(v[l].first.second > 0){
				break;
			}

		if(l == n)
			break;
		r = l + 1;
		for(;r<n;r++)
			if(v[r].first.second > 0){
				break;
			}
		if(r == n)
			break;

		v[l].first.first = v[l].first.first + 1;
		v[l].first.second = -v[l].first.second - 1;
		v[r].first.first = v[r].first.first + 1;
		v[r].first.second = -v[r].first.second - 1;
	}

	if(l < n && c % 2 == 1){
		v[l].first.first = v[l].first.first + 1;
		v[l].first.second = -v[l].first.second - 1;
		ll b[n];
		for(ll i=0;i<n;i++)
			b[v[i].second] = v[i].first.second;
		for(ll i=0;i<n;i++){
			cout << b[i] << " ";
		}
		return;
	}

	else if(l >= n && c % 2 == 0){
		ll b[n];
		for(ll i=0;i<n;i++)
			b[v[i].second] = v[i].first.second;
		for(ll i=0;i<n;i++){
			cout << b[i] << " ";
		}
		return;
	}

	else if(l < n && c % 2 == 0){
		sort(v.begin(), v.end());
		for(l=0;l<n;l++)
			if(v[l].first.second > 0)
				break;
		v[l].first.first = v[l].first.first + 1;
		v[l].first.second = -v[l].first.second - 1;
		v[n-1].first.first = v[n-1].first.first + 1;
		v[n-1].first.second = -v[n-1].first.second - 1;
		ll b[n];
		for(ll i=0;i<n;i++)
			b[v[i].second] = v[i].first.second;
		for(ll i=0;i<n;i++){
			cout << b[i] << " ";
		}
		return;
	}

	else{
		sort(v.begin(), v.end());
		v[n-1].first.first = v[n-1].first.first + 1;
		v[n-1].first.second = -v[n-1].first.second - 1;
		ll b[n];
		for(ll i=0;i<n;i++)
			b[v[i].second] = v[i].first.second;
		for(ll i=0;i<n;i++){
			cout << b[i] << " ";
		}
		return;
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