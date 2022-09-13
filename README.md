# Capgemini Techival IoT Workshop Examples
This repository contains some code examples showcasing a few light effects for the LOLIN RGB LED Shield based on measurements from the Capacitive Soil Moisture Sensor.  
Since the sensor is capacitive, it'll detect/measure more than just wet soil. You should be able to use your finger on the sensor to test the code instead of needing a glass of water :)
- **SimpleFade** changes color from red to blue on all LEDs

## Arduino IDE Settings
To upload code to the WEMOS S2 Mini, the Arduino IDE should be set to the following settings under the _Tools_ menu.
- Board: "LOLIN S2 Mini"
  - Can be found under _ESP32 Arduino_
- Port: "COMx (LOLIN S2 Mini)"
  - Where COMx is probably the only available option
  - If your S2 Mini doesn't show up in the list or issues arise when uploading code to the board, hold down the **0** button, press the **RST** button, then release the **0** button

## Tips & Tricks
### Calibration
Opening the Arduino IDE's Serial Monitor will show you the unitless measured values coming straight from the sensor in all these examples. You can use these values to specify the range from dry to wet. These are defined in the examples as `DRY_VAL` and `WET_VAL`, respectively.  
The default values worked for me when I was writing these examples, but depending on the sensor you're using, they might not be optimal, so change them according to the Serial Monitor output.