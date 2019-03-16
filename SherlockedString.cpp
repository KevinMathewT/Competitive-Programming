#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
vector<ll> pos[26];

void te(){
	for(ll i=0;i<26;i++)
		pos[i].clear();
	cin >> s;
	for(ll i=0;i<s.size();i++)
		pos[s[i]-'a'].push_back(i);

	ll ans = 0;

	for(ll i=0;i<13;i++)
		if(pos[i].size() != 0 && pos[25-i].size() != 0)
			ans = max(ans, max(abs(pos[i][0] - pos[25-i][pos[25-i].size()-1]), abs(pos[i][pos[i].size()-1] - pos[25-i][0])));

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