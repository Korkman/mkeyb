/* keydeftr.h */

/*
 * history
 * 17 apr 22: davide bresolin - creation
 */

#define NAME(x) x##_TR

#include <dos.h>
#include "mkeyb.h"

#define LANGUAGE "turkish-q"
#define STATUS   "untested, by Davide"

/********************************************************
 * TURKISH Q keyboard mappings				*
 ********************************************************/

/* keyboard image (by arkady)

Standard layout characters+scancodes:
�������������������������������������������������������������ͻ
�~29�!02�@03�#04�$05�%06�^07�&08�*09�(0A�)0B�-0C�=0D�Backsp 0E�
�������������������������������������������������������������Ķ
�Tab 0F�q10�w11�e12�r13�t14�y15�u16�i17�o18�p19�[1A�]1B�      �
�������������������������������������������������������� <��� �
� Caps 3A�a1E�s1F�d20�f21�g22�h23�j24�k25�l26�;27�'28�Enter 1C�
�������������������������������������������������������������Ķ
� Shift 2A �z2C�x2D�c2E�v2F�b30�n31�m32�,33�.34�/35� Shift 36 �
�������������������������������������������������������������Ķ
� Ctrl 1D� Alt 38�\56�    Spacebar 39    �\2B�Alt E38�Ctrl E1D�
�������������������������������������������������������������ͼ
*/

/* Created from the Turkish Q Layout at http://kbdlayout.info/kbdtuq
   Codepage: 857
   
Changes from US layout. An extra '@' at the end is a COMBI key

Code	US	Norm	Shift	AltGr	AltGr+Shift
----------------------------------------------------------------
02	1	1	!	>		// DIGIT ONE, EXCLAMATION MARK, GREATER-THAN SIGN
03	2	2	'	0x9C		// DIGIT TWO, APOSTROPHE, POUND SIGN
04	3	3	^@	#		// DIGIT THREE, CIRCUMFLEX ACCENT, NUMBER SIGN
05	4	4	+	$		// DIGIT FOUR, PLUS SIGN, DOLLAR SIGN
06	5	5	%	0xAB		// DIGIT FIVE, PERCENT SIGN, VULGAR FRACTION ONE HALF
07	6	6	&			// DIGIT SIX, AMPERSAND
08	7	7	/	{		// DIGIT SEVEN, SOLIDUS, LEFT CURLY BRACKET
09	8	8	(	[		// DIGIT EIGHT, LEFT PARENTHESIS, LEFT SQUARE BRACKET
0a	9	9	)	]		// DIGIT NINE, RIGHT PARENTHESIS, RIGHT SQUARE BRACKET
0b	0	0	=	}		// DIGIT ZERO, EQUALS SIGN, RIGHT CURLY BRACKET
0c	-	*	?	\		// ASTERISK, QUESTION MARK, REVERSE SOLIDUS
0d	=	-	_	|		// HYPHEN-MINUS, LOW LINE, VERTICAL LINE
10	Q	q	Q	@		// LATIN SMALL LETTER Q, LATIN CAPITAL LETTER Q, COMMERCIAL AT
12	E	e	E	0xD5		// LATIN SMALL LETTER E, LATIN CAPITAL LETTER E, EURO SIGN
17	I	0x8D	I			// LATIN SMALL LETTER DOTLESS I, LATIN CAPITAL LETTER I
1a	[	0xA7	0xA8	0xF9@		// LATIN SMALL LETTER G WITH BREVE, LATIN CAPITAL LETTER G WITH BREVE, DIAERESIS
1b	]	0x81	0x9A	~@		// LATIN SMALL LETTER U WITH DIAERESIS, LATIN CAPITAL LETTER U WITH DIAERESIS, TILDE
1f	S	s	S	0xE1		// LATIN SMALL LETTER S, LATIN CAPITAL LETTER S, LATIN SMALL LETTER SHARP S
27	;	0x9F	0x9E	0xEF@		// LATIN SMALL LETTER S WITH CEDILLA, LATIN CAPITAL LETTER S WITH CEDILLA, ACUTE ACCENT
28	'	i	0x98			// LATIN SMALL LETTER I, LATIN CAPITAL LETTER I WITH DOT ABOVE
29	`	"	0x82	<		// QUOTATION MARK, LATIN SMALL LETTER E WITH ACUTE, LESS-THAN SIGN
2b	        ,	;	`@		// COMMA, SEMICOLON, GRAVE ACCENT
33	,	0x94	0x99			// LATIN SMALL LETTER O WITH DIAERESIS, LATIN CAPITAL LETTER O WITH DIAERESIS
34	.	0x87	0x80			// LATIN SMALL LETTER C WITH CEDILLA, LATIN CAPITAL LETTER C WITH CEDILLA
35	/	.	:			// FULL STOP, COLON
56	\	<	>	|		// LESS-THAN SIGN, GREATER-THAN SIGN, VERTICAL LINE

*/

