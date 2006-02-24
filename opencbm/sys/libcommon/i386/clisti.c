/*
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version
 *  2 of the License, or (at your option) any later version.
 *
 *  Copyright 2006 Spiro Trikaliotis
 *
 */

/*! ************************************************************** 
** \file sys/libcommon/i386/clisti.c \n
** \author Spiro Trikaliotis \n
** \version $Id: clisti.c,v 1.2 2006-02-24 12:21:43 strik Exp $ \n
** \n
** \brief Wrappers for CLI/STI for the different platforms. Here: i386
**
****************************************************************/

#include <wdm.h>
#include "cbm_driver.h"

/*! \brief Stop interrupts with CLI assembler command

 This function stops interrupts on the current CPU by executing a CLI
 assembler command.
*/
VOID
CLI(VOID)
{
    __asm cli
}

/*! \brief Restart interrupts with STI assembler command

 This function stops interrupts on the current CPU by executing a STI
 assembler command.
*/
VOID
STI(VOID)
{
    __asm sti
}
