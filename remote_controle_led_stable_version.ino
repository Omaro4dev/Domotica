#include <SoftwareSerial.h>

SoftwareSerial Xbee(2,3); 
const byte frameStartByte = 0x7E;
const byte frameTypeRemoteAT  = 0x17;
const byte remoteATOptionApplyChanges = 0x02;
String commandeLine ;
int remotePin ;
void setup() {
  Xbee.begin(9600);
  Serial.begin(4800);
}
void loop()
{
  commandeLine= getFromRasberry();
  mainController(commandeLine);
  /*
 toggleRemotePin(1);
  delay(3000);
  toggleRemotePin(0);
  delay(2000);
 */
}
byte sendByte(byte value) {
  Xbee.write(value);
  return value;
}
void toggleRemotePin(int value , char remotePin) {  // 0 = off, nonzero = on
  byte pin_state;
  if (value) {
    pin_state = 0x5;
  } else {
    pin_state = 0x4;
  }
  sendByte(frameStartByte); // Begin the API frame
  // High and low parts of the frame length (not counting checksum)
  sendByte(0x0);
  sendByte(0x10);
  long sum = 0; // Accumulate the checksum
  sum += sendByte(frameTypeRemoteAT); // Indicate this frame contains a
                                      // Remote AT command
   sum += sendByte(0x0);  // frame ID set to zero for no reply
  // The following 8 bytes indicate the ID of the recipient.
  // Use 0xFFFF to broadcast to all nodes.
  sum += sendByte(0x0);
  sum += sendByte(0x0);
  sum += sendByte(0x0);
  sum += sendByte(0x0);
  sum += sendByte(0x0);
  sum += sendByte(0x0);
  sum += sendByte(0xFF);
  sum += sendByte(0xFF);
  // The following 2 bytes indicate the 16-bit address of the recipient.
  // Use 0xFFFE to broadcast to all nodes.
  sum += sendByte(0xFF);
  sum += sendByte(0xFF);
  sum += sendByte(remoteATOptionApplyChanges); // send Remote AT options
  // The text of the AT command
  sum += sendByte('D');
  sum += sendByte(remotePin);
  // The value (0x4 for off, 0x5 for on)
  sum += sendByte(pin_state);
  // Send the checksum
  sendByte( 0xFF - ( sum & 0xFF));
  delay(10); // Pause to let the microcontroller settle down if needed
}     

String getFromRasberry()
{
  String commandeLineBuffer;
  char c ;
  Serial.println(" Serial  is  Working ");  

   while (Serial.available()>0)
   {
     commandeLineBuffer=commandeLineBuffer + char(Serial.read());
   }
 delay(1000);
 return commandeLineBuffer;
}

void mainController(String commandeLine){
  char time[4]={0,0,0,0};
  //Serial.println(time);
  Serial.println ("this is the  main controller");
  if ((commandeLine[0]=='1')||(commandeLine[0]=='2')){
    Serial.print("LED ON");
  toggleRemotePin(1,commandeLine[0]);
  delay(3000);
    Serial.print("LED OFF");
  toggleRemotePin(0,commandeLine[0]);
  delay(2000);
  }
}
