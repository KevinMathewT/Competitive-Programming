#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s, mod;
ll n;

void te(){
	cin >> s;
	cin >> n;
	mod = "";

	ll candy = 0, flake = 0;
	for(ll i=0;i<s.size();i++){
		if(s[i] == '?')
			candy++;
		else if(s[i] == '*')
			flake++;
	}

	ll rem = candy + flake;

	// cout << candy << " " << flake << " " << rem << "\n";

	if(n == s.size() - candy - flake){
		for(ll i=0;i<s.size();i++)
			if(s[i] != '?' && s[i] != '*')
				cout << s[i];

		cout << "\n";
		return;
	}

	else if(n < s.size() - candy - flake){
		if(n < s.size() - (2*rem)){
			cout << "Impossible\n";
			return;
		}

		ll tbr = s.size() - rem - n;
		for(ll i=0;i<s.size();i++){
			if(s[i] == '*' || s[i] == '?')
				continue;
			if(i != s.size()-1 && ((s[i+1] == '*' || s[i+1] == '?') && tbr > 0)){
				tbr--;
				continue;
			}

			cout << s[i];
		}

		cout << "\n";
		return;
	}

	else{
		if(flake == 0){
			cout << "Impossible\n";
			return;
		}

		ll flag = 0;
		ll tba = n - (s.size() - rem);

		for(ll i=0;i<s.size();i++){
			if(s[i] == '*' || s[i] == '?')
				continue;
			if(i != s.size()-1 && ((s[i+1] == '*') && flag == 0)){
				flag = 1;
				for(ll j=0;j<=tba;j++)
					cout << s[i];
				continue;
			}

			cout << s[i];
		}

		cout << "\n";
		return;
	}
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