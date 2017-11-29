//
//  VDMultiDownloadFIleManager.h
//  VDMultiDownloadFile
//
//  Created by Macbook on 11/28/17.
//  Copyright © 2017 VDPersonal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>
#import "VDDownloadFileItem.h"

@interface VDMultiDownloadFIleManager : NSObject

#pragma mark - sharedDefaultManager
+ (instancetype)sharedDefaultManager;

#pragma mark - sharedBackgroundManager
+ (instancetype)sharedBackgroundManager;

#pragma mark - startDownloadFileFromURL
- (void)startDownloadFileFromURL:(NSString *)sourceURL infoFileDownloadBlock:(InfoFileDownloadBlock)infoFileDownloadBlock callbackQueue:(dispatch_queue_t)queue;

#pragma mark - cancelDownloadForUrl
- (void)cancelDownloadForUrl:(NSString *)fileIdentifier;

#pragma mark - stopDownLoadForUrl...
- (void)pauseDownLoadForUrl:(NSString *)fileIdentifier;

#pragma mark - resumeDownLoadForUrl...
- (void)resumeDownLoadForUrl:(NSString *)fileIdentifier;

#pragma mark - currentDownloadMaximum
@property (nonatomic) int currentDownloadMaximum;

// maximum waiting time for the next data receiving. Only affect to DefaultSession
#pragma mark - timeoutForRequest
@property (nonatomic)NSTimeInterval timeoutForRequest;

#pragma mark - timeoutForResource
@property (nonatomic)NSTimeInterval timeoutForResource;

#pragma mark - checkConnectionNetWork
- (ConnectionType)checkConnectionNetWork;

@end

#pragma mark - Delegate

@protocol MultiDownlodFileCellActionDelegate <NSObject>

#pragma mark - cancelDownloadWithItemID
- (void)startDownloadFromURL:(NSString *)sourceURL;

#pragma mark - cancelDownloadWithItemID
- (void)pauseDownloadWithItemID:(NSString *)identifier;

#pragma mark - cancelDownloadWithItemID
- (void)resumeDownloadWithItemID:(NSString *)identifier;

#pragma mark - cancelDownloadWithItemID
- (void)cancelDownloadWithItemID:(NSString *)identifier;

@end
