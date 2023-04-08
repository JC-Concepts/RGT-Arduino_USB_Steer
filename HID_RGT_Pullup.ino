/*
RGT Steering USB HID Controller
The Arduino will act as a USB HID keyboard and when you press the buttons it will send the 'A' or 'D' keyboard signals.


https://github.com/JC-Concepts/RGT-Arduino_USB_Steer

Version: 0.1.2

BOM:
- Arduino Pro Micro
- Switch qty: 2 (any contact normally open will work)

*/

#include <Keyboard.h>
#include <Mouse.h>

// Pin Buton declaration
const int buttonLeftPin = 5;
const int buttonRightPin = 7;
const int SW_Bank = A0; // Analog input pin for switch bank

const int LED_P8 = 8; // Pin for LED
const int LED_P9 = 9; // Pin for LED

// Time Intervals
const unsigned long TIME_INTERVAL = 130;
const unsigned long TIME_AUTOSTEER = 60000;         // 60s before it sends a command to wait up the steering
const unsigned long TIME_AUTOSTEER_ACTIVATE = 5000; // Press and hold for this time to activate or disable Auto Steer

unsigned long previousMillis;
unsigned long previousAnalogMillis;

// Auto Steer Start Timer
unsigned long previousAUTOSteerMillis;
unsigned long previousSteerMillis;

bool Activate_A_Steer = false;
bool Activate_D_Steer = false;
bool AUTOSTEER = true;

/*
    Perform the additional RGTT commands: Wave, Look-Back, Win, Lose
*/
void LookBack_CMD()
{
    Mouse.click();

    for (int i = 0; i < 3; i++)
    {
        Keyboard.write(KEY_RIGHT_ARROW);
        delay(45);
    }

    Keyboard.write(KEY_RETURN);
}

void Wave_CMD()
{
    Keyboard.write('t');
    delay(20);
    Keyboard.print("/wave");
    Keyboard.write(KEY_RETURN);
}

void Win_CMD()
{

    Keyboard.write('t');
    delay(20);
    Keyboard.print("/win");
    Keyboard.write(KEY_RETURN);
}

void Lose_CMD()
{
    Keyboard.write('t');
    delay(20);
    Keyboard.print("/lose");
    Keyboard.write(KEY_RETURN);
}

/*
    Determine which switch is pressed in the switch bank
*/
void read_SW_Bank()
{
    int analog_Val = analogRead(SW_Bank);

    if (analog_Val == 0)
    {

        Wave_CMD();
    }
    else if (506 < analog_Val && analog_Val < 513)
    {

        LookBack_CMD();
    }
    else if (670 <= analog_Val && analog_Val <= 695)
    {

        Win_CMD();
    }
    else if (750 <= analog_Val && analog_Val <= 780)
    {

        Lose_CMD();
    }
    else if (800 <= analog_Val && analog_Val <= 830)
    {
        Keyboard.write('p');
    }
}

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
        if (AUTOSTEER && digitalRead(buttonLeftPin) != HIGH)
        {
            AUTOSTEER = false; // Turn Auto Steer & Collision Off
            digitalWrite(LED_P8, HIGH);
            previousAUTOSteerMillis = millis();
        }
        else if (!AUTOSTEER && digitalRead(buttonRightPin) != HIGH)
        {
            AUTOSTEER = true; // Turn Auto Steer & Collision On
            digitalWrite(LED_P8, LOW);
        }
    }
}

void setup()
{
    pinMode(buttonLeftPin, INPUT_PULLUP);
    pinMode(buttonRightPin, INPUT_PULLUP);

    pinMode(LED_P8, OUTPUT);
    pinMode(LED_P9, OUTPUT);
    digitalWrite(LED_P8, LOW);
    digitalWrite(LED_P9, LOW);

    Keyboard.begin();
    Keyboard.releaseAll();

    Mouse.begin();
    Mouse.release();

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
        else
        {
            Activate_A_Steer = false;
            Activate_D_Steer = false;
            previousSteerMillis = millis();
        }

        // AutoSteer_ActivateCount();

        previousMillis = millis();
    }

    if (millis() - previousAnalogMillis >= 250)
    {
        read_SW_Bank();
        previousAnalogMillis = millis();
    }

    if (!AUTOSTEER)
    {
        AutoSteer_OFF();
    }
}
