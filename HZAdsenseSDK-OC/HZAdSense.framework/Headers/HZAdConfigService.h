//
//  HZAdConfigService.h
//  HZAdSense
//
//  Created by 武汉好卓 on 2019/7/15.
//  Copyright © 2019 武汉好卓. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HZAdConfigService : NSObject

/**
 初始化配置信息

 @param appKey 申请的应用appKey
 @param onOff 是否打开GPS定位权限
 @param option 可选扩展，没有则传nil
 */
+ (void)setupConfigWithAppKey:(NSString *)appKey isOpenGPS:(BOOL)onOff optionExtention:(NSMutableDictionary *_Nullable)option;
@end

NS_ASSUME_NONNULL_END
