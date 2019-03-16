#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ld n, r;
ld PI = 3.14159265358979323846;

void te(){
	cin >> n >> r;

	cout << r / ((1 / (sin(PI / n))) - 1) << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << setprecision(7) << fixed;

	te();

	return 0;
}