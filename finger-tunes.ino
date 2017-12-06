/* ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥
♥
♥         @author ovictoraurelio
♥         @github http://github.com/ovictoraurelio
♥         @website http://victoraurelio.com
♥
♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ */

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


#define TUNE_PLAY 0
#define buzzerOut 3

int lock, i;
int input[8];
int sample[8];
int note[8];

void setup () {
  Serial.begin(9600); 
  lock = 0;

  
  
  // Buzzer
  pinMode (buzzerOut, OUTPUT);

  input[0] = A0;
  input[1] = A1;
  input[2] = A2;
  input[3] = A3;
  

  // Initialize the digital pin as an output.
  // Entradas
  pinMode(input[0], INPUT);
  pinMode(input[1], INPUT);  
  pinMode(input[2], INPUT);  
  pinMode(input[3], INPUT);
}
void loop () {

  sample[0] = sample[1] = sample[2] = sample[3] = 0;
  
  for(i=0; i<32; i++){
    sample[i%4] += analogRead(input[i%4]);
    delay(1.5);
  }

  for(i=0; i<4; i++){
    note[i] = sample[i] / 8;
  }

  for(i=0; i<4; i++){
    playNote(i);
  }

  Serial.println("Note 1:\t\tNote 2:\t\tNote 3:\t\tNote 4:");
  Serial.print(note[0]);
  Serial.print("\t\t");
  Serial.print(note[1]);
  Serial.print("\t\t");
  Serial.print(note[2]);
  Serial.print("\t\t");
  Serial.println(note[3]); 
  
}

void playNote(int index){
  /*if(note[index] <= TUNE_PLAY){
    Serial.println(index+1);      
  }*/
  if(note[0] <= TUNE_PLAY){
    callBuzz(buzzerOut, NOTE_C5, 900/12);
  }  
  
  if(note[1] <= TUNE_PLAY){
    callBuzz(buzzerOut, NOTE_A3, 900/12);
  }
  
  if(note[2] <= TUNE_PLAY){
    callBuzz(buzzerOut, NOTE_G7, 900/12);
  }
  
  if(note[3] <= TUNE_PLAY){
    callBuzz(buzzerOut, NOTE_D8, 900/12);
  }
}

void callBuzz(int a, long b, long c){
  buzz(a, b, c);
  lock = 1; 
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  digitalWrite(13, LOW);
 
}
