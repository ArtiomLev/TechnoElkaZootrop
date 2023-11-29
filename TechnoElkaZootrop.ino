//Подключение библиотек
#include <SoftwareSerial.h>
#include <GyverStepper2.h>
#include <GyverTimers.h>
#define COLOR_DEBTH 3
#include <microLED.h>
#include <TimerMs.h>

//Дефайны
#include "parameters.h"
#include "macro.h"

//Инициализация библиотек
GStepper2<STEPPER2WIRE> stepper(STEPS_PER_TURN*STEP_MULTIPLIER, STEP_PIN, DIR_PIN, EN_PIN);

TimerMs RotateTimer((long)SLOW_ROTATE_TIME*1000,false,1);
TimerMs WorkTimer((long)WORK_TIME*1000,false,1);

SoftwareSerial mp3(MP3_RX,MP3_TX);

microLED<LED_COUNT, LED_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_OFF> Backlight;


//Переменные
float currentSpeed = 0; //Текущая скорость (для функций ускорения)
float speed = WORK_SPEED; // Скорость рабочего вражения (обороты в минуту)
float rotateSpeed = ROTATE_SPEED; //Скорость медленного поворота (Обороты в минуту)
bool StrobeEnable = false; // Флаг включения стробоскопа
byte status = 0; // 0 - Сон, 1 - Первое медленное вращение, 2 - Работа, 3 - Второе медленное вращение, [4 - Блокировка (отключение всех функций; пока не реализовано)]

void setup() {
  Serial.begin(115200);

  //Инициализация пинов
  pinMode(STROBE_PIN,OUTPUT);
  pinMode(TOUCH_BUTTON,INPUT);

  stepper.disable();

  delay(1000);

  TimersSetup();

  MP3Setup();

  LedSetup();

  StrobeSetup();

  ButtonsSetup();

  StrobeTest(1000);

  MotorSetup();
}

void loop() {
  stepper.tick();
  TimerTick();
  LedWorker();
}

void yield() {
  stepper.tick();
}

// void varDebug() {
//    Serial.print("Speed: "+String(speed)+"\t");
//    Serial.print("StepSpeed: "+String(speedToSteps(speed))+"\t");
//    Serial.print("RotateSpeed: "+String(rotateSpeed)+"\t");
//    Serial.print("StepRotateSpeed: "+String(speedToSteps(rotateSpeed))+"\t");
//    Serial.print("Status: "+String(status)+"\t");
//    Serial.print("RotateTimer: "+String(RotateTimer.active())+"\t");
//    Serial.print("WorkTimer: "+String(WorkTimer.active())+"\t");
//    Serial.print("StrobeEnable: "+String(StrobeEnable)+"\t");

//    Serial.println("");
// }