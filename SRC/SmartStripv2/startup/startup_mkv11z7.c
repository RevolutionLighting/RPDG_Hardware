//*****************************************************************************
// MKV11Z7 startup code for use with MCUXpresso IDE
//
// Version : 130717
//*****************************************************************************
//
// Copyright(C) NXP Semiconductors, 2017
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// o Redistributions of source code must retain the above copyright notice, this list
//   of conditions and the following disclaimer.
//
// o Redistributions in binary form must reproduce the above copyright notice, this
//   list of conditions and the following disclaimer in the documentation and/or
//   other materials provided with the distribution.
//
// o Neither the name of copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from this
//   software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
// ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//*****************************************************************************

#if defined (DEBUG)
#pragma GCC push_options
#pragma GCC optimize ("Og")
#endif // (DEBUG)

#if defined (__cplusplus)
#ifdef __REDLIB__
#error Redlib does not support C++
#else
//*****************************************************************************
//
// The entry point for the C++ library startup
//
//*****************************************************************************
extern "C" {
    extern void __libc_init_array(void);
}
#endif
#endif

#define WEAK __attribute__ ((weak))
#define WEAK_AV __attribute__ ((weak, section(".after_vectors")))
#define ALIAS(f) __attribute__ ((weak, alias (#f)))

//*****************************************************************************
#if defined (__cplusplus)
extern "C" {
#endif

//*****************************************************************************
// Flash Configuration block : 16-byte flash configuration field that stores
// default protection settings (loaded on reset) and security information that
// allows the MCU to restrict access to the Flash Memory module.
// Placed at address 0x400 by the linker script.
//*****************************************************************************

__attribute__ ((used,section(".FlashConfig"))) const struct {
    unsigned int word1;
    unsigned int word2;
    unsigned int word3;
    unsigned int word4;
} Flash_Config = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFE};

//*****************************************************************************
// Declaration of external SystemInit function
//*****************************************************************************
#if defined (__USE_CMSIS)
extern void SystemInit(void);
#endif // (__USE_CMSIS)

//*****************************************************************************
// Forward declaration of the core exception handlers.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions
//*****************************************************************************
     void ResetISR(void);
WEAK void NMI_Handler(void);
WEAK void HardFault_Handler(void);
WEAK void SVC_Handler(void);
WEAK void PendSV_Handler(void);
WEAK void SysTick_Handler(void);
WEAK void IntDefaultHandler(void);

//*****************************************************************************
// Forward declaration of the application IRQ handlers. When the application
// defines a handler (with the same name), this will automatically take
// precedence over weak definitions below
//*****************************************************************************
WEAK void DMA0_DMA4_IRQHandler(void);
WEAK void DMA1_DMA5_IRQHandler(void);
WEAK void DMA2_DMA6_IRQHandler(void);
WEAK void DMA3_DMA7_IRQHandler(void);
WEAK void DMA_Error_IRQHandler(void);
WEAK void FTFA_IRQHandler(void);
WEAK void LVD_LVW_IRQHandler(void);
WEAK void LLWU_IRQHandler(void);
WEAK void I2C0_IRQHandler(void);
WEAK void Reserved25_IRQHandler(void);
WEAK void SPI0_IRQHandler(void);
WEAK void Reserved27_IRQHandler(void);
WEAK void UART0_IRQHandler(void);
WEAK void UART1_IRQHandler(void);
WEAK void CAN0_IRQHandler(void);
WEAK void ADC0_IRQHandler(void);
WEAK void ADC1_IRQHandler(void);
WEAK void FTM0_IRQHandler(void);
WEAK void FTM1_IRQHandler(void);
WEAK void FTM2_IRQHandler(void);
WEAK void CMP0_IRQHandler(void);
WEAK void CMP1_IRQHandler(void);
WEAK void FTM3_IRQHandler(void);
WEAK void WDOG_EWM_IRQHandler(void);
WEAK void FTM4_IRQHandler(void);
WEAK void DAC0_IRQHandler(void);
WEAK void FTM5_IRQHandler(void);
WEAK void MCG_IRQHandler(void);
WEAK void LPTMR0_IRQHandler(void);
WEAK void PDB0_PDB1_IRQHandler(void);
WEAK void PORTA_IRQHandler(void);
WEAK void PORTB_PORTC_PORTD_PORTE_IRQHandler(void);

