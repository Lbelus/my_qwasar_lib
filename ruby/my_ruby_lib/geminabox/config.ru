require "rubygems"
require "geminabox"
# /home/lorris_belus/.rbenv/shims/ <- exec is here
# type in rackup to launch server 
#https://github.com/geminabox/geminabox
Geminabox.data = "./data"
# Use Rack::Protection to prevent XSS and CSRF vulnerability if your geminabox server is open public.
# Rack::Protection requires a session middleware, choose your favorite one such as Rack::Session::Memcache.
# This example uses Rack::Session::Pool for simplicity, but please note that:
# 1) Rack::Session::Pool is not available for multiprocess servers such as unicorn
# 2) Rack::Session::Pool causes memory leak (it does not expire stored `@pool` hash)
use Rack::Session::Pool, expire_after: 1000 # sec
use Rack::Protection
Geminabox.rubygems_proxy = true
Geminabox.allow_remote_failure = true
run Geminabox::Server