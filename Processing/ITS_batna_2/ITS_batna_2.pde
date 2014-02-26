int xspacing = 50;   // How far apart should each horizontal location be spaced
int w;              // Width of entire wave

float theta = 0.0;  // Start angle at 0
float amplitude = 255;//75.0;  // Height of wave
float period = 500.0;  // How many pixels before the wave repeats
float dx;  // Value for incrementing X, a function of period and xspacing
float[] yvalues;  // Using an array to store height values for the wave

void setup() {
  size(1000, 200);
  w = width;
  
  yvalues = new float[22];//[w/xspacing];
}

void draw() {
  dx = (TWO_PI / mouseX);// * xspacing;
  background(0);
  calcWave();
  renderWave();
  println(yvalues.length);
}

void calcWave() {
  // Increment theta (try different values for 'angular velocity' here
  theta += 0.02;

  // For every x value, calculate a y value with sine function
  float x = theta;
  for (int i = 0; i < yvalues.length; i++) {
      yvalues[i] = abs(sin(x)*amplitude);
   
    x+=dx;
    //println(yvalues[i]);
    //  x = x + mouseX/10;//dx;
  }
}

void renderWave() {
  noStroke();

  // A simple way to draw the wave with an ellipse at each location
  for (int x = 0; x < yvalues.length; x++) {
    float h = abs(yvalues[x]); 
    fill(h);
    println(h);
    // ellipse(i*width/led.length+11, height/2, 30, 30);
    ellipse(x*xspacing, height/2, 30, 30);
//    ellipse(x*xspacing, height/2+yvalues[x], 16, 16);
  }
}

