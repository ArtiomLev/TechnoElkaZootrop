//Стробоскоп
void StrobeSetup() //Стартовые настройки для стробоскопа
{
  Timer2.setPeriod(500); //Период в мкс
  Timer2.enableISR(CHANNEL_A); //Установка выполнения кода по прерыванию
}

void StrobeTest(int TimeMs) //Проверка стробоскопа (Указать время в мс)
{
  int ledTestTimer = millis();
  int lastTime = micros();
  bool StrobeEnFlag;
  while (millis()-ledTestTimer < 1000) {
    if (micros()-lastTime >= (1000*TimeMs)/(FRAMES*FRAMES_MULTIPLIER*speedBySecond(speed))) { 
      digitalWrite(STROBE_PIN,1); 
      lastTime = micros(); 
      StrobeEnFlag = true; 
    }
    if (micros()-lastTime >= PULSE_TIME*1000 && StrobeEnFlag == true) { 
      digitalWrite(STROBE_PIN,0); 
      StrobeEnFlag = false; 
    }
  }
}

ISR(TIMER2_A) 
{
  if (StrobeEnable) {
    static unsigned long lastTime;
    static bool StrobeEnFlag;
    if (micros()-lastTime >= 1000000/(FRAMES*FRAMES_MULTIPLIER*speedBySecond(speed))) { 
      digitalWrite(STROBE_PIN,1); 
      lastTime = micros(); 
      StrobeEnFlag = true; 
    }
    if (micros()-lastTime >= PULSE_TIME*1000 && StrobeEnFlag == true) { 
      digitalWrite(STROBE_PIN,0); 
      StrobeEnFlag = false; 
    }
  } else {
    if (digitalRead(STROBE_PIN)) digitalWrite(STROBE_PIN,0);
  }
}

//Адресная лента
void LedSetup()
{
  Backlight.setBrightness(WORK_BRIGHTNESS);
  
  LedStartAnimation1();

  LedStartAnimation2();

  #if ECONOMY_MOD==1
  delay(500);
  LedDisable();
  #endif
}

void LedDisable() 
{
  delay(1);
  Backlight.clear();
  Backlight.show();
}

void LedStartAnimation1()
{
  Backlight.clear();
  Backlight.show();
  delay(1);
  for (int i=0 ; i<LED_COUNT ; i++) 
  {
    Backlight.set(i, mRGB(0, 191, 255));
    Backlight.show();
    delay(SETUP_ANIMATION1_TIME/LED_COUNT);
  }
}

void LedStartAnimation2()
{
  Backlight.clear();
  Backlight.show();
  Backlight.fill(mRGB(0, 191, 255));
  Backlight.setBrightness(0);
  for (int i=1 ; i<=WORK_BRIGHTNESS ; i++) 
  {
    Backlight.setBrightness(i);
    Backlight.show();
    delay(SETUP_ANIMATION2_TIME/255);
  }
}

void LedWaitAnimation()
{
  
}

void LedSlowRotateAnimation() 
{

}

void LedWorkAnimation()
{

}

void LedWorker()
{
  switch (status) {
    case 0:
      #if ECONOMY_MODE==1
      #else
        LedWaitAnimation();
      #endif
      break;
    case 1:
      LedSlowRotateAnimation();
      break;
    case 2:
      LedWorkAnimation();
      break;
    case 3:
      LedSlowRotateAnimation();
      break;
    case 4:
      Backlight.setBrightness(150);
      Backlight.fill(mRGB(255, 0, 0));
      Backlight.show();
      delay(1);
      break;
    default:
      Backlight.clear();
      Backlight.show();
      delay(1);
      break;
  }
}
