#include <eecs461.h>
#include <qd.h>

int main(){
float angle;
int pad_num;
int i;
initEECS461();
initQD();

for(i=0;i<16;i++){
	pad_num=43+i;
	SIU.PCR[pad_num].B.APC=0;
	SIU.PCR[pad_num].B.PA=0;
	SIU.PCR[pad_num].B.OBE=1;
	}
	
while(1){
angle=updateAngle();

for(i=0;i<16;i++){
		pad_num=43+i;
		SIU.GPDO[pad_num].B.PDO=((((int16_t)angle) >>i) & 0b1);
		}
}
}