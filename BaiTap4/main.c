#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_ints.h"
#include "driverlib/interrupt.h"
int i;
void Ngat_GPIOA(void)
{
	for(i=0;i<5;i++)
	{
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_1,0);
		SysCtlDelay(1333333);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_1,2);
		SysCtlDelay(1333333);
	}
	GPIOPinIntClear(GPIO_PORTA_BASE,GPIO_PIN_0);
}
int main()
{
	SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_OSC|SYSCTL_XTAL_8MHZ|SYSCTL_OSC_MAIN);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	GPIOPinTypeGPIOInput(GPIO_PORTA_BASE,GPIO_PIN_0);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE ,GPIO_PIN_0);
	GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE ,GPIO_PIN_1);
	GPIOPadConfigSet(GPIO_PORTA_BASE,GPIO_PIN_0,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
	GPIOPinIntEnable(GPIO_PORTA_BASE,GPIO_PIN_0);
	IntEnable(INT_GPIOA);
	IntMasterEnable();
	while(1)
	{
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_0,0);
		SysCtlDelay(1333333);
		GPIOPinWrite(GPIO_PORTD_BASE ,GPIO_PIN_0,1);
		SysCtlDelay(1333333);
	}
}