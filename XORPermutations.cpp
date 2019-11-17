#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s[3];

void te(){
	cin >> s[0] >> s[1] >> s[2];

	for(ll i=0;i<3;i++)
		for(ll j=0;j<s[i].size();j++)
			if(s[i][j] == '0')
				for(ll k=j+1;k<s.size();k++)
					if(s[i][k] == '1'){
						swap(s[i][j], s[i][k]);
						break;
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