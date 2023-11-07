require "minitest/autorun"
require "my_rpn"

class RpnTest < Minitest::Test
  def test_01
    assert_equal "21.545454545454547",
    Calc.my_rpn(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])
  end
  
  def test_02
    assert_equal "20.0",
    Calc.my_rpn(["3","2","+","4","*"])
  end

  def test_03
    assert_equal "55.0",
    Calc.my_rpn(["5","4","7","+","*"])
  end
end