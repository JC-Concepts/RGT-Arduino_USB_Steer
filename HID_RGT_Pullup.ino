/*
RGT Steering USB HID Controller
The Arduino will act as a USB HID keyboard and when you press the buttons it will send the 'A' or 'D' keyboard signals.

*** PULL Up Version ***

https://github.com/JC-Concepts/RGT-Arduino_USB_Steer

Version: 0.1.0

BOM:
- Arduino Pro Micro
- Switch qty: 2 (any contact normally open will work)

*/

#include <Keyboard.h>

// Pin Buton declaration
const int buttonLeftPin = 5;
const int buttonRightPin = 7;

// Time Intervals
const unsigned long TIME_INTERVAL = 130;
const unsigned long TIME_AUTOSTEER = 100000;        // 100s before it sends a command to wait up the steering
const unsigned long TIME_AUTOSTEER_ACTIVATE = 5000; // Press and hold for this time to activate or disable Auto Steer

unsigned long previousMillis;

// Auto Steer Start Timer
unsigned long previousAUTOSteerMillis;
unsigned long previousSteerMillis;

bool Activate_A_Steer = false;
bool Activate_D_Steer = false;
bool AUTOSTEER = true;

/*
    Sense the command to Wake Up Steering and in turn disable the Auto Steer
*/
void AutoSteer_OFF()
{
    if ((millis() - previousAUTOSteerMillis) >= TIME_AUTOSTEER)
    {
        Keyboard.write('a');
        delay(50);
        Keyboard.write('d');
        Keyboard.releaseAll();

        previousAUTOSteerMillis = millis();
    }
}

/*
    Check to see if it is time to send the Auto Steer wake messages
*/
void AutoSteer_ActivateCount()
{
    if ((millis() - previousSteerMillis) >= TIME_AUTOSTEER_ACTIVATE)
    {
        if (AUTOSTEER)
        {
            AUTOSTEER = false; // Turn Auto Steer & Collision Off
        }
        else
        {
            AUTOSTEER = true; // Turn Auto Steer & Collision On
        }
    }
}

void setup()
{
    pinMode(buttonLeftPin, INPUT_PULLUP);
    pinMode(buttonRightPin, INPUT_PULLUP);

    Keyboard.begin();
    Keyboard.releaseAll();

    previousMillis = millis();
    previousAUTOSteerMillis = millis();
    previousSteerMillis = millis();
}

void loop()
{
    if (millis() - previousMillis >= TIME_INTERVAL)
    {
        if (digitalRead(buttonLeftPin) != HIGH)
        {
            Keyboard.write('a');

            if (!Activate_A_Steer)
            {
                Activate_A_Steer = true;
                Activate_D_Steer = false;
                previousSteerMillis = millis();
            }

            AutoSteer_ActivateCount();
        }
        else if (digitalRead(buttonRightPin) != HIGH)
        {
            Keyboard.write('d');

            if (!Activate_D_Steer)
            {
                Activate_D_Steer = true;
                Activate_A_Steer = false;
                previousSteerMillis = millis();
            }

            AutoSteer_ActivateCount();
        }

        previousMillis = millis();
    }

    if (!AUTOSTEER)
    {
        AutoSteer_OFF();
    }
}
