#include <bits/stdc++.h>
using namespace std;

void getReflectionAboutXNegativeYAxis(int n, int x[], int y[]) {
	for (int i = 0; i < n; i++) {
		int t = x[i];
		x[i] = -y[i];
		y[i] = -t;
	}
}

int main(){
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	
	cout << "Enter Number of Points : ";
	int n; cin >> n;
	int x[n], y[n];

	cout << "Enter " << n << " points";
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	getReflectionAboutXNegativeYAxis(n, x, y);

	for (int i = 0; i < n; i ++) {
		cout << x[i] << ' ' << y[i] << '\n';
	}

	return 0;
}