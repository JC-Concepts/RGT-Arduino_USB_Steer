# Wahoo RGT - Arduino USB Steering (PC solution)
This project is to create steering buttons for Wahoo RGT using an Arduino Pro Micro (or Leonardo). The concept is to make the Arduino act as an plug & play HID USB keyboard and send the characters 'A' (left) and 'D' (right) commands.

**v0.1.2** Added schematic for the accessory buttons, this is optional. The code will still work with the 0.1.1 schematic (no accessory buttons). The added buttons will allow you to wave, look-back, win, & lose function. The switch bank might be over complicated for a novice to electronics but this ensure the usage of minimal wires from the switch to the Arduino.  

**v0.1.1** Added the ability to override the Auto Steer feature that comes in every 2 minutes if you do not steer. Ideal for Team Time Trial
* To disable Auto Steer, press and hold the Left button for 5-10s (I would do a single press then hold for 10s to be on the safe side)
* To re-enable Auto Steer, press and hold the Right button for 5-10s (I would do a single press then hold for 10s to be on the safe side)
* **Recommendation:** disable on RGT main screen, and re-enable on the main screen so it will not interfere with your ride or text editiing after the ride. 

## Change Log:
View the latest on the [Change Log](https://github.com/JC-Concepts/RGT-Arduino_USB_Steer/blob/main/CHANGELOG.md) 

## Software Installation Notes:
* This was flashed using Arduino IDE 1.8.19 if you are using Arduino 2.0.x there might be some additional settings you will need to modify in the IDE perferences.


## Bill of Materials:
* Arduino Pro Micro (a clone version will work and save you the money)
* Switch qty: 2 (any contact normally open will work, I've used a 5mm x 5mm tactile switch (not waterproof))
* Some wires
* USB A to micro USB cable (if your Arduino did not come with it)
* **Switch Bank**: 5 resistors at 10K Ohm, 5 momentary switch (could be same type as steering switch), and some time to build it
* **LED Status**: 2 LED, 2 resistors at 464 Ohm


## Schematic:

 **v0.1.1 - Base Circuit**
<img src="https://user-images.githubusercontent.com/126370788/221392092-5b1c18ff-61f6-4ccb-b126-18c01fb2226a.png" alt="v0.1.1 Schematic" title="v0.1.1 Schematic">

**v0.1.2 - Circuit to include the Accessory Switch (Optional)**
<img src="https://user-images.githubusercontent.com/126370788/230745742-3a0490c7-8c62-4912-97dc-bf2cc0b4d514.png" alt="v0.1.2 Schematic" title="v0.1.2 Schematic">



# Like this Project? 
You can buy me a gel, coffee, or inner tube. Your support helps me further develop on these types of projects. 


[![](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=RE2GQDK8CD2WW)


## Hardware Installation Example:
- Sample picture: tactile switch hot glued to a scrap plastic from food packaging
- Switch assembly is held onto the hood using an elastic 
- Waterproofing the switch, you can use a small plastic bag or food wrap to seal it
- Cheap alternative to waterproof the ESP32 is to put it into a kids food container (easily found at the dollar store)

**Example pictures**

<img src="https://user-images.githubusercontent.com/126370788/221392142-773b0838-bffe-4697-9338-dc0e4f6b5d25.png" alt="Mounted on Hood" title="Mounted on Hood" height="500" width="500" >
<img src="https://user-images.githubusercontent.com/126370788/221392171-1d6f0b53-b0fe-4620-9c53-d61f71be0e96.png" alt="Splash proof Package" title="Splash Proof Container"height="473" width="800" >
<img src="https://user-images.githubusercontent.com/126370788/230746546-4c3767b5-e2f3-4451-b037-e17c8bdd3cf3.jpg" alt="Switch Bank (Top)" title="Top View of Button Bank"height="546" width="800" >
<img src="https://user-images.githubusercontent.com/126370788/230746548-a7ea665a-f044-4a6a-b3c9-70a816a5bb84.jpg" alt="Switch Bank (Bottom)" title="Back side of circuit board for button bank"height="533" width="800" >


