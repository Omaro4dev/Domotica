/**
@author  :   Garci   Omar  
Date :  01/02/2014
Description   : 
	A Travers ce  montage  ,  on voudra bien comprendre   le fonctionnement des pin  PWM (Pulse Width Modulation)
	Reference :  Modulation en largeur  d'impulsion  . 
	http://fr.wikipedia.org/wiki/Modulation_de_largeur_d%27impulsion

	Il est  à  noter que  les  pins avec  PWM  sur  la  ARDUINO UNO sont  :  3,5,6,9 et  10  . 

	Le principe est simple  :  avec  cette technique  on  pourra   contrôler  la  variation de  la  tension en  Output  du  pin concerné . 

Project : Domotica  . 
Contact  :  omar.garci.etu@gmail.com 
**/

/*****
A travers  ce  montage  ,  on va mettre on oeuvre  l'utilisation de  la  PWM en variant  
la  luminosité d'une LED 
****/

int brightness  = 255 ;  //  variable  contenant la  valeur de luminosité  
const int   ledPin = 5 ; // on va  utiliser  le  pin 5
void  setup() {

	pinMode (ledPin,OUTPUT); 
	Serial.begin(9600) ;
}

void loop() {

	Serial.println("Please Write a  value between 0 and 255") ;  

	while (true)
	{
		while (Serial.available()>1)
		{
			brightness = Serial.parseInt() ;  //  on recupere  la valeur a  partir du  moniteur  Serie  . 

			brightness  =  constraint (brightness,0,255) ;  // on s'assure que   0 <= valeur  <= 255 

			Serial.print(" Setting Brightess to  : ");
			Serial.print(brightness);
			analogWrite(ledPin,brightness);  // on allume  la  Led  avec  la  valeur  recuperee .
		}
	}
}
