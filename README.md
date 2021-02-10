# hamtech_internship
Obstacle avoiding robot which shows reactions with mouth and eyes and is controllable via android app

Table of Contents
-----------------

  * [Requirements](#requirements)
  * [Usage](#usage)
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

Usage
-----

First you should install python on your system and download the dataset.
Then you can run the script with cmd or Anaconda Prompt.

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
