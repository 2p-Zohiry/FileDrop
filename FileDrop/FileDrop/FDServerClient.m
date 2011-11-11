//
//  FDServerClient.m
//  FileDrop
//
//  Created by Ryan Sullivan on 11/10/11.
//  Copyright (c) 2011 Freelance Web Developer. All rights reserved.
//

#import "FDServerClient.h"

@implementation FDServerClient

-(id)initWithToken:(NSString*)tok andFileManager:(FDFileManager *)fm {
    self = [super init];
    if (self) {
        fileManager = fm;
        
        socket = [[RSSocket alloc] initWithHost:FD_SERVER_HOST port:FD_SERVER_PORT];
        if (!socket) {
            return nil;
        }
        
        readThread = [[NSThread alloc] initWithTarget:self selector:@selector(readSocket:) object:nil];
        
        token = [tok copy];
        [KBPacket writeAuth:token toSocket:socket];
    }
    return self;
}

-(void)dealloc {
    [readThread cancel];
    [socket close];
}


#pragma mark -
#pragma mark Socket IO

-(void)readSocket:(id)sender {
    @autoreleasepool {
        while(![readThread isCancelled]) {
            
            id obj = kb_decode_full_fd([socket fd]);
            if (![obj isKindOfClass:[NSDictionary class]]) {
                continue;
            }
            
            NSDictionary *dict = (NSDictionary*)obj;
            NSLog(@"Got dict: %@", dict);
            
        }
    }
}

@end
