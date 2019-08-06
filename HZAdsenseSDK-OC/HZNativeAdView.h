//
//  HZNativeAdView.h
//  HZAdSense
//
//  Created by 武汉好卓 on 2019/8/2.
//  Copyright © 2019 武汉好卓. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HZNativeAdView : UIView
@property (nonatomic,assign,readonly) NSUInteger *type;//此处是枚举的广告类型（三图，单图，上图下文。。。）
@end

NS_ASSUME_NONNULL_END
