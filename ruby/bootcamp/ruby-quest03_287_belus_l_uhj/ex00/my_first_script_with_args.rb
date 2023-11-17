

def my_first_script_with_arg(my_argv)
    my_argv.each { |x| puts x}
end

my_first_script_with_arg(ARGV)