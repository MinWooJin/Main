#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct comp{
	char str1[1001];
	char str2[1001];
	char resulstr1[1001];
	char resulstr2[1001];
};

int compstring(char *s1, char *s2) {
	int comp = strcmp(s1,s2);
	return comp;
}

int main() {
	int testcase, ckcompress = 0, start_compchnum, end_compchnum, ckcom, 
		ckmul = 0, ckml, subnumber, i, j, t, m, n;
	comp compcase;
	char *substr, *substr2, *subnum, *subnum2;
	substr = (char *)malloc(1001);
	substr2 = (char *)malloc(1001);
	subnum = (char *)malloc(100000001);
	subnum2 = (char *)malloc(100000001);
	scanf("%d",&testcase);

	for(i=0; i<testcase; i++) {
		memset(compcase.str1, 0, 1001);
		memset(compcase.str2, 0, 1001);
		memset(compcase.resulstr1, 0, 1001);
		memset(compcase.resulstr2, 0, 1001);

		scanf("%s",&compcase.str1);
		scanf("%s",&compcase.str2);

		t=0;
		for(j=0; j<strlen(compcase.str1); j++) {
			if(compcase.str1[j]=='(') {
				ckcompress=1;
				ckcom=0;
				start_compchnum=j;
			}
			else if (compcase.str1[j]==')') {
				ckcompress=0;
				end_compchnum=j;
			}
			else if (ckcompress==1) {
				substr[ckcom]=compcase.str1[j];
				ckcom++;
			}
			else if (compcase.str1[j]=='^') {
				ckmul=1;
				ckml=0;
			}
			else if (ckmul==1 && compcase.str1[j] > 64) {
				ckmul=0;
				subnumber = atoi(subnum);
				for(m=0; m<subnumber; m++) {
					for(n=0; n<end_compchnum-start_compchnum-1; n++) {
						compcase.resulstr1[t] = substr[n];
						t++;
					}
				}
				compcase.resulstr1[t] = compcase.str1[j];
				t++;
			}
			else if (ckmul==1) {
				if (j == strlen(compcase.str1) - 1) {
					subnum[ckml]=compcase.str1[j];
					ckml++;
					ckmul=0;
					subnumber = atoi(subnum);
					for(m=0; m<subnumber; m++) {
						for(n=0; n<end_compchnum-start_compchnum-1; n++) {
							compcase.resulstr1[t] = substr[n];
							t++;
						}
					}
				}
				else if (j < strlen(compcase.str1) -1) {
					subnum[ckml]=compcase.str1[j];
					ckml++;
					if (compcase.str1[j+1] == '(') {
						ckmul=0;
						subnumber = atoi(subnum);
						for(m=0; m<subnumber; m++) {
							for(n=0; n<end_compchnum-start_compchnum-1; n++) {
								compcase.resulstr1[t] = substr[n];
								t++;
							}
						}
					}
				}
			}
			else {
				compcase.resulstr1[t] = compcase.str1[j];
				t++;
			}
		}
		t=0;
		for(j=0; j<strlen(compcase.str2); j++) {
			if(compcase.str2[j]=='(') {
				ckcompress=1;
				ckcom=0;
				start_compchnum=j;
			}
			else if (compcase.str2[j]==')') {
				ckcompress=0;
				end_compchnum=j;
			}
			else if (ckcompress==1) {
				substr2[ckcom]=compcase.str2[j];
				ckcom++;
			}
			else if (compcase.str2[j]=='^') {
				ckmul=1;
				ckml=0;
			}
			else if (ckmul==1 && compcase.str2[j] > 64) {
				ckmul=0;
				subnumber = atoi(subnum2);
				for(m=0; m<subnumber; m++) {
					for(n=0; n<end_compchnum-start_compchnum-1; n++) {
						compcase.resulstr2[t] = substr2[n];
						t++;
					}
				}
				compcase.resulstr2[t] = compcase.str2[j];
				t++;
			}
			else if (ckmul==1) {
				if (j == strlen(compcase.str2) - 1) {
					subnum2[ckml]=compcase.str2[j];
					ckml++;
					ckmul=0;
					subnumber = atoi(subnum2);
					for(m=0; m<subnumber; m++) {
						for(n=0; n<end_compchnum-start_compchnum-1; n++) {
							compcase.resulstr2[t] = substr2[n];
							t++;
						}
					}
				}
				else if (j < strlen(compcase.str2) -1) {
					subnum2[ckml]=compcase.str2[j];
					ckml++;
					if (compcase.str2[j+1] == '(') {
						ckmul=0;
						subnumber = atoi(subnum2);
						for(m=0; m<subnumber; m++) {
							for(n=0; n<end_compchnum-start_compchnum-1; n++) {
								compcase.resulstr2[t] = substr2[n];
								t++;
							}
						}
					}
				}
			}
			else {
				compcase.resulstr2[t] = compcase.str2[j];
				t++;
			}
		}
		j=compstring(compcase.resulstr1,compcase.resulstr2);
		if(j==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	free(substr);
	free(substr2);
	free(subnum);
	free(subnum2);
	system("pause");
	return 0;
}