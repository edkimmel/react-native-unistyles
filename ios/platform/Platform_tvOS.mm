#if TARGET_OS_TV

#import "Platform_tvOS.h"
#import <React/RCTAppearance.h>

@implementation Platform

- (instancetype)init {
    self = [super init];
    if (self) {
        [self setupListeners];
    }
    return self;
}

- (void)dealloc {
    if (self.unistylesRuntime != nullptr) {
        self.unistylesRuntime = nullptr;
    }

    [[NSNotificationCenter defaultCenter] removeObserver:self
                                          name: UIContentSizeCategoryDidChangeNotification
                                          object: nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self
                                          name: RCTUserInterfaceStyleDidChangeNotification
                                          object: nil];
}

- (void)setupListeners {
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(onAppearanceChange:)
                                                 name:RCTUserInterfaceStyleDidChangeNotification
                                               object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(onContentSizeCategoryChange:)
                                                 name:UIContentSizeCategoryDidChangeNotification
                                               object:nil];
}

- (void)makeShared:(void*)runtime {
    self.unistylesRuntime = runtime;
    
    auto unistylesRuntime = ((UnistylesRuntime*)self.unistylesRuntime);
    
    unistylesRuntime->setScreenDimensionsCallback([self](){
        return [self getScreenDimensions];
    });

    unistylesRuntime->setColorSchemeCallback([](){
        return getColorScheme();
    });
    
    unistylesRuntime->setContentSizeCategoryCallback([](){
        return getContentSizeCategory();
    });
    
    dispatch_async(dispatch_get_main_queue(), ^{
        unistylesRuntime->screen = [self getScreenDimensions];
        unistylesRuntime->contentSizeCategory = getContentSizeCategory();
        unistylesRuntime->colorScheme = getColorScheme();
    });
}

- (void)onAppearanceChange:(NSNotification *)notification {
    if (self.unistylesRuntime != nullptr) {
        ((UnistylesRuntime*)self.unistylesRuntime)->handleAppearanceChange(getColorScheme());
    }
}

- (void)onContentSizeCategoryChange:(NSNotification *)notification {
    if (self.unistylesRuntime != nullptr) {
        ((UnistylesRuntime*)self.unistylesRuntime)->handleContentSizeCategoryChange(getContentSizeCategory());
    }
}

- (Dimensions)getScreenDimensions {
    UIScreen *screen = [UIScreen mainScreen];
    Dimensions screenDimension = {(int)screen.bounds.size.width, (int)screen.bounds.size.height};
    
    return screenDimension;
}

@end

#endif
