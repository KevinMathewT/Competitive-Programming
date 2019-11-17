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

void doSome(int *a){
	for(ll i=0;i<3;i++)
		cout << a[i] << " ";
	cout << "2\n";

	a[1] = 0;

	for(ll i=0;i<3;i++)
		cout << a[i] << " ";
	cout << "3\n";
}

void solve(){
	int a[3] = {0, 1, 2};

	for(ll i=0;i<3;i++)
		cout << a[i] << " ";
	cout << "1\n";

	doSome(a);

	for(ll i=0;i<3;i++)
		cout << a[i] << " ";
	cout << "4\n";
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