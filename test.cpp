#include <iostream> 
#include <string.h>
using namespace std; 

int main() {
  freopen("input.txt", "r", stdin);   //Comment
  freopen("output.txt", "w", stdout);   //this out.
  char* s;
  scanf("%[^\n]s", s);
  printf("%s", s);
}