#include <eecs461.h>
#include <MPC5643L.h>
#include <serial.h>
int pad_num;
int i;
int key1=0;
int key2=0;
char byte_in;

int main(){
initEECS461();
initUART(9600);
serial_puts("\n\n\n\n\n\n\n\n\rSerial Output Enabled.");


	
	for(i=0;i<6;i++){
	pad_num=43+i;
	SIU.PCR[pad_num].B.APC=0;
	SIU.PCR[pad_num].B.PA=0;
	SIU.PCR[pad_num].B.OBE=1;
	}
	
	while(1){
		if (serial_readyToReceive(1)){
			key1=key2;
			byte_in=serial_getchar(1);
			switch (byte_in){
				case '0':
				key2=0;
				break;
				case '1':
				key2=1;
				break;
				case '2':
				key2=2;
				break;
				case '3':
				key2=3;
				break;
				case '4':
				key2=4;
				break;
				case '5':
				key2=5;
				break;
				case '6':
				key2=6;
				break;
				case '7':
				key2=7;
				break;
				case '8':
				key2=8;
				break;
				case '9':
				key2=9;
				break;
			}
		}
		for(i=0;i<6;i++){
		pad_num=43+i;
		SIU.GPDO[pad_num].B.PDO=(((key1+key2)>>i) & 0b1);
		}
		
	}
}



	
	