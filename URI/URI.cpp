#include <stdio.h>
#include <stdlib.h>

int main() {

	int number,i, j, k;
	char uri[100][80], resulturi[100][80];

	scanf("%d",&number);
	for(i=0; i<number; i++)
		scanf("%s",&uri[i]);
	
	for(i=0; i<number; i++) {
		k=0;
		for(j=0; j<sizeof(uri[i]);) {
			if(uri[i][j]=='%') {
				if(uri[i][j+2]=='0') {
					resulturi[i][k]=' '; j+=3; k++;
				}
				else if(uri[i][j+2]=='1') {
					resulturi[i][k]='!'; j+=3; k++;
				}
				else if(uri[i][j+2]=='4') {
					resulturi[i][k]='$'; j+=3; k++;
				}
				else if(uri[i][j+2]=='5') {
					resulturi[i][k]='%'; j+=3; k++;
				}
				else if(uri[i][j+2]=='8') {
					resulturi[i][k]='('; j+=3; k++;
				}
				else if(uri[i][j+2]=='9') {
					resulturi[i][k]=')'; j+=3; k++;
				}
				else if(uri[i][j+2]=='a') {
					resulturi[i][k]='*'; j+=3; k++;
				}
			}
			else {
				resulturi[i][k]=uri[i][j]; j++; k++;
			}
		}
	}
	for (i=0; i<number; i++)
		printf("%s\n",resulturi[i]);

	system("pause");
	return 0;
}