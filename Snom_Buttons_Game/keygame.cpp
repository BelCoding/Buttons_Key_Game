#ifndef _keygame_cpp_
#define _keygame_cpp_

#include "keygame.hpp"
//using namespace std;

namespace game{

//------------------------------------------------------------------------------
// Constructor calls to Initialize a random key for this object "current_key".

ButtonsKey::ButtonsKey():current_key(InitializeRandomKey()), current_leds(InitializeLeds()){}
//ButtonsKey::ButtonsKey():current_key{InitializeRandomKey()}{}

//------------------------------------------------------------------------------
ButtonsKey::~ButtonsKey(){}


//------------------------------------------------------------------------------
const void ButtonsKey::InitializeKeyToSlash(ButtonsRegister& pressed_buttons){

    for( int i = 0; i < TOTAL_BUTTONS ; ++i ){ pressed_buttons[i] = '-'; } // Initialize to '-'. Not valid value

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

    std::cout << "Randomly new key generated." << std::endl;
    
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
const bool ButtonsKey::Play_Session(){

    bool restart_session = false;
    ButtonsRegister pressed_buttons;
	InitializeKeyToSlash(pressed_buttons);

    std::string input;
	std::cin >> input;

    while( bel::strComparePlus(input, "q") != 0 && !restart_session){

    	if( EnterAccepted( input ) ){ // Only accepted when length of the string is 1 AND input == A or B or C

    		pressed_buttons[2] = pressed_buttons[1];
    		pressed_buttons[1] = pressed_buttons[0];
    		pressed_buttons[0] = input[0]; // The last pressed button is allocated in the position 0

    	}else{

    		std::cout << "Input not accepted" << std::endl;
    	}

        std::cout << "Last pressed buttons: ";
        for(int i = 0; i < TOTAL_BUTTONS; ++i){
            std::cout << pressed_buttons[i] << "   ";
        }

        restart_session = UpdateLeds( pressed_buttons );
        PrintLeds();
        
        // when all LEDS are green we restart the session, exiting this one
        if ( restart_session ){
            
            std::cout << std::endl;
            std::cout << "Welcome!!. You found the key, all LEDS are green." << std::endl;
        } else{
        
            std::cout << std::endl;
            std::cin >> input;            
        }

    }
    
return restart_session;
}


//------------------------------------------------------------------------------
const void ButtonsKey::PrintCurrentKey(){
    
	ButtonsRegister key = return_current_key(); //Obtain the current generated key of this object
    std::cout << "Current key: ";    
    for(int i = 0; i < TOTAL_BUTTONS; ++i){
        std::cout << key[i] << "   ";
    }
    std::cout << std::endl;
}


//------------------------------------------------------------------------------
// Following the task description LED 3 corresponds to the last pressed button, which is stored in the position 0.
const void ButtonsKey::PrintLeds(){

	std::cout << "LED3{" << current_leds[2];
	std::cout << "} 	LED2{"  << current_leds[1];
	std::cout << "} 	LED1{"  << current_leds[0] << "}" << std::endl;
    
}



//------------------------------------------------------------------------------
// This function Compares the input button with the Current key in the given position, and return the color of the LED.
const bool ButtonsKey::UpdateLeds(const ButtonsRegister pressed_buttons){

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
// Returns false if the string is not A or B or C.
// Otherwise returns true
const bool ButtonsKey::EnterAccepted(const std::string input ){

	if ((int)input.length() == 1){
        
        if( input[0] == 'A'|| input[0] == 'B' || input[0] == 'C' ){

            return true;
        }else{

            return false;
        }
        
	}else{
        
        return false;
    }
}

//------------------------------------------------------------------------------
// Return the random generated key to a public method
const ButtonsKey::ButtonsRegister ButtonsKey::return_current_key(){ return current_key; }

}
#endif