//*****************************************************************************
// Forward declaration of the driver IRQ handlers. These are aliased
// to the IntDefaultHandler, which is a 'forever' loop. When the driver
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//*****************************************************************************
void DMA0_DMA4_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA1_DMA5_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA2_DMA6_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA3_DMA7_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DMA_Error_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FTFA_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LVD_LVW_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LLWU_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void I2C0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved25_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void SPI0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void Reserved27_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UART0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void UART1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CAN0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void ADC0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void ADC1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FTM0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FTM1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FTM2_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CMP0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void CMP1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FTM3_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void WDOG_EWM_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FTM4_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void DAC0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void FTM5_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void MCG_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void LPTMR0_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PDB0_PDB1_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PORTA_DriverIRQHandler(void) ALIAS(IntDefaultHandler);
void PORTB_PORTC_PORTD_PORTE_DriverIRQHandler(void) ALIAS(IntDefaultHandler);

//*****************************************************************************
// The entry point for the application.
// __main() is the entry point for Redlib based applications
// main() is the entry point for Newlib based applications
//*****************************************************************************
#if defined (__REDLIB__)
extern void __main(void);
#endif
extern int main(void);

//*****************************************************************************
// External declaration for the pointer to the stack top from the Linker Script
//*****************************************************************************
extern void _vStackTop(void);

//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif

//*****************************************************************************
// The vector table.
// This relies on the linker script to place at correct location in memory.
//*****************************************************************************
extern void (* const g_pfnVectors[])(void);
extern void * __Vectors __attribute__ ((alias ("g_pfnVectors")));

__attribute__ ((used, section(".isr_vector")))
void (* const g_pfnVectors[])(void) = {
    // Core Level - CM0P
    &_vStackTop,                       // The initial stack pointer
    ResetISR,                          // The reset handler
    NMI_Handler,                       // The NMI handler
    HardFault_Handler,                 // The hard fault handler
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    0,                                 // Reserved
    SVC_Handler,                       // SVCall handler
    0,                                 // Reserved
    0,                                 // Reserved
    PendSV_Handler,                    // The PendSV handler
    SysTick_Handler,                   // The SysTick handler

    // Chip Level - MKV11Z7
    DMA0_DMA4_IRQHandler,                // 16: DMA channel 0 and 4 transfer complete
    DMA1_DMA5_IRQHandler,                // 17: DMA channel 1 and 5 transfer complete
    DMA2_DMA6_IRQHandler,                // 18: DMA channel 2 and 6 transfer complete
    DMA3_DMA7_IRQHandler,                // 19: DMA channel 2 and 7 transfer complete
    DMA_Error_IRQHandler,                // 20: DMA error interrupt channels 0-7
    FTFA_IRQHandler,                     // 21: FTFA command complete and read collision
    LVD_LVW_IRQHandler,                  // 22: Low-voltage detect, low-voltage warning
    LLWU_IRQHandler,                     // 23: Low Leakage Wakeup
    I2C0_IRQHandler,                     // 24: I2C0 interrupt
    Reserved25_IRQHandler,               // 25: Reserved interrupt
    SPI0_IRQHandler,                     // 26: SPI0 single interrupt vector for all sources
    Reserved27_IRQHandler,               // 27: Reserved interrupt
    UART0_IRQHandler,                    // 28: UART0 status and error
    UART1_IRQHandler,                    // 29: UART1 status and error
    CAN0_IRQHandler,                     // 30: CAN0 interrupt
    ADC0_IRQHandler,                     // 31: ADC0 interrupt
    ADC1_IRQHandler,                     // 32: ADC1 interrupt
    FTM0_IRQHandler,                     // 33: FTM0 single interrupt vector for all sources
    FTM1_IRQHandler,                     // 34: FTM1 single interrupt vector for all sources
    FTM2_IRQHandler,                     // 35: FTM2 single interrupt vector for all sources
    CMP0_IRQHandler,                     // 36: CMP0 interrupt
    CMP1_IRQHandler,                     // 37: CMP1 interrupt
    FTM3_IRQHandler,                     // 38: FTM3 single interrupt vector for all sources
    WDOG_EWM_IRQHandler,                 // 39: Single interrupt vector for  WDOG and EWM
    FTM4_IRQHandler,                     // 40: FTM4 single interrupt vector for all sources
    DAC0_IRQHandler,                     // 41: DAC0 interrupt
    FTM5_IRQHandler,                     // 42: FTM5 single interrupt vector for all sources
    MCG_IRQHandler,                      // 43: MCG interrupt
    LPTMR0_IRQHandler,                   // 44: LPTMR0 interrupt
    PDB0_PDB1_IRQHandler,                // 45: Single interrupt vector for  PDB0 and PDB1
    PORTA_IRQHandler,                    // 46: PORTA pin detect
    PORTB_PORTC_PORTD_PORTE_IRQHandler,  // 47: Single interrupt vector for PORTB, PORTC, PORTD and PORTE pin detect
}; /* End of g_pfnVectors */

