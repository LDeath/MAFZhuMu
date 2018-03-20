//
//  ZhumuSDKConstants.h
//  ZhumuSDK
//
//  Copyright 2006-2017 SUIRUI Co., Ltd. All rights reserved.
//

//ZhumuSDK Base Domain
#define kZhumuSDKBaseDomain      @"launcher.zhumu.me"


//Client Key or Secret is empty
#define kSDKAuthKeyOrSecretEmpty        300
//Client Key or Secret is wrong
#define kSDKAuthKeyOrSecretWrong        3023
//Account does not support SDK feature
#define kSDKAuthAccountNotSupport       3024
//Account has not enabled SDK feature
#define kSDKAuthAccountNotEnableSDK     3025

#if defined(_ZM_BOX_SDK_)
/**
 * Design for enable BoxSDK in ZhumuSDK.
 *
 * **Note**: Before using Zhumu SDK, the client should setup App Key and Secret of BoxSDK by [[NSUserDefaults standardUserDefaults] setObject:@"xxx" forKey:kBoxSDKAppKey], [[NSUserDefaults standardUserDefaults] setObject:@"yyy" forKey:kBoxSDKAppSecret].
 */
#define kBoxSDKAppKey               @"BoxSDK.AppKey"
#define kBoxSDKAppSecret            @"BoxSDK.AppSecret"
#endif

#if defined(_ZM_DROPBOX_SDK_)
/**
 * Design for enable BoxSDK in DropboxSDK.
 *
 * **Note**: Before using Zhumu SDK, the client should setup App Key and Secret of DropboxSDK by [[NSUserDefaults standardUserDefaults] setObject:@"xxx" forKey:kDropboxSDKAppKey], [[NSUserDefaults standardUserDefaults] setObject:@"yyy" forKey:kDropboxSDKAppSecret].
 */
#define kDropboxSDKAppKey           @"DropboxSDK.AppKey"
#define kDropboxSDKAppSecret        @"DropboxSDK.AppSecret"
#endif

typedef enum {
    //Auth Success
    ZhumuSDKAuthError_Success,
    //Key or Secret is empty
    ZhumuSDKAuthError_KeyOrSecretEmpty,
    //Key or Secret is wrong
    ZhumuSDKAuthError_KeyOrSecretWrong,
    //Client Account does not support
    ZhumuSDKAuthError_AccountNotSupport,
    //Client account does not enable SDK
    ZhumuSDKAuthError_AccountNotEnableSDK,
    //Auth Unknown error
    ZhumuSDKAuthError_Unknown,
}ZhumuSDKAuthError;

typedef enum {
    //Success
    ZhumuSDKMeetError_Success                    = 0,
    //Incorrect meeting number
    ZhumuSDKMeetError_IncorrectMeetingNumber     = 1,
    //Meeting Timeout
    ZhumuSDKMeetError_MeetingTimeout             = 2,
    //Network Unavailable
    ZhumuSDKMeetError_NetworkUnavailable         = 3,
    //Client Version Incompatible
    ZhumuSDKMeetError_MeetingClientIncompatible  = 4,
    //User is Full
    ZhumuSDKMeetError_UserFull                   = 5,
    //Meeting is over
    ZhumuSDKMeetError_MeetingOver                = 6,
    //Meeting does not exist
    ZhumuSDKMeetError_MeetingNotExist            = 7,
    //Meeting has been locked
    ZhumuSDKMeetError_MeetingLocked              = 8,
    //Meeting Restricted
    ZhumuSDKMeetError_MeetingRestricted          = 9,
    //JBH Meeting Restricted
    ZhumuSDKMeetError_MeetingJBHRestricted       = 10,
    
    //Invalid Arguments
    ZhumuSDKMeetError_InvalidArguments           = 99,
    //Invalid Arguments
    ZhumuSDKMeetError_InvalidUserType            = 100,
    //Already In another ongoing meeting
    ZhumuSDKMeetError_InAnotherMeeting           = 101,
    //Unknown error
    ZhumuSDKMeetError_Unknown                    = 102,
    
}ZhumuSDKMeetError;

typedef enum {
    //Idle
    ZhumuSDKMeetingState_Idle        = 0,
    //Connecting
    ZhumuSDKMeetingState_Connecting  = 1,
    //In Meeting
    ZhumuSDKMeetingState_InMeeting   = 2,
    
}ZhumuSDKMeetingState;


typedef enum {
    //API user type
    ZhumuSDKUserType_APIUser     = 99,
    //Work email user type
    ZhumuSDKUserType_ZhumuUser    = 100,
    //Single-sign-on user type
    ZhumuSDKUserType_SSOUser     = 101,
}ZhumuSDKUserType;

typedef enum {
    //Leave meeting
    ZhumuLeaveMeetingCmd_Leave,
    //End Meeting
    ZhumuLeaveMeetingCmd_End,
}ZhumuLeaveMeetingCmd;

typedef enum {
    //Show JBH waiting
    ZhumuJBHCmd_Show,
    //Hide JBH waiting
    ZhumuJBHCmd_Hide,
}ZhumuJBHCmd;

typedef enum {
    ZhumuDialOutStatus_Unknown  = 0,
    ZhumuDialOutStatus_Calling,
    ZhumuDialOutStatus_Ringing,
    ZhumuDialOutStatus_Accepted,
    ZhumuDialOutStatus_Busy,
    ZhumuDialOutStatus_NotAvailable,
    ZhumuDialOutStatus_UserHangUp,
    ZhumuDialOutStatus_OtherFail,
    ZhumuDialOutStatus_JoinSuccess,
    ZhumuDialOutStatus_TimeOut,  //For client not get response, maybe network reason
    ZhumuDialOutStatus_ZoomStartCancelCall,
    ZhumuDialOutStatus_ZoomCallCanceled,
    ZhumuDialOutStatus_ZoomCancelCallFail,
    ZhumuDialOutStatus_NoAnswer,  //Indicate the phone ring but no-one answer
    ZhumuDialOutStatus_BlockNoHost,  //JBH case, disable international callout before host join
    ZhumuDialOutStatus_BlockHighRate,  //The price of callout phone number is too expensive which has been blocked by system
    ZhumuDialOutStatus_BlockTooFrequent,  //Invite by phone with pressONE required, but invitee frequently does NOT press one then timeout
}ZhumuDialOutStatus;

