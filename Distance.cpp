#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010], dist[100010], ans[100010];
vector<ll> v;

void te(){

	for(ll i=0;i<n;i++){
		a[i] = dist[i] = ans[i] = 0;
		v.clear();
	}

	cin >> n;
	for(ll i=1;i<n;i++)
		cin >> a[i];

	dist[0] = 0;
	for(ll i=1;i<n;i++)
		dist[i] = dist[i-1] + a[i];

	for(ll i=0;i<n/2;i++)
		v.push_back(dist[n-i-1] - dist[i]);

	ans[0] = 0;
	ll j = 0;

	for(ll i=1;i<n;i+=2)
		ans[i] = v[j++];
	for(ll i=1;i<n;i++)
		ans[i] = ans[i] + ans[i-1];
	for(ll i=1;i<n;i++)
		ans[i] = ans[i] + ans[i-1];


	for(ll i=0;i<n;i++)
		cout << ans[i] << " ";
	cout << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}