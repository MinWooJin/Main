#include <stdio.h>

int input[40];

void qsort(int left, int right);

int main()
{
	int testcase, inputnum;
	float result,subresult;
	int i,j;

	scanf("%d", &testcase);
	for(i=0; i<testcase; i++) {
		result = 0;
		scanf("%d", &inputnum);
		for(j=0; j<inputnum; j++) scanf("%d", &input[j]);
		qsort(0,inputnum-1);
		for(j=0; j<inputnum/2; j++) {
			subresult = (float)(input[inputnum-1-j]+input[j])/2;
			if(result < subresult)
				result = subresult;
		}
		if(inputnum % 2 == 1) {
			subresult = (float)(input[inputnum/2]);
			if(result < subresult)
				result = subresult;
		}
		printf("%.1f\n",result);
	}
	return 0;
}

void qsort(int left, int right) {
	int i, j, pivot, temp;
     	i = left; j = right; pivot = i;                       
     	if (i < j){
           while (i < j){
               	while (input[i] < input[pivot] && i < j) i++;  
               	while (input[j] >= input[pivot] && i < j) j--;
               	temp = input[i];                                  
               	input[i] = input[j];
               	input[j] = temp;
           }
          temp = input[i];                                      
          input[i] = input[pivot];
          input[pivot] = temp;
          qsort(left, i-1);                                    
          qsort(i + 1, right);
     }
}
