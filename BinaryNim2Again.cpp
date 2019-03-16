#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){
	ll n, pl;
	string s;

	cin >> n >> s;
	if(s == "Dee")
		pl = 0;
	else
		pl = 1;

	string stacks[n];
	for(ll i=0;i<n;i++)
		cin >> stacks[i];

	ll Dee = 0;
	ll Dum = 0;

	for(ll i=0;i<n;i++){
		if(stacks[i][stacks[i].size()-1] == '0')
			Dee++;
		else
			Dum++;
	}

	// cout << Dee << " " << Dum << "\n";

	if(Dee < Dum || (Dee == Dum && pl == 0))
		cout << "Dee\n";
	else
		cout << "Dum\n";
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