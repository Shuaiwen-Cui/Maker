#include <Arduino.h>

// this chapter focuses on serial communication



// // example 4-1: Serial output
// /*
//  * SerialOutput sketch
//  * Print numbers to the serial port
// */
// void setup()
// {
//   Serial.begin(9600); // send and receive at 9600 baud
// }

// int number = 0;

// void loop()
// {
//   Serial.print("The number is ");
//   Serial.println(number);    // print the number

//   delay(500); // delay half second between numbers
//   number++; // to the next number
// }

// // example 4-2: Sending Formatted Text and Numeric Data from Arduino
// /*
//   SerialFormatting
//   Print values in various formats to the serial port
// */
// char chrValue  = 65;  // these are the starting values to print
// byte byteValue = 65;
// int intValue   = 65;
// float floatValue = 65.0;

// void setup()
// {
//   while(!Serial); // Wait until serial port's open on Leonardo and SAMD boards
//   Serial.begin(9600);
// }

// void loop()
// {
//   Serial.print("chrValue:   ");
//   Serial.print(chrValue); Serial.print(" ");
//   Serial.write(chrValue); Serial.print(" ");
//   Serial.print(chrValue, DEC);
//   Serial.println();

//   Serial.print("byteValue:  ");
//   Serial.print(byteValue); Serial.print(" ");
//   Serial.write(byteValue); Serial.print(" ");
//   Serial.print(byteValue, DEC);
//   Serial.println();

//   Serial.print("intValue:   ");
//   Serial.print(intValue); Serial.print(" ");
//   Serial.print(intValue, DEC); Serial.print(" ");
//   Serial.print(intValue, HEX); Serial.print(" ");
//   Serial.print(intValue, OCT); Serial.print(" ");
//   Serial.print(intValue, BIN);
//   Serial.println();

//   Serial.print("floatValue: ");
//   Serial.println(floatValue);
//   Serial.println();

//   delay(1000); // delay a second between numbers
//   chrValue++;  // to the next value
//   byteValue++;
//   intValue++;
//   floatValue += 1;
// }

// // example 4-3: Receiving Serial Data in Arduino
// /*
//  * SerialReceive sketch
//  * Blink the LED at a rate proportional to the received digit value
// */
// int blinkDelay = 0;  // blink delay stored in this variable

// void blink();

// void setup()
// {
//   Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
//   pinMode(LED_BUILTIN, OUTPUT); // set this pin as output
// }

// void loop()
// {
//   if (Serial.available()) // Check to see if at least one character is available
//   {
//     char ch = (char) Serial.read();
//     if( isDigit(ch) ) // is this an ASCII digit between 0 and 9?
//     {
//       blinkDelay = (ch - '0');       // ASCII value converted to numeric value
//       blinkDelay = blinkDelay * 100; // actual delay is 100 ms *" received digit
//     }
//   }
//   blink();
// }

// // blink the LED with the on and off times determined by blinkDelay
// void blink()
// {
//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(blinkDelay); // delay depends on blinkDelay value
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(blinkDelay);
// }

// // example 4-4: Sending and Receiving Serial Data in Arduino
// /*
// * SerialParsing sketch
// * Blink the LED at a rate proportional to the received digit value
// */

// int blinkDelay = 0;
// void blink();

// void setup()
// {
//   Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
//   pinMode(LED_BUILTIN, OUTPUT); // set this pin as output
// }

// void loop()
// {
//   if ( Serial.available()) // Check to see if at least one character is available
//   {
//     int i = Serial.parseInt();
//     if (i != 0) {
//         blinkDelay = i;
//     }
//   }
//   blink();
// }

// // blink the LED with the on and off times determined by blinkDelay
// void blink()
// {
//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(blinkDelay); // delay depends on blinkDelay value
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(blinkDelay);
// }

// // example 4-5: Sending and Receiving Serial Data in Arduino
// int blinkDelay = 0;
// const int maxChars = 5;    // an int string contains up to 5 digits and
//                            // is terminated by a 0 to indicate end of string
// char strValue[maxChars+1]; // must be big enough for digits and terminating null
// int idx = 0;               // index into the array storing the received digits
// void blink();

// void setup()
// {
//   Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
//   pinMode(LED_BUILTIN, OUTPUT); // set this pin as output
// }

