#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;

void te(){
	cin >> s;
	ll flag = 1;

	for(ll i=1;i<s.size();i++)
		if((s[i]-s[i-1]+26)%26 != 1)
			flag = 0;

	if(flag)
		cout << "YES\n";
	else
		cout << "NO\n";
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