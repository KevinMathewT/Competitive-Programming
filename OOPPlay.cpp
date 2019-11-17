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

enum C{
	"Hello"
};

class A{
public:
	ll f, g;
	A(ll c = 1, ll d = 2){
		cout << "A C\n";
		f = c;
		g = d;
	}
	~A(){
		cout << "A D\n";
	}
};

class B : public A{
public:
	static A e;
	ll a, b;
	B(ll c = 3, ll d = 4){
		cout << "B C\n";
		a = c;
		b = d;
	}
	~B(){
		cout << "B D\n";
	}
};

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// B b;
	// cout << b.c << "\n";
	// solve();

	cout << sizeof(double) << "\n";

	return 0;
}