//Макро функции
#define speedBySecond(x) (x/60) //Преобразовать скорость в обороты/c
//#define speedToSteps(x) (x/60)*STEPS_PER_TURN //Преобразовать скорость в количество шагов в секунду
#define speedToSteps(x) (x/60)*STEPS_PER_TURN*STEP_MULTIPLIER //Преобразовать скорость в количество шагов в секунду