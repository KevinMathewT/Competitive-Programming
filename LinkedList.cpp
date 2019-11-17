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

void push(Node **ref, int x){
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->val = x;
	new_node->next = *(ref);
	*ref = new_node;
}

void append(Node **ref, int x){
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->val = x;
	new_node->next = NULL;

	Node *copy = *ref;

	if(copy == NULL){
		*ref = new_node;
	}
	else{
		while(copy->next != NULL)
			copy = copy->next;
		copy->next = new_node;
	}
}

void print(Node *head){
	if(head == NULL)
		return;
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
	cout << "\n";
}

void insertAfter(Node **prev, int x){
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->val = x;
	new_node->next = (*prev)->next;
	(*prev)->next = new_node;
}

// void delete(Node **ref, int x){

// }

void solve(){
	Node *head = NULL;

	append(&head, 1);
	print(head);
	append(&head, 2);
	print(head);
	append(&head, 3);
	print(head);
	push(&head, 4);
	print(head);
	push(&head, 5);
	print(head);
	push(&head, 6);
	print(head);
	insertAfter(&(head->next), 7);
	print(head);
	insertAfter(&(head->next), 8);
	print(head);
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