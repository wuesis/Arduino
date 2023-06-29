/*
   Copyright (c) 2019 Arduino.  All rights reserved.
*/

#ifndef TEST_ARDUINO_H_
#define TEST_ARDUINO_H_

/******************************************************************************
   INCLUDE
 ******************************************************************************/

#include <string>

/******************************************************************************
   TYPEDEF
 ******************************************************************************/

typedef std::string String;

/******************************************************************************
   FUNCTION PROTOTYPES
 ******************************************************************************/

void          set_millis(unsigned long const millis);
unsigned long millis();

#endif /* TEST_ARDUINO_H_ */
