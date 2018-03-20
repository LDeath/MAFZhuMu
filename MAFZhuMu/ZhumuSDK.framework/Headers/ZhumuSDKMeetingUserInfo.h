//
//  ZhumuSDKMeetingUserInfo.h
//  ZhumuSDK
//
//  Copyright 2006-2017 SUIRUI Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZhumuSDKVideoStatus : NSObject

@property (nonatomic, assign) BOOL  isSending;
@property (nonatomic, assign) BOOL  isReceiving;
@property (nonatomic, assign) BOOL  isSource;

@end

typedef enum {
    ZhumuSDKAudioType_VoIP   = 0,
    ZhumuSDKAudioType_Telephony,
    ZhumuSDKAudioType_None,
}ZhumuSDKAudioType;

@interface ZhumuSDKAudioStatus : NSObject

@property (nonatomic, assign) BOOL  isMuted;
@property (nonatomic, assign) BOOL  isTalking;
@property (nonatomic, assign) ZhumuSDKAudioType  audioType;

@end

typedef enum {
    ZhumuSDKFeedbackType_None    = 0,
    ZhumuSDKFeedbackType_Hand,
    ZhumuSDKFeedbackType_Yes,
    ZhumuSDKFeedbackType_No,
    ZhumuSDKFeedbackType_Fast,
    ZhumuSDKFeedbackType_Slow,
    ZhumuSDKFeedbackType_Good,
    ZhumuSDKFeedbackType_Bad,
    ZhumuSDKFeedbackType_Clap,
    ZhumuSDKFeedbackType_Coffee,
    ZhumuSDKFeedbackType_Clock,
    ZhumuSDKFeedbackType_Emoji,
}ZhumuSDKFeedbackType;

@interface ZhumuSDKMeetingUserInfo : NSObject

@property (nonatomic, assign) NSUInteger       userID;
@property (nonatomic, strong) NSString*        userName;
@property (nonatomic, strong) NSString*        emailAddress;
@property (nonatomic, strong) NSString*        avatarPath;
@property (nonatomic, assign) NSInteger        unread;
@property (nonatomic, strong) ZhumuSDKVideoStatus*  videoStatus;
@property (nonatomic, strong) ZhumuSDKAudioStatus*  audioStatus;
@property (nonatomic, assign) BOOL             handRaised;
@property (nonatomic, assign) BOOL             inSilentMode;
@property (nonatomic, assign) ZhumuSDKFeedbackType  feedbackType;

@end
