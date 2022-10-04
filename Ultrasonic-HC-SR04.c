int trig = 5;
int echo = 6;

float duration;
int distance;
int Length;
int door_Height =200;

void setup() 
{
  Serial.begin (9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
void loop() 
{
  digitalWrite(trig, LOW);        
  delayMicroseconds(2);              
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);           
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  Length =  door_Height - distance;
  Serial.println("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println("Length: ");
  Serial.print(Length);
  Serial.println(" cm");
  delay(4000);
}
