/****************************************************************
**	OrangeBot Project
*****************************************************************
**        /
**       /
**      /
** ______ \
**         \
**          \
*****************************************************************
**	Anima test bench
*****************************************************************
**  This Engine is a wrapper of the Windows API to
**	interface with console output/input asyncronously
**	It allows to animate the console and to get game like
**	keyboard inputs like multiple key pressed at once
****************************************************************/

/****************************************************************
**	DESCRIPTION
****************************************************************
**	A very simple 'game' with no win/lose states to demonstrate Anima
**	The player uses the arrows to move a '*' on the output console
****************************************************************/

/****************************************************************
**	HISTORY VERSION
****************************************************************
**
****************************************************************/

/****************************************************************
**	KNOWN BUGS
****************************************************************
**
****************************************************************/

/****************************************************************
**	TODO
****************************************************************
**
****************************************************************/

/****************************************************************
**	INCLUDES
****************************************************************/

///Standard C Libraries
#include <cstdio>
//#include <cstdlib>

///Standard C++ libraries
#include <iostream>
//#include <array>
#include <vector>
//#include <queue>
//#include <string>
//#include <fstream>
#include <chrono>
#include <thread>

///OS Libraries
//#define _WIN32_WINNT 0x0500	//Enable GetConsoleWindow
#include <windows.h>

///User Libraries
//Animate the windows console
#include "anima.h"

/****************************************************************
**	NAMESPACES
****************************************************************/

//Never use a whole namespace. Use only what you need from it.
using std::cout;
using std::cerr;
using std::endl;

/****************************************************************
**	DEFINES
****************************************************************/

//for EVER
#define EVER (;;)

/****************************************************************
**	MACROS
****************************************************************/

/****************************************************************
**	PROTOTYPES
****************************************************************/

/****************************************************************
**	CUSTOM TYPES
****************************************************************/

//Coordinate structure
typedef struct _Coord
{
	int r;
	int c;
} Coord;


/****************************************************************
**	GLOBAL VARIABILES
****************************************************************/

/****************************************************************
**	FUNCTIONS
****************************************************************/

/****************************************************************
**	MAIN
****************************************************************
**	INPUT:
**	OUTPUT:
**	RETURN:
**	DESCRIPTION:
****************************************************************/

int main()
{
	///----------------------------------------------------------------
	///	STATIC VARIABILE
	///----------------------------------------------------------------

	//Frame delay in milliseconds
	static const int frame_delay = 10;

	///----------------------------------------------------------------
	///	LOCAL VARIABILE
	///----------------------------------------------------------------

	//current and previous position of player
	Coord player, old;
	//Console animation engine class. Initialize class.
	User::Anima anima;

	///----------------------------------------------------------------
	///	CHECK AND INITIALIZATIONS
	///----------------------------------------------------------------
	//	Write the initial screen configuration

	///if: failed to load Anima
	//if: engine is not running properly
	if (anima.is_invalid() == true)
	{
		cerr << "ERR: Anima did not load correctly!!!\n";
		return -1;
	}

	///Initialize Screen
	//Instructions
	sprintf( &anima.out(0, 0), "Use directional keys to move the '*' | Press Q to quit" );
	//Update the output console
	anima.update_output();

	///Initialize player
	//Player
	player.r = 2;
	player.c = 2;
	//Player previous position
	old = player;

	///----------------------------------------------------------------
	///	BODY
	///----------------------------------------------------------------
	//	Anima is meant to be used in four phases:
	//	1) update virtual keys state
	//	2) use keys to update the game state
	//	3) use game state to update output ascii buffer
	//	4) display ascii output buffer
	//
	//	A better way to do this is to have a thread dedicated to game input and physics
	//	and a thread dedicated to graphics. You can do that if you like.
	//	For simple things it shouldn't be needed.

	//for: game loop
	for EVER
	{
		///----------------------------------------------------------------
		///	UPDATE INPUT BUFFER
		///----------------------------------------------------------------
		//	update_input will update the virtual key input buffer
		//	for every virtual key, anima.in( key ) will be
		//		true: key pressed, key down
		//		false: key released, key up
		//	additionally, anima.get_last_vk() will hold the last key that has been pressed
		//	0 if no event has been detected in this update.

		//Update inputs (non blocking call)
		anima.update_input();

		///----------------------------------------------------------------
		///	PROCESS INPUT
		///----------------------------------------------------------------
		//	Based on which keys are down, move the player
		//	the abstraction layer provided by Anima allows to detect simultaneous key presses

		///Process keys
		//if: Quit
		if (anima.in( VK_Q ) == true)
		{
			return 0;
		}
		//if: DOWN key is pressed
		if (anima.in( VK_DOWN ) == true)
		{
			//move down
			player.r++;
			//boundary limit
			if (player.r >= (int)anima.get_rows())
			{
				player.r = anima.get_rows() -1;
			}
		}
		//if: UP key is pressed
		if (anima.in( VK_UP ) == true)
		{
			//move down
			player.r--;
			//boundary limit
			if (player.r < 1)
			{
				player.r = 1;
			}
		}
		//if: LEFT key is pressed
		if (anima.in( VK_LEFT ) == true)
		{
			//move down
			player.c--;
			//boundary limit
			if (player.c < 0)
			{
				player.c = 0;
			}
		}
		//if: RIGHT key is pressed
		if (anima.in( VK_RIGHT ) == true)
		{
			//move down
			player.c++;
			//boundary limit
			if (player.c >= (int)anima.get_cols())
			{
				player.c = anima.get_cols() -1;
			}
		}

		///----------------------------------------------------------------
		///	PROCESS OUTPUT
		///----------------------------------------------------------------
		//	execute game logic and write in the ascii output buffer

		//delete player from previous position
		anima.out( old.r, old.c ) = ' ';
		//Print player in the player position
		anima.out( player.r, player.c ) = '*';
		//update player previous position
		old = player;

		///----------------------------------------------------------------
		///	UPDATE OUTPUT
		///----------------------------------------------------------------
		//	This function will synchronize the buffer with the console
		//	cout only prints character in sequence, and there is no standard way to do this
		//	the best one can do is to use the OS APIs to access the
		//	console buffer directly.
		//	Anima provides a thin wrapper to hide the system calls and make it simpler

        //Update the output console
        anima.update_output();

		///----------------------------------------------------------------
		///	WAIT NEXT FRAME
		///----------------------------------------------------------------
		//	This can be done with standard library calls with C++11
		//	This can be done better by waking up at the right moment
		//	rather than wait a fixed amount of time

		std::this_thread::sleep_for( std::chrono::milliseconds(frame_delay) );
	}	//end for: game loop

	///----------------------------------------------------------------
	///	FINALIZATIONS
	///----------------------------------------------------------------

    return 0;
}	//end function: main
