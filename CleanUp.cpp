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

string s;
struct keys *lock;

void print(int a[]){
	for(ll i=0;i<5;i++)
		cout << a[i] << " ";
	cout << "\n";
}

void fun1(int *a){
	a[0] = 2;
	cout << "fun1\n";
	print(a);
	cout << "fun1\n";
}

// void fun2(int (*a)[5]){
// 	a[0] = 3;
// 	cout << "fun2\n";
// 	print(a);
// 	cout << "fun2\n";
// }

void fun3(int (&a)[5]){
	a[0] = 4;
	cout << "fun3\n";
	print(a);
	cout << "fun3\n";
}

void fun4(int a[]){
	a[0] = 5;
	cout << "fun3\n";
	print(a);
	cout << "fun3\n";
}

void solve(){
	int a[] = {1, 2, 3, 4, 5};

	// cout << "main()\n";
	// print(a);
	// cout << "main()\n";

	// fun1(a);

	// // cout << "main()\n";
	// // print(a);
	// // cout << "main()\n";

	// // fun2(&a);

	// cout << "main()\n";
	// print(a);
	// cout << "main()\n";

	// fun3(a);

	// cout << "main()\n";
	// print(a);
	// cout << "main()\n";

	// fun4(a);

	// cout << "main()\n";
	// print(a);
	// cout << "main()\n";

	int b = 5;
	int *p = &b;
	int& c = *p;

	cout << b << " " << c << "\n";

	c = 6;

	cout << b << " " << c << "\n";
	cout << (&b) << " " << (&c) << "\n";

	vector<int> vect{ 10, 20, 30, 40};  
  
    // We can modify elements if we  
    // use reference 
    for (int &x : vect)
        x = x + 5;
  
    // Printing elements 
    for (int x : vect)
       cout << x << " ";
  
    // return 0;  
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// ll T;
	// cin >> T;
	// while(T--)
		solve();

	return 0;
}