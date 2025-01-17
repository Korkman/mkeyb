/* keydefbr.h */


#define NAME(x) x##_BR


#include <dos.h>
#include "mkeyb.h"


#define COMBI

/***comments from original author (Henrique Peron - hperon@brturbo.com)***

ABNT Brazilian XKeyb keyboard layout.
Henrique Peron
hperon@brturbo.com

********************************************************/

/* table layout:

key on US keyboard,
        scancode,
                flags, what is defined
                        3 keys for NORMAL+CTRL, 1 for ALTGREY
*/

uchar NAME(scancodetable)[] = {

 /* 1 */       ALTGR     (0x02,                  '�')
 /* 2 */       ALTGR     (0x03,                  '�')
 /* 3 */       ALTGR     (0x04,                  '�')
 /* 4 */       ALTGR     (0x05,                  '�')
 /* 5 */       ALTGR     (0x06,                  '�')
 /* 6 */ PUNCT_ALTGR     (0x07,'6', COMBI5,      '�')
 /* = */  CTRL_ALTGR     (0x0D,     COMBI6,      '�')
 /* ] */ PUNCT_ALTGR     (0x1B,'[','{',           '�')
 /*   */ ALPHA           (0x27,'�','�'               )
//*???*/                 (0x28,                      )
 /* ' */ PUNCT           (0x29,0x27,0x22             )
 /* ] */ PUNCT_ALTGR     (0x2b,']','}',           '�')
 /* ' */ PUNCT           (0x35,';',':'               )
 /* ? */ PUNCT           (0x56,'\\','|'              )
 /* ? */ PUNCT_ALTGR     (0x73,'/','?',           '�')
 /* ? */ PUNCT           (0x7e,'.','.'               )

 /* E */ ALTGR           (0x12, EURO)          // Added by Snoopy81


#ifdef COMBI
 /* [ */ PUNCT           (0x1A,COMBI3,COMBI4        )
 /* ' */ PUNCT           (0x28,COMBI1,COMBI2        )
#endif
         0
};

/* these keys are generated on a COMBI+character base,
   don't know if that is correct.
   I also don't know what keys to generate, as the
   standard character set (DOS/BIOS) doesn't have
   norwegian/swedish/spanish characters
*/

#ifdef COMBI

uchar NAME(combi1table)[] = {         /* ~ a� n� o� #32~ A� N� O� */
        /*scancode lower upper*/
 /* A */ 0x1E, '�','�',
 /* O */ 0x18, '�','�',
 /* N */ 0x31, '�','�',
 /*   */ 0x39, '~', '~', /* and additional generated character */
         0
};

uchar NAME(combi2table)[] = {         /* ^ a� e� i� o� u� #32^ A� E� I� O� U� */
        /*scancode lower upper*/
 /* A */ 0x1E,'�','�',
 /* E */ 0x12,'�','�',
 /* I */ 0x17,'�','�',
 /* O */ 0x18,'�','�',
 /* U */ 0x16,'�','�',
 /*   */ 0x39,  '^',  '^', /* and additional generated character */
         0
};

uchar NAME(combi3table)[] = {         /* � a� e� i� o� u� y� #32� A� E� I� O� U� Y� */
        /*scancode lower upper*/
 /* A */ 0x1E, '�','�',
 /* E */ 0x12, '�','�',
 /* I */ 0x17, '�','�',
 /* O */ 0x18, '�','�',
 /* U */ 0x16, '�','�',
 /* Y */ 0x15, '�','�',
 /*   */ 0x39,  '�',  '�', /* and additional generated character */
         0
};

uchar NAME(combi4table)[] = {         /* ` a� e� i� o� u� #32` A� E� I� O� U� */
        /*scancode lower upper*/
 /* A */ 0x1E,'�','�',
 /* E */ 0x12,'�','�',
 /* I */ 0x17,'�','�',
 /* O */ 0x18,'�','�',
 /* U */ 0x16,'�','�',
 /*   */ 0x39,  '`',  '`', /* and additional generated character */
         0
};

uchar NAME(combi5table)[] = {         /* � a� e� i� o� u� y� #32� A� E� I� O� U� */
        /*scancode lower upper*/
 /* A */ 0x1E,'�','�',
 /* E */ 0x12,'�','�',
 /* I */ 0x17,'�','�',
 /* O */ 0x18,'�','�',
 /* U */ 0x16,'�','�',
 /* Y */ 0x15,'�', 0,           /* Y character not available in CP850 */

 /*   */ 0x39,  '�',  '�', /* and additional generated character */
         0
};

uchar NAME(combi6table)[] = {		/* <Ctrl> + <=> combinations, " ����� �����  */
	/*scancode lower upper*/
 /* A */ 0x1E,'�','�',
 /* E */ 0x12,'�','�',
 /* O */ 0x18,'�','�',
 /* D */ 0x20,'�','�',
 /* T */ 0x14,'�','�', 
 /*   */ 0x39,  '?',  '?', /* and additional generated character */
	
	 0
};

#endif


struct KeyboardDefinition NAME(Keyboard) = {
	"BR",                                    //char LanguageShort[4];			// "GR",                    
	"BRAZIL - portuguese keyboard with combis (Henrique Peron)",//char *Description;				// created by, "with combis"
	DRIVER_FUNCTION_FULL,                    //char DriverFunctionRequired;                                
	NAME(scancodetable),                     //char *ScancodeTable;                                        
#ifdef COMBI
	{	NAME(combi1table),NAME(combi2table),NAME(combi3table),
		NAME(combi4table),NAME(combi5table),NAME(combi6table) },
#else
	{ 0 },
#endif			
	',',                                     //char DezimalDingsbums;                                      
	0,                                       //char DefaultLayoutUS;			// TRUE for russian         
	} ;
