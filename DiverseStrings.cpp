#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
char st[110];

void te(){
	cin >> s;
	for(ll i=0;i<s.size();i++)
		st[i] = s[i];
	sort(st, st + s.size());
	ll ans = 1;
	for(ll i=1;i<s.size();i++)
		if(st[i] - st[i-1] != 1)
			ans = 0;

	if(ans)
		cout << "Yes\n";
	else
		cout << "No\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}