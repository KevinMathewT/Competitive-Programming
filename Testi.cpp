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

class A{
public:
	struct sadij* lwf;
	int x = 6;
	virtual void show(){
		cout << "In Base\n";
	}
};

class B : public A{
public:
	int x = 7;
	virtual void show(){
		cout << "In Derived\n";
	}
};

class C : public A{
public:
	int x = 8;
	virtual void show(){
		cout << "In Derived2\n";
	}
};

int* fun() 
{ 
    static int arr[100];
  
    /* Some operations on arr[] */
    arr[0] = 10; 
    arr[1] = 20; 
  
    return arr; 
} 

void solve(){
	C obj1 = C();
	A *p = &obj1;
	p->show();
	cout << p->x << "\n";

	cout << (70) << "\n";

	// A ob1;
	// B ob2;
	// C ob3;

	// cout << ob1.x << " " << ob2.x << " " << ob3.x << "\n";
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