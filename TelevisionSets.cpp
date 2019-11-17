#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

ll n, r1, r2, t;

void solve(){
	ll days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	ll day_str[12], day_end[12];

	day_str[0] = 1;
	day_end[0] = days[0];

	for(ll i=1;i<12;i++){
		day_str[i] = day_end[i-1] + 1;
		day_end[i] = day_end[i-1] + days[i];
		// cout << day_str[i] << " " << day_end[i] << "\n";
	}

	cin >> n >> r1 >> r2 >> t;

	// cout << r1 << " " << r2 << "\n";

	swap(r1, r2);

	ll l = 0, r = n, mid, ans = 0;

	while(l <= r){
		mid = (l + r) / 2;
		ll earn = 0;

		for(ll i=1;i<=365;i++){
			ll month, day, curr = days[0];
			// cout << curr << " ";
			for(ll j=0;j<12;j++){
				if(i >= day_str[j] && i <= day_end[j]){
					month = j + 1;
					day = i - (day_str[j]) + 1;
					break;
				}
			}

			// cout << curr << " " << i << " " << month << " " << day << " - \n";

			ll pat = pow((6 - month), 2) + abs(day - 15);
			ll add;

			if(pat <= mid)
				add = r1 * pat;
			else if(pat > n)
				add = (r1 * mid) + (r2 * (n - mid));
			else
				add = (r1 * mid) + (r2 * (pat - mid));

			earn += add;

			// cout << pat << " " << i << " " << add << "\n";
		}

		// cout << mid << " " << earn << "\n";

		if(earn >= t){
			ans = max(ans, mid);
			l = mid + 1;
		}
		else
			r = mid - 1;
	}

	cout << (n - ans) << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}