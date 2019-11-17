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

ll i, n, j, s[100010];

void solve(){
	cin >> i >> n >> j;
	fill(s, s + i, 0);
	
	while(j--){
	    ll a, b, x;
	    cin >> a >> b >> x;
	    a--; b--;
	    
	    s[a] += x;
	    s[b + 1] -= x;
	}
	
	int ans = 0;

	if(s[0] < n)
		ans++;
	
	for(ll j=1;j<i;j++){
	    s[j] = s[j] + s[j-1];
	    if(s[j] < n)
	        ans++;
	}
	
	cout << ans << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}