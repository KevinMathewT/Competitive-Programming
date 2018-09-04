#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	string s;
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);

	string new_s = "";
	for(ll i=0;i<s.length();i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y')
			continue;
		new_s = new_s + string(1, '.') + string(1, s[i]);
	}

	cout << new_s << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	// ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}