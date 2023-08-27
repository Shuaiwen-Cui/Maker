// always keep this one
#include <Arduino.h>

// // example 1
// // The setup() method runs once, when the sketch starts
// void setup()
// {
//   pinMode(LED_BUILTIN, OUTPUT); // initialize the onboard LED as an output
// }

// // the loop() method runs over and over again,
// void loop()
// {
//   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on
//   delay(1000);                       // wait a second
//   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off
//   delay(1000);                       // wait a second
// }

// // example 2
// /*
//  * Floating-point example
//  * This sketch initialized a float value to 1.1
//  * It repeatedly reduces the value by 0.1 until the value is 0
//  */
// bool almostEqual(float a, float b);

// float value = 1.1;

// void setup()
// {
//   Serial.begin(9600);
// }

// void loop()
// {
//   value = value - 0.1;   // reduce value by 0.1 each time through the loop
//   if( value == 0)
//   {
//      Serial.println("The value is exactly zero");
//   }
//   else if(almostEqual(value, 0))
//   {
//     Serial.print("The value ");
//     Serial.print(value,7); // print to 7 decimal places
//     Serial.println(" is almost equal to zero, restarting countdown");
//     value = 1.1;
//   }
//   else
//   {
//     Serial.println(value);
//   }
//   delay(250);
// }

// // returns true if the difference between a and b is small
// bool almostEqual(float a, float b)
// {
//   const float DELTA = .00001; // max difference to be almost equal
//   if (a == 0) return fabs(b) <= DELTA;
//   if (b == 0) return fabs(a) <= DELTA;
//   return fabs((a - b) / max(fabs(a), fabs(b))) <= DELTA; // scaling is a good idea here
// }

// // example 3
// /*
//  array sketch
//  an array of switches controls an array of LEDs
//  see Chapter 5 for more on using switches
//  see Chapter 7 for information on LEDs
//  */

// int inputPins[] = {2, 3, 4, 5}; // create an array of pins for switch inputs

// int ledPins[] = {10, 11, 12, 13}; // create array of output pins for LEDs

// void setup()
// {
//   for (int index_new = 0; index_new < 4; index_new++)
//   {
//     pinMode(ledPins[index_new], OUTPUT);         // declare LED as output
//     pinMode(inputPins[index_new], INPUT_PULLUP); // declare as input
//   }
// }

// void loop() {
//   for (int index_new = 0; index_new < 4; index_new++)
//   {
//     int val = digitalRead(inputPins[index_new]);  // read input value
//     if (val == LOW)                           // check if the switch is pressed
//     {
//       digitalWrite(ledPins[index_new], HIGH); // LED on if switch is pressed
//     }
//     else
//     {
//       digitalWrite(ledPins[index_new], LOW);  // turn LED off
//     }
//   }
// }

// // example 4
// /*
//   Basic_Strings sketch
//  */

// String text1 = "This text";
// String text2 = " has more characters";
// String text3; // to be assigned within the sketch

// void setup()
// {
//   Serial.begin(9600);
//   while (!Serial)
//     ; // Wait for serial port (Leonardo, 32-bit boards)

//   Serial.print("text1 is ");
//   Serial.print(text1.length());
//   Serial.println(" characters long.");

//   Serial.print("text2 is ");
//   Serial.print(text2.length());
//   Serial.println(" characters long.");

//   text1.concat(text2);
//   Serial.println("text1 now contains: ");
//   Serial.println(text1);

//   text3 = text1 + " and more";
//   Serial.println(text3);
// }

// void loop()
// {
// }

// example 5
// #include <string.h>

// char stringA[8]; // declare a string of up to 7 chars plus terminating null
// char stringB[8]  = "Arduino"; // as above and initialize the string to "Arduino"
// char stringC[16] = "Arduino"; // as above, but string has room to grow
// char stringD[ ]  = "Arduino"; // the compiler inits string and calculates size

// int length = strlen(string);  // return the number of characters in the string

// // example 6
// /*
//  * SplitSplit sketch
//  * split a comma-separated string
//  */

