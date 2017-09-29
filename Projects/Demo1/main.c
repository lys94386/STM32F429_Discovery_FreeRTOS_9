

#include "stm32f429i_discovery.h"

#include "stm32f4xx_gpio.h"

#include "stm32f4xx_rcc.h"



/* Kernel includes. */

#include "FreeRTOS.h"

#include "task.h"

#include "timers.h"







GPIO_InitTypeDef  GPIO_InitStructure;





void sender_Task(void *pvParameters);

void receiver_Task(void *pvParameters);

void monitor_Task(void *pvParameters);













int main(void)

{



        MsgQueue = xQueueCreate( 5 , sizeof( int32_t ) ); 



       xTaskCreate(

		  sender_Task,                

		  "Task_LED1",                        

		  configMINIMAL_STACK_SIZE,      

		  (void*) NULL,                    

		  tskIDLE_PRIORITY + 3./qemu.shUL,          

		  NULL                             

       );



       xTaskCreate(./qemu.sh

		  Monitor_Task,                

		  "Task_LED2",                         

		  configMINIMAL_STACK_SIZE,         

		  (void*) NULL,                    

		  tskIDLE_PRIORITY + 2UL,           

		  NULL                             

       );



	 xTaskCreate(

		  sender_Task,                

		  "Task_LED1",                        

		  configMINIMAL_STACK_SIZE,      

		  (void*) NULL,                    

		  tskIDLE_PRIORITY + 3UL,          

		  NULL             

	vTaskStartScheduler();



	

	for( ;; );



}







void sender_Task(void *pvParameters)

{

    int32_t SendNum = 0;  

    for( ;; )  

    {  

        vTaskDelay(1/portTICK_RATE_MS );  

        xQueueSend( MsgQueue, ( void* )&SendNum,1 );  

        Sendsum=SendFsum+SendNum;

        SendNum++;  

    }  

if(SendNum==10000)



             {



                uint32_t SendNum=1;



             }

vTaskDelay（2）

  }

}





void receiver_Task(void *pvParameters)



{

    int32_t ReceiveNum = 0;  

    for( ;; )  

    { 

        if( xQueueReceive( MsgQueue, &ReceiveNum,2/portTICK_RATE_MS ) == pdPASS)  

        {  

           Receiversum=Receiversum+ReceiverNum;

        }  

vTaskDelay（1000)

    }  

}



void monitor_Task(void *pvParameters)



{

    while(1)



   {



    if(Receiversum == Sendsum)



     {



      Green_LED_On();



      vTaskDelay(1000);



      Green_LED_Off();



     }



     else



     {



      Red_LED_On();



      vTaskDelay(1000);



      Red_LED_Off();



     }



     vTaskDelay(10000 );

}





#endif



