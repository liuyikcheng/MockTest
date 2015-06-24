#include "unity.h"
#include "Communication.h"
#include "mock_Signal.h"
#include <stdint.h>

void setUp(void){}

void tearDown(void){}


void test_sendBitHigh_given_xxx_should_xxxx(){
  setPinHigh_Expect(IO_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
  sendBitHigh(IO_PIN);
}

void test_sendBitLow_given_xxx_should_xxxx(){
  setPinLow_Expect(IO_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
  sendBitLow(IO_PIN);
}


void test_readTurnAroundIO(){
  setPinToInput_Expect(IO_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  
  readTurnAroundIO(IO_PIN);
}

void test_writeTurnAroundIO(){
  setPinToOutput_Expect(IO_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
  writeTurnAroundIO(IO_PIN);
}

void test_read_given_xxx_should_xxxx(){
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  getPin_ExpectAndReturn(IO_PIN, 1);
  
  readBit(IO_PIN);
}

/**
 *
 *  
 *                |----------------|                                      |---------------|
 *                |   PIC18        |                  cmd = 0xCD          |    External   |
 *                |                |              ------------------->    |     Device    |
 *                |                |                address = 0xDEAD      |               |
 *                |                |              ------------------->    |               |
 *                |                |                  data = 0xCE         |               |
 *                |                |              ------------------->    |               |
 *                |                |                                      |               |
 *                |----------------|                                      |---------------|
 *                  
 *
 *
 */
void test_writeData_given_0xCD_and_address_0xDEAD_and_data_0xC0_should_sent_out_0xCDDEADC0(void){
  // set pin to output 
  setPinToOutput_Expect(IO_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
  // send data
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
  writeData(0xCD, 0xDEAD, 0xC0);
}



/**
 *
 *  
 *                |----------------|                                      |---------------|
 *                |   PIC18        |                    cmd = 0xAB        |    External   |
 *                |                |              ------------------->    |     Device    |
 *                |                |                address = 0xFACE      |               |
 *                |                |              ------------------->    |               |
 *                |                |                                      |               |
 *                |                |              <-------------------    |               |
 *                |                |                     data = 0xBE      |               |
 *                |----------------|                                      |---------------|
 *                  
 *
 *
 */

void test_readData_given_0xAB_and_addr_0xFACE_should_sent_0xABFACE_and_turnaround_and_receive_0xBE(void){
  // set pin to output 
  setPinToOutput_Expect(IO_PIN);
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
  // write data
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinLow_Expect(IO_PIN);  // 0
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(IO_PIN); // 1
  setPinHigh_Expect(CLK_PIN);
  setPinLow_Expect(CLK_PIN);
  
  // set pin to input 
  setPinToInput_Expect(IO_PIN);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  
  // read data
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  getPin_ExpectAndReturn(IO_PIN, 0);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  getPin_ExpectAndReturn(IO_PIN, 1);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  getPin_ExpectAndReturn(IO_PIN, 1);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  getPin_ExpectAndReturn(IO_PIN, 1);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  getPin_ExpectAndReturn(IO_PIN, 1);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  getPin_ExpectAndReturn(IO_PIN, 1);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  getPin_ExpectAndReturn(IO_PIN, 0);
  setPinLow_Expect(CLK_PIN);
  setPinHigh_Expect(CLK_PIN);
  getPin_ExpectAndReturn(IO_PIN, 1);
  
  uint8_t data = readData(0xAB, 0xFACE);
  
  TEST_ASSERT_EQUAL(190,data); // HEX of 129 = BE
}