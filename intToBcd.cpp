/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE
 * <jonas@olofsson.me> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Jonas Olofsson
 * ----------------------------------------------------------------------------
 */

#include "intToBcd.h"
#include "bcdSevenSegment.h"
#include "pins.h"

IntToBcd::IntToBcd()
{
  // TODO lookup pin numbers
  singular = new BcdSevenSegment(SEVEN_SEGMENT_ONES_0,
                                 SEVEN_SEGMENT_ONES_1,
                                 SEVEN_SEGMENT_ONES_2,
                                 SEVEN_SEGMENT_ONES_3);
  tens = new BcdSevenSegment(SEVEN_SEGMENT_TENS_0,
                             SEVEN_SEGMENT_TENS_1,
                             SEVEN_SEGMENT_TENS_2,
                             SEVEN_SEGMENT_TENS_3);
}

void IntToBcd::setInt(int value)
{
  // I will show temperature on two 7-segment units. So no need to calculate
  // more then singular and tens.
  singular->setInt(value % 10);
  tens->setInt((value / 10) % 10);
}
