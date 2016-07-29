//
//  LCBannerView.h
//
//  Created by Leo on 15/11/30.
//  Copyright © 2015年 Leo. All rights reserved.
//
//  GitHub: http://github.com/iTofu
//  Mail:   mailto:devtip@163.com
//  V 2.1.0

#import <UIKit/UIKit.h>


@class LCBannerView;


typedef void(^LCBannerViewDidClickedImageIndexBlock)(LCBannerView *bannerView, NSInteger index);

typedef void(^LCBannerViewDidScrollToIndexBlock)(LCBannerView *bannerView, NSInteger index);


@protocol LCBannerViewDelegate <NSObject>

@optional

/**
 *  Did clicked image at an index.
 *
 *  @param bannerView LCBannerView
 *  @param index      clicked index
 */
- (void)bannerView:(LCBannerView *)bannerView didClickedImageIndex:(NSInteger)index;

/**
 *  Did scroll to an index.
 *
 *  @param bannerView LCBannerView
 *  @param index      scroll to index
 */
- (void)bannerView:(LCBannerView *)bannerView didScrollToIndex:(NSInteger)index;

@end



@interface LCBannerView : UIView


#pragma mark - Properties

/**
 *  Distance to bottom of pageControl. Default is `10.0f`.
 */
@property (nonatomic, assign) CGFloat   pageDistance;

/**
 *  Not allow scrolling. Default `No`, allow scrolling.
 */
@property (nonatomic, assign) BOOL      notScrolling;

/**
 *  Image name.
 */
@property (nonatomic, copy  ) NSString  *imageName;
/**
 *  Image URL array.
 */
@property (nonatomic, strong) NSArray   *imageURLs;
/**
 *  Count of images.
 */
@property (nonatomic, assign) NSInteger count;
/**
 *  Current page indicator tint color.
 */
@property (nonatomic, strong) UIColor   *currentPageIndicatorTintColor;
/**
 *  Other page indicator tint color.
 */
@property (nonatomic, strong) UIColor   *pageIndicatorTintColor;
/**
 *  Placeholder image name.
 */
@property (nonatomic, copy  ) NSString  *placeholderImageName;

/**
 *  Did clicked image at index block.
 */
@property (nonatomic, copy) LCBannerViewDidClickedImageIndexBlock didClickedImageIndexBlock;

/**
 *  Did scroll to index block.
 */
@property (nonatomic, copy) LCBannerViewDidScrollToIndexBlock didScrollToIndexBlock;


#pragma mark - Class methods

/**
 *  Init a LCBannerView object from local.
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
                       timeInterval:(NSInteger)timeInterval
      currentPageIndicatorTintColor:(UIColor *)currentPageIndicatorTintColor
             pageIndicatorTintColor:(UIColor *)pageIndicatorTintColor;

/**
 *  Init a LCBannerView object from internet.
 *
 *  @param frame                         frame
 *  @param delegate                      delegate
 *  @param imageURLs                     image's URLs
 *  @param placeholderImageName          placeholder image
 *  @param timeInterval                  time interval
 *  @param currentPageIndicatorTintColor current page indicator tint color
 *  @param pageIndicatorTintColor        other page indicator tint color
 *
 *  @return a LCBannerView object
 */
+ (instancetype)bannerViewWithFrame:(CGRect)frame
                           delegate:(id<LCBannerViewDelegate>)delegate
                          imageURLs:(NSArray *)imageURLs
               placeholderImageName:(NSString *)placeholderImageName
                       timeInterval:(NSInteger)timeInterval
      currentPageIndicatorTintColor:(UIColor *)currentPageIndicatorTintColor
             pageIndicatorTintColor:(UIColor *)pageIndicatorTintColor;


#pragma mark - Instance methods

/**
 *  Init a LCBannerView object from local.
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
                 timeInterval:(NSInteger)timeInterval
currentPageIndicatorTintColor:(UIColor *)currentPageIndicatorTintColor
       pageIndicatorTintColor:(UIColor *)pageIndicatorTintColor;

/**
 *  Init a LCBannerView object from internet.
 *
 *  @param frame                         frame
 *  @param delegate                      delegate
 *  @param imageURLs                     image's URLs
 *  @param placeholderImageName          placeholder image
 *  @param timeInterval                  time interval
 *  @param currentPageIndicatorTintColor current page indicator tint color
 *  @param pageIndicatorTintColor        other page indicator tint color
 *
 *  @return a LCBannerView object
 */
- (instancetype)initWithFrame:(CGRect)frame
                     delegate:(id<LCBannerViewDelegate>)delegate
                    imageURLs:(NSArray *)imageURLs
         placeholderImageName:(NSString *)placeholderImageName
                 timeInterval:(NSInteger)timeInterval
currentPageIndicatorTintColor:(UIColor *)currentPageIndicatorTintColor
       pageIndicatorTintColor:(UIColor *)pageIndicatorTintColor;


@end
