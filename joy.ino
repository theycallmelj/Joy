int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
int joyPin2 = 1;                 // slider variable connecetd to analog pin 1

int motorP1 = 7;
int motorP2 = 8;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(joyPin1, INPUT); 
  
  pinMode(motorP1, OUTPUT); // Declare the output for one polarity of the motor driver

  
  pinMode(motorP2, OUTPUT); // Declare the output for one polarity of the motor driver

  
}

void loop() {
 int value1;
 //int value2;
 // reads the value of the variable resistor 
  value1 = analogRead(joyPin1);
  
  
 
  
  
  motorMovement(value1,motorP1, motorP2);
  
    
  

  
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  //delay(100);             
  
  
  
  
  //value2 = analogRead(joyPin2); 

 // add code for the moving up and down
}



  void motorMovement(int val, int motorPin1, int motorPin2){
    
    digitalWrite(8, HIGH);
    if(val > 500 && val < 515){// this code ramps it down
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin1, LOW);

    }
    
    if(val < 500){//adds forward momentum
     
      digitalWrite(motorPin2, HIGH);
      digitalWrite(motorPin1, LOW);
      
    
    }
    else if(val > 515){//adds backword momentum
      
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);

    
    
    }
    
  
  
}
