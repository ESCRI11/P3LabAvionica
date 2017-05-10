#include <math.h>

int eix_x = 1;
int eix_y = 2;
int eix_z = 3;
double valX;
double valY;
double valZ;

void setup () {

}

void loop () {
  //Data read
  valX = analogRead(eix_x);
  valY = analogRead(eix_y);
  valZ = analogRead(eix_z);
  //Data conversion to volts
  valX = valX*5/1023;
  valY = valY*5/1023;
  valZ = valZ*5/1023;
  //Data conversion to g's
  valX = (1.4*valX) - 3.5;
  valY = (1.4*valY) - 3.5;
  valZ = (1.4*valZ) - 3.5;
}
