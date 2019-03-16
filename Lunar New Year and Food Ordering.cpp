#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[100010], c[100010];
pair<ll, ll> temp[100010];

void te(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<n;i++){
		cin >> c[i];
		temp[i].first = c[i];
		temp[i].second = i;
	}

	sort(temp, temp+n);

	ll last = temp[0].second;

	for(ll i=0;i<m;i++){
		ll t, d;
		cin >> t >> d;
		ll sum = 0;
		t--;

		if(a[t] >= d){
			sum += c[t] * d;
			a[t] -= d;
			cout << sum << "\n";
			continue;
		}
		else{
			sum += c[t] * a[t];
			d -= a[t];

			while(d > 0){
				if(a[last] >= d){
					sum += c[last] * d;
					a[t] -= d;
					cout << sum << "\n";
					continue;
				}
			}
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