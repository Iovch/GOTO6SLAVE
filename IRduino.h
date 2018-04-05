// IRduino.h Written by Igor Ovchinnikov 21/07/2016
// Команды штатного 17-ти кнопочного ИК пульта Ардуино
// скучновато
// #include <IRremote.h> //В заголовок основного файла

//int RECV_PIN = 12;        //В заголовок основного файла
//IRrecv irrecv(RECV_PIN);  //В заголовок основного файла
//decode_results results;   //В заголовок основного файла

//irrecv.enableIRIn(); // Это в Setup

unsigned int AskIRduino(void)
{
 unsigned int ulRetVal=0;
 if (irrecv.decode(&results))
  { 
    switch(results.value)
     {
      case 16736925: {ulRetVal=13; break;} // "^"
      case 16720605: {ulRetVal=14; break;} // "<"
      case 16712445: {ulRetVal=15; break;} // "Ok"
      case 16761405: {ulRetVal=16; break;} // ">"
      case 16754775: {ulRetVal=17; break;} // "v"
  
      case 16738455: {ulRetVal= 1; break;} // "1"
      case 16750695: {ulRetVal= 2; break;} // "2"
      case 16756815: {ulRetVal= 3; break;} // "3"
      case 16724175: {ulRetVal= 4; break;} // "4"
      case 16718055: {ulRetVal= 5; break;} // "5"
      case 16743045: {ulRetVal= 6; break;} // "6"
      case 16716015: {ulRetVal= 7; break;} // "7"
      case 16726215: {ulRetVal= 8; break;} // "8"
      case 16734885: {ulRetVal= 9; break;} // "9"
      case 16730805: {ulRetVal=10; break;} // "0"
      
      case 16728765: {ulRetVal=11; break;} // "*"
      case 16732845: {ulRetVal=12; break;} // "#"
      case 4294967295: {ulRetVal=50; break;} // "Cycle"
     }
//    ulRetVal=results.value;
    irrecv.resume();
  }
 return ulRetVal;
}
