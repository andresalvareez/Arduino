int valor= 0;

void setup(){
  pinMode(13,OUTPUT);
  pinMode(11,INPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(13, HIGH);
  delay(1000);
  valor=digitalRead(11);
  Serial.println(valor);
  digitalWrite(13, LOW);
  delay(1000);
  valor=digitalRead(11);
  Serial.println(valor);
}
