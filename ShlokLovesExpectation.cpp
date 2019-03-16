#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[1000010], freq[1000010], m = 1000000007;
ll ans;
unordered_map<ll, ll> um;

ll pow(ll x, ll a){
	ll ret = 1;
	while(a > 0){
		if(a & 1)
			ret = (ret * x) % m;
		x = (x * x) % m;
		a /= 2;
	}

	return ret;
}

void te(){
	ans = 0;
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<1000010;i++)
		freq[i] = 0;
	for(ll i=0;i<n;i++)
		freq[a[i]]++;

	sort(a, a + n);

	for(ll i=0;i<n;i++){
		if(um[a[i]] == 0){
			ll f = 0, add = 0;
			for(ll j=i;j<1000010;j++){
				f += freq[j];
				add += 
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