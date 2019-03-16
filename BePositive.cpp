#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, a[100010];

void te(){
	cin >> n;
	for(ll i=0;i<n;i++)
		cin >> a[i];

		// cout << ceil((ld)n / 2) << "\n";
	for(ll d=-1000;d<=1000;d++){
		if(d == 0)
			continue;
		ll cnt = 0;

		for(ll i=0;i<n;i++){
			ld x = a[i];
			ld div = d;
			if((x / d) > 0.0)
				cnt++;
		}

		if(cnt >= ceil((ld)n / 2)){
			cout << d << "\n";
			return;
		}
	}

	cout << 0 << "\n";
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