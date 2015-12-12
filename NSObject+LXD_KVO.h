/**
 File: NSObject + LXD_KVO
 
 Abstract: This is category file of NSObject, This file add two method to add observer with class. We can't custom a selector to be invoked when specified event happens. This makes it very easy to searate things from superclass. In another way, we can's sure if the superclass is interested with the same notification as subclass interestes in. 
 
 Detail: How does apple do to implement KVO. The class as observed object actually motify its isa pointer pointing to an intermediate class rather than the true class when an observer is registered for its attribute of object. Surely, apple must override this intermediate class's setter method to invoke the attribute is observed has changed. By the way, apple will also override method named "class" for concealling the true implementation.
 
 About: This file provide block method instance of default callback method to be invoked by the observer to implement custom selector to be invoked, and also remove the context param cause it really be useless
 
 Warning: This Key-Value-Observe can only be used for id type in objective-c language, if you use this method to observe a no-object, the programm will crash
 
 Implement: Create new class includes observer as NSObject * type, key as NSString * type and handler as custom block type to store each notification event. Use Objective-C's runtime to call something operation base on class-structive
 
 Author: Wrote by John Lin on 2015.3.15
**/

//
//  NSObject+LXD_KVO.h
//  LXD_KeyValueObserveDemo
//
//  Created by linxinda on 15/3/15.
//  Copyright (c) 2015年 Personal. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^LXD_ObservingHandler) (id observedObject, NSString * observedKey, id oldValue, id newValue);

@interface NSObject (LXD_KVO)

/**
 *  method stead of traditional addObserver API
 *
 *  @param object          object as observer
 *  @param key             attribute of object to be observed
 *  @param observedHandler method to be invoked when notification be observed has changed
 */
- (void)LXD_addObserver: (NSObject *)object forKey: (NSString *)key withBlock: (LXD_ObservingHandler)observedHandler;


/**
 *  remove the observe
 *
 *  @param object object as observer
 *  @param key    attribute observed will remove the observe
 */
- (void)LXD_removeObserver: (NSObject *)object forKey: (NSString *)key;

@end