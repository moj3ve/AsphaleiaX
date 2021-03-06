#import <UIKit/UIKit.h>
#import <AppSupport/CPDistributedMessagingCenter.h>

typedef NS_ENUM(NSInteger, ASAuthenticationAlertType) {
	ASAuthenticationAlertAppArranging,
	ASAuthenticationAlertSwitcher,
	ASAuthenticationAlertSpotlight,
	ASAuthenticationAlertPowerDown,
	ASAuthenticationAlertControlCentre,
	ASAuthenticationAlertControlPanel,
	ASAuthenticationAlertDynamicSelection,
	ASAuthenticationAlertPhotos,
	ASAuthenticationAlertSettingsPanel,
	ASAuthenticationAlertFlipswitch
};

typedef NS_ENUM(NSInteger, ASAuthenticationType) {
	ASAuthenticationItem,
	ASAuthenticationFunction,
	ASAuthenticationSecurityMod
};

typedef void (^ASCommonAuthenticationHandler) (BOOL wasCancelled);

@interface ASCommon : NSObject {
	ASCommonAuthenticationHandler authHandler;
	CPDistributedMessagingCenter *_centre;
}
+ (instancetype)sharedInstance;
- (BOOL)displayingAuthAlert;
- (BOOL)authenticateAppWithDisplayIdentifier:(NSString *)appIdentifier customMessage:(NSString *)customMessage dismissedHandler:(ASCommonAuthenticationHandler)handler;
- (BOOL)authenticateFunction:(ASAuthenticationAlertType)alertType dismissedHandler:(ASCommonAuthenticationHandler)handler;

@end
