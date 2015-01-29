
++++++ clarification sur  la librairie  "Ethernet" +++++++ 
+ @author  :  Garci Omar  
+ date :  29/01/2015
+ ce document  explique  les  classes et  les  methodes de  la  libraire Ethernet  d'Arduino  
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

la  librairie   Ethernet  se compose de  4 Classes  

	la classe  Ethernet  
	la classe  Serveur  
	la classe  Client 
	la clasee  EthernetUDP

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+                 la classe  Ethernet                                       +
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		Methodes : 
			+Ethernet.begin(mac) :
			+Ethernet.begin(mac,ip) ;
			+Ethernet.begin(mac,ip,dns);
			+Ethernet.begin(mac,ip,dns,gateway);
			+Ethernet.begin(mac,ip,dns,gateway,subnet);
			
			+Ethernet.localIP()  : permet d'avoir  l'addresse  IP apres attribution  DHCP
			
			+Ethernet.maintain() :  cette methode permet de  maintenir  les addresses IP et de  les  
									negocier avec le  serveur DHCP . lors de  la connexion   ,  le 
									serveur  DHCP  peut attribuer des différentes  addresses ip  à la carte .
									
			
		Returns  :  
			+Ethernet.begin(mac) :  cette Methode utilise les  parametres DHCP
			pour l'obtention automatique d IP .
			1 : pour une  connexion DHCP etablie  
			0 : pour une connexion  DHCP  non  etablie 
			Void :  toutes les autres methodes ne retournent  rien . 

			+Ethernet.localIP () : retourne d'addresse IP 
			
			+Ethernet.maintain()  : 
			0 : nothing happened 
			1 : renew failed 
			2 : renew success
			3 : rebind fail  
			4 : rebind success 
			
			+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			+                         la classe Server                              +
			+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

			Methodes  : 
			
			+ Server( int port);       // instanciation de la classe  EthernetServer avec parametre  listening port  
			+ Server.begin() :        // Ouvrir Le   serveur et rester à l'ecoute des clients 
			+ Server.available () :  // Cette  Fonction  Retourne  un NULL  ou bien elle  retourne  un objet de type Client  .
								               // on   pourra  faire ça : /* EthernetClient client = server.available(); */
			+ Server.write (byte or char) ; 
			+ Server.print ( char , byte , int , long or  string) ; // retourne le  nombre de byte ecrits 
			+ Server.println () :  Cella permet d'envoyer  des  messages aux Clients . 
			
			
			+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			+                     Class Client                                        +
			+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			
			Methodes :  
			
			+EthernetClient()  :     //sert à l'instanciation de  l'objet client . 
			+if (EthernetClient) :   //booléan qui  retourne True si le  client est prêt  .
			+Client.connected ()  :  //permet de savoir  si  le  client est connecté . un client est aussi considéré comme connecté si  la connection
								               //est fermée et  reste  des données  à  lire   . 
									             //Retourne True or  False  .
			
			+Client.connect () ; 
			+client.connect(ip,port);
			+client.connect(URL ,port) ;
			
			+Client.write(byte or  char) :  // Elle permet d'envoyer des données  au serveur auquel  le client est connecté .
			+Client.print( byte , char ,  int  , long or string ) : 
			+Client.println ()  : 
			+Client.available () :  // retourne  le nombre de byte prêt à être  lus (les bytes transmises par  le  serveur)
			+Client.read () :      //Lire  le   byte  qui  suit  (ce qui est envoyé  par  le serveur ).
			+Client.flush  () :  //Vider  la  memoire  . 
			+Cleint.Stop () :   //Fermer  la connexion  
			
			Returns :  
			
			+Client.connect() :  
				1 : Success 
			   -1 : Timed OUT
			   -2 : Invalid_server
			   -3 : Truncated 
			   -4 : invalid_response 
			   
			+Client.read() : 
			   -1 : Nothing available . 
			
			
		+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		+                 class EthnernetUDP                            +
		+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			Configuration  de  la  connexion  à  Travars  UDP
			
	 les méthodes  : 

			+UDP.begin (localport)  : EthnernetUDP udp ; après  on fait  le begin (udp.begin)
			+udp.read() ;
			+udp.write() ; 
			+udp.beginPacket(); 
			+udp.endPacket() ;
			+udp.parsePacket();
			+udp.available() ;  
			+udp.stop(); 
			+udp.remoteIP();
			+udp.remotePort();
