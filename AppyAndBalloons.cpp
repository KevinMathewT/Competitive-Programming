#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, m;
	cin >> n >> m;
	ll a[n], b[n];
	for(ll i=0;i<n;i++)
		cin >> a[i];
	for(ll i=0;i<n;i++)
		cin >> b[i];

	ll maxmul = LLONG_MIN;

	for(ll i=0;i<n;i++)
		maxmul = max(maxmul, a[i]*b[i]);

	ll l = 0, h = 2 * maxmul, mx, mid, x;
	ll flag = 0;
	while(l <= h && flag == 0){
		if(l == h)
			flag = 1;
		ll t = 0;
		mx = 0;
		mid = (l + h) / 2;
		// cout << l << " " << mid << " " << h << "-\n";
		for(ll i=0;i<n;i++){
			if(a[i]*b[i] <= mid){
				mx = max(mx, a[i] * b[i]);
				continue;
			}	
			x = mid / b[i];
			mx = max(mx, ((x) * b[i]));
			t += a[i] - (x);
			// cout << i + 1 << " "  << a[i] << " "  << b[i] << " " << x << "\n";
		}
		// cout << mx << " "  << t << "--\n";
		if(t > m)
			l = mid + 1;
		else
			h = mid;
	}

	cout << mx << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(NULL);							//or this.

	// const clock_t begin_time = clock();
	te();
	// cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC;

	return 0;
}