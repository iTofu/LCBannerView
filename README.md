# LCBannerView

[![Travis](https://img.shields.io/travis/iTofu/LCBannerView.svg?style=flat)](https://travis-ci.org/iTofu/LCBannerView)
[![CocoaPods](https://img.shields.io/cocoapods/v/LCBannerView.svg)](http://cocoadocs.org/docsets/LCBannerView)
[![CocoaPods](https://img.shields.io/cocoapods/l/LCBannerView.svg)](https://raw.githubusercontent.com/iTofu/LCBannerView/master/LICENSE)
[![CocoaPods](https://img.shields.io/cocoapods/p/LCBannerView.svg)](http://cocoadocs.org/docsets/LCBannerView)
[![LeoDev](https://img.shields.io/badge/blog-LeoDev.me-brightgreen.svg)](http://leodev.me)

🔥 A very popular and highly customized banner view! Infinite loop!

![LCBannerView](https://raw.githubusercontent.com/iTofu/LCBannerView/master/LCBannerViewDemo.gif)

````
In me the tiger sniffs the rose.

心有猛虎，细嗅蔷薇。
````

Welcome to visit my blog: <http://LeoDev.me> ✨

[**中文介绍**](https://github.com/iTofu/LCBannerView/blob/master/README-zh_CN.md)



## Introduction

This is a display of advertising or information.

You can using the images from **Local** or **Internet**.

And it won't affect other scrollViews' `scrollsToTop` propertie.

If you feel good, please give me a star, thank you very much! ⭐️



## Installation

LCBannerView is available on [CocoaPods](https://cocoapods.org/). Just add the following to your project Podfile:

````ruby
pod "LCBannerView"  # Podfile
````



## Non-CocoaPods Installation

Just drag the LCBannerView folder into your project.



## Usage

* Use by including the following import:

  ````objc
  #import "LCBannerView.h"
  ````

* Demo code:

  ````objc
  // 1. from internet
  [scrollView addSubview:({

      LCBannerView *bannerView = [LCBannerView bannerViewWithFrame:CGRectMake(0, 300.0f, [UIScreen mainScreen].bounds.size.width, 200.0f)
                                                          delegate:self
                                                         imageURLs:URLs
                                                  placeholderImage:nil
                                                     timerInterval:2.0f
                                     currentPageIndicatorTintColor:[UIColor redColor]
                                            pageIndicatorTintColor:[UIColor whiteColor]];
      bannerView.pageDistance = 20.0f;
      bannerView;
  })];

  // 2. from local
  /*  
   *  If you using images from local, you should let images named: `banner_01@2x.png`, `banner_02@2x.png`...
   *  Than, you just give me a image named: `banner`. 😜
   */
  [scrollView addSubview:({

      LCBannerView *bannerView = [[LCBannerView alloc] initWithFrame:CGRectMake(0, 20.0f, [UIScreen mainScreen].bounds.size.width, 200.0f)
                                                            delegate:self
                                                           imageName:@"banner"
                                                               count:3
                                                       timerInterval:3.0f
                                       currentPageIndicatorTintColor:[UIColor orangeColor]
                                              pageIndicatorTintColor:[UIColor whiteColor]];
      bannerView;
  })];
  ````

* Delegate:（`@optional`）

  ````objc
  - (void)bannerView:(LCBannerView *)bannerView didClickedImageIndex:(NSInteger)index;
  ````

  For example:

  ````objc
  - (void)bannerView:(LCBannerView *)bannerView didClickedImageIndex:(NSInteger)index {

        NSLog(@"you clicked image in %@ at index: %ld", bannerView, (long)index);
  }

  // logs
  2015-11-30 17:36:20.611 LCBannerViewDemo[6075:456257] you clicked image in 0x7fc98b751ff0 at index: 1
  2015-11-30 17:36:21.292 LCBannerViewDemo[6075:456257] you clicked image in 0x7fc98b433190 at index: 1
  2015-11-30 17:36:21.801 LCBannerViewDemo[6075:456257] you clicked image in 0x7fc98b751ff0 at index: 2
  ````

* Custom parameters:（in `LCBannerView.m`）

  ````objc
  // pageControl to the bottom of the distance
  static CGFloat LCPageDistance = 10.0f;
  ````



## Release

### V 1.2.2

* Update CocoaPods source URL.


### V 1.2.0

* You could custom the images should scrolling now, thx [ac1dpax](https://github.com/ac1dpax). For example:

  ````objc
  LCBannerView *bannerView = [[LCBannerView alloc] initWithFrame:CGRectMake(0, 20.0f, [UIScreen mainScreen].bounds.size.width, 200.0f)
                                                        delegate:self
                                                       imageName:@"banner"
                                                           count:3
                                                   timerInterval:3.0f
                                   currentPageIndicatorTintColor:[UIColor orangeColor]
                                          pageIndicatorTintColor:[UIColor whiteColor]];
  bannerView.pageDistance = 20.0f;
  bannerView.notScrolling = YES; // THIS LINE ⬅️
  bannerView;
  ````

### V 1.1.0

* You could custom page control bottom distance now. For example:

  ````objc
  // ...
  bannerView.pageDistance = 20.0f;
  ````


### V 1.0.0

* Initial commit.



## Thanks

* [SDWebImage](https://github.com/rs/SDWebImage)



## Support

* If you have any questions, please [commit a issure](https://github.com/LeoGod/LCBannerView/issues/new)! Thx!
* Mail: devtip@163.com
* Blog: http://LeoDev.me



### License

[MIT License](http://opensource.org/licenses/MIT)
