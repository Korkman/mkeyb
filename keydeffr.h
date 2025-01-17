/* keydeffr.h */



/*
 * history
 * 25 aug 02: tom ehlert - creation
 * 21 oct 02: Snoopy 81 modifications & combos.
 Mail:Snoopy81@ifrance.om
 */


#define NAME(x) x##_FR


#include <dos.h>
#include "mkeyb.h"

#define COMBI


/********************************************************
 * FRENCH keyboard mappings                             *
 ********************************************************/

uchar NAME(scancodetable)[] = {

 /* 1 */ ALPHA           (0x02, '&', '1'         )
 /* 2 */ ALPHA_ALTGR     (0x03, '�', '2',     '~')
 /* 3 */ ALPHA_ALTGR     (0x04, '"', '3',     '#')
 /* 4 */ ALPHA_ALTGR     (0x05, '\'','4',     '{')
 /* 5 */ ALPHA_ALTGR     (0x06, '(', '5',     '[')
 /* 6 */ ALPHA_CTRL_ALTGR(0x07, '-', '6',0x1e,'|')
 /* 7 */ ALPHA_ALTGR     (0x08, '�', '7',     '`')
 /* 8 */ ALPHA_CTRL_ALTGR(0x09, '_', '8',0x1c,'\\')
 /* 9 */ ALPHA_ALTGR     (0x0A, '�', '9',     '^')
 /* 0 */ ALPHA_ALTGR     (0x0B, '�', '0',     '@')
 /* 0 */ ALPHA_ALTGR     (0x0c, ')', '�',     ']')
 /* 0 */ ALPHA_CTRL_ALTGR(0x0d, '=', '+',0x1f,'}')


// /* Q */ REPLACE        (0x10, 0x1e             )	// Q-->A
// /* W */ REPLACE        (0x11, 0x2c             )   // W-->Z
// /* A */ REPLACE        (0x1e, 0x10             )	// A-->Q
// /* Z */ REPLACE        (0x2c, 0x11             )   // Z-->W
// /* ; */ REPLACE        (0x27, 0x32             )   // ;-->M     
                                                           
 /* Q */ PUNCT_ALTGR	(0x10, 'a', 'A', 'a' & 0x1f )
 /* A */ PUNCT_ALTGR	(0x1e, 'q', 'Q', 'q' & 0x1f )
 /* W */ PUNCT_ALTGR	(0x11, 'z', 'Z', 'z' & 0x1f )
 /* Z */ PUNCT_ALTGR	(0x2c, 'w', 'W', 'w' & 0x1f )
 /* ; */ PUNCT_ALTGR	(0x27, 'm', 'M', 'm' & 0x1f )

                                                           
                                                           

 /* E */ ALTGR           (0x12, EURO)          // Added by Snoopy81

 /* Combis by Snoopy81*/
#ifdef COMBI
 /* ] */ ALPHA           (0x1a, COMBI1, COMBI2 )
#else
 /* ] */ ALPHA           (0x1a, '^', '�'   )   // ^�
#endif

 /* ] */ ALPHA_ALTGR     (0x1b, '$', '�','�'     )   // $�

 /* , */ ALPHA           (0x28, '�', '%'   )   // �%
 /* ` */ ALPHA           (0x29, '�',  0    )   // under ESC key...
 /* \ */ ALPHA           (0x2b, '*', '�'   )   // *�
 /* ; */ ALPHA           (0x32, ',', '?'   )   // ,?
 /* M */ ALPHA           (0x33, ';', '.'   )   // ;.
 /* . */ ALPHA           (0x34, ':', '/'   )   // :/
 /* / */ ALPHA           (0x35, '!', ''   )   // Changed by Snoopy81
 /*   */ ALPHA           (0x56,'<', '>'    )   // <>
         0
};


/* these keys are generated on a COMBI+character base,
   don't know if that is correct.
   I also don't know what keys to generate, as the
   standard character set (DOS/BIOS) doesn't have

*/

#ifdef COMBI
/*	COMBIS works OK with CodePage 850
but gives graphics chars with CP437 (MS Keyb.com takes care of CP...)
*/
uchar NAME(combi1table)[] = {         /* ^ a� e� i� o� u� #32^ */
	/*scancode lower upper */

 /* A */ 0x10, '�', '�',
 /* E */ 0x12, '�', '�',
 /* I */ 0x17, '�', '�',
 /* O */ 0x18, '�', '�',
 /* U */ 0x16, '�', '�',
 /*   */ 0x39,  '^',  '^', /* and additional generated character */
	 0
};

uchar NAME(combi2table)[] = {         /* � a� e� i� o� u� A� O� U� y� #32� */
        /*scancode lower upper*/
 /* A */ 0x10, '�', '�',
 /* E */ 0x12, '�', '�',
 /* I */ 0x17, '�', '�',
 /* O */ 0x18, '�', '�',
 /* U */ 0x16, '�', '�',
 /* Y */ 0x15, '�',  0 , /* no Y character ?? */
 /*   */ 0x39, '�', '�', /* and additional generated character */
	 0
};
uchar NAME(combi3table)[] = { /*scancode lower upper*/ 0 };
uchar NAME(combi4table)[] = { /*scancode lower upper*/ 0 };
uchar NAME(combi5table)[] = { /*scancode lower upper*/ 0 };
uchar NAME(combi6table)[] = { /*scancode lower upper*/ 0 };
#endif


struct KeyboardDefinition NAME(Keyboard) = {
        "FR",                   //char LanguageShort[4];
        "FRANCAIS - clavier AZERTY (Snoopy81)",  //char *Description;
        DRIVER_FUNCTION_FULL,   //char DriverFunctionRequired;
        NAME(scancodetable),    //char *ScancodeTable;
#ifdef COMBI
        {       NAME(combi1table),NAME(combi2table),NAME(combi3table),
                NAME(combi4table),NAME(combi5table),NAME(combi6table) },
#else
        { 0 },
#endif
        0,// ',',           //char DezimalDingsbums;
        0,                  //char DefaultLayoutUS;   // TRUE for russian
        } ;
