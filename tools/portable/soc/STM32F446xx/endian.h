/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <lukasz.stempien@gmail.com> wrote this file. As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return.
 *                                                              Lukasz Stempien
 * ----------------------------------------------------------------------------
 */

#include "stm32f4xx_hal_conf.h"

#ifndef __ENDIAN_H__
#define __ENDIAN_H__

#if __BYTE_ORDER == __LITTLE_ENDIAN
	#define HTONL(l)	__REV(l)
	#define HTONS(s)	(uint16_t)__REV16(s)
	#define NTOHL(l)	__REV(l)
	#define NTOHS(s)	(uint16_t)__REV16(s)
#elif __BYTE_ORDER == __BIG_ENDIAN
	#define HTONL(l)	(l)
	#define HTONS(s)	(s)
	#define NTOHL(l)	(l)
	#define NTOHS(s)	(s)
#else
	#error Wrong endian type
#endif

#endif //__ENDIAN_H__