int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int k=1;
byte colDataMatrix[8] = { B01111111,
   B10111111,
   B11011111,
   B11101111,
   B11110111,
   B11111011,
   B11111101,
   B11111110,

  };
  
byte rowDataMatrix[2][8] = {
  { B11111111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111 },
   {B00111100,   
    B01000010,
    B10100101,
    B10000001,
    B10100101,
    B10011001,
    B01000010,
    B00111100}
    };  
                    

// 定義顯示器顯示的時間 (延遲時間), 預設 1ms
int delay_time = 1;

void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
}

void loop() {
  
   for(int i = 0; i < 2 ; i++){
    int d=1;
     unsigned long KK=millis();
     while(d){
      unsigned long AA;
     
    for(int j = 0; j< 8; j++){
      AA=millis();
    
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[j]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i][j]);
    digitalWrite(latchPin,HIGH);
     if((AA-KK)>1000) {d=0;}
    delay(delay_time);   
   
    }
    }
    }
    }
    
  

void pickDigit(int x) {
  byte rowByte = 1 << x;
  shiftOut(dataPin, clockPin, MSBFIRST, rowByte);
}



