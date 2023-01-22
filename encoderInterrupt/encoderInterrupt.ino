int chanA = 2;
int chanB = 7; 
int encoderCount = 0;
int oldCount = 1;

void setup() {
  Serial.begin(9600);

  pinMode(chanA, INPUT_PULLUP);
  pinMode(chanB, INPUT); 
  
  attachInterrupt(digitalPinToInterrupt(chanA), rising, RISING);
}

void rising() {
  if (digitalRead(chanB) == 0){
    encoderCount++;
  }
  else {
    encoderCount--;
  }
}

void loop() {
  if (oldCount != encoderCount){
    Serial.println(encoderCount);
  }
  oldCount = encoderCount;
  if (Serial.available() != 0){
    encoderCount = Serial.parseInt();
  }
}
