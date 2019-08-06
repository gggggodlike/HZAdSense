//
//  HZSplashAd.h
//  HZAdSense
//
//  Created by 武汉好卓 on 2019/7/16.
//  Copyright © 2019 武汉好卓. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class HZSplashAd;

@protocol HZSplashAdDelegate <NSObject>
@optional
/**
 *  接收服务器返回的广告数据成功时调用
 */
- (void)splashAdDidLoad:(HZSplashAd *)splashAd;

/**
 *  接收服务器返回的广告数据失败时调用
 */
- (void)splashAdFailedToLoad:(HZSplashAd *)splashAd error:(NSError *)error;

/**
 *  splashAd曝光成功
 */
- (void)splashAdDidExpose:(HZSplashAd *)splashAd;

/**
 *  splashAd将被用户关闭
 */
- (void)splashAdWillClose:(HZSplashAd *)splashAd;

/**
 *  splashAd倒计时剩余时间回调
 */
- (void)splashAdDisplaySecondesLeft:(NSUInteger)duration;

/**
 *  即将弹出广告详情
 */
- (void)splashAdWillPresentFullScreen:(HZSplashAd *)splashAd;

/**
 *  广告详情将被关闭
 */
- (void)splashAdWillDismissFullScreen:(HZSplashAd *)splashAd;
@end

@interface HZSplashAd : NSObject
/**
 * 【可选】广告展示时间，默认为3秒
 */
@property (nonatomic, assign) NSUInteger displayDuration;

/**
 * 【可选】广告加载时的默认背景,同时也时广告拉取失败的背景图,不传时默认白色背景
 *  建议设置为应用启动图的图片
 */
@property (nonatomic, strong) UIImage *adBackgroundImage;

/**
 * 【必须】构造方法（静态方法，直接类调用获取实例）
 *       positionId - 广告位ID
 *       bottomView - 广告的底部区域可自定义，传nil则为全屏
 *       delegate - 代理的对象
 */
+ (instancetype)getInstanceWithPositionId:(NSString *)positionId
                         customBottomView:(UIView *_Nullable)bottomView
                                 delegate:(nullable id <HZSplashAdDelegate>)delegate;

/**
 * 【必须】显示广告
 */
- (void)adSourceOnShow;
@end

NS_ASSUME_NONNULL_END
