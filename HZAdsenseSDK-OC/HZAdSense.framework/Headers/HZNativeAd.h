//
//  HZNativeAd.h
//  HZAdSense
//
//  Created by 武汉好卓 on 2019/7/16.
//  Copyright © 2019 武汉好卓. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class HZNativeAdView;

@protocol HZNativeAdDelegate <NSObject>
@optional
/**
 *  NativeAd曝光成功
 */
- (void)nativeAdDidExpose:(HZNativeAdView *)nativeAdView;

/**
 *  NativeAd将被用户关闭
 */
- (void)nativeAdWannaBeClosed:(HZNativeAdView *)nativeAdView;

/**
 *  即将弹出广告详情
 */
- (void)nativeAdWillPresentFullScreen:(HZNativeAdView *)nativeAdView;

/**
 *  广告详情将被关闭
 */
- (void)nativeAdWillDismissFullScreen:(HZNativeAdView *)nativeAdView;
@end

@interface HZNativeAd : NSObject
/**
 * 【必须】构造方法
 *  positionId - 广告位ID
 *  viewController - 视图控制器
 *  delegate - 代理对象
 */
- (instancetype)initWithPositionId:(NSString *)positionId
              showInViewController:(UIViewController *)viewController
                          delegate:(nullable id <HZNativeAdDelegate>)delegate;

/**
 * 【必须】显示广告拉取的结果
 *  count - 想要请求的广告数量，个数可能少于请求的数量
 *  viewFrame - 视图位置大小
 *  error为空时代表拉取成功，否则error给出错误信息
 *  views - 为要展示的广告视图，由开发者自行添加（注：其大小为传入的viewFrame.size，一旦创建无法修改）
 */
- (void)adSourceOnShowCount:(NSUInteger)count
                  viewFrame:(CGRect)viewFrame
                     result:(void(^)(NSError *error, NSArray<HZNativeAdView *> *views))result;
@end

NS_ASSUME_NONNULL_END
