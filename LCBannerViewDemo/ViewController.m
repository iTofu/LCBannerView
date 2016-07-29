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

@property (nonatomic, weak) LCBannerView *bannerView1;
@property (nonatomic, weak) LCBannerView *bannerView2;

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
                                                              delegate:nil
                                                             imageName:@"banner"
                                                                 count:2
                                                          timeInterval:3.0f
                                         currentPageIndicatorTintColor:[UIColor orangeColor]
                                                pageIndicatorTintColor:[UIColor whiteColor]];
        bannerView.pageDistance = 20.0f;
        
        bannerView.didClickedImageIndexBlock = ^(LCBannerView *bannerView, NSInteger index) {
            
            NSLog(@"Block: Clicked image in %p at index: %d", bannerView, (int)index);
        };
        
        bannerView.didScrollToIndexBlock = ^(LCBannerView *bannerView, NSInteger index) {
            
            NSLog(@"Block: Scrolled in %p to index: %d", bannerView, (int)index);
        };
        
//        bannerView.notScrolling = YES;
        self.bannerView1 = bannerView;
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
                                                placeholderImageName:nil
                                                        timeInterval:2.0f
                                       currentPageIndicatorTintColor:[UIColor redColor]
                                              pageIndicatorTintColor:[UIColor whiteColor]];
        self.bannerView2 = bannerView;
    })];
    
    [scrollView addSubview:({
        
        UILabel *tipLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 500.0f, [UIScreen mainScreen].bounds.size.width, 30.0f)];
        tipLabel.textAlignment = NSTextAlignmentCenter;
        tipLabel.text = @"⬆️ images from internet.";
        tipLabel;
    })];
    
    [self performSelector:@selector(changed) withObject:nil afterDelay:3.0f];
}

- (void)changed {
    self.bannerView1.count = 3;
    
    NSArray *URLs = @[@"http://admin.guoluke.com:80/userfiles/files/admin/201509181708260671.png",
                      @"http://admin.guoluke.com:80/userfiles/files/admin/201509181707000766.png"];
    self.bannerView2.imageURLs = URLs;
    
    UILabel *label = [[UILabel alloc] init];
    label.text = @"⚠️ Images changed, local images count from 2 to 3, internet image count from 3 to 2, image 3 named `banner_03` and `<201509091054250274.jpg>`.";
    label.textColor = [UIColor redColor];
    label.textAlignment = NSTextAlignmentCenter;
    label.font = [UIFont boldSystemFontOfSize:17.0f];
    label.numberOfLines = 4;
    label.frame = CGRectMake(10.0f, [UIScreen mainScreen].bounds.size.height - 50.0f, [UIScreen mainScreen].bounds.size.width - 10.0f * 2, 50.0f);
    [self.view addSubview:label];
}

//- (void)bannerView:(LCBannerView *)bannerView didClickedImageIndex:(NSInteger)index {
//    
//    NSLog(@"Delegate: Clicked image in %p at index: %d", bannerView, (int)index);
//}
//
//- (void)bannerView:(LCBannerView *)bannerView didScrollToIndex:(NSInteger)index {
//    
//    NSLog(@"Delegate: Scrolled in %p to index: %d", bannerView, (int)index);
//}

@end
