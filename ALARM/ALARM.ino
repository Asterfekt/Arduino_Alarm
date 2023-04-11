#define Buzzer A5
#define Hall_Sensor_Pin A0
void setup() {
  pinMode(Hall_Sensor_Pin, INPUT); // Czujnik Halla
  pinMode(Buzzer, OUTPUT);
}
void loop() {
  int i;
  float voltage;
  voltage = analogRead(Hall_Sensor_Pin);
   if (voltage <= 550)
  {
    delay(60000);
    if (voltage <= 550)
    {
      i = 1;
      while (i == 1)
      {
        tone(Buzzer, 1000); //Wygeneruj sygnał o częstotliwości 1000Hz na pinie A5
        delay(100);
        noTone(Buzzer);
        delay(100);
        delay(50);
        voltage = analogRead(Hall_Sensor_Pin);
        if (voltage >= 550)
        {
          i = 0;
        }
      }
      delay(250);
    }
    else
      i = 0;
  }
}
