#include <Arduino.h>

// // example 1
// // Random
// // demonstrates generating random numbers

// int randNumber;

// void setup()
// {
//   Serial.begin(9600);
//   while (!Serial)
//     ;

//   // Print random numbers with no seed value
//   Serial.println("Print 20 random numbers between 0 and 9");
//   for (int i = 0; i < 20; i++)
//   {
//     randNumber = random(10);
//     Serial.print(randNumber);
//     Serial.print(" ");
//   }
//   Serial.println();
//   Serial.println("Print 20 random numbers between 2 and 9");
//   for (int i = 0; i < 20; i++)
//   {
//     randNumber = random(2, 10);
//     Serial.print(randNumber);
//     Serial.print(" ");
//   }

//   // Print random numbers with the same seed value each time
//   randomSeed(1234);
//   Serial.println();
//   Serial.println("Print 20 random numbers between 0 and 9 after constant seed ");
//   for (int i = 0; i < 20; i++)
//   {
//     randNumber = random(10);
//     Serial.print(randNumber);
//     Serial.print(" ");
//   }

//   // Print random numbers with a different seed value each time
//   randomSeed(analogRead(0)); // read from an analog port with nothing connected
//   Serial.println();
//   Serial.println("Print 20 random numbers between 0 and 9 after floating seed ");
//   for (int i = 0; i < 20; i++)
//   {
//     randNumber = random(10);
//     Serial.print(randNumber);
//     Serial.print(" ");
//   }
//   Serial.println();
//   Serial.println();
// }

// void loop()
// {
// }

// // example 2
// // bitFunctions
// // demonstrates using the bit functions

// byte flags = 0;

// // these examples set, clear, or read bits in a variable called flags

// // bitSet example
// void setFlag(int flagNumber)
// {
//    bitSet(flags, flagNumber);
// }

// // bitClear example
// void clearFlag(int flagNumber)
// {
//    bitClear(flags, flagNumber);
// }

// // bitPosition example

// int getFlag(int flagNumber)
// {
//    return bitRead(flags, flagNumber);
// }

// void showFlags();

// void setup()
// {
//   Serial.begin(9600);
// }

// void loop()
// {
//     flags = 0;   // clear all flags
//     showFlags();
//     setFlag(2);  // set some flags
//     setFlag(5);
//     showFlags();
//     clearFlag(2);
//     showFlags();

//     delay(10000); // wait a very long time
// }

// // reports flags that are set
// void showFlags()
// {
//     for(int flag=0; flag < 8; flag++)
//     {
//       if (getFlag(flag) == true)
//          Serial.print("* bit set for flag ");      else
//          Serial.print("bit clear for flag ");

//       Serial.println(flag);
//     }
//     Serial.println();
// }

// // example 3
// /*
//  * ByteOperators sketch
//  */

// int intValue = 258; // 258 in hexadecimal notation is 0x102

// void setup()
// {
//   Serial.begin(9600);
// }

// void loop()
// {
//   int loWord,hiWord;
//   byte loByte, hiByte;

//   hiByte = highByte(intValue);
//   loByte = lowByte(intValue);

//   Serial.println(intValue, DEC);
//   Serial.println(intValue, HEX);
//   Serial.println(loByte, DEC);
//   Serial.println(hiByte, DEC);

//   delay(10000); // wait a very long time
// }

// example 4
/*
 * Forming an int or long with byte operations sketch
 */

int intValue = 0x102;  // 258

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int aWord;
  byte loByte, hiByte;

  hiByte = highByte(intValue);
  loByte = lowByte(intValue);

  Serial.println(intValue, DEC);
  Serial.println(loByte, DEC);
  Serial.println(hiByte, DEC);

  aWord = word(hiByte, loByte); // convert the bytes back into a word
  Serial.println(aWord, DEC);
  delay(10000); // wait a very long time
}