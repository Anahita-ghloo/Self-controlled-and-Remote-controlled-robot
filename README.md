# hamtech_internship
Obstacle avoiding robot which shows reactions with mouth and eyes and is controllable via android app

Table of Contents
-----------------

  * [Requirements](#requirements)
  * [Description](#description)
  * [Contributing](#contributing)
  * [Support and Migration](#support-and-migration)
  * [License](#license)

Requirements
------------

Softwares and Hardwares used in this project :

  Android App :
  * Android Studio v4+
  * An android device with android7+ for testing
  * [iconfinder.com] for downloading icons
  
  Arduino program :
  * [Arduino IDE] 
 
  Hardware :
  * Programmer, I used [USB Isp]
  * [Arduino pro mini] 
  * [HC-05 Bluetooth module] 
  * L298D motor driver 
  * [Wheel] (2)  
  * [Swivel Castor]
  * [9g Servo] 
  * [Motor DC 3V-6V cu reductor] (2)
  * [Matrice LED 8x8] (3)
  * [HC-SR04 Ultra sonic sensor]
  * Chassis
  * Bread board
  * Jumper Wire

[USB Isp]: https://thecaferobot.com/store/atmel-avr-programmer-usbisp
[iconfinder.com]: https://www.iconfinder.com/
[Arduino IDE]: https://www.arduino.cc/en/software
[Arduino pro mini]: https://thecaferobot.com/store/arduino-pro-mini
[HC-05 Bluetooth module]: https://thecaferobot.com/store/hc-05-bluetooth-module
[Wheel]: https://thecaferobot.com/store/tt-motor-wheels-diameter-65mm
[Swivel Castor]: https://thecaferobot.com/store/cw02-1-inch-fixed-caster-wheel
[9g Servo]: https://thecaferobot.com/store/t-pro-mini-servo-sg-90-9g-servo
[Matrice LED 8x8]: https://thecaferobot.com/store/8x8-common-cathode-red-dot-matrix
[Motor DC 3V-6V cu reductor]: https://thecaferobot.com/store/double-axis-1-48-metal-gear-motor
[HC-SR04 Ultra sonic sensor]: https://thecaferobot.com/store/srf04-ultrasonic-sensor-module

Description
-----

This project consists of a robot with two mode (Remote-Controlled & Self-Controlled).

##### Remote-Controlled Mode :

The robot can be controlled by an android app. There are option for changing eyes and mouth. Arrow keys for moving the robot to four directions. A Remote/Auto control Button in the middle of arrow keys.

##### Self-Controlled Mode :

In Auto mode, robot finds it way by using Ultra sonic sensor.


In this project I used following links :

https://medium.com/swlh/create-custom-android-app-to-control-arduino-board-using-bluetooth-ff878e998aa8
https://create.arduino.cc/projecthub/igorF2/controlling-an-led-matrix-with-arduino-uno-0a9e94
https://create.arduino.cc/projecthub/electropeak/using-8x8-dot-matrix-led-with-arduino-cascade-connection-5cecff

example:
```sh
(base) C:\>python Compare_ID_Shenasa.py --index_directory C:Anahita\dataset\index --others_directory C:Anahita\dataset\others
--output_directory C:\Users\Anahita

```
Note : There is a space between each directory above.

The Script has the following inputs.

`index_directory` is the path of index folder, where the main pictures exist. 

`others_directory` is the path of others folder, where the copies of index pictures exist. 

`output_directory` is the path of output, where the two folders of "same" & "different" are created. 

### Error handling

The script will raise fallowing error if directories are not provided.

AttributeError: `NoneType` object

Contributing
-----

Not yet

Support and Migration
-----

Not yet

License
-----

Not yet
