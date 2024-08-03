// Jubran Khoury 

#define LED1 8
#define LED2 9
#define LED3 10
#define TRIG 7
#define ECHO 6

float distance, duration;

void setup()
{
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(TRIG, OUTPUT);
	pinMode(ECHO, INPUT);
  
    Serial.begin(9600);  
}

void loop()
{
  	digitalWrite(TRIG, LOW);  
	delayMicroseconds(2);  
	digitalWrite(TRIG, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(TRIG, LOW);
    duration = pulseIn(ECHO, HIGH);
    distance = (duration*.0343)/2;

    if (distance < 10){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
    }
  
    else if (distance >= 10 && distance < 20){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
    }
  
    else if (distance >= 20 && distance < 30){
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }
  
    else{
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
    }
  
 	Serial.print("Distance: ");  
	Serial.println(distance);  
	delay(300);  

}
