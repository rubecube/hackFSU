#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
 
#define melodyPin 3

/////////////////////////////////////////////////
// gyroscope
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS1.h>
//#include <Adafruit_Sensor.h>  // not used in this demo but required!

// i2c
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

#define LSM9DS1_SCK A5
#define LSM9DS1_MISO 12
#define LSM9DS1_MOSI A4
#define LSM9DS1_XGCS 6
#define LSM9DS1_MCS 5



///////////////////////////////////////////////

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;


//Mario main theme melody
int MainMariomelody[78] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
 
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
 
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int MainMarionote[78] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};
//Underworld melody
int underworld_melody[56] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underwolrd tempo
int underworld_note[56] = {
  120, 120, 120, 120,
  120, 120, 60, 30,
  120, 120, 120, 120,
  120, 120, 60, 30,
  120, 120, 120, 120,
  120, 120, 60,30,
  120, 120, 120, 120,
  120, 120, 60, 60,
  180, 180, 180,60,
  60,60, 60, 60,
  60,180, 180, 180,
  180, 180, 180,100,
  100, 100,100, 100,
  100,30, 30, 30
};

int GOTmelody[14] = { NOTE_G6, NOTE_C6,NOTE_DS6,NOTE_F6,
                    NOTE_G6, NOTE_C6,NOTE_DS6,NOTE_F6, 
                    NOTE_G6, NOTE_C6,NOTE_DS6,NOTE_F6,
                    NOTE_D6,
                    };
int GOTnote [14] = {  500, 500, 250,250,
                    500, 500, 250,250,
                    500, 500, 250,250,
                    500};

int HAPPYmelody[25] = { NOTE_G6, NOTE_G6, NOTE_A6, NOTE_G6,
                    NOTE_C6, NOTE_B6, NOTE_G6, NOTE_G6, 
                    NOTE_A6, NOTE_G6, NOTE_D6, NOTE_C6,
                    
                    NOTE_G6, NOTE_G6,NOTE_G6,NOTE_E6,
                    NOTE_C6, NOTE_B6,NOTE_A6,NOTE_F6, 
                    NOTE_F6, NOTE_E6,NOTE_C6,NOTE_D6,
                    NOTE_C6}; 
                                  
int HAPPYnote [25] = {250, 250, 500,500,
                    500, 1000, 250,250,
                    500, 500, 500,1000,
                    
                    250, 250, 500,500,
                    500, 500, 500,250,
                    250, 500, 500,500,
                    1000};

int RICKmelody[36] = { NOTE_C6, NOTE_D6, NOTE_F6, NOTE_D6,
                    NOTE_A6, 0, NOTE_A6, NOTE_G6,
                    0, NOTE_C6, NOTE_D6, NOTE_F6,
                    NOTE_D6, NOTE_G6, NOTE_G6, 0,
                    NOTE_F6, 0, NOTE_C6, NOTE_D6,
                    NOTE_F6, NOTE_D6, NOTE_A6, 0,
                    NOTE_A6, NOTE_G6, 0, NOTE_C6,
                    NOTE_D6, NOTE_F6, NOTE_D6, NOTE_G6,
                    NOTE_G6, 0, NOTE_F6, 0};

int RICKnote[36] = {150,150,150,150,
                  150,150,600,600,
                  300,150,150,150,
                  150,150,150,600,
                  600,300,150,150,
                  150,150,150,150,
                  600,600,300,150,
                  150,150,150,150,
                  150,600,600,300};

int THUNDERmelody[32] = {
  1976, 988, 1760, 988,
  1661, 988, 1760, 988,
  1661, 988, 1480, 988,
  1661, 988, 1319, 988,
  1480, 988, 1244, 988,
  1319, 988, 1244, 988,
  1319, 988, 1244, 988,
  1319, 988, 1244, 988
};

int THUNDERnote[32]{
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125,
  125, 125, 125, 125
};

#include <Adafruit_NeoPixel.h>
#define PIN 5
// small led 73
// large led 116
int ledLenght = 75;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(ledLenght, PIN, NEO_GRB + NEO_KHZ800);

void setup(void)
{
  pinMode(3, OUTPUT);//speaker
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("Found LSM9DS1 9DOF");

  // helper to just set the default scaling we want, see above!
  setupSensor();
  strip.begin();
  strip.show();
  
}


