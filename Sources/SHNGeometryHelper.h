//
//  SHNGeometryHelper.h
//
//  Created by Shaun Harrison
//  Copyright (c) 2014 Shaun Harrison.
//

@import Foundation;
@import CoreGraphics;

#import <math.h>

//! Project version number for SHNGeometryHelper.
FOUNDATION_EXPORT double SHNGeometryHelperVersionNumber;

//! Project version string for SHNGeometryHelper.
FOUNDATION_EXPORT const unsigned char SHNGeometryHelperVersionString[];

#if TARGET_OS_IPHONE
	CGFloat _SHNGeometryHelperGetMainScreenScale(void);
#endif

#ifndef __SHNGeometryHelper
#define __SHNGeometryHelper

/**
 * Clamp a value between min and max
 *
 * @param min Min value
 * @param value Current value
 * @param max Max value
 */
#define CLAMP(min,value,max) MIN(max,MAX(min,value))

/**
 * Convert degrees to radians
 *
 * @param degrees Degrees
 */
#define DEGREES_TO_RADIANS(degrees) (degrees * M_PI / 180.0)

#pragma mark - CGRect

/**
 * Make a rect with a size, setting origin to 0,0
 *
 * @param size CGSize
 */
static inline CGRect SHNRectMakeWithSize(CGSize size) {
	return (CGRect) {
		.origin = {
			.x = 0,
			.y = 0
		},
		.size = size
	};
}

/**
 * Get the mid point of a rect
 *
 * @param rect Rect to get mid point of
 */
static inline CGPoint SHNRectGetMid(CGRect rect) {
	return (CGPoint) { CGRectGetMidX(rect), CGRectGetMidY(rect) };
}

/**
 * Get the max point of a rect
 *
 * @param rect Rect to get max point of
 */
static inline CGPoint SHNRectGetMax(CGRect rect) {
	return (CGPoint) { CGRectGetMaxX(rect), CGRectGetMaxY(rect) };
}

/**
 * Get rect centered in another rect, floored using scale
 *
 * @param rect Rect to center
 * @param centeredIn Rect to center in
 * @param scale Scale to floor values to
 */
CGRect SHNRectGetCenteredInRectWithScale(CGRect rect, CGRect centeredIn, CGFloat scale);

#if TARGET_OS_IPHONE
/**
 * Get rect centered in another rect, floored using screen scale
 *
 * @param rect Rect to center
 * @param centeredIn Rect to center in
 */
static inline CGRect SHNRectGetCenteredInRect(CGRect rect, CGRect centeredIn) {
	return SHNRectGetCenteredInRectWithScale(rect, centeredIn, _SHNGeometryHelperGetMainScreenScale());
}
#endif

#pragma mark - CGPoint

/**
 * Get delta between two points
 *
 * @param a Point a
 * @param b Point b
 */
static inline CGPoint SHNPointGetDeltaBetweenPoints(CGPoint a, CGPoint b) {
	return (CGPoint){ b.x - a.x, b.y - a.y };
}

/**
 * Get distance between two points
 *
 * @param b Point a
 * @param a Point b
 */
static inline CGFloat SHNPointGetDistanceBetweenPoints(CGPoint a, CGPoint b) {
#if CGFLOAT_IS_DOUBLE
	return sqrt(pow(b.x - a.x, 2.0) + pow(b.y - a.y, 2.0));
#else
	return sqrtf(powf(b.x - a.x, 2.0) + powf(b.y - a.y, 2.0));
#endif
}

#pragma mark - Rounding

#if CGFLOAT_IS_DOUBLE
	#define CGFloatRound round
	#define CGFloatCeil ceil
	#define CGFloatFloor floor
#else
	#define CGFloatRound roundf
	#define CGFloatCeil ceilf
	#define CGFloatFloor floorf
#endif

/**
 * Round value using scale (2.0 scale will round to nearest 0.5, 3.0 scale will round to nearest 1/3rd)
 *
 * @param value Value to round
 * @param scale Scale to round to
 */
