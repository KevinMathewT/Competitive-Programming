#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

string getString(char x){
    string s(1, x); 
    return s;   
}

void te(){
	ll k; cin >> k;
	string s; cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);

	ll a[26];
	for(ll i=0;i<26;i++) a[i] = 0;
	for(ll i=0;i<s.length();i++)
		a[s[i]-'a']++;

	for(ll i=0;i<26;i++){
		// cout << a[i] << "\n";
		if(a[i] % k != 0){
			cout << -1 << "\n";
			return;
		}
	}

	string new_s = "";
	for(ll i=0;i<26;i++){
		string append = "";
		// cout << a[i] << "\n";
		for(ll j=0;j<(a[i]/k);j++){
			// cout << "sdfsdf - " << j << "\n";
			// cout << char('a' + i) << "\n";
			append = append + getString(char('a' + i));
		}
		new_s = new_s + append;
		// cout << append << "\n";
	}

	// cout << new_s << "\n";

	string final_s = "";
	for(ll i=0;i<k;i++)
		final_s = final_s + new_s;

	cout << final_s << "\n";
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