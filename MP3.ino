static uint8_t cmdbuf[8] = {0}; //Буфер байтов для отправки на плеер
void MP3Command(int8_t cmd, int8_t Para_MSB, int8_t Para_LSB) //Отправить команду на плеер
{
  cmdbuf[0] = 0x7e;
  cmdbuf[1] = 0xFF;
  cmdbuf[2] = 0x06;
  cmdbuf[3] = cmd;
  cmdbuf[4] = 0x00;
  cmdbuf[5] = Para_MSB;
  cmdbuf[6] = Para_LSB;
  cmdbuf[7] = 0xef;
  for (uint8_t i = 0; i < 8; i++)
   {
   mp3.write(cmdbuf[i]);
   Serial.write(cmdbuf[i]);
   }
}

void MP3Setup() //Стартовая настройка для использования модуля
{
  mp3.begin(9600);

  MP3Command(0x07, 0, 0); //Эквалайзер
  MP3SetVolume(VOLUME);
  MP3Stop();
  //MP3PlayNum(3);
  //MP3PlayFolderNum(1,3);
}

void MP3SetVolume(int level) //Установка уровня громкости
{
  if (level > 30) level=30;
  if (level < 0) level=0; 
  MP3Command(0x06, 0, level); //Громкость
}

void MP3PlayNum(int number) //Запуск файла из папки MP3 по номеру
{
  byte firstNum = number / 100;
  byte secondNum = number % 100;
  MP3Command(0x12, firstNum, secondNum); //Запуск проигрывания файла из папки MP3
}

void MP3PlayFolderNum(int folder, int number) //Запуск файла из папки MP3 по номеру
{
  MP3Command(0x0F, folder, number); //Запуск проигрывания файла из папки MP3
}

void MP3Play() 
{
  MP3Command(0x0D, 0, 0);
}

void MP3Pause() 
{
  MP3Command(0x0E, 0, 0);
}

void MP3Stop() 
{
  MP3Command(0x16, 0, 0);
}

void MP3Sleep() 
{
  MP3Command(0x0A, 0, 0);
}

void MP3Awake() 
{
  MP3Command(0x0B, 0, 0);
}