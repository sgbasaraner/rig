#include <stdint.h>

// aliases for data types
typedef uint8_t  BYTE;
typedef uint32_t DWORD;
typedef int32_t  LONG;
typedef uint16_t WORD;

// Adapted from https://msdn.microsoft.com/en-us/library/dd183374(v=vs.85).aspx.

typedef struct 
{ 
    WORD type; 
    DWORD size; 
    WORD reserved1; 
    WORD reserved2; 
    DWORD offBits; 
} __attribute__((__packed__)) 
BITMAPFILEHEADER; 

typedef struct
{
    DWORD size; 
    LONG width; 
    LONG height; 
    WORD planes; 
    WORD bitCount; 
    DWORD compression; 
    DWORD sizeImage; 
    LONG xPelsPerMeter; 
    LONG yPelsPerMeter; 
    DWORD clrUsed; 
    DWORD clrImportant; 
} __attribute__((__packed__))
BITMAPINFOHEADER; 

typedef struct
{
    BYTE blue;
    BYTE green;
    BYTE red;
} __attribute__((__packed__))
RGBTRIPLE;
