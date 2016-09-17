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

#include "apa102.h"

const uint8_t startFrame[] = {0x00, 0x00, 0x00, 0x00};
const uint8_t endFrame[] = {0xff, 0xff, 0xff, 0xff};

void APA102_WriteStartFrame()
{
	AIR_SPI_Write(-1, startFrame, 4);
}

void APA102_WriteEndFrame()
{
	AIR_SPI_Write(-1, endFrame, 4);
}

void APA102_WriteLEDFrame(uint8_t brightness, uint8_t red, uint8_t green, uint8_t blue)
{
	//Each frame is constructed as brightness, blue, green and red.
	//[ 3-bit all 1s][ 5-bit for brightness ][ 8-bits for blue ][ 8-bits for green ][ 8-bits for red ]
	uint8_t tempData[4];
	tempData[0] = brightness;
	tempData[1] = blue;
	tempData[2] = green;
	tempData[3] = red;
	
	AIR_SPI_Write(-1, tempData, 4);
}

void APA102_Animate(AIR_LEDAnimateCallback_ptr animation, unsigned int frame, unsigned int numberOfLEDs, unsigned int numberOfLEDsPerRow, void *args)
{
}
