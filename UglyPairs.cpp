#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Shubham Kumar
// Birla Institute of Technology, Mesra

string s, ns;

void te(){
	cin >> s;
	ns = s;
	ll n = s.size();
	sort(s.begin(), s.end());

	
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
	cin.ignore(256, '\n');
	while(T--)
		te();

	return 0;
}