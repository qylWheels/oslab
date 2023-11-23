
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            start.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "global.h"


/*======================================================================*
                            cstart
 *======================================================================*/
PUBLIC void cstart()
{
	disp_str("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
		 "-----\"cstart\" begins-----\n");

	/* 将 LOADER 中的 GDT 复制到新的 GDT 中 */
	memcpy(&gdt,				  /* New GDT */
	       (void*)(*((u32*)(&gdt_ptr[2]))),   /* Base  of Old GDT */
	       *((u16*)(&gdt_ptr[0])) + 1	  /* Limit of Old GDT */
		);
	/* gdt_ptr[6] 共 6 个字节：0~15:Limit  16~47:Base。用作 sgdt/lgdt 的参数。*/
	u16* p_gdt_limit = (u16*)(&gdt_ptr[0]);
	u32* p_gdt_base  = (u32*)(&gdt_ptr[2]);
	*p_gdt_limit = GDT_SIZE * sizeof(DESCRIPTOR) - 1;
	*p_gdt_base  = (u32)&gdt;

	/* idt_ptr[6] 共 6 个字节：0~15:Limit  16~47:Base。用作 sidt/lidt 的参数。*/
	u16* p_idt_limit = (u16*)(&idt_ptr[0]);
	u32* p_idt_base  = (u32*)(&idt_ptr[2]);
	*p_idt_limit = IDT_SIZE * sizeof(GATE) - 1;
	*p_idt_base  = (u32)&idt;

	init_prot();

	disp_str("-----\"cstart\" ends-----\n");

	disp_pos = 0;
	pmm_init();
	void *phy_page = alloc_page();
	disp_str("physical page base addr: ");
	disp_int((int)phy_page);
	disp_str("\n");

	int a = 5 / 0;
	disp_int(a);
	
	// disp_str("physical page status: ");
	// if (get_page_status(phy_page) == PAGE_FREE) {
	// 	disp_str("free\n");
	// } else {
	// 	disp_str("allocated\n");
	// }

	// free_page(phy_page);
	// disp_str("physical page status: ");
	// if (get_page_status(phy_page) == PAGE_FREE) {
	// 	disp_str("free\n");
	// } else {
	// 	disp_str("allocated\n");
	// }
}
