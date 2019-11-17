#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;

void te(){
	cin >> s;
	if(s[0] < 'a' || s[0] > 'z'){
		cout << "NO\n";
		return;
	}
	ll c = 0;
	for(ll i=0;i<s.size();i++){
		if(s[i] >= 'A' && s[i] <= 'Z')
			c++;
	}

	c++;
	// cout << c << "\n";

	if(c > 7)
		cout << "NO\n";
	else
		cout << "YES\n";
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