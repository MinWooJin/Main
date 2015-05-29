#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solve(char *);

int main() {
	int testcase, i;
	char a[1001], b[1001];

	scanf("%d",&testcase);

	for(i=0; i<testcase; i++) {
		scanf("%s",a);
		scanf("%s",b);
	
     		if(strcmp(solve(a),solve(b)) == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

char* solve(char* input) {
	int order=0;
	int ordernum=0;
	int checknumber=0;
	int j, k, copen=0;
	char m[1001];

	char *ra = (char*)malloc(100000000);
	char *num = (char*)malloc(100000000);

	for(j=0; j<strlen(input); j++) {
		if(copen == 0 && input[j] >= 'A' && input[j] <= 'Z') {
			while(input[j] >= 'A' && input[j] <= 'Z') {
				ra[checknumber]=input[j];
				checknumber++;
				j++;
			}
			j--;
		}
		else if(input[j]=='(') {
			copen=1;
			j++;
			while(input[j] != ')') {
				m[order]=input[j];
				order++;
				j++;
			}
			j--;
		}
		else if(input[j]==')') {
			copen=0;
			j++;
		}
		else {
			if((input[j+1] != '\0' && input[j+1] != '(') && (input[j+1] <= 'A' || input[j+1] >= 'Z')) {
                               while((input[j+1] != '\0' && input[j+1] != '(') && (input[j+1] <= 'A' || input[j+1] >= 'Z')) {
                                       num[ordernum]=input[j];
                                       ordernum++;
                                       j++;
                               }
                               j--;
			}
			//if((input[j+1] >= 'A' && input[j+1] <= 'Z') || (input[j+1] == '\0') || (input[j+1] == '(')) {
			else {
				num[ordernum]=input[j];
				m[order]='\0';
				for(k=0; k<atoi(num); k++) {
					strcat(ra,m);
					checknumber += order;
				}
				memset(m,0,sizeof(char)* order);
				memset(num,0,sizeof(char)* (ordernum+1));
				
				order=0;
				ordernum=0;
			}
			/*else {
				while((input[j+1] != '\0' && input[j+1] != '(') && (input[j+1] <= 'A' || input[j+1] >= 'Z')) {
					num[ordernum]=input[j];
					ordernum++;
					j++;
				}
				j--;
			}*/
		}
	}

	return ra;
	free(ra);
	free(num);
}
