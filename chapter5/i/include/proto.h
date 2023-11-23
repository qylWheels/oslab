/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            proto.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef _ORANGE_PROTO_H_
#define _ORANGE_PROTO_H_

#include "const.h"

/* klib.asm */
PUBLIC void	out_byte(u16 port, u8 value);
PUBLIC u8	in_byte(u16 port);
PUBLIC void	disp_str(char * info);
PUBLIC void	disp_color_str(char * info, int color);
PUBLIC void	init_prot();
PUBLIC void	init_8259A();

PUBLIC void *alloc_page();
PUBLIC void free_page(void *base);
PUBLIC u8 get_page_status(void *base);

PUBLIC void toggle_my_int();

#endif /* _ORANGE_PROTO_H_ */
