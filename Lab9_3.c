#include<REG_MPC82G516.H>
sbit SPK=P3^4; 
void delay_ms(int t){
	int i;
	while(t--)
		for(i=0;i<1000;++i);
}
unsigned int code tone[] = {65536-1000000/(2*523), // DO     1000000 = 12000000/12
	65536-1000000/(2*587), // RA 1 
	65536-1000000/(2*659), // MI 2 
	65536-1000000/(2*698), // FA 3
	65536-1000000/(2*785), // SO 4
	65536-1000000/(2*880), // LA 5
	65536-1000000/(2*998), // SI 6
	65536-1000000/(2*1046)}; // DO h



unsigned char read_min;
unsigned char i,TEMP_H,TEMP_L;
int j ;

void speaker(int t, int time)
{
	TEMP_H = tone[t]/256;
	TEMP_L = tone[t]%256;
	for(j=0;j<=time;j++){ 
		TH0 = TEMP_H;
		TL0 = TEMP_L;
		TR0 = 1;
		while(TF0 == 0); 
		TF0 = 0;
		TR0 = 0;
		SPK = ! SPK; 
	}
	delay_ms(100);
}
void main()
{
	TMOD = 1; 
	
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
		
		speaker(read_min, 400);
		
		delay_ms(150);
	}
}



