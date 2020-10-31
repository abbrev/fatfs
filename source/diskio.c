/*-----------------------------------------------------------------------*/
/* Low level disk I/O module skeleton for FatFs     (C)ChaN, 2019        */
/*-----------------------------------------------------------------------*/
/* If a working storage control module is available, it should be        */
/* attached to the FatFs via a glue function rather than modifying it.   */
/* This is an example of glue functions to attach various exsisting      */
/* storage control modules to the FatFs module with a defined API.       */
/*-----------------------------------------------------------------------*/

#include "ff.h"     /* Obtains integer types */
#include "diskio.h"   /* Declarations of disk functions */

/* Definitions of physical drive number for each drive */
#define DEV_RAM   (1) /* Example: Map Ramdisk to physical drive 0 */
#define DEV_MMC   (0) /* Example: Map MMC/SD card to physical drive 1 */
#define DEV_USB   (2) /* Example: Map USB MSD to physical drive 2 */

#define DEVICE_FUNCTION(name)               \
\
  DSTATUS name ##_## disk_initialize(void);     \
  DSTATUS name ##_## disk_status(void);         \
  DSTATUS name ##_## disk_read(BYTE *buff, DWORD sector, BYTE count);        \
  DSTATUS name ##_## disk_write(const BYTE *buff, DWORD sector, BYTE count); \
  DSTATUS name ##_## disk_ioctl(BYTE ctrl, void *buff); \



DEVICE_FUNCTION(MMC)

/*-----------------------------------------------------------------------*/
/* Get Drive Status                                                      */
/*-----------------------------------------------------------------------*/

DSTATUS disk_status (
  BYTE pdrv   /* Physical drive nmuber to identify the drive */
)
{
  int result;

  switch (pdrv) {
  case DEV_MMC :
    result = MMC_disk_status();

    // translate the reslut code here

    return result;
  }
  return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Inidialize a Drive                                                    */
/*-----------------------------------------------------------------------*/

DSTATUS disk_initialize (
  BYTE pdrv       /* Physical drive nmuber to identify the drive */
)
{
  int result;

  switch (pdrv) {
  case DEV_MMC :
    result = MMC_disk_initialize();

    // translate the reslut code here

    return result;
  }
  return STA_NOINIT;
}



/*-----------------------------------------------------------------------*/
/* Read Sector(s)                                                        */
/*-----------------------------------------------------------------------*/

DRESULT disk_read (
  BYTE pdrv,    /* Physical drive nmuber to identify the drive */
  BYTE *buff,   /* Data buffer to store read data */
  LBA_t sector, /* Start sector in LBA */
  UINT count    /* Number of sectors to read */
)
{
  int result;

  switch (pdrv) {
  case DEV_MMC :
    // translate the arguments here

    result = MMC_disk_read(buff, sector, count);

    // translate the reslut code here

    return result;
  }

  return RES_PARERR;
}



/*-----------------------------------------------------------------------*/
/* Write Sector(s)                                                       */
/*-----------------------------------------------------------------------*/

#if FF_FS_READONLY == 0

DRESULT disk_write (
  BYTE pdrv,      /* Physical drive nmuber to identify the drive */
  const BYTE *buff, /* Data to be written */
  LBA_t sector,   /* Start sector in LBA */
  UINT count      /* Number of sectors to write */
)
{
  int result;

  switch (pdrv) {
  case DEV_MMC :
    // translate the arguments here

    result = MMC_disk_write(buff, sector, count);

    // translate the reslut code here

    return result;
  }

  return RES_PARERR;
}

#endif


/*-----------------------------------------------------------------------*/
/* Miscellaneous Functions                                               */
/*-----------------------------------------------------------------------*/

DRESULT disk_ioctl (
  BYTE pdrv,    /* Physical drive nmuber (0..) */
  BYTE cmd,   /* Control code */
  void *buff    /* Buffer to send/receive control data */
)
{
  DRESULT res = 0;

  switch (pdrv) {
  case DEV_MMC :

    // Process of the command for the MMC/SD card

    return res;
  }

  return RES_PARERR;
}

