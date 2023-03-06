# Wahoo RGT - Arduino USB Steering (PC solution)
This project is to create steering buttons for Wahoo RGT using an Arduino Pro Micro (or Leonardo). The concept is to make the Arduino act as an plug & play HID USB keyboard and send the characters 'A' (left) and 'D' (right) commands.

**v0.1.1** Added the ability to override the Auto Steer feature that comes in every 2 minutes if you do not steer. Ideal for Team Time Trial
* To disable Auto Steer, press and hold the Left button for 5-10s (I would do a single press then hold for 10ss to be on the safe side)
* To re-enable Auto Steer, press and hold the Right button for 5-10s (I would do a single press then hold for 10ss to be on the safe side)
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


## Schematic:

 
<img src="https://user-images.githubusercontent.com/126370788/221392092-5b1c18ff-61f6-4ccb-b126-18c01fb2226a.png" alt="Schematic" title="Schematic">


## Other Wahoo RGT Keyboard Command:
* **p**: Push to Talk
* **t**: Opens the Chat box


# Like this Project? 
You can buy me a gel, coffee, or inner tube


[![](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=RE2GQDK8CD2WW)


## Hardware Installation Example:
- Sample picture: tactile switch hot glued to a scrap plastic from food packaging
- Switch assembly is held onto the hood using an elastic 
- Waterproofing the switch, you can use a small plastic bag or food wrap to seal it
- Cheap alternative to waterproof the ESP32 is to put it into a kids food container (easily found at the dollar store)

**Example pictures**

<img src="https://user-images.githubusercontent.com/126370788/221392142-773b0838-bffe-4697-9338-dc0e4f6b5d25.png" alt="Mounted on Hood" title="Mounted on Hood" height="500" width="500" >
<img src="https://user-images.githubusercontent.com/126370788/221392171-1d6f0b53-b0fe-4620-9c53-d61f71be0e96.png" alt="Splash proof Package" title="Splash Proof Container"height="473" width="800" >


