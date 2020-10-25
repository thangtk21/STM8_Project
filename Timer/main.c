#include <iostm8s005k6.h>
#include <intrinsics.h>
#include <stdint.h>
#define LED4 PB_ODR_bit.ODR0

uint8_t dosang[16];

void LED4_Sang_dan()
{
  
}

void gpio_init()
{
  PB_DDR_bit.DDR0 = 1; // output
  PB_CR1_bit.C10 = 1; // push-pull
}
void clock_init()
{
  CLK_CKDIVR = 0; // f = 16MHz
}

void timer_init()
{
  TIM2_PSCR = 2; // f_cnt = 16/2^2 = 4MHz
  TIM2_ARRH = 400 >> 8;
  TIM2_ARRL = 400; // T_tim2 = 1 * 400 = 400 us
  TIM2_IER_bit.UIE = 1;
  TIM2_CR1_bit.ARPE = 1; // auto reload enable
  TIM2_CR1_bit.CEN = 1;  
}
int main( void )
{
  dosang[0] = 10;
  clock_init();
  __disable_interrupt();
  timer_init();
  __enable_interrupt();
  gpio_init();
  while(1)
  {
    
  }
  return 0;
}

#pragma vector = TIM2_OVR_UIF_vector
__interrupt void tim2_handle()
{
  static uint8_t count = 0;
  if(++count == 100)
  {
    count = 0;
  }
  if(count < dosang[0])
    LED4 = 1;
  else
    LED4 = 0;
  
  
  TIM2_SR1_bit.UIF = 0;
  
}












