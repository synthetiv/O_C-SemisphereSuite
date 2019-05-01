// Categories:
// 0x01 = Modulator
// 0x02 = Sequencer
// 0x04 = Clocking
// 0x08 = Quantizer
// 0x10 = Utility
// 0x20 = MIDI
// 0x40 = Logic
// 0x80 = Other

#define HEMISPHERE_AVAILABLE_APPLETS 23

//////////////////  id  cat   class name
#define HEMISPHERE_APPLETS { \
    DECLARE_APPLET( 15, 0x02, AnnularFusion), \
    DECLARE_APPLET( 47, 0x09, ASRApplet), \
    DECLARE_APPLET(  4, 0x14, Brancher), \
    DECLARE_APPLET( 31, 0x04, Burst), \
    DECLARE_APPLET( 12, 0x10, Calculate),\
    DECLARE_APPLET(  6, 0x04, ClockDivider), \
    DECLARE_APPLET( 28, 0x04, ClockSkip), \
    DECLARE_APPLET( 30, 0x10, Compare), \
    DECLARE_APPLET(  9, 0x08, DualQuant), \
    DECLARE_APPLET( 42, 0x11, EnvFollow), \
    DECLARE_APPLET( 29, 0x04, GateDelay), \
    DECLARE_APPLET( 17, 0x50, GatedVCA), \
    DECLARE_APPLET( 10, 0x44, Logic), \
    DECLARE_APPLET( 50, 0x04, Metronome), \
    DECLARE_APPLET( 33, 0x10, MixerBal), \
    DECLARE_APPLET( 23, 0x80, Scope), \
    DECLARE_APPLET( 48, 0x45, ShiftGate), \
    DECLARE_APPLET( 19, 0x01, Slew), \
    DECLARE_APPLET(  3, 0x10, Switch), \
    DECLARE_APPLET( 37, 0x40, Trending), \
    DECLARE_APPLET( 11, 0x06, TrigSeq), \
    DECLARE_APPLET( 25, 0x06, TrigSeq16), \
    DECLARE_APPLET( 39, 0x80, Tuner), \
}
/*    DECLARE_APPLET(127, 0x80, DIAGNOSTIC), \ */
