#include "const.h"
#include "global.h"
#include "proto.h"
#include "type.h"

const u32 PPN_START = 1;	// we want too use NULL as invalid value
const u32 PPN_LIMIT = 1 << 20;

PUBLIC
void
pmm_init()
{
	for (u32 i = 0; i < BYTE_OF_BITMAP; i += 1) {
		bitmap[i] = 0;
	}
}

PUBLIC
void *
alloc_page()
{
	u32 ppn = 0;	// physical page number
	void *base = NULL;
	for (ppn = PPN_START; ppn < PPN_LIMIT; ppn += 1) {
		if (PAGE_FREE == get_page_status((void *)(ppn << 12))) {
			bitmap[ppn / 8] |= (0x80U >> (ppn % 8));
			base = (ppn << 12);
			break;
		}
	}
	return base;
}

PUBLIC
void
free_page(void *base)
{
	u32 aligned_base = (u32)base & 0xFFFFF000;
	u32 ppn = aligned_base >> 12;
	bitmap[ppn / 8] &= (~(0x80U >> (ppn % 8)));
}

PUBLIC u8 get_page_status(void *base)
{
	u32 aligned_base = (u32)base & 0xFFFFF000;
	u32 ppn = aligned_base >> 12;
	return bitmap[ppn / 8] & (0x80U >> (ppn % 8));
}
