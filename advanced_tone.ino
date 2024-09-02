#define   DURATION  500

int getInt(){
  String inString = "";
  
  while(Serial.available() <= 0){}
  
  for(;;){
    char inChar = Serial.read();
    if(isDigit(inChar)){
      inString += inChar;
    }
    if (inChar=='\n'){
      return inString.toInt();
    }
  }
}

int pin;

void setup() {
  Serial.begin(9600);
  while(!Serial){;}
  Serial.println("Enter the speaker pin.");
  pin = getInt();
  Serial.print("Setting speaker on D");
  Serial.println(pin);
}

void loop() {
  Serial.println("Enter the frequency.");
  int freq = getInt();

  Serial.print("Setting frequency to ");
  Serial.print(freq);
  Serial.println(" Herz.");
  
  tone(pin, freq, DURATION);
  
  delay(DURATION);
}
