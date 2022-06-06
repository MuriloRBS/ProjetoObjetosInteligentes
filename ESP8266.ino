
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Change the credentials below, so your ESP8266 connects to your router
char* ssid = "KEHRLE";
char* password = "11052830";

// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
char* mqtt_server = "192.168.15.14";

// Initializes the espClient. You should change the espClient name if you have multiple ESPs running in your home automation system
WiFiClient espClient22;
PubSubClient client(espClient22);


// Lamp - LED - GPIO 4 = D2 on ESP-12E NodeMCU board
int led = D1;
int led2 = D2;
int led3 = D3;
int led4 = D4;
int led5 = D5;
int led6 = D6;
int led7 = D7;
int led8 = D8;

//Connect your NodeMCU to your router
void setup_wifi() {
  delay(10);
  
  Serial.println();
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected - NodeMCU IP address: ");
  Serial.println(WiFi.localIP());
}

// This functions is executed when some device publishes a message to a topic that your NodeMCU is subscribed to

void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageInfo;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageInfo += (char)message[i];
  }
  Serial.println();

  // If a message is received on the topic room/lamp, you check if the message is either on or off. Turns the lamp GPIO according to the message
  if(topic=="room/light"){
      Serial.print("Changing Room Light to ");
      if(messageInfo == "on"){
        digitalWrite(led, LOW);
        Serial.print("On");
      }
      else if(messageInfo == "off"){
        digitalWrite(led, HIGH);
        Serial.print("Off");
      }
  }
   if(topic=="room2/light"){
      Serial.print("Changing Room Light to ");
      if(messageInfo == "on"){
        digitalWrite(led2, LOW);
        Serial.print("On");
      }
      else if(messageInfo == "off"){
        digitalWrite(led2, HIGH);
        Serial.print("Off");
      }
  }
   if(topic=="room3/light"){
      Serial.print("Changing Room Light to ");
      if(messageInfo == "on"){
        digitalWrite(led3, LOW);
        Serial.print("On");
      }
      else if(messageInfo == "off"){
        digitalWrite(led3, HIGH);
        Serial.print("Off");
      }
  }
   if(topic=="room4/light"){
      Serial.print("Changing Room Light to ");
      if(messageInfo == "on"){
        digitalWrite(led4, LOW);
        Serial.print("On");
      }
      else if(messageInfo == "off"){
        digitalWrite(led4, HIGH);
        Serial.print("Off");
      }
  }
   if(topic=="room5/light"){
      Serial.print("Changing Room Light to ");
      if(messageInfo == "on"){
        digitalWrite(led5, LOW);
        Serial.print("On");
      }
      else if(messageInfo == "off"){
        digitalWrite(led5, HIGH);
        Serial.print("Off");
      }
  }
   if(topic=="room6/light"){
      Serial.print("Changing Room Light to ");
      if(messageInfo == "on"){
        digitalWrite(led6, LOW);
        Serial.print("On");
      }
      else if(messageInfo == "off"){
        digitalWrite(led6, HIGH);
        Serial.print("Off");
      }
  }
    if(topic=="room7/light"){
      Serial.print("Changing Room Light to ");
      if(messageInfo == "on"){
        digitalWrite(led7, LOW);
        Serial.print("On");
      }
      else if(messageInfo == "off"){
        digitalWrite(led7, HIGH);
        Serial.print("Off");
      }
  }
    if(topic=="room8/light"){
      Serial.print("Changing Room Light to ");
      if(messageInfo == "on"){
        digitalWrite(led8, LOW);
        Serial.print("On");
      }
      else if(messageInfo == "off"){
        digitalWrite(led8, HIGH);
        Serial.print("Off");
      }
  }
  Serial.println();
}

// This functions reconnects your ESP8266 to your MQTT broker
// Change the function below if you want to subscribe to more topics with your ESP8266 
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    
    if (client.connect("ESP8266Client22")) {
      Serial.println("connected");  
      // Subscribe or resubscribe to a topic
      // You can subscribe to more topics (to control more LEDs in this example)
      client.subscribe("room/light");
      client.subscribe("room2/light");
      client.subscribe("room3/light");
      client.subscribe("room4/light");
      client.subscribe("room5/light");
      client.subscribe("room6/light");
      client.subscribe("room7/light");
      client.subscribe("room8/light");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

// The setup function sets your ESP GPIOs to Outputs, starts the serial communication at a baud rate of 115200
// Sets your mqtt broker and sets the callback function
// The callback function is what receives messages and actually controls the LEDs
void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

// For this project, you don't need to change anything in the loop function. Basically it ensures that the NodeMCU is connected to MQTT broker
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client22");

  }
