# Glovraille

## Outline
1. [Introduction](#introduction)
2. [Concept](#concept)
3. [proof of concept (version 1)](#proof-of-concept)
4. [Build process (version 2)](#build-process-version-1)
3. [proof of concept (version 2)](#proof-of-concept-version-2)

## Introduction

Gloveraille is a glove that act as a  braille keyboard that is based on an arduino board. 

## Concept

The concept is verry simple, as shown in the figure bellow, the user will type a character using the selector and the character zone, when the user finish typing the character, he can confirm weither it is a number or character using one of the options in the forth finger, the character is then sent to the connected device (computer, phone or other compaptible device) after confirmation. The user can also send space, delete, enter or correct.
The glovebraille consists of 10 pads, 6 for character input, 3 for diffrent options and one pad as a selector. The role of each pad is as follow:
* pad GND : the selector ( connected to GND pin of the Arduino)
* pads from 0 to 5 : character zone, this pads will construct the character (Arduino pins; 2,3,4,5,6 and 7).
* pad 6: When this pad is selected using the selector, if the user already taped a character, it will confirm the **character** and sent it to the connected device. Otherwise, if the user did not enter any character, this will send a **space** to the device. (pin 11 in the Arduino).
* pad 7: When this pad is selected using the selector, if the user already taped a character, it will confirm the **number** and sent it to the connected device. (pin 12 in the Arduino).
* pad 8: When this pad is selected using the selector, if the user already taped a character, it will correct the character, in other words, this action will clear the chararcter buffer and does not send anything to the connected device.  Otherwise, if the user did not enter any character, this will send a **return character**   to the device. (pin 13 of the Arduino).

![Gloveraille schema](Schema.png)

The braille alphabet suported now is presented in the folowing figure:

![Braille alphabet](braille-alphabet.jpeg#center)
 


## proof of concept
The first prototype is made from a simple glove, with alimunium foil stick to the glove using double tape. For connection, wires from a headphone are used for their flixibility.

![Portotype](image1.jpg)

The ideal is to have instead of aluminuim foil a conductive textile, however, I connot find any and it will take long time to arrive if ordred from elsewhere. Also, insted of aluminium foil and double side tape, there is aluminium tape, but that what I have at the moment of making this prototype. For wires, there is also some kind of conductive thread, but for the same reasons mentionned befor, I used wires from and old headphone.

![Portotype](image2.jpg)

Here is a short video of the prototype in action:

[![Glovraille](http://img.youtube.com/vi/Om23hgbdo2s/0.jpg)](https://youtu.be/Om23hgbdo2s "Glovraille: another braille keyboard")

## Build process (version 2)
To build the Glovraille you need the flowing tools:
* A glove
* Arduino pro-mini (or any other Arduino)
* FTDI (if you are using an Arduino pro-mini)
* Headphone wires (thin wires that are inside the headphone cable)
* Conductive thread (if you don't have a conductive thread, you can use the headphone wires or aluminium tape as in version 1)
* Normal thread (optional)

![list of tools](./images/list_of_tools.JPG)


i. The first step is to solder the headphone wires to the Arduino pins (for simplicity, I used the pins 2,3,4,5,6,7 for letters, and 11,12,13 for function buttons).
<center>
<img src="./images/wire_soldering_to_arduino.JPG" width="300">
<img src="./images/wires_after_soldering.JPG" width="300">
</center>

ii. Add the headphone wires to the glove using a needle.

<center>
<img src="./images/sewing0.JPG" width="200">
<img src="./images/sewing1.JPG" width="200">
<img src="./images/sewing2.JPG" width="200">
<img src="./images/sewing3.JPG" width="200">
<img src="./images/sewing4.JPG" width="200">
<img src="./images/sewing5.JPG" width="200">
</center>

iii. Add the conductive thread: I'm not good at sewing, so I tried to have a big suface of the conductive thread, also, I tried diffrent shapes, but they all work fine.

<center>
<img src="./images/conductive_thread.JPG" width="400">
</center>

iv. Connect the headphone wires to the conductive thread: I simpliy made a knot between the headphone wires and the conductive thread. And I used a simple threading wire in order to secure the knot.

<center>
<img src="./images/wire_thread_knot.JPG" width="300">
<img src="./images/securing_the_knot.JPG" width="300">
</center>

v. That's it, now, just upload the  [ Arduino code](./arduino_code/) and enjoy.

<center>
<img src="./images/the_glovraille_v2.JPG" width="400">
</center>

### some issues
When I was testing the code, I noticed that the glovraille always tries to send the 'ENTER' character, that means that the pin number 13 is been activated even if is not selected. The probleme was caused by the built-in LED. At the setup function of the Arduino code, I set all the GPIO pins as OUTPUT with pullups, which made the pin number 13 alway ON, therfore the built-in LED is turned ON. And When the LED is ON, I suspect that this leads to a voltage drop in the pin 13, therfor a value of LOW as if this is selected by the selector (the GND slector in the thumb). 

The solution to this problem is just to remove the built-in LED. I was willing to remove it anyway in order to save some power when adding bluetooth and powering the system from a battery.

<center>
<img src="./images/built_in_LED.JPG" width="300">
<img src="./images/built_in_LED_removed.JPG" width="300">
</center>

## proof of concept (version 2)
Here is a short video of the version 2 of the prototype in action:

[![GlovrailleV2](https://i.ytimg.com/vi/Pz3dDO06ras/hqdefault.jpg)](https://youtu.be/Pz3dDO06ras "Glovraille: another braille keyboard (version 2)")
