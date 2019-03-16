#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	string s;
	getline(cin, s);
	ll a[26];
	for(ll i=0;i<26;i++)
		a[i] = 0;

	ll n = s.size();
	ll sp = 0;

	for(ll i=0;i<n;i++){
		if(s[i] != ' ')
			a[s[i]-'a']++;
		else
			sp++;
	}

	for(ll i=0;i<26;i++)
		cout << ((char)('a' + i)) << " - " << a[i] << "\n";
	cout << "  - " << sp << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}