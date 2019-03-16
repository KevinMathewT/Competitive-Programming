#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, k, a[110];

void te(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	ll mx = LLONG_MIN;

	ll tot_s = 0, tot_e = 0;
	for(ll i=0;i<n;i++)
		if(a[i] == 1)
			tot_s++;
		else
			tot_e++;

	for(ll i=0;i<k;i++){
		ll st = i;
		ll s = 0, e = 0;
		while(st < n){
			if(a[st] == 1)
				s++;
			else
				e++;
			st += k;
		}

		mx = max(mx, abs((tot_s - s) - (tot_e - e)));
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