#include <bits/stdc++.h>
using namespace std;
typedef double ld;

ld f(ld x){
	return x * x * x + x * x + x + 7;
}

void te(){
	ld a = -10, b = +10;
		
	while(abs(a-b) >= 0.00001){
		// cout << a << " " << b << "\n";
		ld temp = b;
		b = a - ((f(a) * (a-b)) / (f(a) - f(b)));
		a = temp;
	}

	cout << b << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}