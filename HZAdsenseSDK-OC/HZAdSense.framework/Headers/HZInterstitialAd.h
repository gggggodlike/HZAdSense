//
//  HZInterstitialAd.h
//  HZAdSense
//
//  Created by 武汉好卓 on 2019/7/16.
//  Copyright © 2019 武汉好卓. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class HZInterstitialAd;

@protocol HZInterstitialAdDelegate <NSObject>
@optional
/**
 *  接收服务器返回的广告数据成功时调用
 */
- (void)interstitialAdDidLoad:(HZInterstitialAd *)interstitialAd;

/**
 *  接收服务器返回的广告数据失败时调用
 */
- (void)interstitialAdFailedToLoad:(HZInterstitialAd *)interstitialAd error:(NSError *)error;

/**
 *  interstitialAd曝光成功
 */
- (void)interstitialAdDidExpose:(HZInterstitialAd *)interstitialAd;

/**
 *  interstitialAd即将关闭
 */
- (void)interstitialAdWillClose:(HZInterstitialAd *)interstitialAd;

/**
 *  即将弹出广告详情
 */
- (void)interstitialAdWillPresentFullScreen:(HZInterstitialAd *)interstitialAd;

/**
 *  广告详情将被关闭
 */
- (void)interstitialAdWillDismissFullScreen:(HZInterstitialAd *)interstitialAd;

@end


@interface HZInterstitialAd : NSObject

/**
 * 【必须】构造方法
 *       positionId - 广告位ID
 *       viewController - 视图控制器
 *       delegate - 代理对象
 */
- (instancetype)initWithPositionId:(NSString *)positionId
              showInViewController:(UIViewController *)viewController
                          delegate:(nullable id <HZInterstitialAdDelegate>)delegate;

/**
 * 【必须】显示广告
 */
- (void)adSourceOnShow;
@end

NS_ASSUME_NONNULL_END
