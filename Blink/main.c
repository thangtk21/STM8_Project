#include <iostm8s005k6.h>
#include <intrinsics.h>

#define LED4 PB_ODR_bit.ODR0
#define LED3 PB_ODR_bit.ODR1
#define LED2 PB_ODR_bit.ODR2
#define LED1 PB_ODR_bit.ODR3

#define LED8 PC_ODR_bit.ODR1
#define LED7 PC_ODR_bit.ODR2
#define LED6 PC_ODR_bit.ODR3
#define LED5 PC_ODR_bit.ODR4

void delay_us(int time)
{
  while(time--)
  {
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
  }
}
void delay_ms(int time)
{
  while(time--)
  {
    delay_us(1000);
  }
}
void clock_init(void)
{
  CLK_ICKR_bit.HSIEN = 1; // hsi rc enable
  while(CLK_ICKR_bit.HSIRDY == 0);
  // Fcpu = main clock /1 = 16MHz
  CLK_CKDIVR = 0;
}
void gpio_init(void)
{
  PB_DDR_bit.DDR0 = 1; // output
  PB_CR1_bit.C10 = 1; // push-pull
  
  PB_DDR_bit.DDR1 = 1; // output
  PB_CR1_bit.C11 = 1; // push-pull
  
  PB_DDR_bit.DDR2 = 1; // output
  PB_CR1_bit.C12 = 1; // push-pull
  
  PB_DDR_bit.DDR3 = 1; // output
  PB_CR1_bit.C13 = 1; // push-pull
  
  PC_DDR_bit.DDR1 = 1; // output
  PC_CR1_bit.C11 = 1; // push-pull
  
  PC_DDR_bit.DDR2 = 1; // output
  PC_CR1_bit.C12 = 1; // push-pull
  
  PC_DDR_bit.DDR3 = 1; // output
  PC_CR1_bit.C13 = 1; // push-pull
  
  PC_DDR_bit.DDR4 = 1; // output
  PC_CR1_bit.C14 = 1; // push-pull
}

int main( void )
{
  clock_init();
  gpio_init();
  while(1)
  {
    PC_ODR_bit.ODR4 = 0;
    delay_ms(100);
    PC_ODR_bit.ODR4 = 1;
    delay_ms(100);
  }
  return 0;
}
