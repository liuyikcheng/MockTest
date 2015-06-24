#include "Communication.h"
#include "Signal.h"
void sendBitHigh(int pinNo){
  setPinHigh(pinNo);
  setPinHigh(CLK_PIN);
  setPinLow(CLK_PIN);
}

void sendBitLow(int pinNo){
  setPinLow(pinNo);
  setPinHigh(CLK_PIN);
  setPinLow(CLK_PIN);
}

/**
 *@brief Perform write-to-read turnaround
 *@param pinNo is the pin to do turnaround
 *@steps  1) set IO pin as input
 *        2) set CLK to low
 *        3) set CLK to high
 */
void readTurnAroundIO(int pinNo){
  setPinToInput(pinNo);
  setPinLow(CLK_PIN);
  setPinHigh(CLK_PIN);
} 

/**
 *@brief Perform write-to-read turnaround
 *@param pinNo is the pin to do turnaround
 *@steps  1) set IO pin as output
 *        2) set CLK to high
 *        3) set CLK to low
 */
void writeTurnAroundIO(int pinNo){
  setPinToOutput(pinNo);
  setPinHigh(CLK_PIN);
  setPinLow(CLK_PIN);
}

uint8_t readBit(int pinNo){
  setPinLow(CLK_PIN);
  setPinHigh(CLK_PIN);
  return getPin(IO_PIN);
}

/**
 *@brief Perform write data
 *@param: cmd is the command value
 *        address is the address of data
 *        data is is the data value from PIC18
 *@steps  1) set IO pin as output
 *        2) set CLK to high
 *        3) set CLK to low
 *        4) send the value of data from LSB
 *        5) send the value of address from LSB
 *        6) send the value of cmd from LSB
 */
void writeData(uint8_t cmd, uint16_t address, uint8_t data){
  int i;
  uint8_t shifter;
  writeTurnAroundIO(IO_PIN);
  
  // send data
   for(i=0 ; i<8 ; i++){
    shifter = (data >> i) & 1;
	// printf("[%d]\n", shifter);
    if(shifter)
      sendBitHigh(IO_PIN);
    else
      sendBitLow(IO_PIN);
  }
  

  
  // send address
  for(i=0 ; i<16 ; i++){
    shifter = (address >> i) & 1;
    if(shifter)
      sendBitHigh(IO_PIN);
    else
      sendBitLow(IO_PIN);
  }
  
  // sent cmd
  for(i=0 ; i<8 ; i++){
    shifter = (cmd >> i) & 1;
    if(shifter)
      sendBitHigh(IO_PIN);
    else
      sendBitLow(IO_PIN);
  }


 }

 
 /**
 *@brief Perform write data
 *@param: cmd is the command value
 *        address is the address of data
 *@return data is is the data value from External device
 *@steps  1) set IO pin as output
 *        2) set CLK to high
 *        3) set CLK to low
 *        4) send the value of address from LSB
 *        5) send the value of cmd from LSB
 *        6) receive the data from external device
 */
uint8_t readData(uint8_t cmd, uint16_t address){
  int i;
  uint8_t shifter;
  uint8_t data;
  writeTurnAroundIO(IO_PIN);
  
  // send address
  for(i=0 ; i<16 ; i++){
    shifter = (address >> i) & 1;
    if(shifter)
      sendBitHigh(IO_PIN);
    else
      sendBitLow(IO_PIN);
  }
 
  // sent cmd
  for(i=0 ; i<8 ; i++){
    shifter = (cmd >> i) & 1;
    if(shifter)
      sendBitHigh(IO_PIN);
    else
      sendBitLow(IO_PIN);
  }
  
  readTurnAroundIO(IO_PIN);
  
  // read data

  for(i=0 ; i<8 ; i++)
    data = data|(readBit(IO_PIN) << i);
  
  return data;
}