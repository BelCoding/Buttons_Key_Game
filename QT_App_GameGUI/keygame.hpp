#ifndef _keygame_hpp_
#define _keygame_hpp_

#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <tr1/array>


namespace bel{

inline int strComparePlus(const std::string a, const std::string b){ return a.compare(b); }

};

namespace game{

class ButtonsKey{

    
    static const int TOTAL_LEDS = 3;
    static const int TOTAL_BUTTONS = 3;
	//const char Buttons[TOTAL_BUTTONS] = { 'A', 'B', 'C' };

    typedef std::tr1::array< char, TOTAL_BUTTONS> ButtonsRegister;
    typedef std::tr1::array< std::string, TOTAL_LEDS> LedsRegister;
  
    const ButtonsRegister InitializeRandomKey();
    LedsRegister InitializeLeds();
    
    public:

        ButtonsKey();
        ~ButtonsKey();

        ButtonsRegister pressed_buttons;
        void NewPressedButton(const char c);
        LedsRegister current_leds;
        bool UpdateLeds(const ButtonsRegister PressedButtons);
        void RestartGame();

    private:
        
        void ResetKey();
        ButtonsRegister current_key;// InitializeRandomKey(const bool printkey);
        const ButtonsRegister return_current_key();
        void InitializeButtonsToSlash();

};

}
#endif
