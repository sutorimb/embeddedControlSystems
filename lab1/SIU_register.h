typedef union {
	volatile unsigned short REGISTER;
	struct {
		volatile unsigned short :1;
		volatile unsigned short SMC:1;
		volatile unsigned short APC:1;
		volatile unsigned short :1;
		volatile unsigned short PA:2;
		volatile unsigned short OBE:1;
		volatile unsigned short IBE:1;
		volatile unsigned short :2;
		volatile unsigned short ODE:1;
		volatile unsigned short :2;
		volatile unsigned short SRC:1;
		volatile unsigned short WPE:1;
		volatile unsigned short WPS:1;
	}SIUFields;
} SIU_register;
		
		
		