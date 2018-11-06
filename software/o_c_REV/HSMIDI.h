// Copyright (c) 2010, 2012, 2013, 2018, Jason Justian
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

//////////////////////////////////////////////////////////////////////////
// This file contains MIDI utilities for Hemisphere Suite, including:
// * System Exclusive Handler base class
// * Data packing structure
// * Teensyduino USB MIDI message number table
// * MIDI note number-name and MIDI channel tables
// * MIDI note/CV quantizer functions
//////////////////////////////////////////////////////////////////////////

#ifndef HSMIDI_H
#define HSMIDI_H

const char* const midi_note_numbers[128] = {
    "C-1","C#-1","D-1","D#-1","E-1","F-1","F#-1","G-1","G#-1","A-1","A#-1","B-1",
    "C0","C#0","D0","D#0","E0","F0","F#0","G0","G#0","A0","A#0","B0",
    "C1","C#1","D1","D#1","E1","F1","F#1","G1","G#1","A1","A#1","B1",
    "C2","C#2","D2","D#2","E2","F2","F#2","G2","G#2","A2","A#2","B2",
    "C3","C#3","D3","D#3","E3","F3","F#3","G3","G#3","A3","A#3","B3",
    "C4","C#4","D4","D#4","E4","F4","F#4","G4","G#4","A4","A#4","B4",
    "C5","C#5","D5","D#5","E5","F5","F#5","G5","G#5","A5","A#5","B5",
    "C6","C#6","D6","D#6","E6","F6","F#6","G6","G#6","A6","A#6","B6",
    "C7","C#7","D7","D#7","E7","F7","F#7","G7","G#7","A7","A#7","B7",
    "C8","C#8","D8","D#8","E8","F8","F#8","G8","G#8","A8","A#8","B8",
    "C9","C#9","D9","D#9","E9","F9","F#9","G9"
};

/*
 * MIDI Quantizer: Converts pitch CV values to MIDI note numbers,
 * and vice versa. CV values are (12 << 7) steps per volt, or
 * 128 steps per semitone.
 */
class MIDIQuantizer {
public:
    /* Given a pitch CV value, return the MIDI note number */
    static uint8_t NoteNumber(int cv, int transpose = 0) {
        // CV controllers might be right on the border between voltages, so provide 1/4 tone offset
        if (cv > 0) cv += 32;
        if (cv < 0) cv -= 32;
        int octave = cv / (12 << 7);
        int semitone = (cv % (12 << 7)) / 128;
        int midi_note_number = (octave * 12) + semitone + transpose + 60;
        if (midi_note_number > 127) midi_note_number = 127;
        if (midi_note_number < 0) midi_note_number = 0;
        return static_cast<uint8_t>(midi_note_number);
    }

    /* Given a MIDI note number, return the pitch CV value */
    static int CV(uint8_t midi_note_number, int transpose = 0) {
        int octave = midi_note_number / 12;
        int semitone = midi_note_number % 12;
        int cv = (octave * (12 << 7)) + (semitone * 128) + (transpose * 128) - (5 * (12 << 7));
        return cv;
    }
};

#endif /* HSMIDI_H */
