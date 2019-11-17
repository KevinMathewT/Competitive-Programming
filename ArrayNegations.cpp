#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, a[1000010];

void te(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	ll t = k;
	for(ll i=0;i<min(n, k);i++){
		if(a[i] > 0)
			break;
		a[i] = -a[i];
		t--;
	}
	sort(a, a+n);
	if(t % 2 != 0)
		a[0] = -a[0];
	cout << accumulate(a, a+n, 0) << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}