# IOT-based-Attandance-System

1) Enter the ThingSpeak.com website and create an account.

2) Login after activating your account and click on New Channel in the My Channel section.

3) In the new window opened for you, write a name for your panel and any description if it is necessary. Determine the number of fields that you need by assigning their names. The remaining parts are optional. Save the panel after completing the information.

4) Now go to API Keys in your panel.

5) You need the Channel ID and Write API Key to transmit data.

5) You need the Channel ID and Write API Key to transmit data, so write them down.

7) Go to the Arduino IDE. Open the WriteMultipleFielsand enter the SSID, Password, Channel ID, and Write API Key values.

# Creating Attendance System Using the Fingerprint Sensor and Arduino

In this system, after registering the entry and exit of a person by his fingerprint, the information including date, name, time of arrival, time of departure and working hours for the employee are stored on the SD card. Then this information will be sent to ThingSpeak at the time you have specified. In the absence of the Internet connection, unpublished data is stored and will be forwarded to ThingSpeak as soon as it is connected to the Internet. Since the information is stored in the EEPROM of the microcontroller, they will not be lost in case of a power outage.

This code is written for 11 people with default names, but you can change them and remove it from the default mode. To register a new name, simply connect the device to your computer and press the key to enter the register mode, then open the Serial Monitor and follow the registration process as is shown on the Serial Monitor.
