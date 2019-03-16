#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll x1, y_first, x2, y2, n, x[200010], y[200010];
char d[200010];

void te(){
	cin >> x1 >> y_first >> x2 >> y2 >> n;

	for(ll i=1;i<=n;i++){
		cin >> d[i];
	}

	// ll pos;

	// ll flag = 0;
	// if(y2 == 999999999){
	// 	for(ll i=0;i<=n;i++)
	// 		if(d[i] == 'U'){
	// 			pos = i;
	// 			flag++;
	// 		}
	// }

	// if(flag > 0)
	// 	cout << pos << " " << flag << "\n";

	x[0] = y[0] = 0;
	for(ll i=1;i<=n;i++){
		x[i] = x[i-1];
		y[i] = y[i-1];

		if(d[i] == 'U')
			y[i] = y[i-1] + 1;
		if(d[i] == 'D')
			y[i] = y[i-1] - 1;
		if(d[i] == 'R')
			x[i] = x[i-1] + 1;
		if(d[i] == 'L')
			x[i] = x[i-1] - 1;
	}

	// for(ll i=0;i<=n;i++)
	// 	cout << x[i] << " " ;
	// cout << "\n";
	// for(ll i=0;i<=n;i++)
	// 	cout << y[i] << " " ;
	// cout << "\n";

	ll l = 1, r = 10000000000000010;
	ll best = LLONG_MAX;

	while(l <= r){
		ll mid = (l + r) / 2;

		ll x_next = x1 + ((mid / n) * x[n]) + x[(mid % n)];
		ll y_next = y_first + ((mid / n) * y[n]) + y[(mid % n)];

		// cout << mid << " " << x_next << " " << y_next << "\n";

		if((abs(x2 - x_next) + abs(y2 - y_next)) <= mid){
			best = min(best, mid);
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}

	if(best == LLONG_MAX)
		cout << -1 << "\n";
	else
		cout << best << "\n";
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