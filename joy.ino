int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
int joyPin2 = 1;                 // slider variable connecetd to analog pin 1

int maxPosResistor = 255;
int minPosResistor = 0;

int motorPin1 = 9;
int motorPin2 = 10;


int x;
void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin1, OUTPUT); // Declare the output for one polarity of the motor driver
  pinMode(motorPin2, OUTPUT); // Declare the output for one polarity of the motor driver
  x = 0;
}

void loop() {
 int value1;
 int value2;
  // reads the value of the variable resistor 
  value1 = analogRead(joyPin1); 
  
  if(value1 < (maxPosResistor -minPosResistor) /2 ){//adds forward momentum
    digitalWrite(motorPin1, LOW);
    x+= value1;
    analogWrite(motorPin2, x);
  }
  else if(value1 > (maxPosResistor -minPosResistor) /2){//adds backword momentum
    digitalWrite(motorPin2, LOW);
    x+= value1;
    analogWrite(motorPin1, x);
  }
  else{// this code ramps it down
    if(x > 0){//kills forward momentum
      digitalWrite(motorPin1, LOW);
      x-= 1;
      analogWrite(motorPin2, x);
    }
    else{//kills backword momentum
      digitalWrite(motorPin2, LOW);
      x-= 1;
      analogWrite(motorPin1, x);
    }
    
  }

  
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(100);             
  // reads the value of the variable resistor 
  value2 = analogRead(joyPin2); 

 // add code for the moving up and down
}
