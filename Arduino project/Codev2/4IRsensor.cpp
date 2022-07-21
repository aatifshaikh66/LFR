/*#####################################################################################################
'''_________________________________________________________________________________

***********************************************************************************
    File Name : 4IRsensor.cpp
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

  #define _IRSensorFrontLeftPin    _Lpin14
  #define _IRSensorFrontRight_Pin  _Lpin13

  #define _IRSensorBackLeftPin     _Lpin12
  #define _IRSensorBackRight_Pin   _Lpin11

/*###################################################################################################
#                                               Global variable                                     #
###################################################################################################*/
/*###################################################################################################
#                                               Function declairation                               #
###################################################################################################*/
/*****************************************************************************
 **@Function     :   FnWifiTCPServerInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void IRSensors :: FnIRSensorsInit ( void )
{
     /*initialize the pin of motor Control*/
     pinMode( _IRSensorFrontLeftPin   ,INPUT );
     pinMode( _IRSensorFrontRight_Pin ,INPUT );    

     pinMode( _IRSensorBackLeftPin    ,INPUT );
     pinMode( _IRSensorBackRight_Pin  ,INPUT );     
}


/*****************************************************************************
 **@Function     :   FnWifiTCPServerInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void IRSensors :: FnIRSensorsRead ( void )
{

     /*initialize the pin of motor Control*/
    VarIRStatus.ui8IRsensorFrontLeftStatus  = digitalRead ( _IRSensorFrontLeftPin   );
    VarIRStatus.ui8IRsensorFrontRightStatus = digitalRead ( _IRSensorFrontRight_Pin );    
    VarIRStatus.ui8IRsensorBackLeftStatus   = digitalRead ( _IRSensorBackLeftPin    );
    VarIRStatus.ui8IRsensorBackRightStatus  = digitalRead ( _IRSensorBackRight_Pin  );     
    
}
