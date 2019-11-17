#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n;
string s[110];
map<string, ll> mp;

void te(){
	cin >> n;
	cin.ignore(256, '\n');
	for(ll i=0;i<n;i++){
		getline(cin, s[i]);
	}

	for(ll i=0;i<n;i++){
		// cout << s[i] << "\n";
		for(ll j=0;j<s[i].size();j++)
			if(s[i][j] == ' '){
				mp[s[i].substr(0, j)]++;
			}
	}

	for(ll i=0;i<n;i++){
		for(ll j=0;j<s[i].size();j++){
			if(s[i][j] == ' ' && mp[s[i].substr(0, j)] > 1)
				cout << s[i] << "\n";
			if(s[i][j] == ' ' && mp[s[i].substr(0, j)] == 1)
				cout << s[i].substr(0, j) << "\n";
		}
	}
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