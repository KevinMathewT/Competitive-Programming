#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll b, k, a[100010];

ll power(ll x, ll p){
	ll ans = 1;

	while(p > 0){
		if(p & 1)
			ans = (ans * x) % 2;
		x = (x * x) % 2;
		p = (p >> 1);
	}

	return ans;
}

void te(){
	cin >> b >> k;
	for(ll i=0;i<k;i++)
		cin >> a[i];

	ll ans = 0;

	for(ll i=k-1;i>=0;i--){
		ans = (ans + ((a[i] * power(b, k-1-i)) % 2)) % 2;
	}

	if(ans == 1)
		cout << "odd\n";
	else
		cout << "even\n";
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