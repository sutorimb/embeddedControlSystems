#include <eecs461.h>
#include <SIU_register.h>
int main(){
	const unsigned int PCR_base=0XC3F90040;
	const unsigned int GPDO_base=0XC3F90600;
	const unsigned int GPDI_base=0XC3F90800;
	volatile SIU_register* siu_pad_ptr; 
	volatile unsigned char *gpdo_ptr;
	volatile unsigned char *gpdi_ptr;
	int pad_num;
	int i;
	int sum;
	initEECS461();
	siu_pad_ptr = (SIU_register*)(PCR_base);
	gpdo_ptr = (unsigned char*)(GPDO_base);
	gpdi_ptr = (unsigned char*)(GPDI_base);

	for(i=0;i<8;i++){
	pad_num=5+i;
	siu_pad_ptr[pad_num].SIUFields.APC=0;
	siu_pad_ptr[pad_num].SIUFields.PA=0;
	siu_pad_ptr[pad_num].SIUFields.IBE=1;
	}

	for(i=0;i<6;i++){
	pad_num=43+i;
	siu_pad_ptr[pad_num].SIUFields.APC=0;
	siu_pad_ptr[pad_num].SIUFields.PA=0;
	siu_pad_ptr[pad_num].SIUFields.OBE=1;
	}
	
	while(1){
	sum=0;
		for(i=0;i<4;i++){
			pad_num=5+i;
			sum=sum+((gpdi_ptr[pad_num] & 0b1) <<i);
		}
		for(i=0;i<4;i++){
			pad_num=9+i;
			sum=sum+((gpdi_ptr[pad_num] & 0b1) <<i);
		}
		
		for(i=0;i<6;i++){
		pad_num=43+i;
		gpdo_ptr[pad_num]=((sum >> i) & 0b1);
		}
	}
}