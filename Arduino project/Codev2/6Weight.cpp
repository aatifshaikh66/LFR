/*#####################################################################################################
'''_________________________________________________________________________________

***********************************************************************************
    File Name : 6Weight.cpp
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

  #define _HX711SensorCLKPin    12
  #define _HX711SensorDOUTPin   13
  
/*###################################################################################################
#                                               Global variable                                     #
###################################################################################################*/

 /********************/
 HX711 HX711Object;
 float HX711CakibrationFactor = -187000;

/*###################################################################################################
#                                               function definition                                 #
###################################################################################################*/
/*****************************************************************************
 **@Function     :   FnWeightInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void HX711Weight :: FnWeightInit(void)
{
  
  /*reset all variable to zero*/
   flWeightInLbs  = reset ;
   flWeightInKG   = reset ;

  /*initialize the driver*/
  HX711Object.begin(_HX711SensorDOUTPin, _HX711SensorCLKPin);
  HX711Object.set_scale(HX711CakibrationFactor);
  HX711Object.tare( );
  long HX711ZeroFactor = HX711Object.read_average(); //Get a baseline reading
  #if (_DebuggEnable == true)       
      Serial.print("Weight Sensor HX711 Init\n\r");      
      Serial.print("Weight Sensor ZERO Factor= ");          
      Serial.print(HX711ZeroFactor);  
      Serial.println("");
  #endif
  
}


/*****************************************************************************
 **@Function     :   FnWeightRead
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void HX711Weight :: FnWeightRead(void)
{

  /*read the weight in lbs*/
  flWeightInLbs = HX711Object.get_units() ;
  /*read the weight in kg*/
  flWeightInKG  = HX711Object.get_units() * 0.453592 ;

}
