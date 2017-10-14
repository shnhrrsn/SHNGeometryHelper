Pod::Spec.new do |s|
	s.name          = "SHNGeometryHelper"
	s.version       = "1.1.0"
	s.summary       = "Geometry helpers for iOS, tvOS and macOS"
	s.homepage      = "https://github.com/shnhrrsn/SHNGeometryHelper"

	s.license       = "MIT"
	s.author        = "Shaun Harrison"
	s.social_media_url = "http://twitter.com/shnhrrsn"

	s.source        = { :git => "https://github.com/shnhrrsn/SHNGeometryHelper.git", :tag => s.version }
	s.source_files  = "Sources/*.{h,m}"

	s.osx.frameworks    = "Foundation", "CoreGraphics"
	s.ios.frameworks    = "Foundation", "CoreGraphics", "UIKit"
	s.tvos.frameworks    = "Foundation", "CoreGraphics", "UIKit"

	s.osx.deployment_target = "10.8"
	s.ios.deployment_target  = "7.0"
	s.tvos.deployment_target = "9.0"

	s.requires_arc  = false
end
