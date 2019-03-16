#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
ll freq[26];
vector<ll> frequencies;

void te(){
	frequencies.clear();
	for(ll i=0;i<26;i++)
		freq[i] = 0;
	cin >> s;
	for(ll i=0;i<s.size();i++)
		freq[s[i]-'a']++;

	for(ll i=0;i<26;i++)
		if(freq[i] != 0)
			frequencies.push_back(freq[i]);
	sort(frequencies.begin(), frequencies.end());

	ll min = LLONG_MAX;

	for(ll i=1;i*i<=s.size();i++){
		ll factor = i;
		if(s.size() % i == 0){
			
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}