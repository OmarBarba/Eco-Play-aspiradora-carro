#include <AFMotor.h> //incluir librería
AF_DCMotor Motor1(1);//definir que vamos a usar el motor 1 
AF_DCMotor Motor2(2);

int trig=36; 
int echo=37;
int trig2=50; 
int echo2=51;
int trig3=22; 
int echo3=23;
char dato;
int vent=31;
 

 
void setup(){  
  Serial.begin (9600);
  pinMode (trig, OUTPUT); 
    pinMode (echo, INPUT); 
     Motor1.setSpeed(200); 
     Motor1.run(RELEASE); 
     Motor2.setSpeed(80); 
     Motor2.run(RELEASE);
    pinMode (vent, OUTPUT);
    pinMode (trig2, OUTPUT); 
    pinMode (echo2, INPUT); 
    pinMode (trig3, OUTPUT); 
    pinMode (echo3, INPUT); 
   }

void av(){ 
Motor1.run(FORWARD); 
Motor2.run(FORWARD);
Serial.println(" HACIA adelante");  
      }
void atras() {
  Motor1.run(BACKWARD);
Motor2.run(BACKWARD);
Serial.println(" HACIA atras");    
     }
void derecha(){
 Motor1.run(BACKWARD); 
Motor2.run(FORWARD);
Serial.println("GIRAR HACIA LA DERECHA");   }

void izquierda() {

 Motor1.run(BACKWARD); 
Motor2.run(BACKWARD);
Serial.println("GIRAR HACIA LA IZQUIERDA");   }

void alto(){
  Motor1.run(RELEASE);
Motor2.run(RELEASE);
Serial.println("GIRAR HACIA LA ALTO");
  }

void loop(){   
  long duracion;
  long distancia;
  int dis;
 
  int bandera=0;
  
   digitalWrite(vent,HIGH);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  
  duracion = pulseIn(echo,HIGH);
  distancia = (duracion/2)/29;
Serial.println(distancia);

  
  delay(50);
 
  if(distancia<=10){
    alto();
    delay(300);
    atras();
     delay(600);
     derecha();
    delay(550); 
    derecha();
    delay(500);   
}
  else {
     av();
      delay(500);
  }
}
