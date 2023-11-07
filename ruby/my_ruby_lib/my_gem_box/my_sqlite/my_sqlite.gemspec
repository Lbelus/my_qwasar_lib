Gem::Specification.new do |s|
  s.name        = "my_sqlite"
  s.version     = "0.0.0"
  s.executables = "my_sqlite"
  s.summary     = "my_sqlite!"
  s.description = "A simple my_sqlite gem"
  s.authors     = ["lorris Belus", "Igor Mirsalikhov"]
  s.email       = ["l@b.moi", "i@g.mail.com"]
  # s.files       = ["lib/hola.rb", "lib/hola/translator.rb"]
  s.files       = Dir["{lib}/**/*.rb", "bin/*", "LICENSE", "*.md"]
  s.homepage    =
    "https://rubygems.org/gems/hola"
  s.license       = "MIT"

  if s.respond_to?(:metadata)
    s.metadata["allowed_push_host"] = "TODO: Set to 'http://localhost/9292/'"
  else
    raise "something else is needed."
  end

end