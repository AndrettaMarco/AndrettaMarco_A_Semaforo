//SEMAFORO
int Ledrosso1=13;
int Ledgiallo1=12;
int Ledverde1=11;
int Ledrosso2=10;
int Ledgiallo2=9;
int Ledverde2=8;

int ciclo;
int tgiallo;
int Lampeggi;
int numLampeggi;

void setup() {
  // put your setup code here, to run once:

pinMode (Ledrosso1, OUTPUT);
pinMode (Ledgiallo1, OUTPUT);
pinMode (Ledverde1, OUTPUT);
pinMode (Ledrosso2, OUTPUT);
pinMode (Ledgiallo2, OUTPUT);
pinMode (Ledverde2, OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

//Tempo totale del semaforo
Serial.println("Tempo totale del semaforo?");
while(Serial.available()==0) {} 
ciclo=Serial.readString().toInt();
Serial.println(ciclo);

//Tempo accensione giallo
Serial.println("Tempo accensione giallo?");
while(Serial.available()==0) {} 
tgiallo=Serial.readString().toInt();
Serial.println(tgiallo);

//Numero lampeggi verde
Serial.println("Numero lampeggi del verde?");
while(Serial.available()==0) {}
numLampeggi=Serial.readString().toInt();
Serial.println(numLampeggi);

//Tempo accensione verde
Serial.println("Tempo lampeggio del verde?");
while(Serial.available()==0) {} 
Lampeggi=Serial.readString().toInt();
Serial.println(Lampeggi);

  
digitalWrite(Ledrosso1, HIGH);
digitalWrite(Ledverde2, HIGH);

for (int i=0;i<=numLampeggi;i++)
{
  digitalWrite(Ledverde2,LOW);
  delay(Lampeggi);
  digitalWrite(Ledverde2,HIGH);
  delay(Lampeggi);
}
digitalWrite(Ledverde2,LOW);
digitalWrite(Ledgiallo1,HIGH);
digitalWrite(Ledgiallo2,HIGH);
delay(tgiallo);
digitalWrite(Ledrosso1, LOW);
digitalWrite(Ledgiallo1,LOW);
digitalWrite(Ledgiallo2,LOW);
digitalWrite(Ledverde1,HIGH);
digitalWrite(Ledrosso2,HIGH);
delay((ciclo-(tgiallo+Lampeggi*numLampeggi))/2);

digitalWrite(Ledrosso2, HIGH);
digitalWrite(Ledverde1, HIGH);
delay((ciclo-(tgiallo+Lampeggi*numLampeggi))/2);
for (int i=0;i<=numLampeggi;i++)
{
  digitalWrite(Ledverde1,LOW);
  delay(Lampeggi);
  digitalWrite(Ledverde1,HIGH);
  delay(Lampeggi);
}
digitalWrite(Ledverde1,LOW);
digitalWrite(Ledgiallo2,HIGH);
digitalWrite(Ledgiallo1,HIGH);
delay(tgiallo);
digitalWrite(Ledrosso2, LOW);
digitalWrite(Ledgiallo2,LOW);
digitalWrite(Ledgiallo1,LOW);
digitalWrite(Ledverde2,HIGH);
digitalWrite(Ledrosso1,HIGH);
delay((ciclo-(tgiallo+Lampeggi*numLampeggi))/2);
}
