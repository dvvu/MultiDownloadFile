//
//  NSFileManager+VDNSFileManager.m
//  VDMultiDownloadFile
//
//  Created by Macbook on 11/28/17.
//  Copyright © 2017 VDPersonal. All rights reserved.
//

#import "NSFileManager+VDNSFileManager.h"

@implementation NSFileManager (VDNSFileManager)

#pragma mark - createDirectory

+ (void)createDirectory:(NSURL *)directoryURL {
    
    NSFileManager* fileManager = [NSFileManager defaultManager];
    
    // Create new directory if not existed
    NSError* error;
    
    if (![directoryURL checkResourceIsReachableAndReturnError:&error]) {
        
        [fileManager createDirectoryAtURL:directoryURL withIntermediateDirectories:YES attributes:nil error:nil];
    }
}

#pragma mark - createFile

+ (void)createFile:(NSURL *)fileURL replace:(BOOL)isReplace {
    
    NSFileManager* fileManager = [NSFileManager defaultManager];
    
    // Create new directory if not existed
    NSError* error;
    
    if (![fileURL checkResourceIsReachableAndReturnError:&error] || isReplace) {
        
        [fileManager createFileAtPath:fileURL.path contents:nil attributes:nil];
    }
    
}

#pragma mark - copyFile

+ (NSError *)copyFile:(NSURL *)source toFile:(NSURL *)destination {
    
    NSFileManager* fileManager = [NSFileManager defaultManager];
    
    NSError* error;
    if ([source checkResourceIsReachableAndReturnError:&error]) {
        
        // Check and create destination folder
        [NSFileManager createDirectory: [destination URLByDeletingLastPathComponent]];
        
        if ([destination checkResourceIsReachableAndReturnError:&error]) {
           
            destination = [NSURL fileURLWithPath:[destination.path stringByAppendingString:@"(1)"]];
        } else {
            
            error = nil;
        }
        
        // Copy item
        [fileManager copyItemAtURL:source toURL:destination error:&error];
    }
    
    return error;
}

#pragma mark - removeFileAt

+ (NSError *)removeFileAt:(NSURL *)filePath {
    
    NSFileManager* fileManager = [NSFileManager defaultManager];
    
    NSError* error;
    [fileManager removeItemAtURL:filePath error:&error];
    return error;
}

#pragma mark - getAvailableDiskSpace

+ (int64_t)getAvailableDiskSpace {
    
    NSDictionary* attributes = [[NSFileManager defaultManager] attributesOfFileSystemForPath:@"/var" error:nil];
    NSNumber* freeSpace = [attributes objectForKey:NSFileSystemFreeSize];
    
    return (freeSpace == nil) ? 0 : freeSpace.unsignedLongLongValue;
}

#pragma mark - getSizeOfFile

+ (NSUInteger)getSizeOfFile:(NSURL *)fileLocation {
    
    return [[[NSFileManager defaultManager] attributesOfItemAtPath:fileLocation.path error:nil] fileSize];
}

#pragma mark - sanitizeFileNameString

+ (NSString *)sanitizeFileNameString:(NSString *)fileName {
    
    NSCharacterSet* illegalFileNameCharacters = [NSCharacterSet characterSetWithCharactersInString:@"/\\?%*|\"<>"];
    return [[fileName componentsSeparatedByCharactersInSet:illegalFileNameCharacters] componentsJoinedByString:@""];
}

@end
