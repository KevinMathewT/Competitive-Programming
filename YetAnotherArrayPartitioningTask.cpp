#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, k, a[200010], taken[200010];

void te(){
	cin >> n >> m >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	priority_queue<pair<ll, ll>> pq;

	for(ll i=0;i<n;i++){
		pq.push(make_pair(a[i], i+1));
	}

	ll vec[200010];
	ll it = 0;

	for(ll i=0;i<n;i++){
		pair<ll, ll> pll = pq.top();
		pq.pop();
		vec[it++] = pll.second;
	}

	for(ll i=0;i<n-1;i++){
		for(ll j=i+1;i<n;j++){
			if()
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}