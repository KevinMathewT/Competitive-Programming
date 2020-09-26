%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%token ID NUM IF THEN LE GE EQ NE OR AND ELSE
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-'
%left '*''/'
%right UMINUS
%left '!'
%%
S : ST {printf("Input accepted.\n");exit(0);};
ST : IF '(' E2 ')' ST1';' ELSE ST1';'
| IF '(' E2 ')' ST1';'
;
ST1 : ST
| E
;
E: ID'='E
| E'+'E
| E'-'E
| E'*'E
| E'/'E
| E'<'E
| E'>'E
| E LE E
| E GE E
| E EQ E
| E NE E
| E OR E
| E AND E
| ID
| NUM
;
E2 : E'<'E
| E'>'E
| E LE E
| E GE E
| E EQ E
| E NE E
| E OR E
| E AND E
| ID
| NUM
;
%%
#include "lex.yy.c"
main() {
    printf("Enter the exp: ");
    yyparse();
}
