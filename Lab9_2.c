#include<REG_MPC82G516.H>

sbit SPK=P3^4; 
void delay_ms(int t);
unsigned int code tone[] = {65536-1000000/(2*523), // DO     1000000 = 12000000/12
	65536-1000000/(2*587), // RA 1 
	65536-1000000/(2*659), // MI 2 
	65536-1000000/(2*698), // FA 3
	65536-1000000/(2*785), // SO 4
	65536-1000000/(2*880), // LA 5
	65536-1000000/(2*998), // SI 6
	65536-1000000/(2*1046)}; // DO h

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

void main(void){
	TMOD = 1; 
	speaker(4, 200);speaker(2, 200);speaker(2, 400);//SO MI MI~
	speaker(3, 200);speaker(1, 200);speaker(1, 400);//FA RE RE~
	speaker(0, 200);speaker(1, 200);speaker(2, 200);//DO RE MI
	speaker(3, 200);speaker(4, 200);speaker(4, 200);speaker(4, 400);//FA SO SO SO~
	
	speaker(4, 200);speaker(2, 200);speaker(2, 400);//SO MI MI~
	speaker(3, 200);speaker(1, 200);speaker(1, 400);//FA RE RE~
	speaker(0, 200);speaker(2, 200);speaker(4, 200);//DO MI SO
	speaker(4, 200);speaker(2, 400);//SO MI~
	
	speaker(1, 200);speaker(1, 200);speaker(1, 200);speaker(1, 200);speaker(1, 200);//RE*5
	speaker(2, 200);speaker(3, 400);//MI FA~
	speaker(2, 200);speaker(2, 200);speaker(2, 200);speaker(2, 200);speaker(2, 200);//MI*5
	speaker(3, 200);speaker(4, 400);//MI FA~
	
	speaker(4, 200);speaker(2, 200);speaker(2, 400);//SO MI MI~
	speaker(3, 200);speaker(1, 200);speaker(1, 400);//FA RE RE~
	speaker(0, 200);speaker(2, 200);speaker(4, 200);//DO MI SO
	speaker(4, 200);speaker(0, 400);//SO MI~
} 

void delay_ms(int t){
	int i;
	while(t--)
		for(i=0;i<1000;++i);
}
