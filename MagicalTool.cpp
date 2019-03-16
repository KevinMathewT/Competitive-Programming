#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
char ch[100000];

void te(){
	cin >> s;
	int pos = 0;
	ch[0] = s[0];

	for(ll i=1;i<s.size();i++){
		if(s[i] != s[i-1])
			ch[point++] = s[i];
	}

	ll cons = 0;

	for(ll i=0;i<point;i++){
		if(cons == 3 && )
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