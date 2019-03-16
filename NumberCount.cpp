#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, k;
ll a[10], countNum[10], dp[100010][10];
vector<ll> nums[10];

ll DP(ll x, ll pos){
	// cout << x << " " << pos << "\n";
	if(pos == n-2)
		return 1;
	if(dp[pos][x] != -1)
		return dp[pos][x];

	// cout << nums[x].size() << "---\n";

	ll ans = 0;
	for(ll j=0;j<nums[x].size();j++)
		ans = (ans + DP(nums[x][j], pos+1)) % 1000000007 ;

	// cout << x << " " << pos << " " << ans << "--\n";

	return dp[pos][x] = ans;
}

void te(){
	cin >> n >> m >> k;
	for(ll i=0;i<10;i++)
		nums[i].clear();
	for(ll i=0;i<100010;i++)
		for(ll j=0;j<10;j++)
			dp[i][j] = -1;
	
	for(ll i=0;i<m;i++){
		countNum[i] = 0;
		cin >> a[i];
	}

	sort(a, a+m);

	for(ll i=0;i<m;i++)
		for(ll j=i;j<m;j++)
			if(a[j] - a[i] >= k){
				// cout << "YAY\n";
				nums[a[i]].push_back(a[j]);
				nums[a[j]].push_back(a[i]);
			}

	ll ans = 0;
	for(ll i=0;i<m;i++)
		if(a[i] != 0)
			ans = (ans + DP(a[i], 0)) % 1000000007;
	// for(ll i=0;i<m;i++)
	// 	cout << countNum[i] << " ";
	// cout << "\n";

	// for(ll i=0;i<m;i++)
	// 	dp[0][a[i]] = 1;

	// for(ll i=1;i<n;i++){
	// 	for(ll j=0;j<m;j++){
	// 		for(ll k=0;k<nums[a[j]].size();k++){
	// 			dp[i][nums[a[j]][k]] = dp[i-1][nums[a[j]][k]] * 
	// 		}
	// 		dp[i][j] = (countNum[j] * dp[i-1][j]) % 1000000007;
	// 		cout << i << " " << j << " " << dp[i][j] << "\n";
	// 	}
	// }

	// ll ans = 0;
	// for(ll i=0;i<m;i++)
	// 	ans = (ans + dp[n-1][i]) % 1000000007;

	cout << ans << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}