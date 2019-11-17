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

ll n, k, a[1000010];

void solve(){
	cin >> n >> k;
	for(ll i=0;i<n;i++)
		cin >> a[i];
	sort(a, a + n);

	ll i = 0, j = n - 1, ans = 0;

	while(i < j){
		if(a[i] + a[j] < k){
			ans += (j - i);
			i++;
			continue;
		}
		if(a[i] + a[j] >= k){
			j--;
		}
	}

	cout << ans << "\n";
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