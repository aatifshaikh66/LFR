/*#####################################################################################################
'''_________________________________________________________________________________

***********************************************************************************
    File Name : 1WifiNTcp.cpp
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

    /*TCP server or Self IP address*/
    #define _SERVER_IP_ADDRESS1   (uint8_t)192
    #define _SERVER_IP_ADDRESS2   (uint8_t)168
    #define _SERVER_IP_ADDRESS3   (uint8_t)1
    #define _SERVER_IP_ADDRESS4   (uint8_t)1

    /*Gateway Address*/  
    #define _GATEWAY_IP_ADDRESS1   (uint8_t)192
    #define _GATEWAY_IP_ADDRESS2   (uint8_t)168
    #define _GATEWAY_IP_ADDRESS3   (uint8_t)1
    #define _GATEWAY_IP_ADDRESS4   (uint8_t)1
                  
    /*Subnet Mask*/  
    #define _SUBNET_MASK1   (uint8_t)255
    #define _SUBNET_MASK2   (uint8_t)255
    #define _SUBNET_MASK3   (uint8_t)0
    #define _SUBNET_MASK4   (uint8_t)0

    /*Subnet Mask*/  
    #define _PRIME_DNS_ADDRESS1   (uint8_t)8
    #define _PRIME_DNS_ADDRESS2   (uint8_t)8
    #define _PRIME_DNS_ADDRESS3   (uint8_t)8
    #define _PRIME_DNS_ADDRESS4   (uint8_t)8

    /*Subnet Mask*/  
    #define _SECOND_DNS_ADDRESS1   (uint8_t)8
    #define _SECOND_DNS_ADDRESS2   (uint8_t)8
    #define _SECOND_DNS_ADDRESS3   (uint8_t)4
    #define _SECOND_DNS_ADDRESS4   (uint8_t)4

    #define _MotorSelectBack      (uint8_t)1
    #define _MotorSelectFront     (uint8_t)2    

    #define _TCP_SERVER_PORT_NO    (uint16_t)2222



/*###################################################################################################
#                                               Global variable                                     #
###################################################################################################*/


  /*set the wifi SSID and Password*/
  const char* wifiSSID     = "ESP32_ROBOT";
  const char* wifiPassword = "ESP1234567890";


  /*et your Static IP address*/
  IPAddress ObjlocalIP     (_SERVER_IP_ADDRESS1,_SERVER_IP_ADDRESS2,_SERVER_IP_ADDRESS3,_SERVER_IP_ADDRESS4);
  /*Set your Gateway IP address*/
  IPAddress ObjLocalGateway(_GATEWAY_IP_ADDRESS1, _GATEWAY_IP_ADDRESS2,_GATEWAY_IP_ADDRESS3, _GATEWAY_IP_ADDRESS4);
  /*Set the subnet mask*/
  IPAddress ObjLocalSubnet (_SUBNET_MASK1, _SUBNET_MASK2, _SUBNET_MASK3, _SUBNET_MASK4);
  /*Set the Primary DNS*/
  IPAddress ObjLocalPrimaryDNS  (_PRIME_DNS_ADDRESS1,_PRIME_DNS_ADDRESS2,_PRIME_DNS_ADDRESS3,_PRIME_DNS_ADDRESS4);     
  /*Set the Secondary DNS*/ 
  IPAddress ObjLocalSecondaryDNS(_SECOND_DNS_ADDRESS1, _SECOND_DNS_ADDRESS2, _SECOND_DNS_ADDRESS3, _SECOND_DNS_ADDRESS4); 

  /*set the port number*/
  WiFiServer ObjTCPServer(_TCP_SERVER_PORT_NO);

  /*WIFI Server */
  WiFiClient ObjTCPClient = NULL ;
  


/*###################################################################################################
#                                               Function Definition                                 #
###################################################################################################*/
/*****************************************************************************
 **@Function     :   FnTempHumidInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void WIFIServer :: FnWifiNetworkInit( void )
{ 
  
  /*Configures static parameters*/
  if (! WiFi.softAPConfig(ObjlocalIP, 
        ObjLocalGateway,
        ObjLocalSubnet /*,
        ObjLocalPrimaryDNS,
        ObjLocalSecondaryDNS */) ) 
      {
        #if (_DebuggEnable == true) 
            Serial.print("WIFI Static Config Failed!\n\r");
        #endif
      }
 else
      {
        #if (_DebuggEnable == true) 
            Serial.print("WIFI Static Config Success!\n\r");
        #endif
      }    


   #if (_DebuggEnable == true) 
        Serial.print("WIFI Network Starting!\n\r");
   #endif
   
   /*start the wifi*/  
   WiFi.softAP(wifiSSID, wifiPassword);   
   IPAddress myIP = WiFi.softAPIP( );
   Serial.print("Server IP address: ");
   Serial.println(myIP);
       
}


