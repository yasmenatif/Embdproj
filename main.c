#include "stdint.h"
#include "E:/Keil/EE319KwareSpring2021/inc/tm4c123gh6pm.h"



void delayms(int n);
void delayms(int n) {
  int i, j;
  for(i=0; i<n; i++)
   for(j=0;j<3000;j++)
    {}
}

int main(void){
	int distance;
	distance = 111;
	SYSCTL_RCGCGPIO_R |=0x20;
	while ((SYSCTL_PRGPIO_R&0x20)==0){};
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
  GPIO_PORTF_CR_R |= 0x04;               
  GPIO_PORTF_AMSEL_R = 0x00;        
  GPIO_PORTF_PCTL_R = 0x00000000;  
  GPIO_PORTF_DIR_R |= 0x04;            
  GPIO_PORTF_AFSEL_R &= ~0x04;                     
  GPIO_PORTF_DEN_R |= 0x04; 	
	
	if (distance >= 100) {
	   GPIO_PORTF_DATA_R |= 0x04;
	 } else if (distance < 100){                        
          GPIO_PORTF_DATA_R &= ~0x04;  
        }
	 
}
	
	

