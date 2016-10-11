# LCBannerView

[![Travis](https://img.shields.io/travis/iTofu/LCBannerView.svg?style=flat)](https://travis-ci.org/iTofu/LCBannerView)
[![CocoaPods](https://img.shields.io/cocoapods/v/LCBannerView.svg)](http://cocoadocs.org/docsets/LCBannerView)
[![CocoaPods](https://img.shields.io/cocoapods/l/LCBannerView.svg)](https://raw.githubusercontent.com/iTofu/LCBannerView/master/LICENSE)
[![CocoaPods](https://img.shields.io/cocoapods/p/LCBannerView.svg)](http://cocoadocs.org/docsets/LCBannerView)
[![LeoDev](https://img.shields.io/badge/blog-LeoDev.me-brightgreen.svg)](http://leodev.me)

🔥 A very popular and highly customized banner view! Infinite loop!

![LCBannerView](https://raw.githubusercontent.com/iTofu/LCBannerView/master/LCBannerViewDemo.gif)

```
In me the tiger sniffs the rose.

心有猛虎，细嗅蔷薇。
```

Welcome to my blog: <http://LeoDev.me> ✨

[**中文介绍**](https://github.com/iTofu/LCBannerView/blob/master/README-zh_CN.md)



## Introduction

This is a display of advertising or information.

You can using the images from **Local** or **Internet**.

And it won't affect other scrollViews' `scrollsToTop` properties.

If you feel good, please give me a star, thank you very much! ⭐️



## Installation

LCBannerView is available on [CocoaPods](https://cocoapods.org/). Just add the following to your project Podfile:

```ruby
pod "LCBannerView"  # Podfile
```



## Non-CocoaPods Installation

Just drag the LCBannerView folder into your project.



## Usage

* Use by including the following import:

  ```objc
  #import "LCBannerView.h"
  ```

* Demo code:

  ```objc
  // 1. From internet
  [scrollView addSubview:({

      LCBannerView *bannerView = [LCBannerView bannerViewWithFrame:CGRectMake(0, 300.0f, [UIScreen mainScreen].bounds.size.width, 200.0f)
                                                          delegate:self
                                                         imageURLs:URLs
                                              placeholderImageName:nil
                                                      timeInterval:2.0f
                                     currentPageIndicatorTintColor:[UIColor redColor]
                                            pageIndicatorTintColor:[UIColor whiteColor]];
      bannerView.pageDistance = 20.0f;
      bannerView;
  })];

  // 2. From local
  // If you using images from local, you should let images named: `banner_01@2x.png`, `banner_02@2x.png`...
  // Than, you just give me a image named: `banner`. 😜
  [scrollView addSubview:({

      LCBannerView *bannerView = [[LCBannerView alloc] initWithFrame:CGRectMake(0, 20.0f, [UIScreen mainScreen].bounds.size.width, 200.0f)
                                                            delegate:self
                                                           imageName:@"banner"
                                                               count:3
                                                        timeInterval:3.0f
                                       currentPageIndicatorTintColor:[UIColor orangeColor]
                                              pageIndicatorTintColor:[UIColor whiteColor]];
      bannerView;
  })];
  ```

* **Advise** for run demo:
  
  You should comment out one of the Block code or Delegate code in demo code, it will help you read code more clearly.

  See below two points for more information.

* Block: (`@optional`)

  ```objc
  @property (nonatomic, copy) LCBannerViewDidClickedImageIndexBlock didClickedImageIndexBlock;

  @property (nonatomic, copy) LCBannerViewDidScrollToIndexBlock didScrollToIndexBlock;
  ```

  For example:

  ```objc
  bannerView.didClickedImageIndexBlock = ^(LCBannerView *bannerView, NSInteger index) {
      
      NSLog(@"Block: Clicked image in %p at index: %d", bannerView, (int)index);
  };
  
  bannerView.didScrollToIndexBlock = ^(LCBannerView *bannerView, NSInteger index) {
      
      NSLog(@"Block: Scrolled in %p to index: %d", bannerView, (int)index);
  };

  // Logs
  2016-07-29 15:41:00.344 LCBannerViewDemo[3251:295032] Block: Scrolled in 0x7ff473538ec0 to index: 1
  2016-07-29 15:41:03.343 LCBannerViewDemo[3251:295032] Block: Scrolled in 0x7ff473538ec0 to index: 2
  2016-07-29 15:41:05.132 LCBannerViewDemo[3251:295032] Block: Clicked image in 0x7ff473538ec0 at index: 2
  2016-07-29 15:41:06.344 LCBannerViewDemo[3251:295032] Block: Scrolled in 0x7ff473538ec0 to index: 0
  2016-07-29 15:41:09.344 LCBannerViewDemo[3251:295032] Block: Scrolled in 0x7ff473538ec0 to index: 1
  2016-07-29 15:41:12.342 LCBannerViewDemo[3251:295032] Block: Scrolled in 0x7ff473538ec0 to index: 2
  ```

* Delegate: (`@optional`)

  ```objc
  - (void)bannerView:(LCBannerView *)bannerView didClickedImageIndex:(NSInteger)index;

  - (void)bannerView:(LCBannerView *)bannerView didScrollToIndex:(NSInteger)index;
  ```

  For example:

  ```objc
  - (void)bannerView:(LCBannerView *)bannerView didClickedImageIndex:(NSInteger)index {
      
      NSLog(@"Delegate: Clicked image in %p at index: %d", bannerView, (int)index);
  }

  - (void)bannerView:(LCBannerView *)bannerView didScrollToIndex:(NSInteger)index {
      
      NSLog(@"Delegate: Scrolled in %p to index: %d", bannerView, (int)index);
  }

  // Logs
  2016-07-29 15:41:45.296 LCBannerViewDemo[3293:296197] Delegate: Scrolled in 0x7f915b7349b0 to index: 1
  2016-07-29 15:41:47.300 LCBannerViewDemo[3293:296197] Delegate: Scrolled in 0x7f915b7349b0 to index: 0
  2016-07-29 15:41:48.429 LCBannerViewDemo[3293:296197] Delegate: Clicked image in 0x7f915b7349b0 at index: 0
  2016-07-29 15:41:49.308 LCBannerViewDemo[3293:296197] Delegate: Scrolled in 0x7f915b7349b0 to index: 1
  2016-07-29 15:41:51.297 LCBannerViewDemo[3293:296197] Delegate: Scrolled in 0x7f915b7349b0 to index: 0
  ```

* Custom parameters:

  ```objc
  // Distance to bottom of pageControl. Default is `10.0f`.
  @property (nonatomic, assign) CGFloat   pageDistance;

  // Not allow scrolling. Default `No`, allow scrolling.
  @property (nonatomic, assign) BOOL      notScrolling;
  ```



## ChangeLog

### V 2.1.1

* Hide pageControl support:

  ```objc
  // Hide or show pageControl. Default is `NO`, show pageControl.
  @property (nonatomic, assign) BOOL      hidePageControl;
  ```

### V 2.1.0

* Implementation requirement: [Issue 6](https://github.com/iTofu/LCBannerView/issues/6) by [skyboy1342](https://github.com/skyboy1342).
  
  Now you could get the clicked image's index and the index scroll to, with **Block** or **Delegate**, see [Usage](https://github.com/iTofu/LCBannerView#usage).

* **Calculation**: `didScrollToIndex` method won't be called to index 0 when you add bannerView to superView, because it hadn't scroll at all, and in fact you know index is 0 now because you do this.

### V 2.0.0 (⚠️ Important)

* Fix [Issue 5](https://github.com/iTofu/LCBannerView/issues/5), thx [MVakas](https://github.com/MVakas)!

* Modify some of the properties' name and methods' name:

  ```objc
  // Properties' name.
  @property (nonatomic, assign) CGFloat timerInterval;
  ->
  @property (nonatomic, assign) CGFloat timeInterval;

  @property (nonatomic, copy  ) NSString  *placeholderImage;
  ->
  @property (nonatomic, copy  ) NSString  *placeholderImageName;

  // All methods' name.
  timerInterval -> timeInterval
  placeholderImage -> placeholderImageName
  ```

### V 1.2.5

* Update README and some documents.


### V 1.2.2

* Update CocoaPods source URL.


### V 1.2.0

* You could custom the images should scrolling now, thx [ac1dpax](https://github.com/ac1dpax). For example:

  ```objc
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
  ```

### V 1.1.0

* You could custom page control bottom distance now. For example:

  ```objc
  // ...
  bannerView.pageDistance = 20.0f;
  ```


### V 1.0.0

* Initial commit.



## Thanks

* [SDWebImage](https://github.com/rs/SDWebImage)



## Support

* If you have any question, just [commit a issue](https://github.com/iTofu/LCBannerView/issues/new)! Thx!

* Mail: devtip@163.com

* Blog: http://LeoDev.me

* Friendly sponsorship with Alipay or Wechat Pay, thank you!

  ![Leo](http://note.leodev.me/alipay.png)



## License

[MIT License](http://opensource.org/licenses/MIT)
