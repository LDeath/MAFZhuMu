//
//  ZhumuSDKAuthService.h
//  ZhumuSDK
//
//  Copyright 2006-2017 SUIRUI Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZhumuSDKConstants.h"

@protocol ZhumuSDKAuthDelegate;

/**
 * This class provides support for authorizing Zhumu SDK.
 *
 * The Authorization Code Grant requires HTTP request to allow the user to authenticate with Zhumu SDK and Authorize your
 * application. Upon successful authorization, the ZhumuSDKAuthDelegate will give ZhumuSDKAuthError_Success to user by method onZhumuSDKAuthReturn.
 *
 * **Note**: Before using Zhumu SDK, the client should authorize the Zhumu SDK at first. or the function in Zhumu
 *   SDK cannot work correctly.
 */
@interface ZhumuSDKAuthService : NSObject

/**
 * The object that acts as the delegate of the receiving auth/login events.
 */
@property (weak, nonatomic) id<ZhumuSDKAuthDelegate> delegate;

/**
 * The key value is used during the authorization code grant.
 *
 */
@property (strong, nonatomic) NSString *clientKey;

/**
 * The secret value is used during the authorization code grant.
 *
 */
@property (strong, nonatomic) NSString *clientSecret;

/**
 * Designated authorizing Zhumu SDK.
 *
 * If the client key or secret is empty, user will get error:ZhumuSDKAuthError_KeyOrSecretEmpty in method onZhumuSDKAuthReturn from ZhumuSDKAuthDelegate
 */
- (void)sdkAuth;

/**
 * @return A BOOL indicating whether the Zhumu sdk auth may be valid.
 */
- (BOOL)isAuthorized;

/**
 * Designated for login Zhumu SDK with work account.
 *
 * @param account, login account.
 * @param password, login password.
 *
 * @return YES, if user can login with work account.
 *
 * *Note*: this method is optional, if you do have work account in Zhumu, just ignore it.
 */
- (BOOL)loginWithZhumu:(NSString*)account password:(NSString*)password;

/**
 * Designated for logout Zhumu SDK.
 *
 * @return YES, if user can logout.
 *
 * *Note*: this method is optional, if you do have work email account in Zhumu, just ignore it.
 */
- (BOOL)logoutZhumu;

@end

/**
 * ZhumuSDKAuthDelegate
 * An Auth Service will issue the following value when the authorization state changes:
 *
 * - ZhumuSDKAuthError_Success: Zoom SDK authorizs successfully.
 * - ZhumuSDKAuthError_KeyOrSecretEmpty: the client key or secret for SDK Auth is empty.
 * - ZhumuSDKAuthError_KeyOrSecretWrong: the client key or secret for SDK Auth is wrong.
 * - ZhumuSDKAuthError_AccountNotSupport: this client account cannot support Zhumu SDK.
 * - ZhumuSDKAuthError_AccountNotEnableSDK: this client account does not enable Zhumu SDK.
 */
@protocol ZhumuSDKAuthDelegate <NSObject>

@required
/**
 * Designated for Zhumu SDK Auth response.
 *
 * @param returnValue tell user when the auth state changed.
 *
 */
- (void)onZhumuSDKAuthReturn:(ZhumuSDKAuthError)returnValue;

@optional
/**
 * Designated for Zhumu SDK Login response.
 *
 * @param returnValue tell user when the login state changed.
 *
 */
- (void)onZhumuSDKLoginReturn:(NSInteger)returnValue;

/**
 * Designated for Zhumu SDK Logout response.
 *
 * @param returnValue tell user whether the logout success or not.
 *
 */
- (void)onZhumuSDKLogoutReturn:(NSInteger)returnValue;

@end