//*****************************************************************************
// Functions to carry out the initialization of RW and BSS data sections. These
// are written as separate functions rather than being inlined within the
// ResetISR() function in order to cope with MCUs with multiple banks of
// memory.
//*****************************************************************************
__attribute__ ((section(".after_vectors.init_data")))
void data_init(unsigned int romstart, unsigned int start, unsigned int len) {
	unsigned int *pulDest = (unsigned int*) start;
	unsigned int *pulSrc = (unsigned int*) romstart;
	unsigned int loop;
	for (loop = 0; loop < len; loop = loop + 4)
		*pulDest++ = *pulSrc++;
}

__attribute__ ((section(".after_vectors.init_bss")))
void bss_init(unsigned int start, unsigned int len) {
	unsigned int *pulDest = (unsigned int*) start;
	unsigned int loop;
	for (loop = 0; loop < len; loop = loop + 4)
		*pulDest++ = 0;
}

//*****************************************************************************
// The following symbols are constructs generated by the linker, indicating
// the location of various points in the "Global Section Table". This table is
// created by the linker via the Code Red managed linker script mechanism. It
// contains the load address, execution address and length of each RW data
// section and the execution and length of each BSS (zero initialized) section.
//*****************************************************************************
extern unsigned int __data_section_table;
extern unsigned int __data_section_table_end;
extern unsigned int __bss_section_table;
extern unsigned int __bss_section_table_end;

//*****************************************************************************
// Reset entry point for your code.
// Sets up a simple runtime environment and initializes the C/C++
// library.
//*****************************************************************************
__attribute__ ((section(".after_vectors.reset")))
void ResetISR(void) {

    // Disable interrupts
    __asm volatile ("cpsid i");

#if defined (__USE_CMSIS)
// If __USE_CMSIS defined, then call CMSIS SystemInit code
    SystemInit();
#else
    // Disable Watchdog
    //  Write 0xC520 to watchdog unlock register
    *((volatile unsigned short *)0x4005200E) = 0xC520;
    //  Followed by 0xD928 to complete the unlock
    *((volatile unsigned short *)0x4005200E) = 0xD928;
    // Now disable watchdog via STCTRLH register
    *((volatile unsigned short *)0x40052000) = 0x01D2u;
#endif // (__USE_CMSIS)

    //
    // Copy the data sections from flash to SRAM.
    //
	unsigned int LoadAddr, ExeAddr, SectionLen;
	unsigned int *SectionTableAddr;

	// Load base address of Global Section Table
	SectionTableAddr = &__data_section_table;

    // Copy the data sections from flash to SRAM.
	while (SectionTableAddr < &__data_section_table_end) {
		LoadAddr = *SectionTableAddr++;
		ExeAddr = *SectionTableAddr++;
		SectionLen = *SectionTableAddr++;
		data_init(LoadAddr, ExeAddr, SectionLen);
	}

	// At this point, SectionTableAddr = &__bss_section_table;
	// Zero fill the bss segment
	while (SectionTableAddr < &__bss_section_table_end) {
		ExeAddr = *SectionTableAddr++;
		SectionLen = *SectionTableAddr++;
		bss_init(ExeAddr, SectionLen);
	}

#if !defined (__USE_CMSIS)
// Assume that if __USE_CMSIS defined, then CMSIS SystemInit code
// will setup the VTOR register

    // Check to see if we are running the code from a non-zero
    // address (eg RAM, external flash), in which case we need
    // to modify the VTOR register to tell the CPU that the
    // vector table is located at a non-0x0 address.
    unsigned int * pSCB_VTOR = (unsigned int *) 0xE000ED08;
    if ((unsigned int *)g_pfnVectors!=(unsigned int *) 0x00000000) {
        *pSCB_VTOR = (unsigned int)g_pfnVectors;
    }
#endif // (__USE_CMSIS)

#if defined (__cplusplus)
    //
    // Call C++ library initialisation
    //
    __libc_init_array();
#endif

    // Reenable interrupts
    __asm volatile ("cpsie i");

#if defined (__REDLIB__)
	// Call the Redlib library, which in turn calls main()
	__main();
#else
	main();
#endif

	//
	// main() shouldn't return, but if it does, we'll just enter an infinite loop
	//
	while (1) {
		;
	}
}

//*****************************************************************************
// Default core exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
WEAK_AV void NMI_Handler(void)
{ while(1) {}
}

