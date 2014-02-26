
float theta = 0.0;  // Start angle at 0
float amplitude = 255;//75.0;  // Height of wave
float dx;  // Value for incrementing X, a function of period and xspacing
float yvalues[12];

int  LED[12] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

int numLed = 12;

void setup() {

  Serial.begin(9600); 
  for (int thisPin = 0; thisPin < numLed; thisPin++)  {
    pinMode(LED[thisPin], OUTPUT);      
  }

}

void loop() {
  dx = (TWO_PI / numLed);// * xspacing;
  
  // first analog input
  int val = analogRead(A0);
  
  // second analog input
  int val2 = analogRead(A1);

  calcWave(val, val2/4);
  //Serial.println(val);

  renderWave();
}

void calcWave(int val, int amplitude) {
  // Increment theta (try different values for 'angular velocity' here
   // val = map(val, 0, 1024, 0, 1);
  float data = val; 
   // theta += 0.05;
  theta += data/1024;
  Serial.println(theta);

  // For every x value, calculate a y value with sine function
  float x = theta;
  for (int i = 0; i < numLed; i++) {
    yvalues[i] = abs(sin(x)*amplitude);
    
    x+=dx;
  }
}

void renderWave() {

  // A simple way to draw the wave with an ellipse at each location
  for (int x = 0; x < numLed; x++) {
    float h = yvalues[x]; 
    analogWrite(LED[x], h);



    //    Serial.print("anlogWrite(");
    //    Serial.print(LED[x]);
    //    Serial.print("),");
    //    Serial.print(h);
    //    Serial.println(");");

    delay(3);
//    delayMicroseconds(10);  
  }
}




