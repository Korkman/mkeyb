/* keydefpo.h */

/*
 * history
 * 26 apr 02: tom ehlert - creation
 */  
 
#define NAME(x) x##_PO


#include <dos.h>
#include "mkeyb.h"
 

#define LANGUAGE "portugese"
#define STATUS   "first try"

/********************************************************
 * PORTUGESE keyboard mappings				*
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

/* copied mostly from norvegian,
   changed

	 5  4 $  .  . �
	12  ' ?  .  . .
	13  � �  .  . .
	26  + *  .  . �
	27  � `  .  . .
	39C � �  .  . .
	40  � �  .  . .
	41  \ | #28 . .
	43  ~ ^ #28 . .
	83N . .  .  . !255
*/

uchar NAME(scancodetable)[] = {

 /* 2 */ PUNCT_ALTGR	 (0x03, '2', '"',	 '@') /*  3 2 #34  .  . @ */
 /* 3 */ PUNCT_ALTGR	 (0x04, '3', '#',	0x9C) /*  4 3 #35  .  . � */
 /* 4 */ PUNCT_ALTGR	 (0x05, '4', '$',	0xF5) /*  5 4  $   .  . � */
 /* 5 */ PUNCT		 (0x06, '5', '%'	    ) /*  6 5  %   .  . . */
 /* 6 */ PUNCT_CTRL	 (0x07, '6', '&',0x1E	    ) /*  7 6  &  #30 . . */
 /* 7 */ PUNCT_ALTGR	 (0x08, '7', '/',	 '{') /*  8 7  /   .  . { */
 /* 8 */ PUNCT_CTRL_ALTGR(0x09, '8', '(',0x1B,	 '[') /*  9 8  (  #27 . [ */
 /* 9 */ PUNCT_CTRL_ALTGR(0x0A, '9', ')',0x1D,	 ']') /* 10 9  )  #29 . ] */
 /* 0 */ PUNCT_ALTGR	 (0x0B, '0', '=',	 '}') /* 11 0  =   .  . } */
 /* - */ PUNCT		 (0x0C,'\'', '?'	    ) /* 12 '  ?   .  . . */
 /* = */ PUNCT		 (0x0D,0xAE,0xAF	    ) /* 13 �  �   .  . . */

 /* [ */ PUNCT_ALTGR	 (0x1A,0x86,0x8F,	0xF9) /* 26  + *  .  . � */
 /* ] */ PUNCT		 (0x1B,0xEF, '`'	    ) /* 27  � `  .  . . */
 /* ; */ ALPHA		 (0x27,0x87,0x80	    ) /* 39C � �  .  . . */
 /* ' */ PUNCT		 (0x28,0xA7,0xA6	    ) /* 40  � �  .  . . */
 /* ~ */ PUNCT		 (0x29,'\\', '|'	    ) /* 41  \ | #28 . . */
 /* \ */ PUNCT		 (0x2B, '~', '^'	    ) /* 43  ~ ^ #28 . . */
 /* , */ PUNCT		 (0x33, ',', ';'	    ) /* 51  , ;  .  . . */
 /* . */ PUNCT		 (0x34, '.', ':'	    ) /* 52  . :  .  . . */
 /* / */ PUNCT		 (0x35, '-', '_'	    ) /* 53  - _ #31 . . */
 /*   */ PUNCT		 (0x56, '<', '>'	    ) /* 86  < >  .  . . */   
 
 /* E */ ALTGR           (0x12, EURO)          // Added by Snoopy81

	 0
};

struct KeyboardDefinition NAME(Keyboard) = {
	"PO",                                          //char LanguageShort[4];			// "GR",                    
	"PORTUGAL - portugese keyboard (by tom)",  //char *Description;				// created by, "with combis"
	DRIVER_FUNCTION_NORMAL,                        //char DriverFunctionRequired;                                  
	NAME(scancodetable),                           //char *ScancodeTable;                                          
#ifdef COMBI
	{	NAME(combi1table),NAME(combi2table),NAME(combi3table),
		NAME(combi4table),NAME(combi5table),NAME(combi6table) },
#else
	{ 0 },
#endif			
	0,                                           //char DezimalDingsbums;                                        
	0,                                             //char DefaultLayoutUS;			// TRUE for russian             
	} ;
