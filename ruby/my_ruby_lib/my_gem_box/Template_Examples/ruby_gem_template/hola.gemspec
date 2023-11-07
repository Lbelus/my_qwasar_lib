Gem::Specification.new do |s|
  s.name        = "hola"
  s.version     = "0.0.0"
  s.executables = "hola"
  s.summary     = "Hola!"
  s.description = "A simple hello world gem"
  s.authors     = ["lorris Belus"]
  s.email       = "l@b.moi"
  # s.files       = ["lib/hola.rb", "lib/hola/translator.rb"]
  s.files       = Dir["{lib}/**/*.rb", "bin/*", "LICENSE", "*.md"]
  s.homepage    =
    "https://rubygems.org/gems/hola"
  s.license       = "MIT"

  if s.respond_to?(:metadata)
    s.metadata["allowed_push_host"] = "TODO: Set to 'http://localhost/9292/'"
  else
    raise "something else is needed. \o/"
  end

end