void loop()
{
  int rInt = 250;
  int gInt = 00;
  int bInt = 20;
  

  int lenghtValue = lenghtOfSonar();
  while (lenghtValue < 30 && lenghtValue != 0){           /// check if the person is close enought

    lsm.read();  // ask it to read in the data 
    // Get a new sensor event 
    sensors_event_t a, m, g, temp;

    lsm.getEvent(&a, &m, &g, &temp); 

    Serial.print("Accel X: "); Serial.print(a.acceleration.x); Serial.print(" m/s^2");
//    Serial.print("\tY: "); Serial.print(a.acceleration.y);     Serial.print(" m/s^2 ");
//    Serial.print("\tZ: "); Serial.print(a.acceleration.z);     Serial.println(" m/s^2 ");
//  
//    Serial.print("Mag X: "); Serial.print(m.magnetic.x);   Serial.print(" gauss");
//    Serial.print("\tY: "); Serial.print(m.magnetic.y);     Serial.print(" gauss");
//    Serial.print("\tZ: "); Serial.print(m.magnetic.z);     Serial.println(" gauss");
//  
//    Serial.print("Gyro X: "); Serial.print(g.gyro.x);   Serial.print(" dps");
//    Serial.print("\tY: "); Serial.print(g.gyro.y);      Serial.print(" dps");
//    Serial.print("\tZ: "); Serial.print(g.gyro.z);      Serial.println(" dps");
//  
//    Serial.println();
    delay(200);  

    if (a.acceleration.z > 9){		//right side up (defualt position)

	       for(int i = 0; i < sizeof(GOTmelody)/sizeof(int);i++){              /// Game of tho 16


          buzz(melodyPin, GOTmelody[i] , GOTnote[i]);
          theaterChase(strip.Color(  255, 255, 0),3); //red

         }

    }else if (a.acceleration.x < -9){	//turned left 90 degrees
	//play song 1
	       for(int i = 0; i < sizeof(MainMariomelody)/sizeof(int);i++){              /// Main Mario 78
          buzz(melodyPin, MainMariomelody[i] , MainMarionote[i]*23);
          theaterChase(strip.Color(  69, 255, 69), 5);
         }
    }else if (a.acceleration.x > 9){	//turned right 90 degrees
        
        for(int i = 0; i < sizeof(HAPPYmelody)/sizeof(int);i++){              /// Happy 25
          buzz(melodyPin, HAPPYmelody[i] , HAPPYnote[i]);
          theaterChase(strip.Color(  225, 0, 255), 4); //red

         }
    }else if (a.acceleration.y < -9){	//turned away from 90 degrees
	//play song 3
      for (int i = 0; i<sizeof(THUNDERmelody)/sizeof(int); i++){
        buzz(melodyPin, THUNDERmelody[i], THUNDERnote[i]);
        theaterChase(strip.Color(255, 0, 0), 6);
      }
 
    }else if (a.acceleration.y > 9){	//turned towards 90 degrees
	//play song 4
       for(int i = 0; i < sizeof(underworld_melody)/sizeof(int);i++){              /// underworld 56
               buzz(melodyPin, underworld_melody[i] , underworld_note[i]*2);
               theaterChase(strip.Color(  0, 0, 255), 2);
       }
    }else if (a.acceleration.z < -9){	//turned upside down
	//play song 5 - rick roll
      for(int i=0; i < sizeof(RICKmelody)/sizeof(int); i++){
        buzz(melodyPin, RICKmelody[i], RICKnote[i]);
        theaterChase(strip.Color(  rInt, gInt, bInt), 7);
      }
    }

    
    if (lenghtOfSonar() > 35 || lenghtOfSonar() == 0){
        buzz(melodyPin, 0 , 0);
        break; 
    }
  }
  
  
}

void setupSensor()
{
  // 1.) Set the accelerometer range
  //lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_4G);
  lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_8G);
  //lsm.setupAccel(lsm.LSM9DS1_ACCELRANGE_16G);
  
  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS1_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS1_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS1_MAGGAIN_12GAUSS);
  //lsm.setupMag(lsm.LSM9DS1_MAGGAIN_16GAUSS);

  // 3.) Setup the gyroscope
  //lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_500DPS);
  lsm.setupGyro(lsm.LSM9DS1_GYROSCALE_2000DPS);
}


int lenghtOfSonar(){
  
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance= duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);  
    return distance;

  
}


void buzz(int targetPin, long frequency, long length) {
    long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
    //// 1 second's worth of microseconds, divided by the frequency, then split in half since
    //// there are two phases to each cycle
    long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
    //// multiply frequency, which is really cycles per second, by the number of seconds to
    //// get the total number of cycles to produce

    for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
      digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
      delayMicroseconds(delayValue); // wait for the calculated delay value
      digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
      delayMicroseconds(delayValue); // wait again or the calculated delay value
    } 
}

void theaterChase(uint32_t c, int pattern) {
  for (int j=0; j<3; j++) {  //do 3 cycles of chasing
    for (int q=0; q < pattern; q++) {
      for (int i=0; i < strip.numPixels(); i=i+pattern) {
        strip.setPixelColor(i+q, c);    //turn every pattern pixel on
      }
      strip.show();
     
      for (int i=0; i < strip.numPixels(); i=i+pattern) {
        strip.setPixelColor(i+q, 0);        //turn every pattern pixel off
      }
    }
  }
}

