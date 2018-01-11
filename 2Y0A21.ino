int i = 0;
unsigned int val = 0;
int IR = A0; //定義紅外線感測器在A0腳位
int LED = 13; //定義LED在A0腳位

void setup() {
    pinMode(IR, INPUT); //定義IR為輸入
    pinMode(LED, OUTPUT); //定義LED為輸出
    Serial.begin(9600);
}
void loop() {
    i=analogRead(IR); //讀取類比訊號
    val=(6762/(i-9))-4; //轉十進制運算式
    if (val <= 45) //如果讀值小於等於45CM,LED閃爍
    {
      digitalWrite(LED, HIGH);
      delay(100);
      digitalWrite(LED, LOW);
      delay(100);
    }
    else //若沒有小於45,關閉LED
    {
      digitalWrite(LED, LOW);
      delay(100);
    }
    Serial.print(val);
    Serial.println(" CM");
    delay(10);
}
