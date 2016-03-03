//
//  ViewController.m
//  LCBannerViewDemo
//
//  Created by Leo on 15/11/30.
//  Copyright © 2015年 Leo. All rights reserved.
//

#import "ViewController.h"
#import "LCBannerView.h"

@interface ViewController () <LCBannerViewDelegate>

@end

@implementation ViewController

- (void)viewDidLoad {
    
    [super viewDidLoad];
    
    UIScrollView *scrollView = [[UIScrollView alloc] initWithFrame:[UIScreen mainScreen].bounds];
    scrollView.contentSize = CGSizeMake(0, [UIScreen mainScreen].bounds.size.height + 300.0f);
    [self.view addSubview:scrollView];
    
    
    /******************** local ********************/
    [scrollView addSubview:({
        
        LCBannerView *bannerView = [[LCBannerView alloc] initWithFrame:CGRectMake(0, 20.0f, [UIScreen mainScreen].bounds.size.width, 200.0f)
                                                              delegate:self
                                                             imageName:@"banner"
                                                                 count:3
                                                         timerInterval:3.0f
                                         currentPageIndicatorTintColor:[UIColor orangeColor]
                                                pageIndicatorTintColor:[UIColor whiteColor]];
        bannerView.pageDistance = 20.0f;
//        bannerView.notScrolling = YES;
        bannerView;
    })];
    
    [scrollView addSubview:({
        
        UILabel *tipLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 220.0f, [UIScreen mainScreen].bounds.size.width, 30.0f)];
        tipLabel.textAlignment = NSTextAlignmentCenter;
        tipLabel.text = @"⬆️ images from local.";
        tipLabel;
    })];
    
    
    /******************** internet ********************/
    NSArray *URLs = @[@"http://admin.guoluke.com:80/userfiles/files/admin/201509181708260671.png",
                      @"http://admin.guoluke.com:80/userfiles/files/admin/201509181707000766.png",
                      @"http://img.guoluke.com/upload/201509091054250274.jpg"];
    
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
    
    [scrollView addSubview:({
        
        UILabel *tipLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 500.0f, [UIScreen mainScreen].bounds.size.width, 30.0f)];
        tipLabel.textAlignment = NSTextAlignmentCenter;
        tipLabel.text = @"⬆️ images from internet.";
        tipLabel;
    })];
}

- (void)bannerView:(LCBannerView *)bannerView didClickedImageIndex:(NSInteger)index {
    
    NSLog(@"you clicked image in %p at index: %ld", bannerView, (long)index);
}

@end
