int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
int joyPin2 = 1;                 // slider variable connecetd to analog pin 1

int maxPosResistor = 1023;
int minPosResistor = 0;

int motorP1 = 9;
int motorP2 = 10;
int slowDownAmt = 1;

int x;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(joyPin1, INPUT); 
  
  pinMode(motorP1, OUTPUT); // Declare the output for one polarity of the motor driver

  
  pinMode(motorP2, OUTPUT); // Declare the output for one polarity of the motor driver



   pinMode(8, OUTPUT); // Declare the output for one polarity of the motor driver
   pinMode(7, OUTPUT); // Declare the output for one polarity of the motor driver
  x = 0;
}

void loop() {
 int value1;
 int value2;
  // reads the value of the variable resistor 
  
  value1 = analogRead(joyPin1);
  //digitalWrite(13, HIGH);
  
  Serial.print("X axis: ");
  Serial.print(analogRead(joyPin1));
  
  
  motorPID(value1,motorP1, motorP2);
  
    
  

  
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(100);             
  // reads the value of the variable resistor 
  
  
  
  //value2 = analogRead(joyPin2); 

 // add code for the moving up and down
}



  void motorPID(int val, int motorPin1, int motorPin2){
    
    digitalWrite(8, HIGH);
    if(val > 500 && val < 515){// this code ramps it down
      //if(x > 0){//kills forward momentum
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);

         digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        
       // digitalWrite(motorPin1, LOW);
        x-= slowDownAmt;
       // analogWrite(motorPin2, x);
     // }
      /**
      else if(x < 0){//kills backword momentum
        digitalWrite(7, LOW);
       // digitalWrite(motorPin2, LOW);
        x-= slowDownAmt;
       // analogWrite(motorPin1, x);
      }
      **/
    }
    
    if(val < 500){//adds forward momentum
      //digitalWrite(motorPin1, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(7, LOW);

        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
      x+= val;
     // analogWrite(motorPin2, x);
    }
    else if(val > 515){//adds backword momentum
      
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);

      digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
     // digitalWrite(motorPin2, LOW);
      x+= val;
     // analogWrite(motorPin1, x);
    }
    
  
  
}