// String  text = "Peter,Paul,Mary";  // an example string
// String  message = text; // holds text not yet split
// int     commaPosition;  // the position of the next comma in the string

// void setup()
// {
//   Serial.begin(9600);
//   while(!Serial); // Wait for serial port (Leonardo, 32-bit boards)

//   Serial.println(message); // show the source string
//   do
//   {
//     commaPosition = message.index_newOf(',');
//     if(commaPosition != -1)
//     {
//       Serial.println( message.substring(0,commaPosition));
//       message = message.substring(commaPosition+1, message.length());
//     }
//     else
//     { // here after the last comma is found
//       if(message.length() > 0)
//         Serial.println(message);  // if there is text after the last comma,
//                                   // print it
//     }
//     delay(2000);
//    }
//    while(commaPosition >=0);
// }

// void loop()
// {
// }

// // example 7
// /*
//  * strtok sketch
//  * split a comma-separated string
//  */

// const int  MAX_STRING_LEN = 20; // set this to the largest string
//                                 // you will process

// char stringList[] = "Peter,Paul,Mary"; // an example string

// char stringBuffer[MAX_STRING_LEN+1]; // static buffer for computation/output

// void setup()
// {
//   Serial.begin(9600);
//   while(!Serial); // Wait for serial port (Leonardo, 32-bit boards)

//   char *str;
//   char *p;
//   strncpy(stringBuffer, stringList, MAX_STRING_LEN); // copy source string
//   Serial.println(stringBuffer);                      // show the source string

//   for( str = strtok_r(stringBuffer, ",", &p);        // split using comma
//        str;                                          // while str is not null
//        str = strtok_r(NULL, ",", &p)                 // get subsequent tokens
//      )
//   {
//     Serial.println(str);
//   }
// }

// void loop()
// {
// }

// // example 8
// String myNumber = String(1234);

// int value = 127;
// String myReadout = "The reading was ";
// myReadout.concat(value);

// int value = 127;
// String myReadout = "The reading was ";
// myReadout += value;

// // example 9
// /*
//  * NumberToString
//  * Creates a string from a given number
//  */

// char buffer[12];  // long data type has 11 characters (including the
//                   // minus sign) and a terminating null

// void setup()
// {
//   Serial.begin(9600);
//   while(!Serial);

//   long value = 12345;
//   ltoa(value, buffer, 10);

//   Serial.print( value);
//   Serial.print(" has  ");
//   Serial.print(strlen(buffer));
//   Serial.println(" digits");

//   value = 123456789;
//   ltoa(value, buffer, 10);

//   Serial.print( value);
//   Serial.print(" has  ");
//   Serial.print(strlen(buffer));
//   Serial.println(" digits");
// }

// void loop()
// {
// }

// // example 10
// /*
//  * StringToNumber
//  * Creates a number from a string
//  */

// int   blinkDelay;     // blink rate determined by this variable
// char strValue[6];     // must be big enough to hold all the digits and the
//                       // 0 that terminates the string
// int index_new = 0;        // the index_new into the array storing the received digits

// void blink();

// void setup()
// {
//  Serial.begin(9600);
//  pinMode(LED_BUILTIN, OUTPUT); // enable LED pin as output
// }

// void loop()
// {
//   if( Serial.available())
//   {
//     char ch = Serial.read();
//     if(index_new < 5 && isDigit(ch) ){
//       strValue[index_new++] = ch; // add the ASCII character to the string;
//     }
//     else
//     {
//       // here when buffer full or on the first nondigit
//       strValue[index_new] = 0;        // terminate the string with a 0
//       blinkDelay = atoi(strValue);  // use atoi to convert the string to an int
//       index_new = 0;
//     }
//   }
//   blink();
// }

// void blink()
// {
//    digitalWrite(LED_BUILTIN, HIGH);
//    delay(blinkDelay/2);  // wait for half the blink period
//    digitalWrite(LED_BUILTIN, LOW);
//    delay(blinkDelay/2);  // wait for the other half
// }