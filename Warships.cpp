#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?

string a, b, c, d;
ll x, y;

void solve(){
	while(cin >> a && cin >> x && cin >> b && cin >> y){
		c = "Tobby";
		d = "Naebbirac";
		if(a == "Destroyers" && b == "Battleships"){
			swap(a, b);
			swap(c, d);
			swap(x, y);
		}

		if(a == "Cruisers" && b == "Destroyers"){
			swap(a, b);
			swap(c, d);
			swap(x, y);
		}

		if(a == "Battleships" && b == "Cruisers"){
			swap(a, b);
			swap(c, d);
			swap(x, y);
		}

		if(a == b){
			if(x == y){
				cout << "Draw\n";
				continue;
			}
			if(x > y){
				cout << c << "\n";
				continue;
			}
			if(x < y){
				cout << d << "\n";
				continue;
			}
		}

		if(y >= 2*x)
			cout << d << "\n";
		else
			cout << c << "\n";
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}