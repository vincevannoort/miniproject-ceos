/*

+-----+-----+---------+------+---+---Pi 3---+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |   2 |   8 |   SDA.1 |   IN | 1 |  3 || 4  |   |      | 5v      |     |     |
 |   3 |   9 |   SCL.1 |   IN | 1 |  5 || 6  |   |      | 0v      |     |     |
 |   4 |   7 | GPIO. 7 |   IN | 1 |  7 || 8  | 1 | IN   | TxD     | 15  | 14  |
 |     |     |      0v |      |   |  9 || 10 | 1 | IN   | RxD     | 16  | 15  |
 |  17 |   0 | GPIO. 0 |   IN | 0 | 11 || 12 | 0 | IN   | GPIO. 1 | 1   | 18  |
 |  27 |   2 | GPIO. 2 |   IN | 0 | 13 || 14 |   |      | 0v      |     |     |
 |  22 |   3 | GPIO. 3 |   IN | 0 | 15 || 16 | 0 | IN   | GPIO. 4 | 4   | 23  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | IN   | GPIO. 5 | 5   | 24  |
 |  10 |  12 |    MOSI | ALT0 | 0 | 19 || 20 |   |      | 0v      |     |     |
 |   9 |  13 |    MISO | ALT0 | 0 | 21 || 22 | 0 | IN   | GPIO. 6 | 6   | 25  |
 |  11 |  14 |    SCLK | ALT0 | 0 | 23 || 24 | 1 | OUT  | CE0     | 10  | 8   |
 |     |     |      0v |      |   | 25 || 26 | 1 | OUT  | CE1     | 11  | 7   |
 |   0 |  30 |   SDA.0 |   IN | 1 | 27 || 28 | 1 | IN   | SCL.0   | 31  | 1   |
 |   5 |  21 | GPIO.21 |   IN | 1 | 29 || 30 |   |      | 0v      |     |     |
 |   6 |  22 | GPIO.22 |   IN | 1 | 31 || 32 | 0 | IN   | GPIO.26 | 26  | 12  |
 |  13 |  23 | GPIO.23 |   IN | 0 | 33 || 34 |   |      | 0v      |     |     |
 |  19 |  24 | GPIO.24 |   IN | 0 | 35 || 36 | 0 | OUT  | GPIO.27 | 27  | 16  |
 |  26 |  25 | GPIO.25 |  OUT | 0 | 37 || 38 | 0 | OUT  | GPIO.28 | 28  | 20  |
 |     |     |      0v |      |   | 39 || 40 | 0 | OUT  | GPIO.29 | 29  | 21  |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BCM | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BCM |
 +-----+-----+---------+------+---+---Pi 3---+---+------+---------+-----+-----+
*/
 
#include <stdio.h>
#include <stdbool.h>
#include <wiringPi.h>
#include <time.h>

int red = 0;     
int b11 = 1;    
int b12 = 2;    
int b21 = 3;    
int b22 = 4;    
int grn = 5;   
int ylw = 6;   
int buzz = 21;

int setupPins() {
  printf ("Setting up Raspberry Pi Pins...\n") ;
 
  if (wiringPiSetup () == -1)
    return 1 ;
 
  pinMode (0, OUTPUT);  // physical pin 11
  pinMode (1, INPUT);   // button 1, R1 (red wire)- physical pin 12
  pinMode (2, INPUT);   // button 1, R2 - physical pin 13
  pinMode (3, INPUT);   // button 2, R1 (blue wire)- physical pin 15
  pinMode (4, INPUT);   // button 2, R2 - physical pin 16
  pinMode (5, OUTPUT);  // green led, physical pin 18
  pinMode (6, OUTPUT);  //yellow led, physical pin 22
  pinMode (21, OUTPUT); //buzzer, physical pin 29
  printf ("Done. ;P\n\n") ;
}

int checkForButtonInput(int timeToMeasure, bool realGame) {
  int i = 0;

  if (realGame == true) {
    digitalWrite(buzz, 1);
    delay(50);
    digitalWrite(buzz, 0);
    printf ("Game started.\n");
  }

  for (i = 0; i < (timeToMeasure * 10); i++) {
    // 1 pressed
    if(digitalRead (b11) == 1 || digitalRead(b12) == 1){
      printf("Button 1 pressed\n");
      digitalWrite(red, 1);
      delay (100);
      digitalWrite(red, 0);
      return 1;
    }
    // 1 pressed
    else if(digitalRead (b21) == 1 || digitalRead (b22) == 1){
      printf("Button 2 pressed\n");
      digitalWrite(ylw, 1);
      delay (100);
      digitalWrite(ylw, 0);
      return 2;
    }
    delay (100);                      //in mS
  }
  return 0;
}