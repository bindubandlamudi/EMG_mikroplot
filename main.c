/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65
        Device            :  PIC16F1619
        Driver Version    :  2.00
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include <stdio.h>

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    //ADC_SelectChannel(POT1_AN4);
    ADC_SelectChannel(EMG_AN6);
    double time_elapsed = 0.0;
    int start_flag = 0;
    int fivesec = 0;
    
    while (1)
    {
        // Following is just to get ADC values for EMG
        if (Switch_RC4_GetValue() == 0 && start_flag == 0)
        {
            printf("START\r\n");
            start_flag = 1;
            __delay_ms(1000);
        } else if (Switch_RC4_GetValue() ==0 && start_flag == 1)
        {
            printf("STOP\r\n");
            start_flag = 0;
            __delay_ms(1000);
        }

        if (start_flag == 1)
        {
            fivesec += 1;
            if(fivesec == 250)
            {
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");
              printf("******************************************************************************\n");

              fivesec = 0;
            }
            ADC_StartConversion();
            adc_result_t adval = ADC_GetConversionResult();
            printf("%u\r\n", adval/100);
            __delay_ms(20);
        }
  
        /* Mikro Plot
        // Uncomment this whole block when using MikroPlot on PC
        if (Switch_RC4_GetValue() == 0 && start_flag == 0)
        {
            printf("START\r\n");
            start_flag = 1;
            __delay_ms(1000);
        }

        if (start_flag == 1)
        {
            ADC_StartConversion();
            adc_result_t adval = ADC_GetConversionResult();
            printf("%u,%f\r\n", adval/100, time_elapsed);
            __delay_ms(20);
            time_elapsed += 5.0;
        }
        */
}
    
}
/**

 End of File
*/