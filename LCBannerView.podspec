Pod::Spec.new do |s|

  s.name         = "LCBannerView"
  s.version      = "2.0.0"
  s.summary      = "A very popular and highly customized banner view! Infinite loop! Support: http://LeoDev.me"
  s.homepage     = "https://github.com/iTofu/LCBannerView"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author             = { "Leo" => "devtip@163.com" }
  s.social_media_url   = "http://LeoDev.me"
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/iTofu/LCBannerView.git", :tag => s.version }
  s.source_files = "LCBannerView/*"
  s.requires_arc = true

  s.dependency "SDWebImage", '~> 3.7.6'

end
