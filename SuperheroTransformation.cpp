#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s, t;

ll isVowel(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return 1;
	return 0;
}

void te(){
	cin >> s >> t;
	if(s.size() != t.size()){
		cout << "No\n";
		return;
	}

	for(ll i=0;i<s.size();i++){
		if((isVowel(s[i]) && isVowel(t[i])) || (!isVowel(s[i]) && !isVowel(t[i])))
			continue;

		cout << "No\n";
		return;
	}

	cout << "Yes\n";
	return;
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