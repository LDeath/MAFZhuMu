//
//  ZhumuSDKRoomDevice.h
//  ZhumuSDK
//
//  Copyright 2006-2017 SUIRUI Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    ZhumuSDKDeviceType_H323  = 1,
    ZhumuSDKDeviceType_SIP,
    ZhumuSDKDeviceType_Both,
}ZhumuSDKDeviceType;

typedef enum {
    ZhumuSDKDeviceEncryptType_None   = 0,
    ZhumuSDKDeviceEncryptType_Encrypt,
    ZhumuSDKDeviceEncryptType_Auto,
}ZhumuSDKDeviceEncryptType;

@interface ZhumuSDKRoomDevice : NSObject

@property (nonatomic, copy) NSString *deviceName;
@property (nonatomic, copy) NSString *ipAddress;
@property (nonatomic, copy) NSString *e164num;
@property (nonatomic, assign) ZhumuSDKDeviceType deviceType;
@property (nonatomic, assign) ZhumuSDKDeviceEncryptType encryptType;

@end
