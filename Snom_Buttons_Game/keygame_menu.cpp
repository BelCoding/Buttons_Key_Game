#include "keygame.cpp"

void PrintHelp(){
        
    std::cout << "keygame description:" << std::endl;
    std::cout << "The system implements a game in which the user has to guess a sequence of three button presses. The sequence can contain any combination, e.g. BAC, CCB, AAA." << std::endl;
    std::cout << "The LEDs should always represent the result of the last 3 button presses." << std::endl;
    std::cout << "* LED 3 will always represent the most recent button event" << std::endl;
    std::cout << "* LED 2 the one before that." << std::endl;
    std::cout << "* LED 1 the one before that." << std::endl;
    std::cout << "Red indicates that the button pressed was wrong for this position, and does not appear in a different position. Orange indicates that the button pressed was wrong for this position, but it does appear in a different position. Green indicates that the button pressed was correct for this position." << std::endl;
    std::cout << "Only button down* events are generated, so there is no need to deal with held buttons. The button sequence is randomly generated on system start-up. After a 3-green result, another random sequence is generated." << std::endl;
    std::cout << std::endl;

    std::cout << "Options:" << std::endl;
    std::cout << "--Help" << std::endl;
    std::cout << "-Print" << std::endl;
    std::cout << "-Play" << std::endl;

        
}

void GoingToPlayGame(const bool printkey){

    std::cout << "Type 'q' and ENTER to exit."<< std::endl;
    std::cout << "Allowed buttons are: A, B or C. Lowercase or other letters not recognised."<< std::endl;
    
    bool restart_session=true; // Continue playing with a new key
    
    while(restart_session){
        game::ButtonsKey obj; // Contruct a new object generating a new key.

        if(printkey)
            obj.PrintCurrentKey();

        restart_session = obj.Play_Session(); 
        obj.~ButtonsKey();
    }
    std::cout << "Exiting game..." << std::endl;


}

//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------

int main(int argc, char* argv[]){


	bool pass = false; // true when pass at least one of the 
	bool printkey = false; // Play with advantage, print the key when It is generated
	
    
    // index of the input parameters of the program
	for( int i = 1; i < argc ; ++i ){
		
		std::string input(argv[i]);

        if( ( bel::strComparePlus(input, "--Help")==0  ||  bel::strComparePlus(input, "-Help")==0  ||  bel::strComparePlus(input, "--help")==0  ||  bel::strComparePlus(input, "-help")==0  ||  bel::strComparePlus(input, "-h")==0  || bel::strComparePlus(input, "-H")==0 ||  bel::strComparePlus(input, "--H")==0 ||  bel::strComparePlus(input, "--h")==0 ) && argc > i){
            PrintHelp();
            return 0;
		}

        if( bel::strComparePlus(input, "-Print")==0 ){
            
            printkey = true;
            pass = true;
        }
        
	}

        // index of the input parameters of the program
    for( int i = 1; i < argc ; ++i ){

		std::string input(argv[i]);

        if( bel::strComparePlus(input, "-Play")==0 ){
            
            GoingToPlayGame(printkey);
            pass=true;
        }
	}
	
	if(!pass)
    {
        std::cout << "If you need help Type: ./keygame --Help" << std::endl;
        std::cout << "Parameters given: " << argc - 1 << std::endl;
    }
return 0;
}
