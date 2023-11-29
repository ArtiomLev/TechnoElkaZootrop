void ButtonsSetup() 
{
  Timer2.enableISR(CHANNEL_B); //Установка выполнения кода по прерыванию
}

ISR(TIMER2_B) //Обработка нажатий кнопок
{
  if (digitalRead(TOUCH_BUTTON)) {
    if (status==0) {
      while (digitalRead(TOUCH_BUTTON)) delay(0);
      StartWork();
    }
  }
}

void StartWork() 
{
  #if ECONOMY_MODE==1
  LedStartAnimation2();
  #endif
  MotorStart(rotateSpeed,false);
  MP3PlayNum(2);
  RotateTimer.start();
  status = 1;
}