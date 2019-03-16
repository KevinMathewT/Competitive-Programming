#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s, t;
unordered_map<string, ll> substringPresent;

ll isPrefix(string s1, string s2){
	for(ll i=0;i<s2.size();i++)
		if(s1[i] != s2[i])
			return 0;

	return 1;
}

ll isDivisor(string s1, string s2){
	for(ll i=0;i<s1.size();i++){
		for(ll j=0;j<s2.size();j++)
			if(s1[i] != s2[i%(s2.size())])
				return 0;
	}

	return 1;
}

void te(){
	cin >> s >> t;

	for(ll i=1;i*i<=s.size();i++){
		if(s.size() % i == 0){
			if(isDivisor(s, s.substr(0, i)))
				substringPresent[s.substr(0, i)] = 1;
			if(isDivisor(s, s.substr(0, s.size()/i)))
				substringPresent[s.substr(0, s.size()/i)] = 1;
		}
	}

	ll divisors = 0;

	for(ll i=1;i*i<=t.size();i++){
		if(t.size() % i == 0){
			if(isDivisor(t, t.substr(0, i)))
				if(substringPresent[t.substr(0, i)] == 1){
					// cout << t.substr(0, i) << "\n";
					divisors++;
				}
			if(i*i != t.size() && isDivisor(t, t.substr(0, t.size()/i)))
				if(substringPresent[t.substr(0, t.size()/i)] == 1){
					// cout << t.substr(0, t.size()/i) << "\n";
					divisors++;
				}
		}
	}

	cout << divisors << "\n";
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