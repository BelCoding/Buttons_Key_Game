#ifndef _keygame_cpp_
#define _keygame_cpp_

#include "keygame.hpp"
//using namespace std;

namespace game{

//------------------------------------------------------------------------------
// Constructor calls to Initialize a random key for this object "current_key".

ButtonsKey::ButtonsKey():current_leds(InitializeLeds()),current_key(InitializeRandomKey()){
    InitializeButtonsToSlash();
}
//ButtonsKey::ButtonsKey():current_key{InitializeRandomKey()}{}

//------------------------------------------------------------------------------
ButtonsKey::~ButtonsKey(){}


//------------------------------------------------------------------------------
void ButtonsKey::InitializeButtonsToSlash(){

    for( int i = 0; i < TOTAL_BUTTONS ; ++i ){ pressed_buttons[i] = '-'; } // Initialize to '-'. Not valid value

}

//------------------------------------------------------------------------------
void ButtonsKey::RestartGame(){

    InitializeButtonsToSlash();
    ResetKey();
    current_leds = InitializeLeds();
}
//------------------------------------------------------------------------------
void ButtonsKey::ResetKey(){

    current_key = InitializeRandomKey();

}

//------------------------------------------------------------------------------
const ButtonsKey::ButtonsRegister ButtonsKey::InitializeRandomKey()
{ // Create a new random key.

    srand( (int)time(0) );
    int achartointeger{'A'};
    ButtonsRegister key;

    for( int i = 0; i < TOTAL_BUTTONS ; ++i ){

    	// Generate random numbers: 0, 1 or 2, which we sum the the int value of char A.
    	// This will produce random chars A, B, C
    	key[i] = static_cast<char>( achartointeger + ( rand() % TOTAL_BUTTONS ) );
    }
    
return key;
}

//------------------------------------------------------------------------------
ButtonsKey::LedsRegister ButtonsKey::InitializeLeds()
{ // Create a new random key.


    LedsRegister leds;

    for( int i = 0; i < TOTAL_LEDS ; ++i ){
        leds[i] = "Red";
    }
    
return leds;
}


//------------------------------------------------------------------------------
void ButtonsKey::NewPressedButton(const char c){

    pressed_buttons[2] = pressed_buttons[1];
    pressed_buttons[1] = pressed_buttons[0];
    pressed_buttons[0] = c; // The last pressed button is allocated in the position 0

}

//------------------------------------------------------------------------------
// This function Compares the input button with the Current key in the given position, and return the color of the LED.
bool ButtonsKey::UpdateLeds(const ButtonsRegister pressed_buttons){

    for(int i = 0, led_pos = 2; i < TOTAL_LEDS; ++i, --led_pos){
        
        // Starting by i = 0 (last pressed button), led_pos = 2 (LED3);
        
        if (pressed_buttons[i] == '-') {

            current_leds[led_pos] = "Red";
            // Red by default when the pressed_buttons[i] has not yet been pressed, for instance in first iterations

        }else if ( current_key[i] == pressed_buttons[i] ) {

            current_leds[led_pos] = "Green"; // Green if It match with the position given

        }else{

            current_leds[led_pos] = "Red"; // Red by default when we do not find It anywhere.
            for(int key_index = 0; key_index < TOTAL_BUTTONS; ++key_index){

                if( current_key[key_index] == pressed_buttons[i] ){ current_leds[led_pos] = "Orange"; } 
                // Orange if we find It in a different position
            }
        }
    }
    
// This condition returns true when all 3 colors are green.
return (bel::strComparePlus(current_leds[2], "Green") == 0 && bel::strComparePlus(current_leds[1], "Green") == 0 && bel::strComparePlus(current_leds[0], "Green") == 0);

}

//------------------------------------------------------------------------------
// Return the random generated key to a public method
const ButtonsKey::ButtonsRegister ButtonsKey::return_current_key(){ return current_key; }

}
#endif
