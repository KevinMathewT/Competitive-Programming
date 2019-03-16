#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];

	sort(a, a+n);
	ll corr = 0;

	for(ll k=1;k<=10;k++){
		ll sum = 0;
		for(ll i=n-1;i>=1;i--)
			for(ll j=i-1;j>=0;j--)
				sum += pow(a[i]-a[j], k);
		if(k == 1)
			corr = sum;
		cout << sum / corr << ",";
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