//
//  LDPMPopoverMenu.h
//  PreciousMetals
//  Origin https://github.com/kolyvan/kxmenu/
//  Created by wangchao on 10/30/15.
//  Copyright © 2015 NetEase. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LDPMMenuDismissNotification @"LDPMMenuDismissNotification"

@interface LDPMPopoverMenuItem : NSObject

@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) UIColor *titleColor;
@property (nonatomic, strong) UIColor *highlightedColor;
@property (nonatomic, strong) UIColor *backgroundColor;
@property (strong, nonatomic) UIFont *titleFont;
@property (weak, nonatomic) id target;
@property (assign, nonatomic) SEL action;
@property (assign, nonatomic) NSTextAlignment titleAlignment;

// 针对广贵"荐"字的需求, 在 Item 的最右边增加一个附加的 UIView
@property (nonatomic, strong) UIView *attachmentView;

- (instancetype) initWithTitle:(NSString *)title
                        target:(id)target
                        action:(SEL)action;

- (instancetype) initWithTitle:(NSString *) title
                    titleColor:(UIColor *)titleColor
                     titleFont:(UIFont *)titleFont
                titleAlignment:(NSTextAlignment)titleAlignment
                         image:(UIImage *)image
                        target:(id)target
                        action:(SEL)action;

// 针对广贵"荐"字的需求, 增加一个 Item 的初始化方法
- (instancetype) initWithTitle:(NSString *) title
                         image:(UIImage *)image
                attachmentView:(UIView *)attachmentView
                        target:(id)target
                        action:(SEL)action;

- (instancetype) initWithTitle:(NSString *) title
                    titleColor:(UIColor *)titleColor
                     titleFont:(UIFont *)titleFont
                titleAlignment:(NSTextAlignment)titleAlignment
                         image:(UIImage *)image
                attachmentView:(UIView *)attachmentView
                        target:(id)target
                        action:(SEL)action;



@end

@interface LDPMPopoverMenu : NSObject

- (instancetype)init;

- (instancetype)initWithTintColor:(UIColor *)tintColor
                        maskColor:(UIColor *)maskColor
             itemHorizontalMargin:(CGFloat)itemHorizontalMargin
               itemVerticalMargin:(CGFloat)itemVerticalMargin
               leftInsetOfSepline:(CGFloat)leftInsetOfSepline
                     seplineColor:(UIColor *)seplineColor
                        arrowSize:(CGFloat)arrowSize;

- (void) showMenuInView:(UIView *)inView
               fromView:(UIView *)fromView
              menuItems:(NSArray *)menuItems;

- (void) showMenuInView:(UIView *)view
               fromRect:(CGRect)rect
              menuItems:(NSArray *)menuItems;


- (void) dismissMenu;

@property (strong, nonatomic) UIColor *tintColor;
@property (assign, nonatomic) CGFloat leftInsetOfSepline;
@property (strong, nonatomic) UIColor *seplineColor;
@property (assign, nonatomic) CGFloat itemHorizontalMargin;
@property (assign, nonatomic) CGFloat itemVerticalMargin;
@property (assign, nonatomic) CGFloat arrowSize;
@property (strong, nonatomic) UIColor *maskColor;
@property (assign, nonatomic) CGFloat rightMargin;//距右边界的距离。默认5.f

// 针对广贵"荐"字的需求, 增加一个 margin, 标记文案与"荐"字的间距
@property (nonatomic, assign) CGFloat marginTextToAttachmentView;
// 针对广贵"荐"字的需求, 增加一个判断Menu宽度是否固定的标志
@property (nonatomic, assign) BOOL isMenuWidthFixed;
// 针对广贵"荐"字的需求, 增加一个 fixed width 来记录 Menu 的固定长度
@property (nonatomic, assign) CGFloat menuFixedWidth;



@end
