#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

void te(){
	string s; cin >> s;

	ll pos = -1;
	for(ll i=0;i<s.length();i++)
		if(s[i] == '0'){
			pos = i;
			break;
		}

	if(pos == -1)
		cout << s.substr(0, s.length()-1) << "\n";
	else
		cout << s.substr(0, pos) << s.substr(pos+1) << "\n";
}

int main(){
// 	freopen("input.txt", "r", stdin);		//Comment
// 	freopen("output.txt", "w", stdout);		//this out.
// 	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}