#include <stdio.h>
int n,t,s,S,i;
char x[99];
int main(){
	for(;i++<20;){
		scanf("%s %d.%d %s",x,&n,&t,x);
		if(*x==80) continue;
		S+=n,t=*x>68?0:69-*x,t=t*10+(x[1]&&x[1]-48?5:0),s+=n*t;
	}
	printf("%lf",(double)s/S/10);
}