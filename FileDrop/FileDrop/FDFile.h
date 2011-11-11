//
//  FDFile.h
//  FileDrop
//
//  Created by Ryan Sullivan on 11/9/11.
//  Copyright (c) 2011 Freelance Web Developer. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FDFile : NSObject {
    NSString *fileID;
    NSString *localPath;
    NSData *fileHash;
    NSString *filename;
    
    BOOL isPaused;
    BOOL isAccepted;
    BOOL progressIndeterminate;
    
    NSUInteger bytesTransfered;
    NSUInteger bytesTotal;
    
    NSImage *icon;
}

@property (nonatomic, copy, readonly) NSString *fileID;
@property (nonatomic, copy, readonly) NSString *localPath;

@property (nonatomic, assign) BOOL isPaused;
@property (nonatomic, assign) BOOL isAccepted;

@property (nonatomic, assign) NSUInteger bytesTransfered;
@property (nonatomic, readonly) NSUInteger bytesTotal;

@property (nonatomic, retain, readonly) NSImage *icon;

#pragma mark - Bindings Support
// Don't need to touch these, these will be set by the custom setters
@property (nonatomic, copy, readonly) NSString *filename;
@property (nonatomic, assign) BOOL progressIndeterminate;
@end
