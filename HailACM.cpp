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

ll k, n;
string s;
ll a[100010];

ll subarrayXor(ll m) 
{ 
    ll ans = 0;
    ll xorArr[n];
    unordered_map<ll, ll> mp;
    xorArr[0] = a[0];
    for(ll i=1;i<n;i++) 
        xorArr[i] = xorArr[i-1] ^ a[i];
    ll p = 0;
    for(ll i=k-1;i<n;i++){
        ll tmp = m ^ xorArr[i];
        ans = ans + ((ll)mp[tmp]);
        if(xorArr[i] == m) 
            ans++;
        mp[xorArr[p++]]++;
    }
    return ans; 
} 

void solve(){
	cin >> k;
	cin >> s;
	n = s.size();

	for(ll i=0;i<s.size();i++)
		a[i] = (1 << (s[i] - 'a'));

	ll Xor = 0;
	for(ll i=0;i<n;i++)
		Xor ^= a[i];

	cout << subarrayXor(Xor) << "\n";
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