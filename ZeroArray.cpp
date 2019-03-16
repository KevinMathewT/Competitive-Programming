#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, q;
	cin >> n >> q;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];

	unordered_map<ll, ll> m;
	ll distinct = 0;

	for(ll i=0;i<n;i++){
		if(m[a[i]] == 0 && a[i] != 0)
			distinct++;
		m[a[i]]++;
	}

	while(q--){
		ll b, c, d;
		cin >> b;
		if(b == 1){
			cin >> c >> d;
			if(m[a[c-1]] == 1 && a[c-1] != 0)
				distinct--;
			if(m[d] == 0 && d != 0)
				distinct++;
			
			// cout << m[a[c-1]] << " " << m[d] << "\n";
			m[a[c-1]]--;
			m[d]++;
			// cout << m[a[c-1]] << " " << m[d] << " " << distinct << "\n";

			a[c-1] = d;
		}

		if(b == 2){
			cout << distinct << "\n";
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

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}