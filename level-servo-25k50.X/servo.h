/*
 * Copyright (C) 2017 Johan Bergkvist
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#ifndef SERVO_H
#define	SERVO_H

#include <stdint.h>

void ServoInit();
void ServoSet(int8_t value);

#endif	/* SERVO_H */

