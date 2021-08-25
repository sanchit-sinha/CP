#include<stdio.h>
#include<strings.h>

void reverse(char *ans, char *str, int l, int r){
	// base case
	if(l > r){
		// ans[l] = str[l];
		return;
	}
	else{
		char c = str[l];
		char d = str[r];

		int true1 = 0;
		int true2 = 0;
		int trueboth = 0;
		
		if(c >= 'd' && c <= 's') true1 = 1; 
		if(c >= 'D' && c <= 'S') true1 = 1; 

		if(d >= 'd' && d <= 's') true2 = 1; 
		if(d >= 'D' && d <= 'S') true2 = 1; 
		
		if(true1 && true2) trueboth = 1;

		// if(c < 'd' && c < 'D') true = 0;
		// if(d < 'd' && d < 'D') true = 0;

		// if(c > 's' && c > 'S') true = 0;
		// if(d > 's' && d > 'S') true = 0;

		//Debug
		// printf("%d\n", l);
		// printf("%c\n", str[l]);
		// printf("%d\n", r);
		// printf("%c\n", str[r]);
		// printf("%d\n", trueboth);
		// printf("\n");

		if(trueboth){
			ans[l] = str[r];
			ans[r] = str[l];
		} 
		else{
			ans[l] = str[l];
			ans[r] = str[r];
		}
		l++ , r--;
		reverse(ans , str , l , r);

	}	
}
int main(){
	char str[1000];

	char c = getchar();
	int index = 0;
	while(c != '\n'){
		str[index++] = c;
		c = getchar();
	}	
	str[index] = '\0';

	// printf("%s" , str);

	// contains final answer
	char ans[1000];

	int start = 0 , end = index - 1;
	reverse(ans , str , start , end);
	
	ans[index] = '\0';		
	
	for(int i = 0 ; i < index ; i++) printf("%c", ans[i]);
		printf("\n");	
}	