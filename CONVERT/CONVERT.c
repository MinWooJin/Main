#include <stdio.h>
#include <string.h>

int main() {
	int number, i;
	float inputnum;
	char inputch[2];

	fflush(stdin);
	scanf("%d",&number);

	for(i=0; i<number; i++) {
		fflush(stdin);
		scanf("%f",&inputnum);
		fflush(stdin);
		scanf("%s",inputch);

		printf("%d ",i+1);
		if(strcmp(inputch,"kg")==0)
			printf("%.4f %s\n", inputnum*2.2046, "lb");
		else if(strcmp(inputch,"l")==0)
			printf("%.4f %s\n", inputnum*0.2642, "g");
		else if(strcmp(inputch,"lb")==0)
			printf("%.4f %s\n", inputnum*0.4536, "kg");
		else if(strcmp(inputch,"g")==0)
			printf("%.4f %s\n",  inputnum*3.7854, "l");
		else printf("error\n");
	}
	return 0;
}
