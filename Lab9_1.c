#include<REG_MPC82G516.H>

//sbit P2_1 = P2 ^ 1;
//sbit P2_0 = P2 ^ 0;

void delay_ms(int t){
	int i;
	while(t--)
		for(i=0;i<1000;++i);
}

unsigned char read_min, read_max;

void main()
{
	while(1)
	{
		P21 = 0;
		P21 = 1;
		while(P20 == 1);
		read_min = P1;
		read_min -= 0;	//can change
		read_max = 1;	//can change
		read_min /= read_max;
		P0 = read_min;
		delay_ms(150);
	}
}/*
void main()
{
	while(1)
	{
		P2^1 = 0;
		P2^1 = 1;
		while(P2^0 == 1);
		A = P1;
		A = A - C - 0;	//can change
		B = 1;	//can change
		A /= B;
		P0 = A;
		delay_ms(150);
	}
}*/
