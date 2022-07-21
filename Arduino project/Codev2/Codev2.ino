/*#####################################################################################################
'''_________________________________________________________________________________

***********************************************************************************
    File Name : code.ino
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

/*###################################################################################################
#                                               Global variable                                     #
###################################################################################################*/


  /*class variable*/
  L289MotorController ObjMotor; 
  DHT22TempHumid      ObjTempHumid;
  HX711Weight         ObjWeight;
  WIFIServer          ObjWifi;
  FreeRtosTx          OjbRtos;


/*###################################################################################################
#                                               initialization                                      #
###################################################################################################*/
void setup( ) 
{ 
    
  /*init the serial port to print the debug messages*/
  Serial.begin(115200);
  #if (_DebuggEnable == true) 
      Serial.print("Serial Terminal Init\n\r");
  #endif


  /*init the motor controller*/
  ObjMotor.FnMotorControllerInit( );
  
  /*init the temperature and humidity sensor*/
  ObjTempHumid.FnTempHumidInit( );

  /*init the weight sensor*/
  ObjWeight.FnWeightInit( );

  /*init the wifi network*/
  ObjWifi.FnWifiNetworkInit( );

  /*init the TCP Server*/  
  ObjWifi.FnWifiTCPServerInit( );

  /*init the Thread*/  
  OjbRtos.FnFreeRtosInit( );

  /*initialize digital pin LED_BUILTIN as an output*/
  //pinMode(LED_BUILTIN, OUTPUT);
  
}


/*###################################################################################################
#                                               start of the code                                   #
###################################################################################################*/
void loop( ) 
{
   /*call the Tcp listner*/
   ObjWifi.FnWifiTCPServerListen( );    
}
