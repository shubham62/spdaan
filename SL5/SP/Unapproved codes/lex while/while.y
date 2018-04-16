%{
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
char st[100][10];
int top=0;
char i[2]="0";
char temp[2]="t";
int lnum=1;
int start=1;
void yyerror(char *msg);
extern yytext;
extern yylex();
%}

%token ID NUM WHILE
%right '='
%left '+' '-'
%left '*' '/'
%left UMINUS
%start S
%%

S : WHILE{lab1();} '(' E ')'{lab2();} E ';'{lab3();}
;
E :V '='{push();} E{codegen_assign();}
| E '+'{push();} E{codegen();}
| E '-'{push();} E{codegen();}
| E '*'{push();} E{codegen();}
| E '/'{push();} E{codegen();}
| '(' E ')'
| '-'{push();} E{codegen_umin();} %prec UMINUS
| V
| NUM{push();}
;
V : ID {push();}
;
%%

void yyerror(char *msg){
fprintf(stderr,"%s",msg);
exit(1);
}
void main()
{
printf("Enter the expression : ");
yyparse();
}

push()
{
strcpy(st[++top],yytext);
}
codegen()
{
strcpy(temp,"t");
strcat(temp,i);
printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
top-=2;
strcpy(st[top],temp);
i[0]++;
}
codegen_umin()
{
strcpy(temp,"t");
strcat(temp,i);
printf("%s = -%s\n",temp,st[top]);
top--;
strcpy(st[top],temp);
i[0]++;
}
codegen_assign()

{
printf("%s = %s\n",st[top-2],st[top]);
top-=2;
}

lab1()
{
printf("L%d: \n",lnum++);
}

lab2()
{
strcpy(temp,"t");
strcat(temp,i);
printf("%s = not %s\n",temp,st[top]);
printf("if %s goto L%d\n",temp,lnum);
i[0]++;
}
lab3()
{
printf("goto L%d \n",start);
printf("L%d: \n",lnum);
}
