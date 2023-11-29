void TimersSetup()
{
  WorkTimer.attach(WorkTimerFunc);
  RotateTimer.attach(RotateTimerFunc);
}

void TimerTick()
{
  WorkTimer.tick();
  RotateTimer.tick();
}

void WorkTimerFunc() {
  MotorStart(rotateSpeed,false);
  StrobeEnable = false;
  MP3PlayNum(2);
  RotateTimer.start();
  status=3;
}

void RotateTimerFunc() {
  switch (status) {
    case 1:
      StrobeEnable = true;
      MotorStart(speed,false);
      MP3PlayNum(1);
      WorkTimer.start();
      status=2;
      break;
    case 3:
      MotorStop(false);
      MP3Stop();
      #if ECONOMY_MODE==1
      LedDisable();
      #endif
      status=0;
      break;
    default:
      MotorStop(false);
      break;
  }
}