uchar NAME(scancodetable)[] = {

 /* ` */ PUNCT_ALTGR	(0x29, '"',  0x82,      '<'   )
 /* 1 */ PUNCT_ALTGR	(0x02, '1',  '!',       '>'   )
 /* 2 */ PUNCT_ALTGR	(0x03, '2',  '\'',      0x9C  )
#ifdef COMBI
 /* 3 */ PUNCT_ALTGR	(0x04, '3',  COMBI1,    '#'   )
#else
 /* 3 */ PUNCT_ALTGR	(0x04, '3',  '^',       '#'   )
#endif
 /* 4 */ PUNCT_ALTGR	(0x05, '4',  '+',       '$'   )
 /* 5 */ PUNCT_ALTGR	(0x06, '5',  '%',       0xAB  )
 /* 6 */ PUNCT		(0x07, '6',  '&'              )
 /* 7 */ PUNCT_ALTGR	(0x08, '7',  '/',       '{'   )
 /* 8 */ PUNCT_ALTGR	(0x09, '8',  '(',       '['   )
 /* 9 */ PUNCT_ALTGR	(0x0a, '9',  ')',       ']'   )
 /* 0 */ PUNCT_ALTGR	(0x0b, '0',  '=',       '}'   )
 /* - */ PUNCT_ALTGR	(0x0c, '*',  '?',       '\\'  )
 /* = */ PUNCT_ALTGR	(0x0d, '-',  '_',       '|'   )

 /* Q */ ALPHA_ALTGR	(0x10, 'q',  'Q',       '@'   )
 /* E */ ALPHA_ALTGR	(0x12, 'e',  'E',       0xD5  )
 /* I */ ALPHA		(0x17, 0x8D, 'I'              )
#ifdef COMBI
 /* [ */ ALPHA_ALTGR	(0x1a, 0xA7, 0xA8,      COMBI2)
 /* ] */ ALPHA_ALTGR	(0x1b, 0x81, 0x9A,      COMBI3)
#else
 /* [ */ ALPHA_ALTGR	(0x1a, 0xA7, 0xA6,      0xF9  )
 /* ] */ ALPHA_ALTGR	(0x1b, 0x81, 0x9A,      '~'   )
#endif

 /* S */ ALPHA_ALTGR	(0x1f, 's',  'S',       0xE1  )
#ifdef COMBI
 /* ; */ ALPHA_ALTGR	(0x27, 0x9F, 0x9E,      COMBI4)
 /*   */ PUNCT_ALTGR	(0x2b, ',',  ';',       COMBI5)
#else
 /* ; */ ALPHA_ALTGR	(0x27, 0x9F, 0x9E,      0xEF  )
 /*   */ PUNCT_ALTGR	(0x2b, ',',  ';',       '`'   )
#endif
 /* ' */ ALPHA		(0x28, 'i',  0x98             )

 /* , */ ALPHA		(0x33, 0x94, 0x99             )
 /* . */ ALPHA		(0x34, 0x87, 0x80             )
 /* / */ PUNCT		(0x35, '.',  ':'              )
 /* \ */ PUNCT_ALTGR	(0x56, '<',  '>',      '|'    )

	 0
};

struct KeyboardDefinition NAME(Keyboard) = {
	"TR",                                          //char LanguageShort[4];			// "GR",
	"TURKISH - Q layout (untested, by Davide)",    //char *Description;			// created by, "with combis"
	DRIVER_FUNCTION_NORMAL,                        //char DriverFunctionRequired;
	NAME(scancodetable),                           //char *ScancodeTable;
#ifdef COMBI
	{	NAME(combi1table),NAME(combi2table),NAME(combi3table),
		NAME(combi4table),NAME(combi5table),NAME(combi6table) },
#else
	{ 0 },
#endif			
	',',                                           //char DezimalDingsbums;                                        
	0,                                             //char DefaultLayoutUS;			// TRUE for russian             
	} ;
