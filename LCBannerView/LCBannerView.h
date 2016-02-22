//
//  LCBannerView.h
//  LCBannerViewDemo
//
//  Created by Leo on 15/11/30.
//  Copyright © 2015年 Leo. All rights reserved.
//
//  GitHub: http://github.com/LeoiOS
//  Mail:   mailto:devtip@163.com
//  V 1.1.0

#import <UIKit/UIKit.h>


@class LCBannerView;


@protocol LCBannerViewDelegate <NSObject>

@optional

- (void)bannerView:(LCBannerView *)bannerView didClickedImageIndex:(NSInteger)index;

@end



@interface LCBannerView : UIView


#pragma mark - Property

/**
 *  Page control view bottom distance. Default is `10.0f`.
 */
@property (nonatomic, assign) CGFloat pageDistance;


#pragma mark - Class methods

/**
 *  init a LCBannerView object from local
 *
 *  @param frame                         frame
 *  @param delegate                      delegate
 *  @param imageName                     image name. eg: `banner_01@2x.png`, `banner_02@2x.png`... you should set it `banner`
 *  @param count                         images count
 *  @param timeInterval                  time interval
 *  @param currentPageIndicatorTintColor current page indicator tint color
 *  @param pageIndicatorTintColor        other page indicator tint color
 *
 *  @return a LCBannerView object
 */
+ (instancetype)bannerViewWithFrame:(CGRect)frame
                     delegate:(id<LCBannerViewDelegate>)delegate
                    imageName:(NSString *)imageName
                        count:(NSInteger)count
                timerInterval:(NSInteger)timeInterval
currentPageIndicatorTintColor:(UIColor *)currentPageIndicatorTintColor
       pageIndicatorTintColor:(UIColor *)pageIndicatorTintColor;

/**
 *  init a LCBannerView object from internet
 *
 *  @param frame                         frame
 *  @param delegate                      delegate
 *  @param imageURLs                     image's URLs
 *  @param placeholderImage              placeholder image
 *  @param timeInterval                  time interval
 *  @param currentPageIndicatorTintColor current page indicator tint color
 *  @param pageIndicatorTintColor        other page indicator tint color
 *
 *  @return a LCBannerView object
 */
+ (instancetype)bannerViewWithFrame:(CGRect)frame
                           delegate:(id<LCBannerViewDelegate>)delegate
                          imageURLs:(NSArray *)imageURLs
                   placeholderImage:(NSString *)placeholderImage
                      timerInterval:(NSInteger)timeInterval
      currentPageIndicatorTintColor:(UIColor *)currentPageIndicatorTintColor
             pageIndicatorTintColor:(UIColor *)pageIndicatorTintColor;


#pragma mark - Instance methods

/**
 *  init a LCBannerView object from local
 *
 *  @param frame                         frame
 *  @param delegate                      delegate
 *  @param imageName                     image name. eg: `banner_01@2x.png`, `banner_02@2x.png`... you should set it `banner`
 *  @param count                         images count
 *  @param timeInterval                  time interval
 *  @param currentPageIndicatorTintColor current page indicator tint color
 *  @param pageIndicatorTintColor        other page indicator tint color
 *
 *  @return a LCBannerView object
 */
- (instancetype)initWithFrame:(CGRect)frame
                     delegate:(id<LCBannerViewDelegate>)delegate
                    imageName:(NSString *)imageName
                        count:(NSInteger)count
                timerInterval:(NSInteger)timeInterval
currentPageIndicatorTintColor:(UIColor *)currentPageIndicatorTintColor
       pageIndicatorTintColor:(UIColor *)pageIndicatorTintColor;

/**
 *  init a LCBannerView object from internet
 *
 *  @param frame                         frame
 *  @param delegate                      delegate
 *  @param imageURLs                     image's URLs
 *  @param placeholderImage              placeholder image
 *  @param timeInterval                  time interval
 *  @param currentPageIndicatorTintColor current page indicator tint color
 *  @param pageIndicatorTintColor        other page indicator tint color
 *
 *  @return a LCBannerView object
 */
- (instancetype)initWithFrame:(CGRect)frame
                     delegate:(id<LCBannerViewDelegate>)delegate
                    imageURLs:(NSArray *)imageURLs
             placeholderImage:(NSString *)placeholderImage
                timerInterval:(NSInteger)timeInterval
currentPageIndicatorTintColor:(UIColor *)currentPageIndicatorTintColor
       pageIndicatorTintColor:(UIColor *)pageIndicatorTintColor;


@end
