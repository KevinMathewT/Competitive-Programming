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

string s;
ll q, l, r, x, y, m, n;
ll freq[100010], dp[3000][3000];
unordered_map<ll, ll> um;

void solve(){
	um.clear();
	fill(freq, freq + 3000, 0);
	for(ll i=0;i<3000;i++)
		fill(dp[i], dp[i] + 3000, 0);

	cin >> s;
	n = s.size();
	cin >> q >> l >> r >> x >> y >> m;
	// cout << q << l << r << x << y << m << "\n";
	// cout << s << "\n";

	for(ll i=0;i<n;++i) 
        dp[i][i] = true;
    ll start = 0;
    for(ll i=0;i<n-1;++i){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
            freq[2]++;
        }
    }
    for (ll k=3;k<=n;++k){
        for (ll i=0;i<n-k+1;++i){ 
            ll j = i + k - 1;
            if (dp[i+1][j-1] && s[i] == s[j]){
                dp[i][j] = true;
                freq[k] = 1;
            } 
        } 
    }

    for(ll i=1;i<s.size();i++)
    	freq[i] = freq[i] + freq[i-1];

    ll tot = 0, ans = 0;
    // cout << n << "\n";

   	while(q--){
   		// ans = 0;
   		cout << l << " " << r << "\n";
   		ans = freq[r-1] - freq[l-2];
   		tot += ans;
   		l = 1 + ((l + 0) % n);
   		r = 1 + ((r + 0) % n);
   		if(l > r)
   			swap(l, r);
   		x = 1 + ((x + ans) % n);
   		y = 1 + ((y + ans) % n);
   		if(x > y)
   			swap(x, y);
   	}

   	cout << tot << "\n";
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
		solve();

	return 0;
}