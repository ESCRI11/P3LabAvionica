
int x = 2;
int y = 0;
int z = 1;
double accX = 0;
double accY = 0;
double accZ = 0;
double gaingX = 0;
double gaingY = 0;
double gaingZ = 0;
double Aoffx = 0;
double Aoffy = 0;
double Aoffz = 0;
double Arealx = 0;
double Arealy = 0;
double Arealz = 0;
double Ag1x = 0;
double Am1x = 0;
double Vxn = 1.96;
double Vxp = 2.88;
double Vyn = 1.83;
double Vyp = 2.8;
double Vzn =1.87;
double Vzp = 2.81;
double theta = 0;
double psi = 0;
double phi = 0;

void setup () {
  Serial.begin(9600);
  gaingX = 0.5*(convert(Vxp) - convert(Vxn));
  Aoffx = 0.5*(convert(Vxp) + convert(Vxn));
  gaingY = 0.5*(convert(Vyp) - convert(Vyn));
  Aoffy = 0.5*(convert(Vyp) + convert(Vyn));
  gaingZ = 0.5*(convert(Vzp) - convert(Vzn));
  Aoffz = 0.5*(convert(Vzp) + convert(Vzn));
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
  //X
  Arealx = ((accX-Aoffx)/(gaingX));
  //Y
  Arealy = ((accY-Aoffy)/(gaingY));
  //Z
  Arealz = ((accZ-Aoffz)/(gaingZ));
  //Serial.println(Arealz);
  delay(300);
  //Angle
  theta = (Arealx)/(sqrt((Arealy*Arealy)+(Arealz*Arealz)));
  theta = atan(theta);
  psi = atan((Arealy)/(sqrt((Arealx*Arealx)+(Arealz*Arealz))));
  phi = atan((sqrt((Arealx*Arealx)+(Arealy*Arealy)))/(Arealz));

  Serial.print(theta);
  Serial.print(" ");
  Serial.print(psi);
  Serial.print(" ");
  Serial.println(phi);

}

double convert(double acc) {
  double result;
  result = (1.4*acc)-3.5;
  return result;
}
