/*
 *  CTDefines.h
 *  CoreText
 *
 *  Copyright (c) 2010-2012 Apple Inc. All rights reserved.
 *
 */

#ifndef __CTDEFINES__
#define __CTDEFINES__

#ifndef __has_feature
# define __has_feature(x) 0
#endif

#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#if defined(CT_BUILDING_CoreText)
# define CT_AVAILABLE(_mac, _ios)
# define CT_AVAILABLE_MAC(_mac)
# define CT_AVAILABLE_IOS(_ios)
# define CT_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep)
# define CT_DEPRECATED_IOS(_iosIntro, _iosDep)
# define CT_ENUM_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep)
#else /* defined(CT_BUILDING_CoreText) */
# include <Availability.h>
# define CT_AVAILABLE(_mac, _ios) __OSX_AVAILABLE_STARTING(__MAC_##_mac, __IPHONE_##_ios)
# define CT_AVAILABLE_MAC(_mac) __OSX_AVAILABLE_STARTING(__MAC_##_mac, __IPHONE_NA)
# define CT_AVAILABLE_IOS(_ios) __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_##_ios)
# define CT_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_##_macIntro, __MAC_##_macDep, __IPHONE_##_iosIntro, __IPHONE_##_iosDep)
# define CT_DEPRECATED_IOS(_iosIntro, _iosDep) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_NA, __MAC_NA, __IPHONE_##_iosIntro, __IPHONE_##_iosDep)
# if __has_feature(enumerator_attributes) && __has_attribute(availability)
#  define CT_ENUM_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep) __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_##_macIntro, __MAC_##_macDep, __IPHONE_##_iosIntro, __IPHONE_##_iosDep)
# else
#  define CT_ENUM_DEPRECATED(_macIntro, _macDep, _iosIntro, _iosDep)
# endif
#endif /* defined(CT_BUILDING_CoreText) */

#endif
