/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE
 * <jonas@olofsson.me> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Jonas Olofsson
 * ----------------------------------------------------------------------------
 */

#pragma once

class BcdSevenSegment
{
public:
  BcdSevenSegment(int d0, int d1, int d2, int d3);
  void setInt(int value);
private:
  /** Pin number on the Arduino coupled to the input pins on the HEF4511 */
  int d0, d1, d2, d3;
};
