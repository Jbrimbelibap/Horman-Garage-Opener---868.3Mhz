#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

//0 is P0, 1 is P1, 2 is P2, etc. - unlike the analog inputs, for digital outputs the pin number matches.
#define  FS1000A_DATA_PIN    2
#define pulse 471

void setup() {                
  pinMode(FS1000A_DATA_PIN, OUTPUT);  

  digitalWrite(FS1000A_DATA_PIN, HIGH);
  delay(73);

  digitalWrite(FS1000A_DATA_PIN, LOW);
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
  char sequence1[] = "11111111011010011110100001100011111111100011";
 
  uint8_t i;
  digitalWrite(FS1000A_DATA_PIN, LOW);
  delayMicroseconds(pulse);
  digitalWrite(FS1000A_DATA_PIN, HIGH);
  delayMicroseconds(pulse*25.6);

  for (i = 0; i<sizeof(sequence1); i++) //actual code sequence
   {  
    send(sequence1[i]);
   }
}
