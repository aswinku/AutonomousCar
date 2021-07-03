int Aa = 0;
int Ab = 1;
int Ba = 2;
int Bb = 3;
int Ca = 4;
int Cb = 5;
int Da = 6;
int Db = 7;
int trigPin = 8;
int echoPin = 9;
int trigPin2 = 10;
int echoPin2 = 11;
int trigPin3 = 12;
int echoPin3 = 13;
long duration, duration2, duration3, cm, cm2, cm3, inches, inches2, inches3;

int Reverse = 0;
int cm3Pre = 0;


void setup() {
  // put your setup code here, to run once:
pinMode (Aa, OUTPUT);
pinMode (Ab, OUTPUT);
pinMode (Ba, OUTPUT);
pinMode (Bb, OUTPUT);
pinMode (Ca, OUTPUT);
pinMode (Cb, OUTPUT);
pinMode (Da, OUTPUT);
pinMode (Db, OUTPUT);
pinMode (trigPin, OUTPUT);
pinMode (echoPin, INPUT);
pinMode (trigPin2, OUTPUT);
pinMode (echoPin2, INPUT);
pinMode (trigPin3, OUTPUT);
pinMode (echoPin3, INPUT);
} 

void loop() {
  // put your main code here, to run repeatedly:
  //right
digitalWrite(trigPin, LOW);
delayMicroseconds (5);
digitalWrite(trigPin, HIGH);
delayMicroseconds (10);
digitalWrite(trigPin, LOW);

pinMode (echoPin, INPUT);
duration = pulseIn (echoPin, HIGH);

  //left
digitalWrite(trigPin2, LOW);
delayMicroseconds (5);
digitalWrite(trigPin2, HIGH);
delayMicroseconds (10);
digitalWrite(trigPin2, LOW);

pinMode (echoPin2, INPUT);
duration2 = pulseIn (echoPin2, HIGH);

  //front
digitalWrite(trigPin3, LOW);
delayMicroseconds (5);
digitalWrite(trigPin3, HIGH);
delayMicroseconds (10);
digitalWrite(trigPin3, LOW);

pinMode (echoPin3, INPUT);
duration3 = pulseIn (echoPin3, HIGH);


//right
cm = (duration/2) / 29.1;
inches = (duration/2) / 74;
//left
cm2 = (duration2/2) / 29.1;
inches2 = (duration2/2) / 74;
//front
cm3 = (duration3/2) / 29.1;
inches3 = (duration3/2) / 74;

Serial.print (inches);
Serial.print ("in, ");
Serial.print (cm);
Serial.print ("cm");
Serial.println ();

Serial.print (inches2);
Serial.print ("in, ");
Serial.print (cm2);
Serial.print ("cm");
Serial.println ();

Serial.print (inches3);
Serial.print ("in, ");
Serial.print (cm3);
Serial.print ("cm");
Serial.println ();

// if it is not going forward then go backward and turn
if (cm3Pre == cm3) {
    backward ();
    delay(500);
  if (cm2>30){
     left ();
     delay (500);
  }
  else if (cm>30){    
     right ();
     delay (500);
  }
  else {
	Reverse = 1;
  }
	
}
else {
	cm3Pre == cm3
    if (cm<30 && cm2<30 && cm3<30){
      backward ();
      Reverse = 1;
      delay(500);
    }
    else if (cm>30 && cm2>30 && cm3>30) {
      forward ();
	 Reverse = 0;
    }    
    else if (cm2>30 && cm3<30){
      backward ();
      delay(500);
      left ();
      Reverse = 0;
      delay (500);
    }
    else if (cm>30 && cm3<30){    
       backward ();
       delay(500);
       right ();
       Reverse = 0;
       delay (500);
   }
   else if (Reverse ==0){
       forward ();
   }
   else {
       backward ();
       delay (500);
   }

}
delay (250);

}

void forward() {
  digitalWrite (0, LOW);//back right
  digitalWrite (1, HIGH);
  digitalWrite (2, LOW); //back left
  digitalWrite (3, HIGH);
  digitalWrite (4, HIGH); //front left
  digitalWrite (5, LOW);
  digitalWrite (6, LOW); //front right
  digitalWrite (7, HIGH);
}
void sTop() {
  digitalWrite (0, LOW);//back right
  digitalWrite (1, LOW);
  digitalWrite (2, LOW);//back left
  digitalWrite (3, LOW);
  digitalWrite (4, LOW); //front left
  digitalWrite (5, LOW);
  digitalWrite (6, LOW); //front right
  digitalWrite (7, LOW);
}
void backward() {
  digitalWrite (0, HIGH); //back right
  digitalWrite (1, LOW);
  digitalWrite (2, HIGH);//back left
  digitalWrite (3, LOW);
  digitalWrite (4, LOW); //front left
  digitalWrite (5, HIGH);
  digitalWrite (6, HIGH); //front right
  digitalWrite (7, LOW);
}
void right() {
  digitalWrite (0, LOW); //back right
  digitalWrite (1, HIGH);
  digitalWrite (2, LOW);//back left
  digitalWrite (3, HIGH);
  digitalWrite (4, LOW); //front left
  digitalWrite (5, LOW);
  digitalWrite (6, LOW); //front right
  digitalWrite (7, HIGH);
}
void left() {
  digitalWrite (0, LOW); //back right
  digitalWrite (1, HIGH);
  digitalWrite (2, LOW);//back left
  digitalWrite (3, LOW);
  digitalWrite (4, HIGH); //front left
  digitalWrite (5, LOW);
  digitalWrite (6, LOW); //front right
  digitalWrite (7, LOW);
}
