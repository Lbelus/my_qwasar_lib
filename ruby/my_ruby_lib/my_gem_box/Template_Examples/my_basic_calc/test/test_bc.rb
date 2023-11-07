require "minitest/autorun"
require "my_rpn"
require "my_bc.rb"
# require "my_rpn/operators"

class My_bc_Test < Minitest::Test
  # include Operator

  # def test_05 # test for step 5
  #   rpn_notation = my_bc_fn( ["1","*","10","^","2","+","5"] )
  #   puts "this is test N 05 : #{rpn_notation}"
  #   assert_equal "25.0",
  #   my_rpn_fn(rpn_notation)
  # end
# ["3", "1", "2", "2", "*", "+", "*", "5", "+"]
  def test_06 # test for step 6
    puts "begin test 6 "  
    rpn_notation = my_bc_fn( ["3","*","(","1","+","2","*","2",")","+","5"] )
    puts "this is test N 06 : #{rpn_notation}" 
    assert_equal "20.0",
    my_rpn_fn(rpn_notation)
  end

  def test_extra_01
    rpn_notation = my_bc_fn(["(", "(", "4", "+", "2", ")", "*", "3", ")", "/", "(", "5", "-", "1", ")"])
    assert_equal "4.5",
    my_rpn_fn(rpn_notation)
  end

  def test_extra_02
    rpn_notation = my_bc_fn( ["(", "3","+","2",")","*","4"] )
    assert_equal "20.0",
    my_rpn_fn(rpn_notation)
  end

  def test_extra_03
    rpn_notation = my_bc_fn(["5","*","(","4","+","7",")"])
    assert_equal "55.0",
    my_rpn_fn(rpn_notation)
  end

  def test_extra_04
    p "begin test 04 "  
    rpn_notation = my_bc_fn(["2", "+", "3", "*", "4"])
    p "this rpn : #{rpn_notation}"
    assert_equal "14.0",
    my_rpn_fn(rpn_notation)
  end

  def test_extra_05
    rpn_notation = my_bc_fn(["(", "4", "+", "3", ")", "*", "(", "6", "-", "2", ")", "/", "(", "9", "-", "1", ")"] )
    # puts "this is test N 05 : #{rpn_notation}" 
    assert_equal "3.5",
    my_rpn_fn(rpn_notation)
  end

  def test_qw_01
    rpn_notation = my_bc_fn( ["1","+","2","*","(","3","-","42",")","/","5"] )
    # puts "this is test N 05 : #{rpn_notation}" 
    assert_equal "-14.6",
    my_rpn_fn(rpn_notation)
  end

end