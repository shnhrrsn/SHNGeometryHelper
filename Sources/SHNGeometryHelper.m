//
//  SHNGeometryHelper.m
//
//  Created by Shaun Harrison
//  Copyright (c) 2014 Shaun Harrison.
//

#import "SHNGeometryHelper.h"

#if TARGET_OS_IPHONE
	@import UIKit;

	CGFloat _SHNGeometryHelperGetMainScreenScale() {
		return [UIScreen mainScreen].scale;
	}
#endif

#pragma mark - CGRect

CGRect SHNRectGetCenteredInRectWithScale(CGRect rect, CGRect centeredIn, CGFloat scale) {
	rect.origin.x = centeredIn.origin.x + SHNFloorWithScale((centeredIn.size.width - rect.size.width) / 2.0, scale);
	rect.origin.y = centeredIn.origin.y + SHNFloorWithScale((centeredIn.size.height - rect.size.height) / 2.0, scale);
	return rect;
}
