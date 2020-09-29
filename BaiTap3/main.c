#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_pwm.h"
#include "driverlib/pwm.h"
int dem;
int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
	//Buoc 2
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM);
	GPIOPinTypeGPIOInput(GPIO_PORTA_BASE ,GPIO_PIN_0);
	GPIOPinTypeGPIOInput(GPIO_PORTA_BASE ,GPIO_PIN_1);
	GPIOPadConfigSet(GPIO_PORTA_BASE ,GPIO_PIN_0,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPadConfigSet(GPIO_PORTA_BASE ,GPIO_PIN_1,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	//Buoc 3:
	GPIOPinTypePWM(GPIO_PORTD_BASE,GPIO_PIN_1);
	//Buoc 4:
  PWMGenConfigure(PWM_BASE,PWM_GEN_0,PWM_GEN_MODE_UP_DOWN);	
	PWMGenPeriodSet(PWM_BASE,PWM_GEN_0,2000);
	PWMPulseWidthSet(PWM_BASE,PWM_OUT_1,0);
	PWMOutputState(PWM_BASE,PWM_OUT_1_BIT,true);
	PWMGenEnable(PWM_BASE, PWM_GEN_0);
	dem=0;
	while(1)
	{
		if(GPIOPinRead(GPIO_PORTA_BASE ,GPIO_PIN_0)==0)
		{
			while(GPIOPinRead(GPIO_PORTA_BASE ,GPIO_PIN_0)==0);
			dem++;
			if(dem>3)
			{
				dem=1;
			}
		}
		if(GPIOPinRead(GPIO_PORTA_BASE ,GPIO_PIN_1)==0)
		{
			dem=0;
		}
		if (dem==0) //cap do 1
		{
			PWMPulseWidthSet(PWM_BASE,PWM_OUT_1,0);
		}
		else if(dem==1)//cap do 2
		{
			PWMPulseWidthSet(PWM_BASE,PWM_OUT_1,400);//20%
		}
		else if (dem==2)
		{
			PWMPulseWidthSet(PWM_BASE,PWM_OUT_1,1200);//60%
		}
		else 
		{
			PWMPulseWidthSet(PWM_BASE,PWM_OUT_1,1800);//90%
		}
	}
}