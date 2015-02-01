/**
	@author :  Garci  Omar 
	Date :  01/02/2015
	Projet  :  Domotica 
	Description :  Contrôller  un moteur  

 Transistor  :  
 	Dans ce  montage ,  on a utilisé un  Transistor  . Le fonctionnement  
 	du moteur  nécessite  bcp plus d'ampérage que celui fournit par  la carte 

Flyback  diode  :  
	On a aussi  utilisé  une flyback diode  afin d'eviter  le  retour du  
	courant  qui peut endommager  le Transistor

Branchement  : 
	Transistor  :   
		Raccordement de  Pin 9 a une resistance  330 Ohm puis  a la  BASE 
		du  Transistor  . 
		Raccordement du  collecteur au  moteur et  l Emetteur a  la masse  GND  . 

	Diode  :  
		Raccordemement de la cathode (avec  bande )  à 5V  . 
		Raccordement de  l'anode  avec  le  moteur  . 

Note  importante :

	Il faut  toujours  utiliser un  PIN PWM  . 
	au dessus de   la valeur de 50 , le  moteur  ne tournera  pas  . 

Référence : 
	Montage  12 de Sparkfun  . 
	How _ to _ PWM .ino. 	

Contact  :  omar.garci.etu@gmail.com	 
**/

const int motorPin = 9;


void setup()
{
  

  pinMode(motorPin, OUTPUT); // Utilisation du  Pin en mode Output  .
  Serial.begin(9600); // intialisation de  la  liason série . 
}


void loop()
{

	/**
	Implementation de  4  methodes  différentes  . 
	Décommenter  pour  utiliser  . Don 't be  that  Noob  Man   . 
	**/

 //  motorOnThenOff();
  // motorOnThenOffWithSpeed();
  //motorAcceleration();
  
    serialSpeed();
}


//  Cette methode permet de  declancher  et d'arreter  le  moteur 

void motorOnThenOff()
{
  int onTime = 3000;  // temps en  millisecondes en  mode ON 
  int offTime = 3000; // temps  en millisecondes en  mode  OF
  
  digitalWrite(motorPin, HIGH); // Allummer  le  moteur en  pleine vitesse (HIGH)
  delay(onTime);                // delais en  mode  "ON"
  digitalWrite(motorPin, LOW);  // Arreter  le  moteur 
  delay(offTime);               // delais en  mode "OFF"
}


// Cette fonction altérne  entre deux vitesse différentes.

void motorOnThenOffWithSpeed()
{
  int Speed1 = 200;  // initialisation de la premiere  vitesse  .
  int Time1 = 3000;  //  SameThing  Upstairs ;)
  
  int Speed2 = 50;   // initialisation de la deuxiéme  vitesse  . 
  int Time2 = 3000;  
  
  analogWrite(motorPin, Speed1);  // Let It  be  baby   ! 
  delay(Time1);                   
  analogWrite(motorPin, Speed2);  // arreter  le  moteur  .
  delay(Time2);                   //  le temps c'est le l'argent .
}


// Cette fonction permet d'accélerer le  moteur  petit a petit,

void motorAcceleration()
{
  int speed;
  int delayTime = 20; // delais entre les incrémentations 
  
  // accélerer  le  moteur  .

  for(speed = 0; speed <= 255; speed++)
  {
    analogWrite(motorPin,speed);	// tourner le  moteur  avec  la vitesse 
    delay(delayTime);           	//  temps necessaire
  }
  
  // decelerer le moteur . 

  for(speed = 255; speed >= 0; speed--)
  {
    analogWrite(motorPin,speed);	
    delay(delayTime);           	
  }
}


// Cette fonction permet d'utilair



void serialSpeed()
{
  int speed;
  
  Serial.println("Type a speed (0-255) into the box above,");
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Print a blank line

  while(true)  // "true" is always true, so this will loop forever.
  {
    /
  
    while (Serial.available() > 0)
    {
     
      
      speed = Serial.parseInt();
  
     
      speed = constrain(speed, 0, 255);
    
      Serial.print("Setting speed to ");
      Serial.println(speed);
  
      
      analogWrite(motorPin, speed);
    }
  }
}




