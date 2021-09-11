/*
 * keyb.h
 *
 *  Created on: Apr 8, 2020
 *      Author: user
 */

#ifndef INC_KEYB_H_
#define INC_KEYB_H_

#define KEY_PORT   PIND

#define KEY0 ( 1 << 0 )
#define KEY1 ( 1 << 1 )
#define KEY2 ( 1 << 2 )
#define KEY3 ( 1 << 3 )
#define KEY4 ( 1 << 4 )

#define KEY_LEFT  	KEY0
#define KEY_UP    	KEY1
#define KEY_RIGHT   KEY2
#define KEY_DOWN  	KEY3
#define KEY_OK 		KEY4
#define ANYKEY     (KEY0 | KEY1 | KEY2 | KEY3 | KEY4)
#define KEY_MASK   (KEY0 | KEY1 | KEY2 | KEY3 | KEY4)

#define KBD_LOCK     1
#define KBD_NOLOCK   0

#define KBD_DEFAULT_ART   ((void *)0)

void
ClrKeyb( int lock );

unsigned int
GetKeys( void );

unsigned int
KeysTime( void );

unsigned int
IsKeyPressed( unsigned int mask );

unsigned int
IsKey( unsigned int mask );

void
KeybLock( void );

void
KeybSetAutoRepeatTimes( unsigned short * AutoRepeatTab );

void
KeybProc( void );

#endif /* INC_KEYB_H_ */
