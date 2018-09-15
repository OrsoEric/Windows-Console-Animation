/****************************************************************************
**	OrangeBot Project
*****************************************************************************
**        /
**       /
**      /
** ______ \
**         \
**          \
*****************************************************************************
**	Anima
*****************************************************************************
**	Windows Console Animation Engine
*****************************************************************************
**	Author: 			Orso Eric
**	GitHub:				https://github.com/OrsoEric
**	Creation Date:
**	Last Edit Date:
**	Revision:			2
**	Version:			1.0
****************************************************************************/

/****************************************************************************
**	HYSTORY VERSION
*****************************************************************************
**	V1.0 rev2
**		>output ascii buffer and console output update works
**		>input virtual keys buffer and console input update works
**		>cleaned up code from debug constructs
**		>added library description
****************************************************************************/

/****************************************************************************
**	HISTORY
*****************************************************************************
**		Problem:
**	I was searching for an easy way to animate the output console
**	I wanted to display numbers changing in real time (weights of
**	a neural network) without writing tons of lines or jumping to
**	a big framework with tons of dependencies to handle
**
**		Process:
**	The task that proved much trickier than expected and required lots of research
**	Can I do it with C++ standard library alone? NO.
**	Search for libraries and dependencies that achieve the objective.
**	Are there libraries out there that do it? YES. Tons of them!
**	Problem:
**		Libraries I found are either full blown frameworks (QT, etc...) or
**		non standard/unstable/compiler dependent mess (conio, etc...)
**
**		Solution:
**	The reason small libraries are a mess IMHO is because they try to be more than what they are
**	The simplest way with the least dependencies to do it is to make use of the OS APIs
**	You lose some portability, but save time in solving dependencies
**	Anima is a fairly thin wrapper that provides the minimum possible features
**	to achieve the desired result.
**	It's imperative that the library is consistent in what it does
**
**		Scope:
**	Anima is meant to be quick, easy to use and require little to no messing with the compiler
**	Anima is a basic library meant to do basic stuffs quickly
**	Display numbers that change in real time? OK
**	Press a key to tune a parameter? OK
**	Little ascii game for fun and profit? OK
**	Jpeg loader with ascii art converter? NO!
**	ascii GUI drawing primitives? NO!!!
**	Fractal ascii art drawing primitives? HELL NO!!!
**
**		Limitations:
**	Anima works only on windows 2000 and above
**	Anima provides only a virtual key buffer and an output buffer it's up to the user to do everything else
**	If fancy things are required, than Anima is NOT the answer you are looking for
****************************************************************************/

/****************************************************************************
**	DESCRIPTION
*****************************************************************************
**	KISS: Keep It Simple Stupid.
**
**	Anima allows to read input from console in a game like way (std::cin can't do it)
**	Anima allows fast update of the output console (std::cout can't do it)
**	Anima is a thin wrapper of the Windows API. Should work on win2000 and above
**	Anima provides the smallest possible set of functions that still make Anima useful
**
**	Building requires windows.h, -C++11 and -lgdi32. Nothing else.
*****************************************************************************
**	Inside the core loop, Anima is meant to be used in four steps:
**
**	1) anima.update_input()
**		this do magic with the windows APIs to maintain a list of keys
**
**	2) anima.in( VK_* ) == true
**		buffer of 256 virtual keys. index VK_*
**		true if key is pressed. false if key is released
**		it doesn't get any easier than that as interface
**		allows processing of multiple key presses at once (std::cin can't do it)
**		it's the minimum feature required to make input viable during animation
**
**	3) anima.out( row, col ) = something
**		user edit the output buffer according to some logic
**		be it an ascii movie or a game of tetris or whatever
**		it's a buffer. timing doesn't matter
**		it doesn't get any easier than that as interface
**
**	4) anima.update_output()
**		this do magic with the windows APIs to refresh the output ascii buffer
**		edit character before the cursor.
**		its' much, much faster than std::cout
**		random access is the minimum feature that makes output viable in animation
**
**	Anima could be easily be expanded to provide wrappers for cursor position,
**	drawing primitives, double buffering! colors!! etc...
**	Think twice before adding functionalities. Anima is meant to be cheap and easy.
**	If you want something powerful and complete there are better frameworks out there.
**	This is meant to make animating a console in windows easy and dependence free.
****************************************************************************/

