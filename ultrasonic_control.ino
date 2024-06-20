#include <Ultrasonic.h>

const int trigPinUpDown = 2;  
const int echoPinUpDown = 3; 
const int trigPinLeftRight = 4;  
const int echoPinLeftRight = 5; 

Ultrasonic ultrasonicUpDown(trigPinUpDown, echoPinUpDown);
Ultrasonic ultrasonicLeftRight(trigPinLeftRight, echoPinLeftRight);

long duration;
int distanceUpDown, distanceLeftRight;
unsigned long temp = 0;

void find_distances(void);

void setup()
{
  Serial.begin(9600);
  pinMode(trigPinUpDown, OUTPUT);
  pinMode(echoPinUpDown, INPUT);
  pinMode(trigPinLeftRight, OUTPUT);
  pinMode(echoPinLeftRight, INPUT);
  delay(1000);
}

void loop()
{
  find_distances();

  

  if (distanceUpDown <= 40 && distanceUpDown >= 20)
  {
    delay(2000);
    find_distances();
    if (distanceUpDown <= 20 && distanceUpDown >= 0)
    {
      Serial.println("down");
      
      Serial.println(distanceUpDown);
    }
  }

  if (distanceUpDown <= 20 && distanceUpDown >= 0)
  {
    delay(2000);
    find_distances();
    if (distanceUpDown <= 40 && distanceUpDown >= 20)
    {
      Serial.println("up");
      // Send distance data to Python script
      Serial.println(distanceUpDown);
    }
  }

  if (distanceLeftRight <= 40 && distanceLeftRight >= 20)
  {
    delay(2000);
    find_distances();
    if (distanceLeftRight <= 20 && distanceLeftRight >= 0)
    {
      Serial.println("left");
      
      Serial.println(distanceLeftRight);
    }
  }

  if (distanceLeftRight <= 20 && distanceLeftRight >= 0)
  {
    delay(2000);
    find_distances();
    if (distanceLeftRight <= 40 && distanceLeftRight >= 20)
    {
      Serial.println("right");
      
      Serial.println(distanceLeftRight);
    }
  }
}

void find_distances(void)
{
  distanceUpDown = ultrasonicUpDown.read();
  distanceLeftRight = ultrasonicLeftRight.read();
  delay(100); 
}