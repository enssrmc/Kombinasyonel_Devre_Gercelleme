// ENES SIRMACI
// KONYA TEKNİK ÜNİVERSİTESİ
// ELEKTRİK ELEKTRONİK MÜHENDİSLİĞİ
int laserA=2;
int laserB=3;
int laserC=4;
int laserD=5;
int ldrA=A0;
int ldrB=A1;
int ldrC=A2;
int ldrD=A3;
int ledA=6; //Kavonozun capi kucuk
int ledB=7; //Kavonozun capi kucuk
int ledC=8; //Kavonozun capi istenilen degerde 
int ledD=9; //Kavonozun capi buyuk
int buzzer=10; //Bantda hic bir vazo olmadiginda

void setup() {
 pinMode(laserA,OUTPUT);
 pinMode(laserB,OUTPUT);
 pinMode(laserC,OUTPUT);
 pinMode(laserD,OUTPUT);
 pinMode(ledA,OUTPUT);
 pinMode(ledB,OUTPUT);
 pinMode(ledC,OUTPUT);
 pinMode(ledD,OUTPUT);
 pinMode(buzzer,OUTPUT);
 Serial.begin(9600);
}

void loop() {
 int degerA = analogRead(ldrA);
 int degerB = analogRead(ldrB);
 int degerC = analogRead(ldrC);
 int degerD = analogRead(ldrD);

 /*
  Ortam=400 
  Laser=600
  Ortam+Laser=1000
  Kontrol degeri=800
  (Rakamlar temsili verilmistir)
  Eger ldr kontrol degerinden daha dusuk bir deger okuyorsa vazo banta konulmus demektir
  Bantda vazolar sirasi ile su ldr'leri gorur  ldrA ldrB ldrC ldrD
  */

  // sorunun cozumu buradan sonra basliyor

  if(degerA<800 && degerB<800 && degerC<800 && degerD<800){
    Serial.println("Bantda vazo yok");
    digitalWrite(buzzer,HIGH);
    digitalWrite(ledA,LOW);
    digitalWrite(ledB,LOW);
    digitalWrite(ledC,LOW);
    digitalWrite(ledD,LOW);
    }
  else if(degerA>800 && degerB<800 && degerC<800 && degerD<800){
    Serial.println("Bantdaki vazonun capi istenilen degerden kucuk");
    Serial.println("Vazo iskartadir");
    digitalWrite(buzzer,LOW);
    digitalWrite(ledA,HIGH);
    digitalWrite(ledB,LOW);
    digitalWrite(ledC,LOW);
    digitalWrite(ledD,LOW);
    }
  else if(degerA>800 && degerB>800 && degerC<800 && degerD<800){
    Serial.println("Bantdaki vazonun capi istenilen degerden kucuk");
    Serial.println("Vazo iskartadir");
    digitalWrite(buzzer,LOW);
    digitalWrite(ledA,HIGH);
    digitalWrite(ledB,HIGH);
    digitalWrite(ledC,LOW);
    digitalWrite(ledD,LOW);
    }
  else if(degerA>800 && degerB>800 && degerC>800 && degerD<800){
    Serial.println("Bantdaki vazonun capi istenilen degerde");
    Serial.println("Vazo iyidir");
    digitalWrite(buzzer,LOW);
    digitalWrite(ledA,HIGH);
    digitalWrite(ledB,HIGH);
    digitalWrite(ledC,HIGH);
    digitalWrite(ledD,LOW);
    }
  else  if(degerA>800 && degerB>800 && degerC>800 && degerD>800){
    Serial.println("Bantdaki vazonun capi istenilen degerden buyuk");
    Serial.println("Vazo iskartadir");
    digitalWrite(buzzer,LOW);
    digitalWrite(ledA,HIGH);
    digitalWrite(ledB,HIGH);
    digitalWrite(ledC,HIGH);
    digitalWrite(ledD,HIGH);
    }
    delay(1000);
}
