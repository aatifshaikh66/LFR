/*#####################################################################################################
'''_________________________________________________________________________________

***********************************************************************************
    File Name : 0headers.h
***********************************************************************************
    File Type : header
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
#ifndef __Headers_H__
#define __Headers_H__

/*###################################################################################################
#                                               Include files                                      #
###################################################################################################*/

    /*standard includes*/
    #include "stdio.h"  //standard input/ output files
    #include "stdlib.h" //standard libraary functions 
    #include "stdint.h" //standard integer data type definition
    #include "string.h" //standard string functions
    #include "errno.h"  //standard error numbers  
    #include "math.h"   //standard math library

    /*hardware intrerface includes*/
    //make sure whichever Arduino family members you are using has a wifi interface
    #include <WiFi.h>        //wifi standard library     
    #include <WiFiClient.h>  //wifi client library
    #include <WiFiAP.h>      //wifi host/ AP library

    /*additional includes*/  
    #include "DHT.h"     //Standard library for DHT22 (temperature and humidity sensor) 
    #include "HX711.h"   //Standard library for HX711 (weight sensor)




/*###################################################################################################
#                                               Hash definitions                                   #
###################################################################################################*/

#define set   (uint8_t)1
#define reset (uint8_t)0

/*pin configuration*/
#define UNUSED_PIN (uint8_t)50 

/*system used pins*/
#define VCC5      UNUSED_PIN
#define VCC3_3    UNUSED_PIN
#define GND       UNUSED_PIN
#define EN        UNUSED_PIN

/*all gpio numbers of controller*/
#define GPIO01   (uint8_t)01
#define GPIO02   (uint8_t)02
#define GPIO03   (uint8_t)03
#define GPIO04   (uint8_t)04
#define GPIO05   (uint8_t)05
#define GPIO16   (uint8_t)16
#define GPIO13   (uint8_t)13
#define GPIO12   (uint8_t)12
#define GPIO14   (uint8_t)14
#define GPIO15   (uint8_t)15
#define GPIO16   (uint8_t)16
#define GPIO17   (uint8_t)17
#define GPIO18   (uint8_t)18
#define GPIO19   (uint8_t)19
#define GPIO21   (uint8_t)21
#define GPIO22   (uint8_t)22
#define GPIO23   (uint8_t)23
#define GPIO27   (uint8_t)27
#define GPIO26   (uint8_t)26
#define GPIO25   (uint8_t)25
#define GPIO33   (uint8_t)33
#define GPIO32   (uint8_t)32
#define GPIO35   (uint8_t)35
#define GPIO34   (uint8_t)34
#define GPIO39   (uint8_t)39
#define GPIO36   (uint8_t)36


/*left side of the board (by keeping USB port towards you)*/
#define _Lpin0  VCC5 
#define _Lpin1  GND 
#define _Lpin2  GPIO13 
#define _Lpin3  GPIO12 
#define _Lpin4  GPIO14 
#define _Lpin5  GPIO27 
#define _Lpin6  GPIO26 
#define _Lpin7  GPIO25 
#define _Lpin8  GPIO33 
#define _Lpin9  GPIO32 
#define _Lpin10 GPIO35 
#define _Lpin11 GPIO34 
#define _Lpin12 GPIO39 
#define _Lpin13 GPIO36 
#define _Lpin14 EN 


/*right side of the board (by keeping USB port towards you)*/
#define _Rpin0  VCC3_3 
#define _Rpin1  GND 
#define _Rpin2  GPIO15 
#define _Rpin3  GPIO02 
#define _Rpin4  GPIO04 
#define _Rpin5  GPIO16 
#define _Rpin6  GPIO17 
#define _Rpin7  GPIO05 
#define _Rpin8  GPIO18 
#define _Rpin9  GPIO19 
#define _Rpin10 GPIO21 
#define _Rpin11 GPIO03 
#define _Rpin12 GPIO01 
#define _Rpin13 GPIO22 
#define _Rpin14 GPIO23 


/*digital out pin*/
#define _DACChannel1  _Lpin7
#define _DACChannel2  _Lpin6 

