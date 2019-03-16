#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
ll freq[26];

void te(){
	cin >> s;
	for(ll i=0;i<26;i++)
		freq[i] = 0;

	for(ll i=0;i<s.size();i++)
		freq[s[i] - 'A']++;

	vector<ll> f;
	for(ll i=0;i<26;i++)
		if(freq[i] != 0)
			f.push_back(freq[i]);

	sort(f.begin(), f.end());

	ll ans = LLONG_MAX;

	for(ll i=1;i<=26;i++){
		if(i > s.size() || s.size() % i != 0)
			continue;

		ll tot = 0;
		ll nu = i;
		ll fr = s.size() / i;

		for(ll i=0;i<nu;i++){
			if(i >= f.size()){
				tot += fr;
				continue;
			}

			// cout << fr << " " << f[f.size()-i-1] << "--\n";
			if(fr - f[f.size()-i-1] >= 0)
			tot += fr - f[f.size()-i-1];
		}

		// cout << i << " " << tot << "\n";

		ans = min(ans, tot);
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

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}