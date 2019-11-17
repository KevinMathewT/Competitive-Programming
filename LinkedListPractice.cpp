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

struct Node{
	int val;
	Node *next;
};

void print(Node *head){
	if(head == NULL)
		return;
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}

	cout << "\n";
}

void push(Node **ref, int x){
	cout << "-------------------------------\n";
	cout << (*ref == NULL) << " - 1\n";
	print(*ref);
	// cout << "-\n";
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->val = x;
	new_node->next = (*(ref));
	// cout << new_node->next->val << "\n";
	print(new_node);
	print(*ref);
	*ref = new_node;
	cout << (*ref)->val << " - 3\n";
	cout << "-------------------------------\n";
}

void solve(){
	cout << "shdfl \n";
	Node *head = NULL;
	push(&head, 1);
	print(head);
	push(&head, 2);
	print(head);
	push(&head, 3);
	print(head);
	push(&head, 4);
	print(head);
	push(&head, 5);
	print(head);

	cout << "//////////////////////////\n";

	Node *a, *b, **c;
	a = (Node *) malloc(sizeof(Node));
	a->val = 8;
	a->next = NULL;

	c = &a;

	print(*c);

	b = (Node *) malloc(sizeof(Node));
	b->val = 9;
	b->next = *c;

	c = &b;

	print(a);
	print(b);
	print(*c);
	cout << "//////////////////////////\n";
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