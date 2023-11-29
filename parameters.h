//Пины драйвера
#define EN_PIN 3
#define DIR_PIN 4
#define STEP_PIN 5
//Пины кнопок
#define TOUCH_BUTTON 6
//Пины SoftwareSerial для MP3 модуля
#define MP3_RX 7
#define MP3_TX 8
//Пин для ШИМ света
#define STROBE_PIN 2
//Пин для адресной диодной ленты
#define LED_PIN 9
#define LED_COUNT 18


//Параметры мотора
#define STEP_MULTIPLIER 16 //Величина, обратная дроблению шагов: 1/4 => 4
#define STEPS_PER_TURN 200 //Шаги на оборот
#define ACCELERATION 10 //Измеряется в Шаг/с^2
#define WORK_SPEED 120 //Измеряется в оборотах/мин
#define ROTATE_SPEED 10 //Измеряется в оборотах/мин

//Настройки стробоскопа
#define PULSE_TIME 2 //Время импульса в милисекундах
#define FRAMES 24 //Количество кадров в секунду
#define FRAMES_MULTIPLIER 0.9695401 //Множитель количества кадров в секунду || Деревянный круг: | 120об - 0.742 | 240об - 0.947 | 180об - 0.695 (?) ||
// Меньще - вращение против часовой стрелки (по реальному вращению); Больше - вращение по часовой стрелке (против реального вращения)

//Нстройка подсветки
#define WORK_BRIGHTNESS 150

//Время
#define SLOW_ROTATE_TIME 12.8 //Время медленного вращения в секундах
#define WORK_TIME 39.8 //Время быстрого вращения со стробоскопом в секундах

//Время стартовых анимаций
#define SETUP_ANIMATION1_TIME 2000 //Время стартовой анимации диодной ленты в мс
#define SETUP_ANIMATION2_TIME 1500 //Время стартовой анимации диодной ленты в мс
#define WAITING_ANIMATION_SPEED //

//Музыкальный плеер
#define VOLUME 30

//Настройка
#define ECONOMY_MODE 0 //0 - Выкл (все функции включены), 1 - Вкл (некоторые функции не работают в спящем режиме)