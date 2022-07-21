/*#####################################################################################################
'''_________________________________________________________________________________

***********************************************************************************
    File Name : 2FreeRTOS.cpp
***********************************************************************************
    File Type : C++
***********************************************************************************    
    Last Edit : 01/02/22
***********************************************************************************    
    Version   : Version -> V0.0.0    
***********************************************************************************
    Edited By : Aatif Shaikh 
***********************************************************************************
    Author    : Aatif Shaikh (v16he9m2@gmail.com)    
***********************************************************************************
    About file: This file is basically a template file, which discribe the
                basic rules that needs to be followed during the coding.
                By following these rules it will help you to understand
                and manage your code in a better way.
***********************************************************************************                 
    Licency   :
                No-Copyright (c):
                No copyrights are being imposed on these software files.
                Information shall have to be freely available for the rapid
                development of science to benefit humanity. When the information
                is free, this is not a barrier to their progress. Therefore, I,
                Aatif Shaikh, license you the right to use, modify, copy and
                distribute this software however you desire.

                Note*
                Software and documentation are provided "as is" without warranty
                of any kind, either express or implied, including without
                limitation, any warranty of merchantability, title, non-infringement
                and fitness for a particular purpose. In no event shall, I
                (Aatif Shaikh) liable or obligated under contract, negligence,strict
                liability, contribution, breach of warranty, or other legal equitable
                theory any direct or indirect damages or expenses including but not
                limited to any incidental, special, indirect, punitive or
                consequential damages, lost profits or lost data, cost of procurement
                of substitute goods, technology, services, or any claims by third
                parties (including but not limited to any defence thereof), or
                other similar costs.                 
   _________________________________________________________________________'''

#####################################################################################################*/


/*###################################################################################################
#                                               Include files                                      #
###################################################################################################*/

  #include "0headers.h"

/*###################################################################################################
#                                               Hash definitions                                   #
###################################################################################################*/

  #if CONFIG_FREERTOS_UNICORE
  #define ARDUINO_RUNNING_CORE 0
  #else
  #define ARDUINO_RUNNING_CORE 1
  #endif

/*###################################################################################################
#                                               Function Decaliration                               #
###################################################################################################*/

    void FnThreadFunction1 (void* vArgument);
    void FnThreadFunction2 (void* vArgument);    

/*###################################################################################################
#                                               Global variable                                     #
###################################################################################################*/
/*****************************************************************************
 **@Function     :   FnWifiTCPServerInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void FreeRtosTx :: FnFreeRtosInit (void)
{

 /*Initialize a thread to read temperature, humidity and weight */  
  xTaskCreatePinnedToCore(
  FnThreadFunction1
  ,  "Reading Operation"
  ,  1024  // Stack size
  ,  NULL
  ,  1     // Priority
  ,  NULL 
  ,  ARDUINO_RUNNING_CORE);


 /*Initialize a thread to listen the TCP communication */ 
 /*
  xTaskCreatePinnedToCore(
  FnThreadFunction2
  ,  "TCPServer"
  ,  1024  // Stack size
  ,  NULL
  ,  1     // Priority
  ,  NULL 
  ,  ARDUINO_RUNNING_CORE);
  */

}

/*****************************************************************************
 **@Function     :   FnThreadFunction1
 **@Descriptions :   
 **@parameters   :   void* vArgument
 **@return       :   none
*****************************************************************************/
void FnThreadFunction1 (void* vArgument)
{
  
  uint8_t ui8TempVar = reset ;
  while ( true )
  {
    
    /*****************************/
    ObjTempHumid.FnTempHumidRead();
  
    /*****************************/  
    ObjWeight.FnWeightRead( );

    /*****************************/
  //  if (ui8TempVar == reset)
  //       { digitalWrite(LED_BUILTIN, HIGH); ui8TempVar = set  ; }
  //  else { digitalWrite(LED_BUILTIN, LOW) ; ui8TempVar = reset; }  

    /*****************************/
    sleep(1);  
  }
  
}


/*****************************************************************************
 **@Function     :   FnThreadFunction2
 **@Descriptions :   
 **@parameters   :   void* vArgument
 **@return       :   none
*****************************************************************************/
void FnThreadFunction2 (void* vArgument)
{
  
  while(true)
  {
   /*call the Tcp listner*/
   ObjWifi.FnWifiTCPServerListen( );    
  } 

}
