/**********************************************************************************
**	ENVIROMENT VARIABILE
**********************************************************************************/

#ifndef ANIMA_H_
	#define ANIMA_H_

/**********************************************************************************
**	GLOBAL INCLUDES
**********************************************************************************/

/**********************************************************************************
**	DEFINES
**********************************************************************************/

/**********************************************************************************
**	MACROS
**********************************************************************************/

//Numeric virtual Keys codes
enum
{
	VK_0 = 0x30,
	VK_1 = 0x31,
	VK_2 = 0x32,
	VK_3 = 0x33,
	VK_4 = 0x34,
	VK_5 = 0x35,
	VK_6 = 0x36,
	VK_7 = 0x37,
	VK_8 = 0x38,
	VK_9 = 0x39
};

//Letter virtual keys codes.
//NOTE: there is no difference between capital and lower case with virtual keys. look for caps lock or shift if you must.
enum
{
	VK_A = 0x41,
	VK_B = 0x42,
	VK_C = 0x43,
	VK_D = 0x44,
	VK_E = 0x45,
	VK_F = 0x46,
	VK_G = 0x47,
	VK_H = 0x48,
	VK_I = 0x49,
	VK_J = 0x4A,
	VK_K = 0x4B,
	VK_L = 0x4C,
	VK_M = 0x4D,
	VK_N = 0x4E,
	VK_O = 0x4F,
	VK_P = 0x50,
	VK_Q = 0x51,
	VK_R = 0x52,
	VK_S = 0x53,
	VK_T = 0x54,
	VK_U = 0x55,
	VK_V = 0x56,
	VK_W = 0x57,
	VK_X = 0x58,
	VK_Y = 0x59,
	VK_Z = 0x5A
};

/**********************************************************************************
**	NAMESPACE
**********************************************************************************/

//Assign class to a namespace
namespace User
{

/**********************************************************************************
**	TYPEDEFS
**********************************************************************************/

/**********************************************************************************
**	PROTOTYPE: STRUCTURES
**********************************************************************************/

/**********************************************************************************
**	PROTOTYPE: GLOBAL VARIABILES
**********************************************************************************/

/**********************************************************************************
**	PROTOTYPE: CLASS
**********************************************************************************/

/****************************************************************************
**	Class
**	Anima
*****************************************************************************
**	PARAMETER:
**	RETURN:
**	DESCRIPTION:
**	This is a low level class that interfaces with the Windows API for the console
**	It allows to syncronize the console with an output ACSII buffer
**	it allow to synchronize the virtual keys status buffer (UP/DOWN for each key)
****************************************************************************/

class Anima
{
	//Visible to all
	public:
		///--------------------------------------------------------------------------
		///	CONSTRUCTORS
		///--------------------------------------------------------------------------

		//Default constructor
		Anima( void );

		///--------------------------------------------------------------------------
		///	DESTRUCTORS
		///--------------------------------------------------------------------------

		//Default destructor
		~Anima( void );

		///--------------------------------------------------------------------------
		///	OPERATORS
		///--------------------------------------------------------------------------

		//ASCII buffer reference operator
		char &out( unsigned int row, unsigned int col );
		//Virtual Key reference operator
		char &in( unsigned int key );

		///--------------------------------------------------------------------------
		///	SETTERS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	GETTERS
		///--------------------------------------------------------------------------

		//Console size
		unsigned int get_rows( void );
		//Console size
		unsigned int get_cols( void );
		//return the last key that was pressed
		char get_last_vk( void );

		///--------------------------------------------------------------------------
		///	TESTERS
		///--------------------------------------------------------------------------

		//Test if the engine is running as intended
		bool is_invalid( void );

		///--------------------------------------------------------------------------
		///	PUBLIC METHODS
		///--------------------------------------------------------------------------

		//sync the buffer with the console
		bool update_output( void );
		//update the status of the virtual key buffer
		bool update_input( void );

		///--------------------------------------------------------------------------
		///	PUBLIC STATIC METHODS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PUBLIC VARS
		///--------------------------------------------------------------------------

		//Maximum number of input events
		static const int max_input_events = 100;

	//Visible to derived classes
	protected:
		///--------------------------------------------------------------------------
		///	PROTECTED METHODS
		///--------------------------------------------------------------------------

		///--------------------------------------------------------------------------
		///	PROTECTED VARS
		///--------------------------------------------------------------------------

	//Visible only inside the class
	private:
		///--------------------------------------------------------------------------
		///	PRIVATE METHODS
		///--------------------------------------------------------------------------

		//link the handle of the console
		bool load_console( void );
		//Initialize the anima class
		bool init( void );

		///--------------------------------------------------------------------------
		///	PRIVATE VARS
		///--------------------------------------------------------------------------

		//Handle to standard output console
		HANDLE gl_console_output_handle;
		//handle to standard input console
		HANDLE gl_console_input_handle;
		//Console informations
		CONSOLE_SCREEN_BUFFER_INFO gl_console_output_info;
		//Console dimensions
		unsigned int gl_rows, gl_cols, gl_size;
		//ASCII output buffer
		std::vector<char> gl_ascii_buffer;
		//Status of the virtual keys. 0=UP. 1=DOWN
		std::vector<char> gl_vk_buffer;
		//Most recent key that has been pressed
		char gl_last_vk_down;
};	//End Class: Anima

/**********************************************************************************
**	NAMESPACE
**********************************************************************************/

} //End Namespace

#else
    #warning "Multiple inclusion of hader file"
#endif
