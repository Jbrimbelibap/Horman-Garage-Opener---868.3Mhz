#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

//0 is P0, 1 is P1, 2 is P2, We use P2 for our data pin. ~~ I don't think that you will need to adjust the pulse length
#define  FS1000A_DATA_PIN    2
#define pulse 471

void setup() {                
  pinMode(FS1000A_DATA_PIN, OUTPUT);  

  digitalWrite(FS1000A_DATA_PIN, HIGH);  //The remote sends a wakeup call only once, it starts with a 73ms long transmission (The garage uses OOK - on off keying, the easiest modulation)
  delay(73);

  digitalWrite(FS1000A_DATA_PIN, LOW); //It is followed by a 173ms long pause. Then we move on to repeating the code sequence
  delay(173);
}


void send(char c) 
      {
      switch (c) {
    
        case '0':
        digitalWrite(FS1000A_DATA_PIN, LOW);
        delayMicroseconds(pulse);
        digitalWrite(FS1000A_DATA_PIN, HIGH);
        delayMicroseconds(pulse);
        digitalWrite(FS1000A_DATA_PIN, LOW);
        delayMicroseconds(pulse);
        break;

        case '1':
        digitalWrite(FS1000A_DATA_PIN, LOW);
        delayMicroseconds(pulse);
        digitalWrite(FS1000A_DATA_PIN, HIGH);
        delayMicroseconds(pulse);
        digitalWrite(FS1000A_DATA_PIN, HIGH);
        delayMicroseconds(pulse);
        break;

        default:
        digitalWrite(FS1000A_DATA_PIN, LOW);
        break;
      };
    }

void loop() {

   // now the decoded pulse definition taken from Universal Radio Hacker tool and your keys
  char sequence1[] = "11111111000110100111100011000111111111100011"; //put your code in
 
  uint8_t i;
  digitalWrite(FS1000A_DATA_PIN, LOW); //This is the 12ms block of transmission at the start of the code. The remote itself repeats it before each actual code sequence.
  delayMicroseconds(pulse);
  digitalWrite(FS1000A_DATA_PIN, HIGH);
  delayMicroseconds(pulse*25.6);

  for (i = 0; i<sizeof(sequence1); i++) //actual code sequence
   {  
    send(sequence1[i]);
   }
}
