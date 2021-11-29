// ENES SIRMACI
// KONYA TEKNİK ÜNİVERSİTESİ
// ELEKTRİK ELEKTRONİK MÜHENDİSLİĞİ
int min_seviye=100;
int max_seviye=600;

//Seviyeler rasgale alinmistir

int role=11; 
int su_seviye=A0;
int seviye=0;

//Bu ornekte su pompasi yerine role kullanilactir

void setup() {
Serial.begin(9600);
pinMode(role,OUTPUT);
}

void loop() {
seviye=analogRead(su_seviye);

if(seviye==0){
  if(role=0){
    Serial.println("Su seviyesi dusuk");
    digitalWrite(role,HIGH);
    }
  }
else if(seviye>0 && seviye<=min_seviye){
  if(role=0){
    Serial.println("Su seviyesi dusuk");
    digitalWrite(role,HIGH);
    }
  }
else if(seviye>min_seviye && seviye<=max_seviye){
  if(role=0){
    Serial.println("Su seviyesi orta");
    digitalWrite(role,HIGH);
    }
  }
else if(seviye>max_seviye){
  if(role=1){
    Serial.println("Su seviyesi yuksek");
    digitalWrite(role,LOW);
    } 
  }
delay(1000);
}
