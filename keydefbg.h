/* keydefbg.h */

/*
 * history
 * 22 may 03: Anton Zinoviev <anton@lml.bas.bg> - creation
 */

#define NAME(x) x##_BG

#include <dos.h>
#include "mkeyb.h"


/********************************************************
 * BULGARIAN standard (BDS) keyboard mappings			*
 ********************************************************/

uchar NAME(scancodetable)[] = {

//* 1 */ PUNCT(0x02, '1', '!')
 /* 2 */ PUNCT(0x03, '2', '?')
 /* 3 */ PUNCT(0x04, '3', '+')
 /* 4 */ PUNCT(0x05, '4', '"')
//* 5 */ PUNCT(0x06, '5', '%')
 /* 6 */ PUNCT(0x07, '6', '=')
 /* 7 */ PUNCT(0x08, '7', ':')
 /* 8 */ PUNCT(0x09, '8', '/')
 /* 9 */ PUNCT(0x0A, '9', '�')
 /* 0 */ PUNCT(0x0B, '0', '�')
 /* - */ PUNCT(0x0C, '-', 'I')
 /* = */ PUNCT(0x0D, '.', 'V')

 /* q */ PUNCT(0x10, ',', '�')
 /* w */ ALPHA(0x11, '�', '�')
 /* e */ ALPHA(0x12, '�', '�')
 /* r */ ALPHA(0x13, '�', '�')
 /* t */ ALPHA(0x14, '�', '�')
 /* y */ ALPHA(0x15, '�', '�')
 /* u */ ALPHA(0x16, '�', '�')
 /* i */ ALPHA(0x17, '�', '�')
 /* o */ ALPHA(0x18, '�', '�')
 /* p */ ALPHA(0x19, '�', '�')
 /* [ */ ALPHA(0x1A, '�', '�')
 /* ] */ PUNCT(0x1B, ';', '�')

 /* a */ ALPHA(0x1E, '�', '�')
 /* s */ ALPHA(0x1F, '�', '�')
 /* d */ ALPHA(0x20, '�', '�')
 /* f */ ALPHA(0x21, '�', '�')
 /* g */ ALPHA(0x22, '�', '�')
 /* h */ ALPHA(0x23, '�', '�')
 /* j */ ALPHA(0x24, '�', '�')
 /* k */ ALPHA(0x25, '�', '�')
 /* l */ ALPHA(0x26, '�', '�')
 /* ; */ ALPHA(0x27, '�', '�')
 /* ' */ ALPHA(0x28, '�', '�')

 /* ~ */ PUNCT(0x29, '(', ')')
 /* \ */ PUNCT(0x2B, '\'','�')

 /* z */ ALPHA(0x2C, '�', '�')
 /* x */ ALPHA(0x2D, '�', '�')
 /* c */ ALPHA(0x2E, '�', '�')
 /* v */ ALPHA(0x2F, '�', '�')
 /* b */ ALPHA(0x30, '�', '�')
 /* n */ ALPHA(0x31, '�', '�')
 /* m */ ALPHA(0x32, '�', '�')
 /* , */ ALPHA(0x33, '�', '�')
 /* . */ ALPHA(0x34, '�', '�')
 /* / */ ALPHA(0x35, '�', '�')
	 0
};

struct KeyboardDefinition NAME(Keyboard) = {
	"BG",                             //char LanguageShort[4]; // "GR",
	"BULGARIAN - use right Ctrl to switch (by Anton Zinoviev)",  //char *Description; // created by, "with combis"
	DRIVER_FUNCTION_FASTSWITCH,          //char DriverFunctionRequired;
	NAME(scancodetable),              //char *ScancodeTable;
#ifdef COMBI
	{	NAME(combi1table),NAME(combi2table),NAME(combi3table),
		NAME(combi4table),NAME(combi5table),NAME(combi6table) },
#else
	{ 0 },
#endif			
	0,                                //char DezimalDingsbums;
	1,                                //char DefaultLayoutUS; // TRUE for non-latin languages
	} ;                               
                                      
                                      
                                      
