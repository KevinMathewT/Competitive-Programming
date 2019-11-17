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

ll n, m, a[200010], mp[1000010], temp[1000010];

void solve(){
	cin >> n >> m;
	for(ll i=0;i<n;i++)
		cin >> a[i];

	for(ll i=0;i<1000010;i++)
		mp[i] = temp[i] = 0;

	cout << 0 << " ";
	ll curr = a[0];
	mp[a[0]] = 1;

	for(ll i=1;i<n;i++){
		// sort(a, a + i);
		curr += a[i];
		// cout << curr << "-\n";
		ll t = curr;

		ll count = 0;

		// if(t > m)
		// 	for(ll j=i-1;j>=0;j--){
		// 		t -= a[j];
		// 		count++;
		// 		if(t <= m)
		// 			break;
		// 	}

		// for(ll i=0;i<n;i++)
		// 	cout << mp[a[i]] << " ";
		// cout << "\n";

		// while(t > m){
		// cout << t << "-\n";
		for(ll j=100;j>=1;j--){
			// cout << j << " - " << mp[j] << "\n";
			if(t <= m)
				break;
			if(mp[j] > 0){
				// cout << j << " - " << mp[j] << "-----\n";
				if(j * mp[j] <= (t - m)){
					t -= j * mp[j];
					temp[j] = mp[j];
					count += mp[j];
					mp[j] = 0;
					// cout << mp[j] << "-------\n";
				}
				else{
					ll c = ceil((t - m) / (j + 0.0));
					t -= (j * c);
					temp[j] = c;
					mp[j] -= c;
					count += c;
					// cout << c << "-------\n";
					break;
				}
			}
		}
		// cout << t << "---\n";
			// t--;
		// }

		for(ll j=1;j<=100;j++)
			mp[j] += temp[j];
		for(ll j=1;j<=100;j++)
			temp[j] = 0;

		mp[a[i]]++;

		cout << count << " ";
	}
	// cout << "\n";
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