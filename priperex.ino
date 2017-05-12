int x = 2;
int y = 0;
int z = 1;
double accX = 0;
double accY = 0;
double accZ = 0;

void setup () {
  Serial.begin(9600);
}

void loop () {
  //Data read
  accX = analogRead(x);
  accY = analogRead(y);
  accZ = analogRead(z);
  //Conversion to volts
  accX = accX*5/1023;
  accY = accY*5/1023;
  accZ = accZ*5/1023;
  //Conversion to g's
  accX = convert(accX);
  accY = convert(accY);
  accZ = convert(accZ);
}

double convert(double acc) {
  double result;
  result = (1.4*acc)-3.5;
  return result;
}
