//Intensity numbers for each color for the led
int red = 0;
int blue = 0;
int green = 0;

void setup() {
  // put your setup code here, to run once
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

   while (Serial.available()){
     //Stores recieved data in variable data
     int data = Serial.read();
   
     //tests for given value then changes the voltage on the red, green, or blue pin
     if(data == 0){
       red = changeIntensity(5, red);
       analogWrite(11, red);
     }
     if(data == 1){
       red = changeIntensity(-5, red);
       analogWrite(11, red);
     }
     if(data == 2){
       green = changeIntensity(5, green);
       analogWrite(10, green);
     }
     if(data == 3){
       green = changeIntensity(-5, green);
       analogWrite(10, green);
     }
     if(data == 4){
       blue = changeIntensity(5, blue);
       analogWrite(9, blue);
     }
     if(data == 5){
       blue = changeIntensity(-5, blue);
       analogWrite(9, blue);
     }

     //updates data on request]
     if (data == 6){
      updateData();
     }
   }
}

int changeIntensity(int amount, int color){
  //changes intensity value
  color = color + amount;
    
  // test to make sure intensity is > 0
  if(color < 0){
    color = 0;
  }

  // test to make sure intensity is < 255
  else if(color > 255){
    color = 255;
  }
  return color;
}

void updateData(){
  Serial.write(red);
  Serial.write(green);
  Serial.write(blue);
}


