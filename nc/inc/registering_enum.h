/**
 * Steve Rabin - The Simplest AI Trick in the Book
 * https://youtu.be/iVBCBcEANBc
 */

#ifndef REGISTERING_ENUM
#define REGISTERING_ENUM

// Create the Enum
#define COLOR(x) x,
typedef enum
{
	#include "color.h"
	COLOR_NUM
} Color;
#undef COLOR

// Create the Strings
#define COLOR(x) #x,
static const char* ColorName[] =
{
	#include "color.h"
	"Invalid"
};
#undef COLOR

#endif
