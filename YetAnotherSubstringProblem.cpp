#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
ll n, a[100010], pre[100010];
unordered_map<ll, ll> um;

void te(){
	um.clear();
	cin >> s;
	n = s.size();
	for(ll i=0;i<n;i++)
		a[i] = pow(2, (s[i] - 'a'));

	pre[0] = a[0];
	for(ll i=1;i<n;i++)
		pre[i] = pre[i-1] ^ a[i];

	ll ans = 0;
	for(ll i=0;i<n;i++){
		ans += um[pre[i]];
		if(pre[i] == 0)
			ans++;
		um[pre[i]]++;
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

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}