#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, k;

void te(){
	cin >> n >> m >> k;
	if(n > m){
		ll t = n;
		n = m;
		m = t;
	}

	ll l = 1, r = n * m;

	ll min_pos = 0, max_pos = 0, mid;

	while(l <= r){
		mid = (l + r) / 2;
		// cout << mid << "\n";
		min_pos = 0;

		for(ll i=1;i<=n;i++){
			min_pos += min(m, (mid-1) / i);
		}

		min_pos++;

		// cout << min_pos << "-\n";

		ll freq = 0;

		for(ll i=1;i*i<=mid;i++){
			if(mid % i == 0){
				if(i * i == mid && i <= n && i <= m)
					freq++;
				else{
					if(mid / i <= n && i <= m)
						freq++;
					if(mid / i <= m && i <= n)
						freq++;
				}
			}
		}

		// cout << freq << "\n";

		if(k >= min_pos && k <= min_pos + freq - 1){
			cout << mid << "\n";
			break;
		}
		else{
			if(k < min_pos)
				r = mid - 1;
			else
				l = mid + 1;
		}
	}
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