/****************************************************************************
**	KNOWN BUG
*****************************************************************************
**
****************************************************************************/

/****************************************************************************
**	TODO
*****************************************************************************
**	ADD:
**	>Adding mouse handing seems cheap and useful enough...
**	REMOVE:
**	>Do I really need the recent key press?
****************************************************************************/

/****************************************************************************
**	INCLUDES
****************************************************************************/

///Standard C Libraries
//#include <cstdio>
//#include <cstdlib>

///Standard C++ libraries
#include <iostream>
//#include <array>
#include <vector>
//#include <string>
//#include <fstream>

///OS Libraries
#include <windows.h>

///User Libraries
//Class Header
#include "anima.h"

/****************************************************************************
**	NAMESPACES
****************************************************************************/

//Never use a whole namespace. Use only what you need from it.
using std::cout;
using std::cerr;
using std::vector;

//Namespace in which class methods are stored
namespace User
{

/****************************************************************************
**	GLOBAL VARIABILE
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	CONSTRUCTORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Default Constructor
**	Anima
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	Initialize Anima Class
**	Link stdin and stdout of the console of this process.
****************************************************************************/

Anima::Anima( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//return bool
	bool f_ret;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Initialize the Anima Class.
	f_ret = this -> init();
	//if: fail
	if (f_ret == true)
	{
		cerr << "ERR: failed to init class\n";
		return;
	}

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end constructor:

/****************************************************************************
*****************************************************************************
**	DESTRUCTORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Default Destructor
**	~Anima
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

Anima::~Anima( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	RETURN
	///--------------------------------------------------------------------------

	return;
}	//end default destructor

/****************************************************************************
*****************************************************************************
**	OPERATORS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Reference Operator
**	out | unsigned int rows, unsigned int col
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	access to an element of the array.
**	fast method with no checks
****************************************************************************/

char &Anima::out( unsigned int row, unsigned int col )
{
	///--------------------------------------------------------------------------
	/// RETURN
	///--------------------------------------------------------------------------

	//Return reference to the right element
	return this -> gl_ascii_buffer[ row *this -> gl_cols +col];
}	//end method: out | unsigned int rows, unsigned int col

/****************************************************************************
**	Reference Operator
**	in | unsigned int rows, unsigned int col
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	access to an element of the array.
**	fast method with no checks
****************************************************************************/

char &Anima::in( unsigned int key )
{
	///--------------------------------------------------------------------------
	/// RETURN
	///--------------------------------------------------------------------------

	//Return reference to the right element
	return this -> gl_vk_buffer[key];
}	//end method: in | unsigned int rows, unsigned int col

/****************************************************************************
*****************************************************************************
**	SETTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
*****************************************************************************
**	GETTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Public Getter
**	get_rows | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	return the number of rows of the ascii output buffer
****************************************************************************/

unsigned int Anima::get_rows( void )
{
	///--------------------------------------------------------------------------
	/// RETURN
	///--------------------------------------------------------------------------

	return this -> gl_rows;
}	//end method: get_rows | void

/****************************************************************************
**	Public Getter
**	get_cols | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	return the number of columns of the ascii output buffer
****************************************************************************/

unsigned int Anima::get_cols( void )
{
	///--------------------------------------------------------------------------
	/// RETURN
	///--------------------------------------------------------------------------

	return this -> gl_cols;
}	//end method: get_cols | void

/****************************************************************************
**	Public Getter
**	get_last_vk | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	return the most recent key that has been pressed
**	if no key was pressed, return 0
****************************************************************************/

char Anima::get_last_vk( void )
{
	///--------------------------------------------------------------------------
	/// RETURN
	///--------------------------------------------------------------------------

	return this -> gl_last_vk_down;
}	//end method: get_last_vk | void

/****************************************************************************
*****************************************************************************
**	TESTERS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Public Tester
**	is_invalid | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**		false: everything's okay
**		true: FAIL
**	DESCRIPTION:
**	Test whatever the Anima class is running properly
****************************************************************************/

bool Anima::is_invalid( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//if: bad input
	if (this -> gl_console_input_handle == INVALID_HANDLE_VALUE)
	{
		cerr << "ERR: input not valid\n";
		return true;	//fail
	}
	//if: bad output
	if (this -> gl_console_output_handle == INVALID_HANDLE_VALUE)
	{
		cerr << "ERR: output not valid\n";
		return true;	//fail
	}
	//if: bad input buffer
	if (gl_vk_buffer.empty() == true)
	{
		cerr << "ERR: bad input buffer\n";
		return true;	//fail
	}
	//if: bad output buffer
	if (gl_ascii_buffer.empty() == true)
	{
		cerr << "ERR: bad output buffer\n";
		return true;	//fail
	}

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	return false;	//OK
}	//end method: is_invalid | void

/****************************************************************************
*****************************************************************************
**	PUBLIC METHODS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Public Method
**	update_output | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	sync the ascii output buffer with the console
**	refresh the character shown to match the content of the ascii output buffer
**	I feel this can be done in a more efficient way, but it's good enough.
****************************************************************************/

bool Anima::update_output( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//return value
	bool f_ret;
	//console coordinate
	COORD origin;
	//return
	DWORD ret;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	if (this -> gl_console_output_handle == INVALID_HANDLE_VALUE)
	{
		cerr << "ERR: invalid handle\n";
		return true; //Fail
	}

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//Start writing char from first cell
	origin.X = 0;
	origin.Y = 0;

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------
	//	shove the whole buffer on the console

	//Windows API to access the console buffer
	f_ret = WriteConsoleOutputCharacter
	(
		this -> gl_console_output_handle,	//handle to console
		&this -> gl_ascii_buffer[0],		//pointer to buffer
		this -> gl_size,						//number of char to write
		origin,								//coordinate where start writing
		&ret								//return number of char actually written
	);
	//if: fail
    if (f_ret == false)
    {
		cerr << "ERR: could not write characters\n";
        return true;	//Fail
	}
	//if: bad number of character written
	if (this -> gl_size != ret)
	{
		cerr << "ERR: inconsistent number of characters written\n";
        return true;	//Fail
	}

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	return false;	//OK
}	//end method: update_output | void

/****************************************************************************
**	Public Method
**	update_input | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	physical key are abstracted to virtual keys to be hardware independent
**	update the status of the virtual key buffer
**	false = released, up, inactive
**	true = pressed, down, active
****************************************************************************/

bool Anima::update_input( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//counter
	unsigned int t;
	//return flag
	bool f_ret;
	//Handle to console input buffer
	HANDLE h;
	//Return dword
	DWORD ret, ret_aux;
	//Input event structure
	INPUT_RECORD input_event[ max_input_events ];

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//Link handler
	h = this -> gl_console_input_handle;
	//if: fail
	if (h == INVALID_HANDLE_VALUE)
	{
		cerr << "ERR: bad input handle\n";
		return true; //Fail
	}

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//Get number of pending input events
	f_ret = GetNumberOfConsoleInputEvents( h, &ret );
	//if: fail
	if (f_ret == false)
	{
		cerr << "ERR: could not get number of pending input events\n";
		return true; //Fail
	}
	//if: at least one event has been detected
	if (ret > 0)
	{
		//if: above processing limits
		if (ret >= max_input_events)
		{
			cerr << "ERR: too many input events\n";
			return true; //Fail
		}
		//Get all the input event
		f_ret = ReadConsoleInput
		(
			h,
			input_event,
			ret,
			&ret_aux
		);
		//for: every input event
		for (t = 0;t < ret_aux; t++)
		{
			//switch: Decode event type
			switch(input_event[t].EventType)
			{
				//case: keyboard
				case KEY_EVENT:
				{
					//Structure holding key event
					KEY_EVENT_RECORD &event = input_event[t].Event.KeyEvent;
					//Record key status on virtual key buffer
					this -> gl_vk_buffer[ event.wVirtualKeyCode ] = event.bKeyDown;
					//true=down, pressed | false = up, released
					if (event.bKeyDown == true)
					{
						//Update most recent key pressed (active)
						this -> gl_last_vk_down = event.wVirtualKeyCode;
					}

					break;
				}
				//case: mouse
				case MOUSE_EVENT:
				{
					break;
				}
				//case: windows resize?
				case WINDOW_BUFFER_SIZE_EVENT:
				{
					break;
				}
				//case: focus/unfocus window
				case FOCUS_EVENT:
				{
					break;
				}
				//case: menu actions
				case MENU_EVENT:
				{
					break;
				}
				//unhandled input event
				default:
				{
					//do nothing
				}
			}	//end switch: Decode event type
		}	//end for: every input event
	}	//end if: at least one event has been detected
	//if: no event detected
	else
	{
		//clear the last key reading
		this -> gl_last_vk_down = 0;
	}

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	return false;	//OK
}	//end method: update_input | void

/****************************************************************************
*****************************************************************************
**	PRIVATE METHODS
*****************************************************************************
****************************************************************************/

/****************************************************************************
**	Private Method
**	load_console_handle | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	link the handle of the console
**	There is an input stream for inputs from mouse, keyboard, etc...
**	There is an output for the console. It's like an ASCII buffer
****************************************************************************/

bool Anima::load_console( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//return value
	bool f_ret;
	//temp handle
	HANDLE h;
	//temp info
	CONSOLE_SCREEN_BUFFER_INFO info;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	//initialize the console handle
	this -> gl_console_output_handle = INVALID_HANDLE_VALUE;

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//get handle to console
    h = GetStdHandle( STD_OUTPUT_HANDLE );
    //if: invalid handle
    if (h == INVALID_HANDLE_VALUE)
    {
		cerr << "ERR: bad console output handle\n";
        return true;	//FAIL
	}
	//Save handle
	this -> gl_console_output_handle = h;
	//Fill the console info structure
    f_ret = GetConsoleScreenBufferInfo( h, &info );
	//if: fail
    if (f_ret == false)
    {
		cerr << "ERR: could not load console info\n";
        return true;	//Fail
	}
	//Save info
	this -> gl_console_output_info = info;
	//Save console size
	this -> gl_rows = info.dwSize.Y;
	this -> gl_cols = info.dwSize.X;
	this -> gl_size = this -> gl_rows *this -> gl_cols;

	//Get handle to standard input of console associated to this process
	h = GetStdHandle( STD_INPUT_HANDLE );
    //if: fail
    if (h == INVALID_HANDLE_VALUE)
    {
		cerr << "ERR: bad console input handle\n";
		return true; //Fail
	}
	//save handle
	this -> gl_console_input_handle = h;

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	return false;	//OK
}	//end method: load_console_handle | void

/****************************************************************************
**	Private Method
**	init | void
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
****************************************************************************/

bool Anima::init( void )
{
	///--------------------------------------------------------------------------
	///	STATIC VARIABILE
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	LOCAL VARIABILE
	///--------------------------------------------------------------------------

	//return flag
	bool f_ret;

	///--------------------------------------------------------------------------
	///	CHECK
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	INITIALIZATIONS
	///--------------------------------------------------------------------------

	///--------------------------------------------------------------------------
	///	BODY
	///--------------------------------------------------------------------------

	//load the handle to the console
	f_ret = this -> load_console();
	//if: fail
	if (f_ret == true)
	{
		cerr << "ERR: failed to load handle to console\n";
		return true;
	}
	//Create ASCII output buffer
	this -> gl_ascii_buffer = vector<char>( this -> gl_size, ' ' );
	//Create input event vector
	this -> gl_vk_buffer = vector<char>( 256 );

	///--------------------------------------------------------------------------
	///	FINALIZATIONS
	///--------------------------------------------------------------------------

	return false;	//OK
}	//end method: init | void

/****************************************************************************
**	NAMESPACES
****************************************************************************/

} //End Namespace
