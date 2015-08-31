#include <stdio.h>
#include <stdint.h>

int main()
{
	int n, ii;
	uint32_t num;
	uint32_t b0, b1, b2, b3, ret;
	
	scanf("%d", &n);
	for(ii=0; ii<n; ii++)
	{
		scanf("%d",&num);
		b0 = (num & 0x000000ff) << 24u;
		b1 = (num & 0x0000ff00) << 8u;
		b2 = (num & 0x00ff0000) >> 8u;
		b3 = (num & 0xff000000) >> 24u;
		
		ret = b0 | b1 | b2 | b3;
		printf("%u\n",ret);
	}
	
	return 0;
}
