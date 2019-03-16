#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
ll gorb[26], k;
const ll p = 27, m = 59604644783353249;
unordered_map<ll, ll> um;

void te(){
	cin >> s;
	string gorbs;
	cin >> gorbs;

	for(ll i=0;i<26;i++)
		gorb[i] = gorbs[i] - '0';

	cin >> k;
	ll ans = 0, hash = 0, countBad = 0, p_pow = 1;

	for(ll i=0;i<s.size();i++){
		hash = 0;
		p_pow = 1;
		countBad = 0;

		for(ll j=i;j<s.size();j++){
			if(gorb[s[j]-'a'] == 0)
				countBad++;
			// cout << countBad << " " << i << " " << j << "\n";
			if(countBad > k)
				break;

			hash = (hash + (((s[j] - 'a' + 1) * p_pow) % m)) % m;
			p_pow = (p * p_pow) % m;

			if(um[hash] != 1){
				// cout << i <	< " " << j << "\n";
				um[hash] = 1;
				ans++;
			}
		}
	}

	cout << ans << "\n";
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