#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010], b[100010];;

void te(){
	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b, b + n);

	ll h = b[n-1];

	ll ans = 0;
	ll mx = 1;
	for(ll i=0;i<n;i++){
		if(a[i] == h){
			ans++;
			mx = max(mx, ans);
		}
		else
			ans = 0;
	}

	cout << mx << "\n";
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