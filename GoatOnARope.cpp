#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;


// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

void te(){

	ld x1, y1, x2, y2, x, y;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;

	ld dist1;
	if((x >= x1 && x <= x2) || (x <= x1 && x >= x2))
		dist1 = min(abs(y-y1), abs(y-y2));
	
	else if((y >= y1 && y <= y2) || (y <= y1 && y >= y2))
		dist1 = min(abs(x-x1), abs(x-x2));

	else{
		ld dist2 = sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
		ld dist3 = sqrt((x2-x)*(x2-x) + (y1-y)*(y1-y));
		ld dist4 = sqrt((x1-x)*(x1-x) + (y2-y)*(y2-y));
		ld dist5 = sqrt((x2-x)*(x2-x) + (y2-y)*(y2-y));
		dist1 = min(dist2, min(dist3, min(dist4, dist5)));
	}

	cout << dist1 << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << fixed << setprecision(3);

	te();

	return 0;
}