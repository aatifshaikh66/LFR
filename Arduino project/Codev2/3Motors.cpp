/*#####################################################################################################
'''_________________________________________________________________________________

***********************************************************************************
    File Name : 3Motos.cpp
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


    #define _MotorBackLeft1Pin     _Rpin14
    #define _MotorBackLeft2Pin     _Rpin13    

    #define _MotorBackRight1Pin    _Rpin10
    #define _MotorBackRight2Pin    _Rpin9     

    #define _MotorFrontLeft1Pin    _Rpin8
    #define _MotorFrontLeft2Pin    _Rpin7    

    #define _MotorFrontRight1Pin   _Rpin4
    #define _MotorFrontRight2Pin   _Rpin3 

    #define _MotorBackSpeedPin     _Rpin2
    #define _MotorFrontSpeedPin    _Lpin3


    #define _MotorSelectBack      (uint8_t)1
    #define _MotorSelectFront     (uint8_t)2         
    #define _MotorDeafultSeed     (uint8_t)30
    #define _MotorTurnSeed        (uint8_t)20


    #define _MotorPWMChannel1     (uint8_t)0
    #define _MotorPWMChannel2     (uint8_t)1

    #define _MotorPWMFrequnecy    (uint16_t)3000
    #define _MotorPWMResolution   (uint8_t)8
    

/*###################################################################################################
#                                               Function declairation                               #
###################################################################################################*/
/*****************************************************************************
 **@Function     :   FnWifiTCPServerInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void L289MotorController :: FnMotorControllerInit ( void )
{

     /*initialize the pin of motor Control*/
     pinMode( _MotorBackLeft1Pin   ,OUTPUT );
     pinMode( _MotorBackLeft2Pin   ,OUTPUT );    

     pinMode( _MotorBackRight1Pin  ,OUTPUT );
     pinMode( _MotorBackRight2Pin  ,OUTPUT );     

     pinMode( _MotorFrontLeft1Pin  ,OUTPUT );
     pinMode( _MotorFrontLeft2Pin  ,OUTPUT );    


     pinMode( _MotorFrontRight1Pin ,OUTPUT );
     pinMode( _MotorFrontRight2Pin ,OUTPUT ); 

     pinMode(_MotorBackSpeedPin    , OUTPUT);
     pinMode(_MotorFrontSpeedPin   , OUTPUT);

     
     /*configure LED PWM functionalitites*/
     ledcSetup(_MotorPWMChannel1, _MotorPWMFrequnecy, _MotorPWMResolution);
     /* attach the channel to the GPIO to be controlled */
     ledcAttachPin(_MotorBackSpeedPin, _MotorPWMChannel1);

  
     /*configure LED PWM functionalitites*/
     ledcSetup(_MotorPWMChannel2, _MotorPWMFrequnecy, _MotorPWMResolution);
     /* attach the channel to the GPIO to be controlled */
     ledcAttachPin(_MotorFrontSpeedPin, _MotorPWMChannel2);      
     
    /*init the default speed*/
     ui8MotorControllerSpeed = _MotorDeafultSeed;     

}


/*****************************************************************************
 **@Function     :   FnMotorControllerSpeed
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void L289MotorController :: FnMotorControllerSpeed (uint8_t ui8SelectMotor, uint8_t ui8Speed )
{
      
  /*convert the 0 to 100% speed into */
  ui8MotorControllerSpeed = (ui8Speed /(uint8_t)100) * (uint16_t)255 ;

  /*set the DAC value*/    
     if ( ui8SelectMotor == _MotorSelectBack )
          ledcWrite(_MotorPWMChannel1, ui8MotorControllerSpeed);           
    else  ledcWrite(_MotorPWMChannel2, ui8MotorControllerSpeed);     
    
}



/*****************************************************************************
 **@Function     :   FnMotorControllerStop
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void L289MotorController :: FnMotorControllerStop ( void )
{

  /*stop the car by setting the speed 0*/
  FnMotorControllerSpeed(_MotorSelectBack ,reset);
  FnMotorControllerSpeed(_MotorSelectFront,reset);

   digitalWrite( _MotorBackLeft1Pin   ,LOW  );
   digitalWrite( _MotorBackLeft2Pin   ,LOW  );    

   digitalWrite( _MotorBackRight1Pin  ,LOW  );
   digitalWrite( _MotorBackRight2Pin  ,LOW  );     

   digitalWrite( _MotorFrontLeft1Pin  ,LOW  );
   digitalWrite( _MotorFrontLeft2Pin  ,LOW  );    

   digitalWrite( _MotorFrontRight1Pin ,LOW  );
   digitalWrite( _MotorFrontRight2Pin ,LOW  ); 

}




