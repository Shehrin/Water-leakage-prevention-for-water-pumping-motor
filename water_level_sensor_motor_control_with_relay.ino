const int relay1 = 2;
const int relay2 = 3;
int level = 0;
const int watersensor = A0;
const int buzzPin=8;

void setup() 
{
pinMode(buzzPin, OUTPUT);
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
Serial.begin(9600);
Serial.print("WATER LEVEL: ");
delay(2000);
}


void loop() 
{
level = analogRead(watersensor);
Serial.println(level);

delay(2000);

if (level<=100)
{
  Serial.println("Low ");
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  digitalWrite(buzzPin, LOW);


}

else if (level>100 && level<=450)
{
Serial.println("Almost High");
digitalWrite(buzzPin, HIGH);
}
else if (level>450)
{
Serial.println("High ");
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
digitalWrite(buzzPin, LOW);

}

delay(1000);
}