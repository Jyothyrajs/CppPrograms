#if os(OSX)
    typealias Image     = NSImage
    typealias ImageName = NSImage.Name
#elseif os(iOS)
    import UIKit

    typealias Image     = UIImage
    typealias ImageName = String
#endif

extension Image {
    static var assets_AppIcon: Image { return Image(named: ImageName("AppIcon"))! }
    static var assets_hello: Image { return Image(named: ImageName("hello"))! }
}