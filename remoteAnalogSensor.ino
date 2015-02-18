#include <SoftwareSerial.h>

SoftwareSerial Xbee(2,3); 
float temp   ;  
int analogReading , voltage , degreeC , degreeF ; 
void setup () {
	Serial.begin(9600);
	Xbee.begin(9600);
}

void loop () {
	
	//xbee_reading();

	if(Xbee.available() >= 21 ) {

		if (Xbee.read()==0x7E)
		{
			for (int i=1; i <19 ;  i++) {
			byte discardByte = Serial.read();
			}

		int analogMSB = Xbee.read();
		int analogLSB = Xbee.read();

		analogReading = analogLSB + (analogMSB * 256);

			votage = analogReading * 0.004882814 ;
			degreeC = (voltage-0.5)*100 ;
			degreeF = degreeC *(9.0/5.0)+32.0 ;

			/*** Affichage  serie ******/
		Serial.print("voltage: ");
       	Serial.print(voltage);
      	Serial.print("  deg C: ");
      	Serial.print(degreesC);
      	Serial.print("  deg F: ");
      	Serial.println(degreesF);

		}

	}

}
