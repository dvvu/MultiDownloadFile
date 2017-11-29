//
//  NSFileManager+VDNSFileManager.h
//  VDMultiDownloadFile
//
//  Created by Macbook on 11/28/17.
//  Copyright © 2017 VDPersonal. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSFileManager (VDNSFileManager)

#pragma mark - createDirectory
+ (void)createDirectory:(NSURL *)directoryURL;

#pragma mark - createFile
+ (void)createFile:(NSURL *)fileURL replace:(BOOL)isReplace;

#pragma mark - copyFile
+ (NSError *)copyFile:(NSURL *)source toFile:(NSURL *)destination;

#pragma mark - removeFileAt
+ (NSError *)removeFileAt:(NSURL *)filePath;

#pragma mark - getAvailableDiskSpace
+ (int64_t)getAvailableDiskSpace;

#pragma mark - getSizeOfFile
+ (NSUInteger)getSizeOfFile:(NSURL *)fileLocation;

#pragma mark - sanitizeFileNameString
+ (NSString *)sanitizeFileNameString:(NSString *)fileName;

@end
