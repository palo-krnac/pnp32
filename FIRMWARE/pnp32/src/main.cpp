#include <Arduino.h>
#include "config.h"
#include <GCodeParser.h>
#include "gcode/dispatcher.h"
#include "mcode/dispatcher.h"
#include "mcode/m150.h"
#include <TMC5160.h> // tmc



// GCodeParser GCode = GCodeParser();

// float xPos = NAN, yPos = NAN, zPos = NAN, aPos = NAN, bPos = NAN, cPos = NAN;
// int gCode = -1, mCode = -1;


const uint8_t SPI_CS = 0; // CS pin in SPI mode   tmc
const uint8_t SPI_DRV_ENN = 5;  // DRV_ENN pin in SPI mode   tmc

TMC5160_SPI motor = TMC5160_SPI(SPI_CS); //Use default SPI peripheral and SPI settings.

void setup()
{
  Serial.begin(SERIAL_SPEED); //set in config.h
  //Serial.println("Ready GCodeParser");

  pinMode(SPI_DRV_ENN, OUTPUT);   // tmc
  digitalWrite(SPI_DRV_ENN, LOW); // Active low tmc

  // This sets the motor & driver parameters /!\ run the configWizard for your driver and motor for fine tuning !  //tmc
  TMC5160::PowerStageParameters powerStageParams; // defaults.  //tmc
  TMC5160::MotorParameters motorParams;  //tmc
  motorParams.globalScaler = 98; // Adapt to your driver and motor (check TMC5160 datasheet - "Selecting sense resistors")  //tmc
  motorParams.irun = 31;  //tmc   31
  motorParams.ihold = 16;  //tmc  16

  SPI.begin();  //tmc
  motor.begin(powerStageParams, motorParams, TMC5160::NORMAL_MOTOR_DIRECTION);  //tmc

  delay(1000); // Standstill for automatic tuning tmc
  // ramp definition
  motor.setRampMode(TMC5160::POSITIONING_MODE);  //tmc
  motor.setMaxSpeed(400);  //tmc
  motor.setAcceleration(500);  //tmc

  Serial.println("starting up");  //tmc

  delay(1000); // Standstill for automatic tuning tmc

  //setupM150();  // inicializácia LED pásov
  //#ifdef pnp32_MC
 // Serial.println("Bežíme na ESP32");
 // #elif defined(pnp32_MCM)
 // Serial.println("Bežíme na MCM");
 // #elif defined(pnp32_MCH)
 // Serial.println("Bežíme na MCH");
  //#elif defined(PnP_Controller)
//  Serial.println("Bežíme na Teensy 4.0");
//#else
//  #error "Nezvolená podpora dosky!"
//#endif
}

void loop()
/*
{
  if (Serial.available() > 0)
  {
    if (GCode.AddCharToLine(Serial.read()))
    {
      GCode.ParseLine();
      GCode.RemoveCommentSeparators();

      Serial.print("\nPrijatý riadok: ");
      Serial.println(GCode.line);

      xPos = yPos = zPos = aPos = bPos = cPos = NAN;
      gCode = mCode = -1;

      bool hasG = GCode.HasWord('G');
      bool hasM = GCode.HasWord('M');

      if (GCode.HasWord('X')) xPos = GCode.GetWordValue('X');
      if (GCode.HasWord('Y')) yPos = GCode.GetWordValue('Y');
      if (GCode.HasWord('Z')) zPos = GCode.GetWordValue('Z');
      if (GCode.HasWord('A')) aPos = GCode.GetWordValue('A');
      if (GCode.HasWord('B')) bPos = GCode.GetWordValue('B');
      if (GCode.HasWord('C')) cPos = GCode.GetWordValue('C');

      if (hasG) {
        gCode = GCode.GetWordValue('G');
        dispatchGCode(gCode, xPos, yPos, zPos, aPos, bPos, cPos);
      }

      if (hasM) {
        mCode = GCode.GetWordValue('M');
        dispatchMCode(mCode, GCode);
      }

      if (!hasG && !hasM) {
        Serial.println(" → Žiadny G ani M kód.");
      }
    }
  }
  */
{
  uint32_t now = millis();   //tmc
  static unsigned long t_dirchange, t_echo;  //tmc
  static bool dir;  //tmc

  // every n seconds or so...  v//tmc
  if ( now - t_dirchange > 3000 )  //tmc
  {
    t_dirchange = now;  //tmc

    // reverse direction  //tmc
    dir = !dir;  //tmc
    motor.setTargetPosition(dir ? 200 : 0);  // 1 full rotation = 200s/rev  //tmc
  }

  // print out current position  //tmc
  if( now - t_echo > 100 )  //tmc
  {
    t_echo = now;  //tmc

    // get the current target position
    float xactual = motor.getCurrentPosition();  //tmc
    float vactual = motor.getCurrentSpeed();  //tmc
    Serial.print("current position : ");  //tmc
    Serial.print(xactual);  //tmc
    Serial.print("\tcurrent speed : ");  //tmc
    Serial.println(vactual);  //tmc
  }
}
