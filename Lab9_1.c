#include<REG_MPC82G516.H>

void delay_ms(int t){
	int i;
	while(t--)
		for(i=0;i<1000;++i);
}

unsigned char read_min;

void main()
{
	while(1)
	{
		P21 = 0;
		P21 = 1;
		while(P20 == 1);
		//P0 = P1;
		//P0 = (read_min/16)<<4 + (read_min%16);
		
		read_min = P1;
		read_min -= 16;	//can change
		read_min /= 32;//can change
		P0 = read_min;
		delay_ms(150);
	}
}
