/*
   lab3.c
 */
 
#include <eecs461.h>
#include <adc.h>
#include <MPC5643L.h>
int main(){
vuint16_t iAnalog;
int pad_num;
int i;
char index[8] = {0};
initEECS461();
initADC0_oneshot(1, index);
for(i=0;i<1;i++){
	pad_num=43+i;
	SIU.PCR[pad_num].B.APC=0;
	SIU.PCR[pad_num].B.PA=0;
	SIU.PCR[pad_num].B.OBE=1;
	}
while(1){
iAnalog=readADC0_oneshot(0);
if ((vuint16_t)iAnalog >(vuint16_t)4095/2){
SIU.GPDO[pad_num].B.PDO=1;
}
else{
SIU.GPDO[pad_num].B.PDO=0;
} 


}
}