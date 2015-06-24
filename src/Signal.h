#ifndef Signal_H
#define Signal_H

#define IO_PIN      4
#define CLK_PIN     5

/**
 *@brief Set pin to high
 *@param pinNo is the pin to set high
 */
void setPinHigh(int pinNo);

/**
 *@brief Set pin to high
 *@param pinNo is the pin to set low
 */
void setPinLow(int pinNo);

/**
 *@brief Read pin state
 *@param pinNo is the pin to read from
 *@return 1 if pin is high, otherwise 0
 */
int getPin(int pinNo);

/**
 *@brief Set pin as output
 *@param pinNo is the pin set as output
 */
void setPinToOutput(int pinNo);

/**
 *@brief Set pin as input
 *@param pinNo is the pin set as input
 */
void setPinToInput(int pinNo);

#endif // Communication_H
