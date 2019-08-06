//
//  HZBannerAdView.h
//  HZAdSense
//
//  Created by 武汉好卓 on 2019/7/17.
//  Copyright © 2019 武汉好卓. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class HZBannerAdView;

@protocol HZBannerAdViewDelegate <NSObject>
@optional
#warning 合并成功和失败的回调方法/或者复用ADSourceOnShow方法通过block给出结果，其他回调只做关键的功能性
/**
 *  接收服务器返回的广告数据成功时调用
 */
- (void)bannerAdViewDidLoad:(HZBannerAdView *)bannerAdView;

/**
 *  接收服务器返回的广告数据失败时调用
 */
- (void)bannerAdViewFailedToLoad:(HZBannerAdView *)bannerAdView error:(NSError *)error;

/**
 *  bannerAdView曝光成功
 */
- (void)bannerAdViewDidExpose:(HZBannerAdView *)bannerAdView;

/**
 *  bannerAdView将被用户关闭
 */
- (void)bannerAdViewWillClose:(HZBannerAdView *)bannerAdView;

/**
 *  即将弹出全屏广告详情
 */
- (void)bannerAdViewWillPresentFullScreen:(HZBannerAdView *)bannerAdView;

/**
 *  广告详情即将被关闭
 */
- (void)bannerAdViewWillDismissFullScreen:(HZBannerAdView *)bannerAdView;

@end

@interface HZBannerAdView : UIView
/**
 * 【可选】广告自动刷新间隔，范围 [30, 120] 秒，默认值 30 秒。设 0 则不刷新。
 */
@property(nonatomic, assign) NSInteger autoRefreshInterval;

/**
 * 【必须】构造方法
 *  详解：frame - banner展示的位置和大小
 *       positionId - 广告位ID
 *       delegate - 代理对象
 */
- (instancetype)initWithFrame:(CGRect)frame
                   positionId:(NSString *)positionId
                     delegate:(nullable id <HZBannerAdViewDelegate>)delegate;

#warning 广告加载成功直接显示，不需要用户手动调用，此方法可以专门用作网络请求和刷新
/**
 * 【必须】显示广告
 */
- (void)adSourceOnShow;
@end

NS_ASSUME_NONNULL_END
