
#ifndef _EEPROM_H_
#define _EEPROM_H_

#include "ch.h"
#include "stm32f30x_flash.h"

#define EE_START ((uint32_t)0x8025000) /* Pointer to start of EE */
#define EE_LENGTH (108*1024)
#define EE_PAGE_SIZE (2*1024)
#define EE_MAGIC ((uint32_t)0xABEF1289) /* Used to identify pages in use */

/* Support functions */
uint8_t eeWriteFlash(const uint32_t addr, const uint32_t *buf, uint8_t len); /* Write data to page */
uint8_t eeErasePage(const uint32_t addr);
uint32_t * eeFindCurrentPage(void);
uint32_t * eeFindNextPage(void);

/* Public functions */
uint8_t eeEraseAll(void); /* Erase all pages */
uint8_t eePushPage(uint32_t *buffer, uint32_t len); /* Push data to next page */
uint8_t eePullPage(uint32_t *buffer, uint32_t len); /* Pull data from current page */


#endif