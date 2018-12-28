/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE
 * <jonas@olofsson.me> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return. Jonas Olofsson
 * ----------------------------------------------------------------------------
 */

#include "bcdSevenSegment.h"

BcdSevenSegment::BcdSevenSegment(int d0, int d1, int d2, int d3)
{
  this->d0 = d0; // LSB
  this->d1 = d1;
  this->d2 = d2;
  this->d3 = d3; // MSB
}

void BcdSevenSegment::setInt(int value)
{
  switch (value)
  {
    case 0:
      d0 = 0;
      d1 = 0;
      d2 = 0;
      d3 = 0;
      break;
    case 1:
      d0 = 1;
      d1 = 0;
      d2 = 0;
      d3 = 0;
      break;
    case 2:
      d0 = 0;
      d1 = 1;
      d2 = 0;
      d3 = 0;
      break;
    case 3:
      d0 = 1;
      d1 = 1;
      d2 = 0;
      d3 = 0;
      break;
    case 4:
      d0 = 0;
      d1 = 0;
      d2 = 1;
      d3 = 0;
      break;
    case 5:
      d0 = 1;
      d1 = 0;
      d2 = 1;
      d3 = 0;
      break;
    case 6:
      d0 = 0;
      d1 = 1;
      d2 = 1;
      d3 = 0;
      break;
    case 7:
      d0 = 1;
      d1 = 1;
      d2 = 1;
      d3 = 0;
      break;
    case 8:
      d0 = 0;
      d1 = 0;
      d2 = 0;
      d3 = 1;
      break;
    case 9:
      d0 = 1;
      d1 = 0;
      d2 = 0;
      d3 = 1;
      break;
    default:
      d0 = 1;
      d1 = 1;
      d2 = 1;
      d3 = 1;
      break;
  }
}