/*****************************************************************************
 **@Function     :   FnMotorControllerStop
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void L289MotorController :: FnMotorControllerStart ( void )
{

  /*stop the car by setting the speed 0*/
  FnMotorControllerSpeed(_MotorSelectBack ,ui8MotorControllerSpeed);
  FnMotorControllerSpeed(_MotorSelectFront,ui8MotorControllerSpeed);


}


/*****************************************************************************
 **@Function     :   FnMotorControllerStop
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void L289MotorController :: FnMotorControllerTurnLeft ( void )
{

  FnMotorControllerStop();
  sleep(1);
    
  /*reduce the speed before taking the turn*/
  FnMotorControllerSpeed(_MotorSelectBack , _MotorTurnSeed);
  FnMotorControllerSpeed(_MotorSelectFront, _MotorTurnSeed);


   /*set the direction of pin for motor Control*/
   digitalWrite( _MotorBackLeft1Pin   ,HIGH );
   digitalWrite( _MotorBackLeft2Pin   ,LOW  );    

   digitalWrite( _MotorBackRight1Pin  ,HIGH );
   digitalWrite( _MotorBackRight2Pin  ,LOW  );     

   digitalWrite( _MotorFrontLeft1Pin  ,HIGH );
   digitalWrite( _MotorFrontLeft2Pin  ,LOW  );    

   digitalWrite( _MotorFrontRight1Pin ,HIGH );
   digitalWrite( _MotorFrontRight2Pin ,LOW  ); 
  
}


/*****************************************************************************
 **@Function     :   FnMotorControllerStop
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void L289MotorController :: FnMotorControllerTurnRight ( void )
{

    FnMotorControllerStop();
    sleep(1);

   /*reduce the speed before taking the turn*/
    FnMotorControllerSpeed( _MotorSelectBack , _MotorTurnSeed);
    FnMotorControllerSpeed( _MotorSelectFront, _MotorTurnSeed);


   /*set the direction of pin for motor Control*/
   digitalWrite( _MotorBackLeft1Pin   ,LOW  );
   digitalWrite( _MotorBackLeft2Pin   ,HIGH );    

   digitalWrite( _MotorBackRight1Pin  ,LOW  );
   digitalWrite( _MotorBackRight2Pin  ,HIGH );     

   digitalWrite( _MotorFrontLeft1Pin  ,LOW  );
   digitalWrite( _MotorFrontLeft2Pin  ,HIGH );    

   digitalWrite( _MotorFrontRight1Pin ,LOW  );
   digitalWrite( _MotorFrontRight2Pin ,HIGH ); 
  
}

/*****************************************************************************
 **@Function     :   FnMotorControllerStop
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void L289MotorController :: FnMotorControllerMoveforward ( void )
{
  FnMotorControllerStop();
  sleep(1);
  
   /*set the speed to normal*/
  FnMotorControllerSpeed(_MotorSelectBack ,ui8MotorControllerSpeed);
  FnMotorControllerSpeed(_MotorSelectFront,ui8MotorControllerSpeed);

   /*set the direction of pin for motor Control*/
   digitalWrite( _MotorBackLeft1Pin   ,LOW  );
   digitalWrite( _MotorBackLeft2Pin   ,HIGH );    

   digitalWrite( _MotorBackRight1Pin  ,HIGH );
   digitalWrite( _MotorBackRight2Pin  ,LOW  );     

   digitalWrite( _MotorFrontLeft1Pin  ,LOW  );
   digitalWrite( _MotorFrontLeft2Pin  ,HIGH );    

   digitalWrite( _MotorFrontRight1Pin ,HIGH );
   digitalWrite( _MotorFrontRight2Pin ,LOW  ); 
    
}



/*****************************************************************************
 **@Function     :   FnMotorControllerStop
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void L289MotorController :: FnMotorControllerMoveBackward ( void )
{
  FnMotorControllerStop();
  sleep(1);

   /*set the speed to normal*/
  FnMotorControllerSpeed(_MotorSelectBack ,ui8MotorControllerSpeed);
  FnMotorControllerSpeed(_MotorSelectFront,ui8MotorControllerSpeed);

  
   /*set the direction of pin for motor Control*/
   digitalWrite( _MotorBackLeft1Pin   ,HIGH );
   digitalWrite( _MotorBackLeft2Pin   ,LOW  );    

   digitalWrite( _MotorBackRight1Pin  ,LOW  );
   digitalWrite( _MotorBackRight2Pin  ,HIGH );     

   digitalWrite( _MotorFrontLeft1Pin  ,HIGH );
   digitalWrite( _MotorFrontLeft2Pin  ,LOW  );    

   digitalWrite( _MotorFrontRight1Pin ,LOW  );
   digitalWrite( _MotorFrontRight2Pin ,HIGH ); 
   
}
