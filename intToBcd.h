/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE
 * <jonas@olofsson.me> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Jonas Olofsson
 * ----------------------------------------------------------------------------
 */
#pragma once

#include "bcdSevenSegment.h"

class IntToBcd
{
public:
  IntToBcd();
  void setInt(int value);
private:
  BcdSevenSegment *singular;
  BcdSevenSegment *tens;
};
