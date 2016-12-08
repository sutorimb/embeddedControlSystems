#include <eecs461.h>
#include <MPC5643L.h>
int main(){
	
	int pad_num;
	int i;
	int sum;
	initEECS461();

	for(i=0;i<8;i++){
	pad_num=5+i;
	SIU.PCR[pad_num].B.APC=0;
	SIU.PCR[pad_num].B.PA=0;
	SIU.PCR[pad_num].B.IBE=1;
	}
	
	for(i=0;i<6;i++){
	pad_num=43+i;
	SIU.PCR[pad_num].B.APC=0;
	SIU.PCR[pad_num].B.PA=0;
	SIU.PCR[pad_num].B.OBE=1;
	}
	
	while(1){
	sum=0;
		for(i=0;i<4;i++){
			pad_num=5+i;
			sum=sum+((SIU.GPDI[pad_num].B.PDI & 0b1) << i);
		}
		for(i=0;i<4;i++){
			pad_num=9+i;
			sum=sum+((SIU.GPDI[pad_num].B.PDI & 0b1) << i);
		}
		
		for(i=0;i<6;i++){
		pad_num=43+i;
		SIU.GPDO[pad_num].B.PDO=((sum >>i) & 0b1);
		}
	}
}