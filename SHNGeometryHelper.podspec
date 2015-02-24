Pod::Spec.new do |s|
	s.name          = "SHNGeometryHelper"
	s.version       = "1.0.0"
	s.summary       = "Geometry helpers for iOS/OS X"
	s.homepage      = "https://github.com/shnhrrsn/SHNGeometryHelper"

	s.license       = "MIT"
	s.author        = "Shaun Harrison"

	s.source        = { :git => "https://github.com/shnhrrsn/SHNGeometryHelper.git", :tag => "1.0.0" }
	s.source_files  = "*.{h,m}"
	s.requires_arc  = false
end