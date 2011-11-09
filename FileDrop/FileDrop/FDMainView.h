//
//  MainView.h
//  FileDrop
//
//  Created by Ryan Sullivan on 11/9/11.
//  Copyright (c) 2011 Freelance Web Developer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RSUIToolBox.h"
#import "FDFileCell.h"

@interface FDMainView : TUIView <TUITableViewDelegate, TUITableViewDataSource> {
    TUITableView *_tableView;
}

@end
