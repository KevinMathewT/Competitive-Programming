#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Shubham Kumar
// Birla Institute of Technology, Mesra

ll v, h;
string s;

void te(){
	cin >> s;
	v = h = 0;

	for(ll i=0;i<s.size();i++){
		if(s[i] == '1'){
			v += 2;
			h += 0;
		}
		if(s[i] == '2'){
			v += 2;
			h += 3;
		}
		if(s[i] == '3'){
			v += 2;
			h += 3;
		}
		if(s[i] == '4'){
			v += 3;
			h += 1;
		}
		if(s[i] == '5'){
			v += 2;
			h += 3;
		}
		if(s[i] == '6'){
			v += 3;
			h += 3;
		}
		if(s[i] == '7'){
			v += 2;
			h += 1;
		}
		if(s[i] == '8'){
			v += 4;
			h += 3;
		}
		if(s[i] == '9'){
			v += 3;
			h += 3;
		}
		if(s[i] == '0'){
			v += 4;
			h += 2;
		}
	}

	cout << (v - h) << "\n";
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