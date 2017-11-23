#include <stdio.h>
#define HALF_BITS_LENGTH 4
#define FULLMASK 255
#define LMASK (FULLMASK << HALF_BITS_LENGTH)	//11110000
#define RMASK (FULLMASK >> HALF_BITS_LENGTH)	//00001111
#define RSET(b,n) (b = ((LMASK & b) | (n)))   //b的右边设置成n
#define LSET(b,n) (b = ((RMASK & b) | ((n) << HALF_BITS_LENGTH))) //b的左边设置成n
#define RGET(b) (RMASK & b)		//得到b右边值
#define LGET(b) ((LMASK & b) >> HALF_BITS_LENGTH) 		//得到b左边值
#define GRIDW 3
int main()
{
	unsigned char b;
	for(LSET(b,1);LGET(b) <= GRIDW*GRIDW; LSET(b, (LGET(b) + 1)))
		for(RSET(b,1);RGET(b) <= GRIDW*GRIDW; RSET(b, (RGET(b) + 1)))
			if(LGET(b) % GRIDW != RGET(b) % GRIDW)
				printf("A= %d, B= %d\n"; LGET(b),RGET(b));
	return 0;
}