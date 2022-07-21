/*#####################################################################################################
'''_________________________________________________________________________________

***********************************************************************************
    File Name : 5TempNHumid.cpp
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

  #define _DHT22SensorPin    _Lpin4
  #define _DHTType           DHT22

  
/*###################################################################################################
#                                               Global variable                                     #
###################################################################################################*/

/* Initialize DHT sensor */
DHT DHTObject(_DHT22SensorPin, _DHTType);    

/*###################################################################################################
#                                               function definition                                 #
###################################################################################################*/
/*****************************************************************************
 **@Function     :   FnTempHumidInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void DHT22TempHumid :: FnTempHumidInit (void)
{

  /*reset all variable to zero*/
  VarTempHumid.FlTemperature        = reset;
  VarTempHumid.FlHumidity           = reset;
  VarTempHumid.FlAverageTemperature = reset;
  VarTempHumid.FlAverageHumidity    = reset;

  /*reset array to default*/
  memset( VarTempHumid.FlArrayTempearture,reset,sizeof(VarTempHumid.FlArrayTempearture));
  memset( VarTempHumid.FlArrayHumidity   ,reset,sizeof(VarTempHumid.FlArrayHumidity   ));  

  /*reset the counter to zero*/
  VarTempHumid.ui8TempHumidCount    = reset;

  /*initialize the driver*/
  DHTObject.begin( );  


  #if (_DebuggEnable == true) 
      Serial.print("Temperature Sensor DHT22 Init\n\r");
  #endif


}


/*****************************************************************************
 **@Function     :   FnTempHumidRead
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void DHT22TempHumid :: FnTempHumidRead ( void )
{

  /*store the instant temperature and humiidty in a float variable*/
  VarTempHumid.FlTemperature = DHTObject.readHumidity   ( );
  VarTempHumid.FlHumidity    = DHTObject.readTemperature( );

  /*store the instant temperature and humiidty in an array*/
  VarTempHumid.FlArrayTempearture[VarTempHumid.ui8TempHumidCount] = VarTempHumid.FlTemperature ;
  VarTempHumid.FlArrayHumidity   [VarTempHumid.ui8TempHumidCount] = VarTempHumid.FlHumidity    ;

  /*increment the store counter*/
  VarTempHumid.ui8TempHumidCount++;  

  /*check if the temperature counter reached 10*/
  if( VarTempHumid.ui8TempHumidCount == (uint8_t)10 )
      VarTempHumid.ui8TempHumidCount = reset ;

  /*reset a temporary variable*/
  VarTempHumid.FlTemporaryVariable = reset ;
  for (uint8_t ui8Loop = reset ; ui8Loop < (uint8_t)10 ; ui8Loop++ )
      VarTempHumid.FlTemporaryVariable = VarTempHumid.FlTemporaryVariable + VarTempHumid.FlArrayTempearture[ui8Loop];
  /*store the average value in a variable*/    
  VarTempHumid.FlAverageTemperature = VarTempHumid.FlTemporaryVariable / (uint8_t)10 ;      

  /*reset a temporary variable*/
  VarTempHumid.FlTemporaryVariable = reset ;
  for (uint8_t ui8Loop = reset ; ui8Loop < (uint8_t)10 ; ui8Loop++ )
      VarTempHumid.FlTemporaryVariable = VarTempHumid.FlTemporaryVariable + VarTempHumid.FlArrayHumidity[ui8Loop];
  /*store the average value in a variable*/    
  VarTempHumid.FlAverageHumidity = VarTempHumid.FlTemporaryVariable / (uint8_t)10 ;      


}
