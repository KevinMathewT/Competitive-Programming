#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	ll c = 0;
	map<ll, ll> m;
	while(n--){
		ll a, k;
		cin >> a >> k;
		if(a == 1)
			if(m.find(k) == m.end()){
				m[k] = 1;
				c += m[k];
			}
			else{
				m[k]++;
				c += m[k];
			}

		if(a == 0){
			if(m.find(k) == m.end()){
				m[k] = 0;
			}
			else{
				c -= m[k];
				m[k] = max(m[k]-1, (ll)0);
			}
		}
		cout << c << "\n";
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
	for(ll i=0;i<T;i++)
		te();

	return 0;
}