// void loop()
// {
//   if( Serial.available())
//   {
//     char ch = (char) Serial.read();
//     if( idx < maxChars && isDigit(ch) ){
//       strValue[idx++] = ch; // add the ASCII character to the string;
//     }
//     else
//     {
//       // here when buffer full or on the first nondigit
//       strValue[idx] = 0;           // terminate the string with a 0
//       blinkDelay = atoi(strValue); // use atoi to convert the string to an int
//       idx = 0;
//     }
//   }
//   blink();
// }

// void blink()
// {
//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(blinkDelay); // delay depends on blinkDelay value
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(blinkDelay);
// }

// // example 4-6: Sending and Receiving Serial Data in Arduino

// /*
//  * SerialEvent Receive sketch
//  * Blink the LED at a rate proportional to the received digit value
//  */
// int blinkDelay = 0;     // blink delay stored in this variable
// void blink();

// void setup()
// {
//   Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
//   pinMode(LED_BUILTIN, OUTPUT); // set this pin as output
// }

// void loop()
// {
//   blink();
// }

// void serialEvent()
// {
//   while(Serial.available())
//   {
//     char ch = (char) Serial.read();
//     Serial.write(ch);
//     if( isDigit(ch) ) // is this an ASCII digit between 0 and 9?
//     {
//       blinkDelay = (ch - '0');       // ASCII value converted to numeric value
//       blinkDelay = blinkDelay * 100; // actual delay is 100 ms times digit
//     }
//   }
// }

// // blink the LED with the on and off times determined by blinkDelay
// void blink()
// {
//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(blinkDelay); // delay depends on blinkDelay value
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(blinkDelay);
// }

// // example 4-7: Sending Multiple Text Fields from Arduino in a Single Message
// // CommaDelimitedOutput sketch

// void setup()
// {
//   Serial.begin(9600);
// }

// void loop()
// {
//   int value1 = 10;    // some hardcoded values to send
//   int value2 = 100;
//   int value3 = 1000;

//   Serial.print('H'); // unique header to identify start of message
//   Serial.print(",");
//   Serial.print(value1,DEC);
//   Serial.print(",");
//   Serial.print(value2,DEC);
//   Serial.print(",");
//   Serial.print(value3,DEC);
//   Serial.println();  // send a carriage return and line feed
//   delay(100);
// }

// // Processing Sketch to read comma delimited serial
// // expects format: H,1,2,3

// import processing.serial.*;

// Serial myPort;        // Create object from Serial class
// char HEADER = 'H';    // character to identify the start of a message
// short LF = 10;        // ASCII linefeed

// // WARNING!
// // If necessary change the definition below to the correct port
// short portIndex = 0;  // select the com port, 0 is the first port

// void setup() {
//   size(200, 200);
//   println( (Object[]) Serial.list());
//   println(" Connecting to -> " + Serial.list()[portIndex]);
//   myPort = new Serial(this, Serial.list()[portIndex], 9600);
// }

// void draw() {
//   if (myPort.available() > 0) {

//     String message = myPort.readStringUntil(LF); // read serial data
//     if (message != null)
//     {
//       message = message.trim(); // Remove whitespace from start/end of string
//       println(message);
//       String [] data = message.split(","); // Split the comma-separated message
//       if (data[0].charAt(0) == HEADER && data.length == 4) // check validity
//       {
//         for (int i = 1; i < data.length; i++) // skip header (start at 1, not 0)
//         {
//           println("Value " +  i + " = " + data[i]);  // Print the field values
//         }
//         println();
//       }
//     }
//   }
// }

/*
 * SerialReceiveMultipleFields sketch
 * This code expects a message in the format: H,12,345,678
 * This code requires a newline character to indicate the end of the data
 * Set the serial monitor to send newline characters
 */

const int NUMBER_OF_FIELDS = 3; // how many comma separated fields we expect
int values[NUMBER_OF_FIELDS];   // array holding values for all the fields

void setup()
{
  Serial.begin(9600); // Initialize serial port to send and receive at 9600 baud
}

void loop()
{
  if ( Serial.available())
  {
    if (Serial.read() == 'H') {

      // Read the values
      for (int i = 0; i < NUMBER_OF_FIELDS; i++)
      {
        values[i] = Serial.parseInt();
      }

      // Display the values in comma-separated format
      Serial.print(values[0]); // First value

      // Print the rest of the values with a leading comma
      for (int i = 1; i < NUMBER_OF_FIELDS; i++)
      {
        Serial.print(","); Serial.print(values[i]);
      }
      Serial.println();
    }
  }
}