Pod::Spec.new do |s|

  s.name         = "LCBannerView"
  s.version      = "1.0.0"
  s.summary      = "A very popular and highly customized banner view! . Support: http://www.leodong.com"
  s.homepage     = "https://github.com/LeoiOS/LCBannerView"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author             = { "Leo" => "leoios@sina.com" }
  s.social_media_url   = "http://www.leodong.com"
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/LeoiOS/LCBannerView.git", :tag => s.version }
  s.source_files  = "LCBannerView/*"
  s.requires_arc = true

  s.dependency "SDWebImage"

end
