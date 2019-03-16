#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[200010], odd[200010], even[200010];

void te(){
	cin >> n;
	for(ll i=1;i<=n;i++)
		cin >> a[i];

	odd[0] = even[0] = 0;
	odd[n+1] = even[n+1] = 0;
	odd[1] = a[1];
	even[1] = 0;

	for(ll i=2;i<=n;i++){
		odd[i] = odd[i-1];
		even[i] = even[i-1];
		if(i % 2 == 0)
			even[i] = a[i] + even[i-1];
		else
			odd[i] = a[i] + odd[i-1];
	}

	ll ans = 0;

	for(ll i=1;i<=n;i++){
		if((even[i-1] + odd[n] - odd[i]) == (even[n] - even[i] + odd[i-1])){
			// cout << i << "\n";
			ans++;
		}
	}

	cout << ans << "\n";
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