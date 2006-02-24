/*
 *	This program is free software; you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License
 *	as published by the Free Software Foundation; either version
 *	2 of the License, or (at your option) any later version.
 *
 *  Copyright 1999 Michael Klein <michael(dot)klein(at)puffin(dot)lb(dot)shuttle(dot)de>
*/

#ifdef SAVE_RCSID
static char *rcsid =
    "@(#) $Id: morse.c,v 1.3 2006-02-24 12:21:40 strik Exp $";
#endif

#include "opencbm.h"

#include "arch.h"

#include <fcntl.h>
#include <stdlib.h>

static unsigned char morse[] = {
#include "morse.inc"
};

int ARCH_MAINDECL main(int argc, char *argv[])
{
    __u_char drv = argc > 1 ? arch_atoc(argv[1]) : 8;
    CBM_FILE fd;
    
    if(cbm_driver_open(&fd, 0) == 0)
    {
        cbm_upload(fd, drv, 0x0500, morse, sizeof(morse));
        cbm_listen(fd, drv, 15);
        cbm_raw_write(fd, "U3:SOS", 6);
        cbm_unlisten(fd);
        cbm_driver_close(fd);
        return 0;
    }
    return 1;
}
