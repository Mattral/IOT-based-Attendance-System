#include "Thingspeak.h"
#include ESP8266WiFi.h>
char ssid[] = "YOUR SSID";
char pass[] = "SSID PASSWORD";
WiFiClient  client;
unsigned long myChannelNumber = YOUR CHANNEL ID;
const char * myWriteAPIKey = "YOUR CHANNEL WRITE API KEY";
String Final = "";
String Date = "";
String Enter = "";
String Exit = "";
String Name = "";
String WT = "";
void String_Analyze(String input) {
 int index1, index2, index3, index4;
 index1 =  input.indexOf('*', 0);
 index2 =  input.indexOf('*', index1 + 1);
 index3 =  input.indexOf('*', index2 + 1);
 index4 =  input.lastIndexOf('*');
 Name = input;
 Date = input;
 Enter = input;
 Exit = input;
 WT = input;
 Name.remove(index1);
 Date.remove(index2);
 Date.remove(0, index1 + 1);
 Enter.remove(index3);
 Enter.remove(0, index2 + 1);
 Exit.remove(index4);
 Exit.remove(0, index3 + 1);
 WT.remove(0, index4 + 1);
}
void Get_String()
{
 while (Serial.available()) {
   Final = Serial.readString(); // read the incoming data as string
   //Serial.println(Final);
 }
}
void setup() {
 Serial.begin(9600);
 WiFi.mode(WIFI_STA);
 Thingspeak.begin(client);
 pinMode(LED_BUILTIN, OUTPUT);
 digitalWrite(LED_BUILTIN, HIGH);
}
void loop() {
 if (WiFi.status() != WL_CONNECTED) {
   //Serial.print("Attempting to connect to SSID: ");
   // Serial.println(ssid);
   while (WiFi.status() != WL_CONNECTED) {
     WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
     Serial.print("0");
     delay(5000);
   }
 }
 digitalWrite(LED_BUILTIN, LOW);
 //Serial.println("\nConnected.");
 Get_String();
 String_Analyze(Final);
 if (!Final.equals(""))
 {
   Thingspeak.setField(1, Date);
   Thingspeak.setField(2, Name);
   Thingspeak.setField(3, Enter);
   Thingspeak.setField(4, Exit);
   Thingspeak.setField(5, WT);
   int x = Thingspeak.writeFields(myChannelNumber, myWriteAPIKey);
   if (x == 200) {
     delay(100);
     Serial.print("1");
   }
   else {
     delay(100);
     Serial.print("0");
   }
   delay(17000);
   Final = "";
 }