/*digital in pin*/
#define _ADC1Channel0  _Lpin13
#define _ADC1Channel3  _Lpin12
#define _ADC1Channel6  _Lpin11
#define _ADC1Channel6  _Lpin10
    
#define _DebuggEnable   true



/*###################################################################################################
#                                               strui8ture definition                                #
###################################################################################################*/


  /* temperature structure*/
  typedef struct
  { 
       
    /*instant temperataure*/
    float FlTemperature ;
    float FlHumidity ;           

    /*aray to store the data of last 10 reading*/
    float FlArrayTempearture[(uint8_t)10];
    float FlArrayHumidity[(uint8_t)10];

    /*average of last 10 readings*/
    float FlAverageTemperature;
    float FlAverageHumidity;

    /*counter to keep the track of reading count*/
    uint8_t ui8TempHumidCount;

    /*temporary veriable for processing*/
    float FlTemporaryVariable;
      
  }stTempHumid;


  /*IR Sensor structure*/
  typedef struct
  {

    /**Store the status of the IR sensors**/  
    uint8_t ui8IRsensorFrontLeftStatus ;
    uint8_t ui8IRsensorFrontRightStatus;   
     
    uint8_t ui8IRsensorBackLeftStatus ;
    uint8_t ui8IRsensorBackRightStatus;        
    
  }IRStatus;  




/*###################################################################################################
#                                               class definition                                    #
###################################################################################################*/



/*********************** Motor Control ***********************/ 
class L289MotorController
{

  /*to store the motor Speed */
  uint8_t ui8MotorControllerSpeed ;
 
  /***********************/
  public:
  
  /*function declairation*/
   void FnMotorControllerInit  ( void );
   void FnMotorControllerSpeed ( uint8_t ui8SelectMotor, uint8_t ui8Speed );
   void FnMotorControllerStop  ( void );
   void FnMotorControllerStart ( void );

   void FnMotorControllerTurnLeft     ( void );
   void FnMotorControllerTurnRight    ( void );
   void FnMotorControllerMoveforward  ( void );
   void FnMotorControllerMoveBackward ( void );


};


/*********************** IR Sensor Reading ***********************/ 
class IRSensors
{
  
  /***********************/
  public:
  IRStatus VarIRStatus;

  /*function declairation*/
  void FnIRSensorsInit( void );
  void FnIRSensorsRead( void );
  
};




/*********************** tempereature ***********************/ 
class DHT22TempHumid
{

  /***********************/
  public:

  /*structure variable*/ 
   stTempHumid  VarTempHumid;
  
  /*function declairation*/
   void FnTempHumidInit(void);
   void FnTempHumidRead(void);
  
};


/*********************** weight ***********************/ 
class HX711Weight
{

  /***********************/
  public:

  float flWeightInLbs ;
  float flWeightInKG  ;

  /*function declairation*/
  void FnWeightInit(void);  
  void FnWeightRead(void);  
  
};


/*********************** WIFI ***********************/ 
class WIFIServer
{
  
  uint8_t ui8TCPCleintStatus;
  char si8TCPReceiveBuffer[(uint8_t)50];
  char si8TCPTransmitBuffer[(uint8_t)50];  
  uint8_t ui8TCPReceiveCNT; 
  uint8_t ui8TCPTransmitFlag;   


  /***********************/
  public:
  
  /*function declairation*/
  void FnWifiNetworkInit   ( void );
  void FnWifiTCPServerInit ( void );
  void FnWifiTCPServerListen( void );
  void FnWifiTCPMessageProcess(char *ucString);

  
};


/*********************** FreeRtos ***********************/ 
class FreeRtosTx
{
  
  /***********************/
  public:

  /*function declairation*/
  void FnFreeRtosInit  ( void );
  
};

/*###################################################################################################
#                                               extern variable                                     #
###################################################################################################*/

  /*class variable*/
  extern DHT22TempHumid  ObjTempHumid;
  extern HX711Weight     ObjWeight;
  extern WIFIServer      ObjWifi;
  extern FreeRtosTx      OjbRtos;
  extern L289MotorController ObjMotor; 

#endif /*__Headers_H__*/
