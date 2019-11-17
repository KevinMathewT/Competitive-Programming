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

ll h, w, a, b;

void ret(){
	cout << "-1\n";
	exit(0);
}

void solve(){
	cin >> h >> w >> a >> b;

	if(a > w || b > h)
		ret();

	if(h == 1 || w == 1){
		if(h == 1 && w == 1){
			if(a > 1 || b > 1)
				ret();
			cout << 0 << "\n";
			return;
		}

		if(h == 1){
			if(a > ((ll)(w / 2)))
				ret();
			for(ll i=0;i<w;i++)
				if(i < a)
					cout << 1 << "\n";
				else
					cout << 0 << "\n";
		}

		if(w == 1){
			if(b > ((ll)(h / 2)))
				ret();
			for(ll i=0;i<h;i++)
				if(i < b)
					cout << 1 << "\n";
				else
					cout << 0 << "\n";
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

	solve();

	return 0;
}