/*
 *  Project     HID Buttons Library
 *  @author     David Madison
 *  @link       github.com/dmadison/HID_Buttons
 *  @license    MIT - Copyright (c) 2019 David Madison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef HID_Button_Mouse_h
#define HID_Button_Mouse_h

#include "HID_Button_API.h"

#if defined(MOUSE_h) && defined(_USING_HID)
class MouseButton : public HID_Button {
public:
	MouseButton(uint8_t b) :
		buttonID(b) {}

	uint16_t getButton() const {
		return buttonID;
	}

	HID_Button_Type getType() const {
		return HID_Button_Type::Mouse;
	}

	static const HID_Button_Type HID_Type = HID_Button_Type::Mouse;

protected:
	void sendState(boolean state) {
		state ? Mouse.press(buttonID) : Mouse.release(buttonID);
	}

	const uint8_t buttonID;
};
#endif

#endif
