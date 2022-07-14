#include<drivers/pin.h>
#include "../drivers/drv_gpio.h"

int main(int argc, char **argv, char **env, struct callvectors *cv ,rt_uint8_t pin_gpio8 , rt_uint8_t pin_gpio9 ,rt_uint8_t pin_gpio7)
{
 callvec = cv; // 这条语句之后才能使用 PMON 提供的打印功能
 bsp_init();
 test_gpio_output();
  unsigned int gpio7 = 7; 
   unsigned int gpio8 = 8; 
    unsigned int gpio9 = 9; 


    // 把相应gpio设为输出模式
    rt_pin_mode(pin_gpio8, PIN_MODE_OUTPUT);
    rt_pin_mode(pin_gpio7, PIN_MODE_INPUT);
    rt_pin_mode(pin_gpio9, PIN_MODE_INPUT);
    while (1)  
    {
        if(PIN_HIGHT == rt_pin_read(pin_gpio9)&&PIN_HIGHT == rt_pin_read(pin_gpio7))
        {
         
         rt_pin_write(pin_gpio8, PIN_LOW);
        
        }
        if(PIN_LOW == rt_pin_read(pin_gpio9))
        {

          rt_pin_write(pin_gpio8, PIN_HIGHT);

        }      

       
    }  

 return(0);
}
void test_gpio_output(void)
{
 int i;
 unsigned int gpio = 52; 
 // 初始化
 gpio_init(gpio, gpio_mode_output);
 // 输出 10 个矩形波，如果 gpio52 上有 led，则可以看见 led 闪烁 10 次
 for (i=0; i<10; i++)
 {
 gpio_set(gpio, gpio_level_low);
 delay_s(1);
 gpio_set(gpio, gpio_level_high);
 delay_s(1);
 }
 return ;
}
