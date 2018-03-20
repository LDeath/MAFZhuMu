//
//  ZhumuSDK.h
//  ZhumuSDK
//
//  Copyright 2006-2017 SUIRUI Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for ZhumuSDK.
FOUNDATION_EXPORT double ZhumuSDKVersionNumber;

//! Project version string for ZhumuSDK.
FOUNDATION_EXPORT const unsigned char ZhumuSDKVersionString[];

//Zhumu SDK Constants
#import <ZhumuSDK/ZhumuSDKConstants.h>

//Zhumu SDK AuthService
#import <ZhumuSDK/ZhumuSDKAuthService.h>

//Zhumu SDK MeetingService
#import <ZhumuSDK/ZhumuSDKMeetingService.h>
#import <ZhumuSDK/ZhumuSDKMeetingService+AppShare.h>
#import <ZhumuSDK/ZhumuSDKMeetingService+InMeeting.h>
#import <ZhumuSDK/ZhumuSDKMeetingService+Customize.h>

//Zhumu SDK MeetingSettings
#import <ZhumuSDK/ZhumuSDKMeetingSettings.h>

//Zhumu SDK Invite Helper
#import <ZhumuSDK/ZhumuSDKInviteHelper.h>

//Zhumu SDK Pre-meeting Service
#import <ZhumuSDK/ZhumuSDKPremeetingService.h>

//Zhumu SDK Room Device
#import <ZhumuSDK/ZhumuSDKRoomDevice.h>

//Zhumu SDK Meeting User Info
#import <ZhumuSDK/ZhumuSDKMeetingUserInfo.h>

/**
 * The ZhumuSDK class is a class that exposes a Zhumu API Rest Client.
 *
 * Access to this class and all other components of the ZhumuSDK can be granted by including `<ZhumuSDK/ZhumuSDK.h>`
 * in your source code.
 *
 * This class provides a class method sharedSDK which provides a preconfigured SDK client,
 * including a ZhumuSDKMeetingService.
 *
 */
@interface ZhumuSDK : NSObject
{
    NSString                    *_zhumuDomain;
    ZhumuSDKMeetingService      *_meetingService;
    ZhumuSDKMeetingSettings     *_meetingSettings;
    
    ZhumuSDKAuthService         *_authService;
    ZhumuSDKPremeetingService   *_premeetingService;
}

@property (retain, nonatomic) NSString *zhumuDomain;

/**
 * Returns the ZhumuSDK default SDK client
 *
 * This method is guaranteed to only instantiate one sharedSDK over the lifetime of an app.
 *
 * This client must be configured with your client key and client secret.
 *
 * *Note*: sharedSDK returns a ZhumuSDK configured with a ZhumuSDKMeetingService.
 *
 * @return a preconfigured SDK client
 */
+ (ZhumuSDK*)sharedSDK;

/**
 * Sets the Zhumu SDK client domain
 *
 * @param domain A domain which used as start/join zhumu meeting
 *
 * *Note*: the domain should not include protocol "https" or "http", the format is just like "www.zhumu.me".
 */
- (void)setZhumuDomain:(NSString*)domain;

/**
 * Get the Zhumu SDK client root navigation controller
 *
 * @return navController, A root navigation controller.
 */
- (UINavigationController*)zhumuRootController;

/**
 * Sets the Zhumu SDK client root navigation controller
 *
 * @param navController A root navigation controller for pushing Zhumu meeting UI.
 */
- (void)setZhumuRootController:(UINavigationController*)navController;

/**
 * Returns the Zhumu SDK default Auth Service
 *
 * *Note*: Auth Service should be called at first, the Zhumu SDK can be used after authorizing successfully.
 *
 * @return a preconfigured Auth Service
 */
- (ZhumuSDKAuthService*)getAuthService;

/**
 * Returns the ZhumuSDK default Pre-meeting Service
 *
 * *Note*: Pre-meeting Service should be called after signed with work email, which is used to schedule/edit/list/delete meeting etc.
 *
 * @return a preconfigured Pre-meeting Service
 */
- (ZhumuSDKPremeetingService*)getPreMeetingService;

/**
 * Returns the Zhumu SDK default Meeting Service
 *
 * @return a preconfigured Meeting Service
 */
- (ZhumuSDKMeetingService*)getMeetingService;

/**
 * Returns the Zhumu SDK default Meeting Settings
 *
 * @return a object of Meeting Settings
 */
- (ZhumuSDKMeetingSettings*)getMeetingSettings;

/**
 * To get SDK supported languages
 *
 * @return SDK supported languages array
 */
- (NSArray *)supportedLanguages;

/**
 * Set the SDK language
 *
 * @param lang indicate language type base on SDK supported language.
 *
 * @return YES if success, Otherwise return NO.
 */
- (void)setLanguage:(NSString *)lang;

/**
 * Notify common layer that app will resign active
 */
- (void)appWillResignActive;

/**
 * Notify common layer that app did become active
 */
- (void)appDidBecomeActive;

/**
 * Notify common layer that app did enter backgroud
 */
- (void)appDidEnterBackgroud;

@end