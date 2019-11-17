#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll T;
string s;

void te(){
	cin >> T;
	cin >> s;
	ll c = 0;
	for(ll i=0;i<s.size();i++)
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			c++;

	if(c >= 4)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

		te();

	return 0;
}