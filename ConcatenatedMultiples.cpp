#include <bits/stdc++.h>
using namespace std;
typedef double ld;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll numOfDigits(ll n){
	ll d = 0;
	while(n > 0){
		d++;
		n /= 10;
	}

	return d;
}

void te(){
	ll n, k;
	cin >> n >> k;

	ll a[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];
	unordered_map<ll, map<ll, ll> > m;

	for(ll i=0;i<n;i++){
		m[numOfDigits(a[i])][(a[i]%k) == k ? 0: a[i]%k]++;
	}

	// for(ll i=0;i<n;i++){
	// 	cout << a[i] << " " << numOfDigits(a[i]) << " " << ((a[i]%k) == k ? 0: a[i]%k) << " " << m[numOfDigits(a[i])][(a[i]%k) == k ? 0: a[i]%k] << "\n";
	// }

	ll tot = 0;
	for(ll i=0;i<n;i++){
		m[numOfDigits(a[i])][(a[i]%k) == k ? 0: a[i]%k]--;
		ll temp = (a[i]%k) == k ? 0: a[i]%k;
		for(ll i=1;i<=10;i++){
			temp = ((((temp%k) * (10%k))) % k) == k ? 0 : (((temp%k) * (10%k)) % k);
			// cout << temp << " " << i << " " << (k-((temp)%k) == k ? 0 : k-((temp)%k)) << "\n";
 			tot += m[i][temp == 0 ? 0 : k - temp];
		}
		m[numOfDigits(a[i])][(a[i]%k) == k ? 0: a[i]%k]++;
	}
	// cout << "\n";

	cout << tot << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}