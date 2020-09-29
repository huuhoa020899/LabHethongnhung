#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_pwm.h"
#include "driverlib/pwm.h"
int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPWMClockSet(SYSCTL_PWMDIV_1);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM);
	// Buoc3
	GPIOPinTypePWM(GPIO_PORTD_BASE ,GPIO_PIN_1);
	// Buoc4
	PWMGenConfigure(PWM_BASE ,PWM_GEN_0,PWM_GEN_MODE_UP_DOWN);
	PWMGenPeriodSet(PWM_BASE ,PWM_GEN_0,500);
	PWMPulseWidthSet(PWM_BASE,PWM_OUT_1,0);
	PWMOutputState(PWM_BASE,PWM_OUT_1_BIT,true);
	PWMGenEnable(PWM_BASE, PWM_GEN_0);
	while(1)
	{
	PWMGenPeriodSet(PWM_BASE ,PWM_GEN_0,500);
	PWMPulseWidthSet(PWM_BASE,PWM_OUT_1,250);
	SysCtlDelay(2666666);
	PWMGenPeriodSet(PWM_BASE ,PWM_GEN_0,1000);
	PWMPulseWidthSet(PWM_BASE,PWM_OUT_1,300);
	SysCtlDelay(2666666);
	}
}