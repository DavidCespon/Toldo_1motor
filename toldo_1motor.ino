/*
	Funcionamiento de un toldo accionado por un solo pulsador 
	y con 2 finales de carrera para saber el estado del toldo,
    además tenemos un sensor de luminosidad LDR que dependiendo
    de su estado el motor irá a una velocidad más rápida o más lenta
    de lo normal.
    
    Autor:  DAVID CESPÓN MÍGUEZ 
    Data:	13/03/2024
    Ultima modificación: 
*/

//Definir Pins Entrada/Salida 

	int pinentrada = 13;
	int pinsalida1 = 12;
	int pinsalida2 = 2;
	int pinfinal1 = 4;
	int pinfinal2 = 3;
	int ldr = A0;
	int salidaalimentacion = 7;

//Valores referencia del sensor LDR y la velocidad de los motores 

	int valormaximo = 679;
	int valor1 = 34;
	int valor2 = 136;
	int valor3 = 271;
	int valor4 = 407;
	int valor5 = 543;
	int velocidadmaxima = 255;
	int velocidad1 = 12;
    int velocidad2 = 51; 
    int velocidad3 = 102;
    int velocidad4 = 153;
    int velocidad5 = 204;

//Variables sensores y motores 

	int estadoentradaanterior = LOW;
	int salidaactiva = 0;
	int estadoentrada = 0;
	int direccion = 0;
	int valorfinal1 = 0;
	int valorfinal2 = 0;
	int valorldr = 0;
	int velocidadactual = 0;

void setup(){ //Configurar pines
  pinMode(pinentrada, INPUT);
  pinMode(pinfinal1, INPUT);
  pinMode(pinfinal2, INPUT);
  pinMode(pinsalida1, OUTPUT);
  pinMode(pinsalida2, OUTPUT);
  pinMode(salidaalimentacion, OUTPUT);
    
    
    Serial.begin(9600); }
 

void loop(){ //Leer el estado de los sensores
 valorfinal1 = digitalRead(pinfinal1);
 valorfinal2 = digitalRead(pinfinal2);
 valorldr = analogRead(ldr);
 
while(digitalRead(pinentrada)){ estadoentrada = 1; } 
  
if (estadoentrada) { estadoentrada = 0;
                      
if (salidaactiva) {
  direccion = !direccion;
  digitalWrite(pinsalida1, LOW);
  digitalWrite(pinsalida2,LOW);
  salidaactiva = 0;
} else {
  salidaactiva = 1;
  
  if (direccion) {
    digitalWrite(pinsalida1, HIGH);
  } else {  
    digitalWrite(pinsalida2, HIGH);
  }  
}  
}  

 
if (valorfinal1) { direccion = 0; salidaactiva = 0; digitalWrite(pinsalida1, LOW); }  

if (valorfinal2) { direccion = 1; salidaactiva = 0; digitalWrite(pinsalida2, LOW); }

if (valorldr <= valor1) { velocidadactual = velocidad1; }  
 else if (valorldr <= valor2) { velocidadactual = velocidad2; }                    
 else if (valorldr <= valor3) { velocidadactual = velocidad3; }                      
 else if (valorldr <= valor4) { velocidadactual = velocidad4; }                      
 else if (valorldr <= valor5) { velocidadactual = velocidad5; }
 else { velocidadactual = velocidadmaxima; }
 
                      
analogWrite(salidaalimentacion, velocidadactual);
delay (10); estadoentradaanterior =estadoentrada;}                                             
