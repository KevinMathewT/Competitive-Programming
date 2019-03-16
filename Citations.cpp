#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n;
	cin >> n;
	while(n--){
		unordered_map<ll, string> m;
		for(ll i=0;i<8;i++){
			string s;
			cin >> s;
			if(s[0] == 't')
				m[0] = s.substr(7, s.size()-9);
			else if(s[0] == 'a')
				m[1] = s.substr(8, s.size()-10);
			else if(s[0] == 'j')
				m[2] = s.substr(9, s.size()-11);
			else if(s[0] == 'v')
				m[3] = s.substr(8, s.size()-10);
			else if(s[0] == 'n')
				m[4] = s.substr(8, s.size()-10);
			else if(s[0] == 'y')
				m[5] = s.substr(6, s.size()-8);
			else if(s[0] == 'p' && s[1] == 'a')
				m[6] = s.substr(7, s.size()-9);
			else
				m[7] = s.substr(11, s.size()-13);
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