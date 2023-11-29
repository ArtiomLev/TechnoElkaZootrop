void MotorSetup() //Стартовая настройка мотора
{
  stepper.setAcceleration(ACCELERATION);
  stepper.enable();
}

void MotorStart(float speed, bool accel) //Запуск мотора (speed - скорость об/c; true/false - вкл/выкл ускорение)
{
  if (accel) {
    if (currentSpeed < speed) {

    } else if (currentSpeed == speed) {

    } else {
      
    }
  } else {
    stepper.enable();
    stepper.setSpeed(speedToSteps(speed));
  }
}

void MotorStop(bool accel) //Остановка мотора (true/false - вкл/выкл ускорение)
{ 
  if (accel) {
    
    
    
  } else {
    stepper.setSpeed(0);
    stepper.disable();
  }
}