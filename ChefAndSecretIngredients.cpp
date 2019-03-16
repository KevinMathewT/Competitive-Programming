#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

unordered_map<ll, unordered_map<ll, ll> > mp;
string s[1010];
ll n, ch[26];

void te(){
	mp.clear();
	for(ll i=0;i<26;i++)
		ch[i] = 0;
	cin >> n;
	for(ll i=0;i<n;i++){
		cin >> s[i];
	}

	for(ll i=0;i<n;i++){
		for(ll j=0;j<s[i].size();j++){
			if(mp[i][s[i][j]-'a'] != 1){
				mp[i][s[i][j]-'a'] = 1;
				ch[s[i][j]-'a']++;
			}
		}
	}

	ll ans = 0;

	for(ll i=0;i<26;i++)
		if(ch[i] == n)
			ans++;

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