# LCBannerView
A very popular and highly customized banner view! 

````
心有猛虎，细嗅蔷薇。
````

## Installation

LCBannerView is available on [CocoaPods](https://cocoapods.org/). Just add the following to your project Podfile:
````ruby
pod "LCBannerView"  # Podfile
````

## Non-CocoaPods Installation



## Usage

* Use by including the following import:
````objc
#import "LCBannerView"
````
* demo code:
````objc
[scrollView addSubview:({
    
    LCBannerView *bannerView = [LCBannerView bannerViewWithFrame:CGRectMake(0, 300.0f, [UIScreen mainScreen].bounds.size.width, 200.0f)
                                                        delegate:self
                                                       imageURLs:URLs
                                                placeholderImage:nil
                                                   timerInterval:2.0f
                                   currentPageIndicatorTintColor:[UIColor redColor]
                                          pageIndicatorTintColor:[UIColor whiteColor]];
    bannerView;
})];
````
