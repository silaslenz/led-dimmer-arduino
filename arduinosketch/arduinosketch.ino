/* 
Transmit sketch - RF Calibration
   Written by ScottC 17 July 2014
   Arduino IDE version 1.0.5
   Website: http://arduinobasics.blogspot.com
   Transmitter: FS1000A/XY-FST
   Description: A simple sketch used to calibrate RF transmission.          
------------------------------------------------------------- */
  
  #define rfTransmitPin 4  //RF Transmitter pin = digital pin 4
  #define ledPin 13        //Onboard LED = digital pin 13
  
  const int codeSize = 25;      //The size of the code to transmit
  int codeToTransmit[codeSize]; //The array used to hold the RF code
  int lightOnOff[]={4,2,4,2,2,2,4,4,4,4,2,2,4,4,4,4,2,2,2,2,2,2,2,4,3}; //Code for the signal for the On/Off button
  int light100p[]={4,2,4,2,2,2,4,4,4,4,2,2,4,4,4,4,2,2,2,2,2,4,4,4,3}; 
  int lightMinus[]={4,2,4,2,2,2,4,4,4,4,2,2,4,4,4,4,2,2,2,2,2,4,4,2,3};
  int lightPlus[]={4,2,4,2,2,2,4,4,4,4,2,2,4,4,4,4,2,2,2,2,2,4,2,4,3};
  int light50p[]={4,2,4,2,2,2,4,4,4,4,2,2,4,4,4,4,2,2,2,2,4,2,2,2,3};
  int light25p[]={4,2,4,2,2,2,4,4,4,4,2,2,4,4,4,4,2,2,2,2,4,2,2,4,3};
  
  
  void setup(){
   pinMode(rfTransmitPin, OUTPUT);   //Transmit pin is an output  
   transmitCode(light25p);
  }
  
  void loop(){
  
  
  }
  void transmitCode(int code[25]){
    //initialise the variables 
    int highLength = 0;
    int lowLength = 0;
    
    //The signal is transmitted 4 times 
    for(int j = 0; j<4; j++){
      for(int i = 0; i<codeSize; i++){ 
        switch(code[i]){
          case 2: // SH + LL
            highLength=300;
            lowLength=1000;
          break;
          case 3: // SH + VLL
            highLength=300;
            lowLength=114000;
          break;
          case 4: // LH + SL
            highLength=1000;
            lowLength=300;
          break;
        }
           
         transmitPair(highLength, lowLength);
      }
    }
  }
  
  void transmitPair(int highLength, int lowLength){
       // Transmit a HIGH signal
     digitalWrite(rfTransmitPin, HIGH);     
     delayMicroseconds(highLength); 
     
     // Transmit a LOW signal 
     digitalWrite(rfTransmitPin,LOW);     
     delayMicroseconds(lowLength);
  }

