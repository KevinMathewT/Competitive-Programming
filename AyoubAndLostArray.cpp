#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, l, r, a[200010], dp[200010][3], m = 1000000007;

void fillZer0(){
	ll left = l, right = r;

	if(right - left <= 50){
		for(ll i=left;i<=right;i++){
			// cout << i % 3 << "\n";
			dp[0][i%3]++;
		}

		return;
	}

	while(true){
		if(left % 3 == 0|| left >= right)
			break;
		dp[0][left%3]++;
		left++;
	}

	while(true){
		if(right % 3 == 0 || right <= left)
			break;
		dp[0][right%3]++;
		right--;
	}

	dp[0][0] += ((right-left) / 3) + 1;
	dp[0][1] += ((right-left) / 3);
	dp[0][2] += ((right-left) / 3);
}

void te(){
	cin >> n >> l >> r;

	dp[0][0] = dp[0][1] = dp[0][2] = 0;

	fillZer0();
	for(ll i=1;i<n;i++){
		dp[i][0] = (((((dp[i-1][0] * dp[0][0]) % m) + dp[i-1][1] * dp[0][2]) % m) + ((dp[0][1] * dp[i-1][2]) % m)) % m;
		dp[i][1] = (((((dp[i-1][0] * dp[0][1]) % m) + dp[i-1][1] * dp[0][0]) % m) + ((dp[0][2] * dp[i-1][2]) % m)) % m;
		dp[i][2] = (((((dp[i-1][0] * dp[0][2]) % m) + dp[i-1][2] * dp[0][0]) % m) + ((dp[0][1] * dp[i-1][1]) % m)) % m;
	}
	// for(ll i=0;i<n;i++){
	// 	cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << "\n";
	// }

	cout << dp[n-1][0] << "\n";
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