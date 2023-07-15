# Horman-Garage-Opener---868.3Mhz
An arduino IDE sketch meant for digispark, that allows you to open your Horman garage (only yours, keep it legal). You need a modified 868mhz rf module and a cheap RTL-SDR to decode your garage code.


Also I can't assure you that this code will work on your particular horman garage, but if it doesn't my code is very simple and should be easy enough to adjust.


This is what I ended with, the usb-c connector is just there so that my phone can power it : ![IMG_20230715_202216](https://github.com/Jbrimbelibap/Horman-Garage-Opener---868.3Mhz/assets/90109439/a23db211-c874-4640-b5a5-1a02744f2ee3)
To test the code you really just need 3 wires and a modified RF module.



This is the kind of remote that this project is able to replace : ![image](https://github.com/Jbrimbelibap/Horman-Garage-Opener---868.3Mhz/assets/90109439/20b7767d-ec8e-48af-87cc-f21b89f90602)


######
HARDWARE :
Required hardware : Digispark 
![image](https://github.com/Jbrimbelibap/Horman-Garage-Opener---868.3Mhz/assets/90109439/9f8ce798-c65d-41f4-9850-2383a5e9a932)

433mhz module that will be modified : 
![image](https://github.com/Jbrimbelibap/Horman-Garage-Opener---868.3Mhz/assets/90109439/95b8223d-1a3c-4e29-a765-47bad023b55b)

![image](https://github.com/Jbrimbelibap/Horman-Garage-Opener---868.3Mhz/assets/90109439/78a88073-6790-4b29-88f6-9fa48efb4b6d)

You need this partiticular one. I have gotten it to work with the more popular FS1000A but not reliably at all.

868.35Mhz Cristal : 
![image](https://github.com/Jbrimbelibap/Horman-Garage-Opener---868.3Mhz/assets/90109439/6494ed71-b2bb-444f-bda3-1127bd520afc)


All can be found on Aliexpress, for the module search for "433mhz ASK module" or use this link if still alive : 
https://fr.aliexpress.com/item/32735888738.html

For the cristal search for "868.35Mhz Cristal Oscillator Saw" (more difficult to find) or use this link : 
https://fr.aliexpress.com/item/1005005625251557.html


You will need to solder the new cristal in place of the old one.

The last piece of equipment needed is a rtl-sdr dongle, that's what we use to find the garage code as well as making sure that the modified module works :

![image](https://github.com/Jbrimbelibap/Horman-Garage-Opener---868.3Mhz/assets/90109439/e57c6688-c51e-441c-b5b5-843d8fa87168)


As far as connection goes, this is very easy. Vcc goes to 5V, GDN goes to GND, and Data goes to P2 (you can change this pin in the sketch)


This brings the total cost of this project to 18.5€ for me, although if you already have everything and only need the 868.3Mhz module, then it costs about 3€.



######
SOFTWARE :



Universal radio hacker to decode your garage code : https://github.com/jopohl/urh 
Spektrum to verify the frequency of the remote or see if it works at all : https://github.com/pavels/spektrum




In universal radio hacker record your garage keyfob signal, (inside of a project) you should obtain something that looks like this : ![image](https://github.com/Jbrimbelibap/Horman-Garage-Opener---868.3Mhz/assets/90109439/f141b4cd-2f85-4a92-a039-deda32fe0e69)
The pulse at the start corresponds to the 73ms transmission in the code, followed by a 173ms pause. Let's focus on the code itself :



![Untitled](https://github.com/Jbrimbelibap/Horman-Garage-Opener---868.3Mhz/assets/90109439/b750b44e-e1d7-44d1-a3fd-d6834e2dc34c)
This is the start of my code sequence, as you can see it's rather easy to decode.

A sequence is 80ms long and starts with a 12ms block, that's how you can spot where a signal starts and ends. Here we use the demodulated view in order to make the decoding clearer.

Each bit 1 or 0 is composed as 3 pulse length, the pulse length is 471us.

Just paste your string in the sketch once you have it decoded !



