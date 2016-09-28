// Copyright (c) 2016, Anaren Inc.
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer. 
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// The views and conclusions contained in the software and documentation are those
// of the authors and should not be interpreted as representing official policies, 
// either expressed or implied, of the FreeBSD Project.

#ifndef APA102_H
#define APA102_H

#include "../spi/spi.h"
#include "apa102_config.h"
#include <stdint.h>

#ifndef AIR_LED_ANIMATE_CALLBACK
#define AIR_LED_ANIMATE_CALLBACK
typedef void (*AIR_LEDAnimateCallback_ptr)(unsigned int frame, unsigned int currentColumn, unsigned int currentRow, unsigned int totalColumns, unsigned int totalRows, void *args, uint8_t *brightness, uint8_t *red, uint8_t *green, uint8_t *blue);
#endif

//------------------------------------------------------------------------------
/**
 *  Defines, enumerations, and structure definitions
 */
// 


void APA102_WriteStartFrame();

void APA102_WriteEndFrame();

void APA102_WriteLEDFrame(uint8_t brightness, uint8_t red, uint8_t green, uint8_t blue);

void APA102_Animate(AIR_LEDAnimateCallback_ptr animation, unsigned int frame, unsigned int numberOfLEDs, unsigned int numberOfLEDsPerRow, bool serpentine, void *args);

#endif  /* APA102_H */