/*****************************************************************************
 **@Function     :   FnWifiTCPServerInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void WIFIServer :: FnWifiTCPServerInit(void)
{ 
  /*start the TCP server*/
  ObjTCPServer.begin( );

  /*Close all the connections*/
  ObjTCPClient.stop( );

  /*reset the tcp connection status*/
  ui8TCPCleintStatus = reset ;

  /*reset all receive and transmit buffer*/
  ui8TCPReceiveCNT = reset ;
  memset(si8TCPTransmitBuffer,reset,
  sizeof(si8TCPTransmitBuffer));
  memset(si8TCPReceiveBuffer ,reset,
  sizeof(si8TCPReceiveBuffer));            


   #if (_DebuggEnable == true) 
        Serial.print("TCP Server Start!\n\r");
   #endif

}


/*****************************************************************************
 **@Function     :   FnWifiTCPServerInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void WIFIServer :: FnWifiTCPServerListen( void )
{

  while (true)
  {
    /*if there is no connection connected. accept a new connection*/
      if( ui8TCPCleintStatus == reset
      && !ObjTCPClient.connected( )  )       
          ObjTCPClient = ObjTCPServer.available( );

    /*if new connection is accepted*/        
     if(ObjTCPClient)
       {
          /*change the status after getting a new connection*/
          if ( ui8TCPCleintStatus != set )
             { ui8TCPCleintStatus  = set;
               ObjTCPClient.write("You are connected to ESP32 Server now!\n");
               #if (_DebuggEnable == true) 
                    Serial.print("TCP New client connected!\n\r");
               #endif         
             }
             
        /*store data received from the client*/
         if ( ObjTCPClient.available( ) ) 
            {
              char c = ObjTCPClient.read( );
              #if (_DebuggEnable == true)              
                //   Serial.write(c);    
              #endif
              si8TCPReceiveBuffer[ui8TCPReceiveCNT++] = c ;
                
              if (c == (char)'\n')
              {
                FnWifiTCPMessageProcess(si8TCPReceiveBuffer);                               
                memset(si8TCPReceiveBuffer,reset,
                sizeof(si8TCPReceiveBuffer));                
                ui8TCPReceiveCNT = reset ;
              }

              /*if we received more than required */
              if ( ui8TCPReceiveCNT >= (uint8_t)50 )
              {                 
                memset(si8TCPReceiveBuffer,reset,
                sizeof(si8TCPReceiveBuffer));                
                ui8TCPReceiveCNT = reset ;  
              }                            
            }
       }

    /*continiously check and update the status*/
    if (  ObjTCPClient.connected( ))
          ui8TCPCleintStatus =   set;
    else {
          ui8TCPCleintStatus = reset;
          ObjTCPClient.stop( );   
         }
                        
  }
}

