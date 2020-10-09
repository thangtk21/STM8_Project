#include <iostm8s005k6.h>
#include <intrinsics.h>

void clock_init(void)
{
  CLK_ICKR_bit.HSIEN = 1; // hsi rc enable
  while(CLK_ICKR_bit.HSIRDY == 0);
  
}


int main( void )
{
  
  return 0;
}
