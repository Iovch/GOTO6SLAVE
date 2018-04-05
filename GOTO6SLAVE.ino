// GOTO6SLAVE.ino Written by Igor Ovchinnikov 30/07/2016

#include <IRremote.h>
#include <Wire.h>

#define RECV_PIN   12 //Пин ИК приемника
#define SLAVE_ADDR 10 //Адрес I2C Slave устройства

IRrecv irrecv(RECV_PIN); //Создаем обработчик ИК сигнала
decode_results results;  //Переменная, хранящая результат

unsigned int iLastValue=0;
boolean bDebug=false;

//Этот файл должен находиться в той же директории, что основной GOTO6SLAVE.ino:

#include "IRduino.h"

void ReqEvent(void)
{
 Wire.write(iLastValue);
 if(bDebug) Serial.println(iLastValue); //Дублируем данные в СОМ порт при отладке
}

void setup()
{
  Wire.begin(SLAVE_ADDR);    // Создаем I2C Slave устройство
  Wire.onRequest(ReqEvent);  // Регистрируем функцию обработки запроса I2C
  if(bDebug) {Serial.begin(9600); Serial.flush();} // Подготавливаем СОМ порт для отладки
  irrecv.enableIRIn();       // Начинаем прием
}

void loop()
{
 unsigned int iValue=0;
 iValue=AskIRduino(); // Опрос 17 кнопочного пульта от Ардуино
 if(iValue!=50) iLastValue=iValue;
 if(bDebug){ ReqEvent(); }
 delay(125);
}