/*****************************************************************************
 **@Function     :   FnWifiTCPServerInit
 **@Descriptions :   
 **@parameters   :   none
 **@return       :   none
*****************************************************************************/
void WIFIServer :: FnWifiTCPMessageProcess(char *ucString)
{

    /*if user sends a command to read the weight*/
    if( strstr(ucString,(char *)"read weight") != reset )
      {      
        sprintf(si8TCPTransmitBuffer,"Weight KG=%.3f Weight LBS= %.3f\n",
        ObjWeight.flWeightInKG,ObjWeight.flWeightInLbs);
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                     
      }  

    else /*if user sends a command to read the temperature*/
    if( strstr(ucString,(char *)"read temperature") != reset )
      {       
        sprintf(si8TCPTransmitBuffer,"Temperature=%.2f\n",
        ObjTempHumid.VarTempHumid.FlAverageTemperature);
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                     
      }  

    else /*if user sends a command to read the humidity*/
    if( strstr(ucString,(char *)"read humidity") != reset )
      {      
        sprintf(si8TCPTransmitBuffer,"Humidity=%.2f\n",
        ObjTempHumid.VarTempHumid.FlAverageHumidity);
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                     
      } 

    else /*if user sends a command to start the motors*/
    if( strstr(ucString,(char *)"start car") != reset )
      {      
        /*start the motor controller*/
        ObjMotor.FnMotorControllerStart( );               
        sprintf(si8TCPTransmitBuffer,"car started\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                              
      }

    else /*if user sends a command to stops the motors*/
    if( strstr(ucString,(char *)"stop car") != reset )
      {      
        /*start the motor controller*/
        ObjMotor.FnMotorControllerStop( );               
        sprintf(si8TCPTransmitBuffer,"car stopped\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                           
        
      }       
      
    else /*if user sends a command to move forward*/
    if( strstr(ucString,(char *)"move car forward") != reset )
      {      
        /*start the motor controller*/
        ObjMotor.FnMotorControllerMoveforward( );    
        sprintf(si8TCPTransmitBuffer,"car moving forward\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                           
        
      }

    else /*if user sends a command to move forward*/
    if( strstr(ucString,(char *)"move car backward") != reset )
      {      
        /*start the motor controller*/
        ObjMotor.FnMotorControllerMoveBackward( );               
        sprintf(si8TCPTransmitBuffer,"car moving backward\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                           
        
      }

    else
    if( strstr(ucString,(char *)"move car left") != reset )
      {      
        /*start the motor controller*/
        ObjMotor.FnMotorControllerTurnLeft( );               
        sprintf(si8TCPTransmitBuffer,"car moving left\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                           
        
      }

    else
    if( strstr(ucString,(char *)"move car right") != reset )
      {
              
        /*start the motor controller*/
        ObjMotor.FnMotorControllerTurnRight( );               
        sprintf(si8TCPTransmitBuffer,"car moving right\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                           
        
      }      

    else
    if( strstr(ucString,(char *)"car speed slow") != reset )
      {
              
        /*start the motor controller*/
        ObjMotor.FnMotorControllerSpeed(_MotorSelectBack , (uint8_t)20 );               
        ObjMotor.FnMotorControllerSpeed(_MotorSelectFront, (uint8_t)20 );               
                
        sprintf(si8TCPTransmitBuffer,"car speed set to slow\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                            
      }      
      

    else
    if( strstr(ucString,(char *)"car speed medium") != reset )
      {
              
        /*start the motor controller*/
        ObjMotor.FnMotorControllerSpeed(_MotorSelectBack , (uint8_t)35 );               
        ObjMotor.FnMotorControllerSpeed(_MotorSelectFront, (uint8_t)35 );               
                
        sprintf(si8TCPTransmitBuffer,"car speed set to medium\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                            
      }      


    else
    if( strstr(ucString,(char *)"car speed fast") != reset )
      {
              
        /*start the motor controller*/
        ObjMotor.FnMotorControllerSpeed(_MotorSelectBack , (uint8_t)50 );               
        ObjMotor.FnMotorControllerSpeed(_MotorSelectFront, (uint8_t)50 );               
                
        sprintf(si8TCPTransmitBuffer,"car speed set to fast\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                            
      }      

      
   else
    if( strstr(ucString,(char *)"car speed medium") != reset )
      {
              
        /*start the motor controller*/
        ObjMotor.FnMotorControllerSpeed(_MotorSelectBack , (uint8_t)20 );               
        ObjMotor.FnMotorControllerSpeed(_MotorSelectFront, (uint8_t)20 );               
                
        sprintf(si8TCPTransmitBuffer,"car speed set to slow\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                           
        
      }      

    else
    if( strstr(ucString,(char *)"move car right") != reset )
      {
              
        /*start the motor controller*/
        ObjMotor.FnMotorControllerTurnRight( );               
        sprintf(si8TCPTransmitBuffer,"car moving right\n");
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                           
        
      }            

     else
     {        
        sprintf(si8TCPTransmitBuffer,"unknown command:%s\n",ucString);
        ui8TCPTransmitFlag = set;     
        #if (_DebuggEnable == true) 
             Serial.print(si8TCPTransmitBuffer);
        #endif                                
     }

    if (ui8TCPTransmitFlag == set )
    {
      ui8TCPTransmitFlag = reset ;
      ObjTCPClient.write(si8TCPTransmitBuffer);
      memset(si8TCPTransmitBuffer,reset,
      sizeof(si8TCPTransmitBuffer));      
    }
    
}
