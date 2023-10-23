#include <stm8s.h>
#include "stm8s_uart1.h"
#include "stm8s_gpio.h"
 #include "stm8s_tim1.h"


 int ui=0;


// Delay loop


//
// Actual delay depends on clock settings
// and compiler optimization settings.
//
void TIM4_setup(void)
{   

     TIM4_DeInit();
     TIM4_TimeBaseInit(TIM4_PRESCALER_128, 255);      
     TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
      enableInterrupts();

     TIM4_Cmd(ENABLE);
     
		 
}
void delay(unsigned int n)
{
  while (n-- > 0);
}

 
void GPIO_setup(void)
{
  GPIO_Init( GPIOC,  GPIO_PIN_7,GPIO_MODE_OUT_PP_HIGH_FAST  );//LED GREEN
   GPIO_Init( GPIOD,  GPIO_PIN_4,GPIO_MODE_OUT_PP_HIGH_FAST  );//ENABLE RS485
  GPIO_Init( GPIOD,  GPIO_PIN_2,GPIO_MODE_IN_PU_IT );//CALL BUTTOM
   GPIO_Init( GPIOA,  GPIO_PIN_3,GPIO_MODE_IN_PU_IT );//acknolodge
   GPIO_Init( GPIOC,  GPIO_PIN_6,GPIO_MODE_OUT_PP_HIGH_FAST  );//COM1 LED
   GPIO_Init( GPIOC,  GPIO_PIN_5,GPIO_MODE_OUT_PP_HIGH_FAST  );//COM2  LED
   GPIO_Init( GPIOC,  GPIO_PIN_4,GPIO_MODE_OUT_PP_HIGH_FAST  );// COM3 LED
   GPIO_Init( GPIOC,  GPIO_PIN_3,GPIO_MODE_IN_PU_NO_IT  );// COMP1
    GPIO_Init( GPIOB,  GPIO_PIN_4,GPIO_MODE_IN_PU_NO_IT  );// COMP2
     GPIO_Init( GPIOB,  GPIO_PIN_5,GPIO_MODE_IN_PU_NO_IT  );// COMP3
      GPIO_Init( GPIOD,  GPIO_PIN_3,GPIO_MODE_OUT_PP_HIGH_FAST  );//RELAY

}
 
 
void EXTI_setup(void)
{
 
                
    EXTI_DeInit();
    EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_FALL_ONLY);
    EXTI_SetTLISensitivity(EXTI_TLISENSITIVITY_FALL_ONLY);
     EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOA, EXTI_SENSITIVITY_FALL_ONLY);
    EXTI_SetTLISensitivity(EXTI_TLISENSITIVITY_FALL_ONLY);               
 }
void clock_setup(void)
{
        CLK_DeInit();
       CLK_HSECmd(DISABLE);
       CLK_LSICmd(DISABLE);
       CLK_HSICmd(ENABLE);
        CLK_ClockSwitchCmd(ENABLE);
      CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
      CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
       CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI,
       DISABLE, CLK_CURRENTCLOCKSTATE_ENABLE);
       CLK_PeripheralClockConfig(CLK_PERIPHERAL_SPI, DISABLE);
       CLK_PeripheralClockConfig(CLK_PERIPHERAL_I2C, DISABLE);
       CLK_PeripheralClockConfig(CLK_PERIPHERAL_ADC, DISABLE);
       CLK_PeripheralClockConfig(CLK_PERIPHERAL_AWU, DISABLE);
       CLK_PeripheralClockConfig(CLK_PERIPHERAL_UART1, ENABLE);
       CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER1, DISABLE);
       CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER2, DISABLE);
       CLK_PeripheralClockConfig(CLK_PERIPHERAL_TIMER4, ENABLE);

}
int main( void )
{
   clock_setup();
   GPIO_setup();

   GPIO_WriteHigh(GPIOD,  GPIO_PIN_4);
            GPIO_WriteHigh(GPIOD,  GPIO_PIN_3);
        
   UART1_DeInit();
   UART1_Init
    (4800,UART1_WORDLENGTH_8D,UART1_STOPBITS_1,
  UART1_PARITY_NO,UART1_SYNCMODE_CLOCK_DISABLE,UART1_MODE_TXRX_ENABLE);
   UART1_Cmd(ENABLE);
   EXTI_setup();
   TIM4_setup();

   while (1)
  {
 
            
 
            
                             

     
                
               


    }
}
