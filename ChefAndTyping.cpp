#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;


// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	map<string, ll> m;

	ld time = 0.0;
	ll curr;

	string s;
	while(n--){
		ld tot = 0.0;
		cin >> s;
		// cout << s << "\n";
		
		if(s.length() < 1) continue;
		
		tot += 0.2;
		
		if(s[0] == 'd' || s[0] == 'f')
			curr = 0;
		else
			curr = 1;


		for(ll i=1;i<s.length();i++){
			if((s[i] == 'd' || s[i] == 'f') && curr == 0 || ((s[i] == 'j' || s[i] == 'k') && curr == 1)){
				tot += 0.4;
			}
			else{
				tot += 0.2;
				curr = 1 - curr;
			}
			// cout << curr << "\n";
		}

		// cout << tot  << "\n";

		if(m.find(s) == m.end()){
			time += tot;
			m[s] = 1;
		}
		else
			time += tot / 2;
	}

	cout << time * 10 << "\n";
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
