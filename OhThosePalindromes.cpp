#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	string s;
	cin >> s;

	sort(s, s+n);
	vector<pair<char, ll> > v;

	v.push_back(make_pair(s[0], 1));
	ll pos = 0;
	for(ll i=1;i<s.length();i++){
		if(s[i] == v[pos].first)
			v[pos].second++;
		else
			v.push_back(make_pair(s[i], 1));
	}
	for(ll i=0;i<)
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