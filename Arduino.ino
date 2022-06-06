#define FLAME 2 // connect DO pin of sensor to this pin
#define ALARM 8 // pin 8 for Alarm 


void setup() {
  Serial.begin(9600);
  Serial.println("Robojax.com Fire Module Test");
  pinMode(FLAME, INPUT);//define FLAME input pin
  pinMode(ALARM, OUTPUT);//define ALARM output pin
  // Flame sensor code for Robojax.com

}

void loop() {
    // Flame sensor code for Robojax.com

  int fire = digitalRead(FLAME);// read FLAME sensor


  if( fire == HIGH)
  {
    digitalWrite(ALARM,HIGH);// set the buzzer ON
    Serial.println("Fire! Fire!");
  }else{
    digitalWrite(ALARM,LOW); // Set the buzzer OFF
    Serial.println("Peace");
    // Flame sensor code for Robojax.com

  }




  delay(200);
}


 
