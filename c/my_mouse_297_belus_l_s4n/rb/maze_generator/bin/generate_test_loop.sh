# generate a bunch of of test. 

for i in {1..10}; do
    ruby maze_generator.rb 10 10 "* o12" > test"$i".txt
done