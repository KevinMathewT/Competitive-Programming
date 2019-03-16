#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	string s[n];

	for(ll i=0;i<n;i++)
		cin >> s[i];

	unordered_map<vector<char>, ll> m;

	for(ll i=0;i<n;i++){
		vector<char> a;
		for(ll j=0;j<s[i].size();j++){
			a.push_back(s[i][j]);
			m[a]++;
		}
	}

	ll maxi = -1;

	for(ll i=0;i<n;i++){
		string a = "";
		for(ll j=0;j<s[i].size();j++){
			a.push_back(s[i][j]);
			maxi = max(maxi, (j+1) * (m[a]));
		}
	}

	cout << maxi << "\n";
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