WEAK_AV void HardFault_Handler(void)
{ while(1) {}
}

WEAK_AV void SVC_Handler(void)
{ while(1) {}
}

WEAK_AV void PendSV_Handler(void)
{ while(1) {}
}

WEAK_AV void SysTick_Handler(void)
{ while(1) {}
}

//*****************************************************************************
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//*****************************************************************************
WEAK_AV void IntDefaultHandler(void)
{ while(1) {}
}

//*****************************************************************************
// Default application exception handlers. Override the ones here by defining
// your own handler routines in your application code. These routines call
// driver exception handlers or IntDefaultHandler() if no driver exception
// handler is included.
//*****************************************************************************
WEAK_AV void DMA0_DMA4_IRQHandler(void)
{   DMA0_DMA4_DriverIRQHandler();
}

WEAK_AV void DMA1_DMA5_IRQHandler(void)
{   DMA1_DMA5_DriverIRQHandler();
}

WEAK_AV void DMA2_DMA6_IRQHandler(void)
{   DMA2_DMA6_DriverIRQHandler();
}

WEAK_AV void DMA3_DMA7_IRQHandler(void)
{   DMA3_DMA7_DriverIRQHandler();
}

WEAK_AV void DMA_Error_IRQHandler(void)
{   DMA_Error_DriverIRQHandler();
}

WEAK_AV void FTFA_IRQHandler(void)
{   FTFA_DriverIRQHandler();
}

WEAK_AV void LVD_LVW_IRQHandler(void)
{   LVD_LVW_DriverIRQHandler();
}

WEAK_AV void LLWU_IRQHandler(void)
{   LLWU_DriverIRQHandler();
}

WEAK_AV void I2C0_IRQHandler(void)
{   I2C0_DriverIRQHandler();
}

WEAK_AV void Reserved25_IRQHandler(void)
{   Reserved25_DriverIRQHandler();
}

WEAK_AV void SPI0_IRQHandler(void)
{   SPI0_DriverIRQHandler();
}

WEAK_AV void Reserved27_IRQHandler(void)
{   Reserved27_DriverIRQHandler();
}

WEAK_AV void UART0_IRQHandler(void)
{   UART0_DriverIRQHandler();
}

WEAK_AV void UART1_IRQHandler(void)
{   UART1_DriverIRQHandler();
}

WEAK_AV void CAN0_IRQHandler(void)
{   CAN0_DriverIRQHandler();
}

WEAK_AV void ADC0_IRQHandler(void)
{   ADC0_DriverIRQHandler();
}

WEAK_AV void ADC1_IRQHandler(void)
{   ADC1_DriverIRQHandler();
}

WEAK_AV void FTM0_IRQHandler(void)
{   FTM0_DriverIRQHandler();
}

WEAK_AV void FTM1_IRQHandler(void)
{   FTM1_DriverIRQHandler();
}

WEAK_AV void FTM2_IRQHandler(void)
{   FTM2_DriverIRQHandler();
}

WEAK_AV void CMP0_IRQHandler(void)
{   CMP0_DriverIRQHandler();
}

WEAK_AV void CMP1_IRQHandler(void)
{   CMP1_DriverIRQHandler();
}

WEAK_AV void FTM3_IRQHandler(void)
{   FTM3_DriverIRQHandler();
}

WEAK_AV void WDOG_EWM_IRQHandler(void)
{   WDOG_EWM_DriverIRQHandler();
}

WEAK_AV void FTM4_IRQHandler(void)
{   FTM4_DriverIRQHandler();
}

WEAK_AV void DAC0_IRQHandler(void)
{   DAC0_DriverIRQHandler();
}

WEAK_AV void FTM5_IRQHandler(void)
{   FTM5_DriverIRQHandler();
}

WEAK_AV void MCG_IRQHandler(void)
{   MCG_DriverIRQHandler();
}

WEAK_AV void LPTMR0_IRQHandler(void)
{   LPTMR0_DriverIRQHandler();
}

WEAK_AV void PDB0_PDB1_IRQHandler(void)
{   PDB0_PDB1_DriverIRQHandler();
}

WEAK_AV void PORTA_IRQHandler(void)
{   PORTA_DriverIRQHandler();
}

WEAK_AV void PORTB_PORTC_PORTD_PORTE_IRQHandler(void)
{   PORTB_PORTC_PORTD_PORTE_DriverIRQHandler();
}

//*****************************************************************************

#if defined (DEBUG)
#pragma GCC pop_options
#endif // (DEBUG)