static inline CGFloat SHNRoundWithScale(CGFloat value, CGFloat scale) {
	return CGFloatRound(value * scale) / scale;
}

/**
 * Floor value using scale (2.0 scale will floor to nearest 0.5, 3.0 scale will floor to nearest 1/3rd)
 *
 * @param value Value to floor
 * @param scale Scale to floor to
 */
static inline CGFloat SHNFloorWithScale(CGFloat value, CGFloat scale) {
	return CGFloatFloor(value * scale) / scale;
}

/**
 * Ceil value using scale (2.0 scale will ceil to nearest 0.5, 3.0 scale will ceil to nearest 1/3rd)
 *
 * @param value Value to ceil
 * @param scale Scale to ceil to
 */
static inline CGFloat SHNCeilWithScale(CGFloat value, CGFloat scale) {
	return CGFloatCeil(value * scale) / scale;
}

#if TARGET_OS_IPHONE
/**
 * Round value using screen scale
 *
 * @param value Value to round
 * @see SHNRoundWithScale
 */
static inline CGFloat SHNScreenRound(CGFloat value) {
	return SHNRoundWithScale(value, _SHNGeometryHelperGetMainScreenScale());
}

/**
 * Floor value using screen scale
 *
 * @param value Value to floor
 * @see SHNFloorWithScale
 */
static inline CGFloat SHNScreenFloor(CGFloat value) {
	return SHNFloorWithScale(value, _SHNGeometryHelperGetMainScreenScale());
}

/**
 * Ceil value using screen scale
 *
 * @param value Ceil to round
 * @see SHNCeilWithScale
 */
static inline CGFloat SHNScreenCeil(CGFloat value) {
	return SHNCeilWithScale(value, _SHNGeometryHelperGetMainScreenScale());
}
#endif

#pragma mark - CGSize

/**
 * Floor size width/height using scale
 *
 * @param size Size to floor
 * @param scale Scale to floor to
 * @see SHNFloorWithScale
 */
static inline CGSize SHNSizeFloor(CGSize size, CGFloat scale) {
	return (CGSize) {
		.width = SHNFloorWithScale(size.width, scale),
		.height = SHNFloorWithScale(size.height, scale)
	};
}

/**
 * Ceil size width/height using scale
 *
 * @param size Size to ceil
 * @param scale Scale to ceil to
 * @see SHNCeilWithScale
 */
static inline CGSize SHNSizeCeil(CGSize size, CGFloat scale) {
	return (CGSize) {
		.width = SHNCeilWithScale(size.width, scale),
		.height = SHNCeilWithScale(size.height, scale)
	};
}

/**
 * Round size width/height using scale
 *
 * @param size Size to round
 * @param scale Scale to round to
 * @see SHNRoundWithScale
 */
static inline CGSize SHNSizeRound(CGSize size, CGFloat scale) {
	return (CGSize) {
		.width = SHNRoundWithScale(size.width, scale),
		.height = SHNRoundWithScale(size.height, scale)
	};
}


#if TARGET_OS_IPHONE
/**
 * Floor size width/height using screen scale
 *
 * @param size Size to floor
 * @see SHNFloorCeil
 */
static inline CGSize SHNSizeScreenFloor(CGSize size) {
	return SHNSizeFloor(size, _SHNGeometryHelperGetMainScreenScale());
}

/**
 * Ceil size width/height using screen scale
 *
 * @param size Size to ceil
 * @see SHNSizeCeil
 */
static inline CGSize SHNSizeScreenCeil(CGSize size) {
	return SHNSizeCeil(size, _SHNGeometryHelperGetMainScreenScale());
}

/**
 * Round size width/height using screen scale
 *
 * @param size Size to round
 * @see SHNSizeRound
 */
static inline CGSize SHNSizeScreenRound(CGSize size) {
	return SHNSizeRound(size, _SHNGeometryHelperGetMainScreenScale());
}
#endif

#endif
