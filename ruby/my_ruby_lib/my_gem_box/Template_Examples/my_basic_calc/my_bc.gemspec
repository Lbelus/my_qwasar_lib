Gem::Specification.new do |s|
  s.name        = "my_bc"
  s.version     = "0.0.0"
  s.executables = "my_bc"
  s.summary     = "Perfoms basic operation"
  s.description = "A simple basic calc gem to learn how to create gems and structures programs in ruby"
  s.authors     = ["lorris Belus"]
  s.email       = "l@b.moi"
  # s.files       = ["lib/hola.rb", "lib/hola/translator.rb"]
  s.files       = Dir["{lib}/**/*.rb", "bin/*", "LICENSE", "*.md"]
  s.homepage    =
    "https://rubygems.org/gems/my_bc" #not published
  s.license       = "MIT"

  if s.respond_to?(:metadata)
    s.metadata["allowed_push_host"] = "TODO: Set to 'http://localhost/9292/'"
  else
    raise "something else is needed. \o/"
  end

end