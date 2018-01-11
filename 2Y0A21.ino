int i = 0;
int val = 0;
int IR = A0;
int LED = 13;

void setup() {
    pinMode(IR, INPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}
void loop() {
    i=analogRead(IR);
    val=(6762/(i-9))-4;
    if (val <= 45)
    {
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
      delay(100);
    }
    else
    {
      digitalWrite(LED, LOW);
      delay(100);
    }
    Serial.print(val);
    Serial.println(" CM");
    delay(10);
}
