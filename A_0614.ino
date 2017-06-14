int latchPin = 8;
int clockPin = 12;
int dataPin = 11; 

byte colDataMatrix[8] = { B01111111,
   B10111111,
   B11011111,
   B11101111,
   B11110111,
   B11111011,
   B11111101,
   B11111110
  };

const byte IMAGES[4][8] = {
{
  B11111111,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B11111111
},{
  B00000000,
  B01111110,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B01111110,
  B00000000
},{
  B00000000,
  B00000000,
  B00111100,
  B00100100,
  B00100100,
  B00111100,
  B00000000,
  B00000000
},{
  B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
}};

// 定義顯示器顯示的時間 (延遲時間), 預設 1ms
int delay_time = 500;
       
void setup() {
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
}
void loop() {
 for(int i=0; i<4 ; i++){
    for(int t = 0; t < 10 ; t++){
      for(int j = 0; j < 8 ; j++){
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[j]);
        shiftOut(dataPin, clockPin, MSBFIRST, IMAGES[i][j]);
        digitalWrite(latchPin,HIGH);
        delay(1);
      }
    }
  }
}


