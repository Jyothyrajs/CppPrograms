import Foundation

extension String {
  var localized: String { return NSLocalizedString(self, comment: self) }
}
extension String {
    static var localized_helloWorld: String { return "helloWorld".localized }
}