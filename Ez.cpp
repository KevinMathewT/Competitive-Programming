#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll x1;
ll z1;
ll x2;
ll y2;

void te(){
	cin >> x1 >> z1 >> x2 >> y2;

	if(x1 == x2)
		cout << "Parallel to y-axis\n";	
	else if(z1 == y2)
		cout << "Parallel to x-axis\n";	
	else
		cout << "None\n";	
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