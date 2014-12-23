#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct comp{
	char str1[1000];
	char str2[1000];
	char resulstr1[1000];
	char resulstr2[1000];
};

int compstring(char *s1, char *s2) {
	int comp = strcmp(s1,s2);
	return comp;
}

int main() {
	int testcase, ckcompress, start_compchnum, end_compchnum, ckcom, 
		ckmul, ckml, subnumber, i, j, t, m, n;
	comp compcase[100] = {{0,},{0,},{0,},{0,},};
	char *substr, *substr2, *subnum, *subnum2;
	substr = (char *)malloc(1000);
	substr2 = (char *)malloc(1000);
	subnum = (char *)malloc(100000000);
	subnum2 = (char *)malloc(100000000);
	scanf("%d",&testcase);

	for(i=0; i<testcase; i++) {
		scanf("%s",&compcase[i].str1);
		scanf("%s",&compcase[i].str2);
	}

	for(i=0; i<testcase; i++) {
		t=0;
		for(j=0; j<strlen(compcase[i].str1); j++) {
			if(compcase[i].str1[j]=='(') {
				ckcompress=1;
				ckcom=0;
				start_compchnum=j;
			}
			else if (compcase[i].str1[j]==')') {
				ckcompress=0;
				end_compchnum=j;
			}
			else if (ckcompress==1) {
				substr[ckcom]=compcase[i].str1[j];
				ckcom++;
			}
			else if (compcase[i].str1[j]=='^') {
				ckmul=1;
				ckml=0;
			}
			else if (ckmul==1 && compcase[i].str1[j] > 64) {
				ckmul=0;
				subnumber = atoi(subnum);
				for(m=0; m<subnumber; m++) {
					for(n=0; n<end_compchnum-start_compchnum-1; n++) {
						compcase[i].resulstr1[t] = substr[n];
						t++;
					}
				}
				compcase[i].resulstr1[t] = compcase[i].str1[j];
				t++;
			}
			else if (ckmul==1) {
				if (j == strlen(compcase[i].str1) - 1) {
					subnum[ckml]=compcase[i].str1[j];
					ckml++;
					ckmul=0;
					subnumber = atoi(subnum);
					for(m=0; m<subnumber; m++) {
						for(n=0; n<end_compchnum-start_compchnum-1; n++) {
							compcase[i].resulstr1[t] = substr[n];
							t++;
						}
					}
				}
				else if (j < strlen(compcase[i].str1) -1) {
					subnum[ckml]=compcase[i].str1[j];
					ckml++;
					if (compcase[i].str1[j+1] == '(') {
						ckmul=0;
						subnumber = atoi(subnum);
						for(m=0; m<subnumber; m++) {
							for(n=0; n<end_compchnum-start_compchnum-1; n++) {
								compcase[i].resulstr1[t] = substr[n];
								t++;
							}
						}
					}
				}
			}
			else {
				compcase[i].resulstr1[t] = compcase[i].str1[j];
				t++;
			}
		}
		t=0;
		for(j=0; j<strlen(compcase[i].str2); j++) {
			if(compcase[i].str2[j]=='(') {
				ckcompress=1;
				ckcom=0;
				start_compchnum=j;
			}
			else if (compcase[i].str2[j]==')') {
				ckcompress=0;
				end_compchnum=j;
			}
			else if (ckcompress==1) {
				substr2[ckcom]=compcase[i].str2[j];
				ckcom++;
			}
			else if (compcase[i].str2[j]=='^') {
				ckmul=1;
				ckml=0;
			}
			else if (ckmul==1 && compcase[i].str2[j] > 64) {
				ckmul=0;
				subnumber = atoi(subnum2);
				for(m=0; m<subnumber; m++) {
					for(n=0; n<end_compchnum-start_compchnum-1; n++) {
						compcase[i].resulstr2[t] = substr2[n];
						t++;
					}
				}
				compcase[i].resulstr2[t] = compcase[i].str2[j];
				t++;
			}
			else if (ckmul==1) {
				if (j == strlen(compcase[i].str2) - 1) {
					subnum2[ckml]=compcase[i].str2[j];
					ckml++;
					ckmul=0;
					subnumber = atoi(subnum2);
					for(m=0; m<subnumber; m++) {
						for(n=0; n<end_compchnum-start_compchnum-1; n++) {
							compcase[i].resulstr2[t] = substr2[n];
							t++;
						}
					}
				}
				else if (j < strlen(compcase[i].str2) -1) {
					subnum2[ckml]=compcase[i].str2[j];
					ckml++;
					if (compcase[i].str2[j+1] == '(') {
						ckmul=0;
						subnumber = atoi(subnum2);
						for(m=0; m<subnumber; m++) {
							for(n=0; n<end_compchnum-start_compchnum-1; n++) {
								compcase[i].resulstr2[t] = substr2[n];
								t++;
							}
						}
					}
				}
			}
			else {
				compcase[i].resulstr2[t] = compcase[i].str2[j];
				t++;
			}
		}

	}
	for(i=0; i<testcase; i++) {
		j=compstring(compcase[i].resulstr1,compcase[i].resulstr2);
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