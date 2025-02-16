#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class Mat_dxtTest < OpenCVTestCase
  def test_dft_1D
    n = 32
    w = 2 * Math::PI / n
    
    mat0 = create_mat(n, 1, :cv32f, 2) { |j, i, c|
      s = Math.sin(c * w)
      Cv::Scalar.new(s, s)
    }
    mat1 = mat0.dft(CV_DXT_FORWARD)
    mat2 = mat0.dft(CV_DXT_FORWARD | CV_DXT_SCALE)
    mat3 = mat0.dft(CV_DXT_FORWARD | CV_DXT_SCALE).dft(CV_DXT_INVERSE)
    n.times { |j|
      if j == 1
        assert_in_delta(n / 2, mat1[j, 0][0], 0.001)
        assert_in_delta(-n / 2, mat1[j, 0][1], 0.001)
        assert_in_delta(0.5, mat2[j, 0][0], 0.001)
        assert_in_delta(-0.5, mat2[j, 0][1], 0.001)
      elsif j == n - 1
        assert_in_delta(-n / 2, mat1[j, 0][0], 0.001)
        assert_in_delta(n / 2, mat1[j, 0][1], 0.001)
        assert_in_delta(-0.5, mat2[j, 0][0], 0.001)
        assert_in_delta(0.5, mat2[j, 0][1], 0.001)
      else
        assert_in_delta(0, mat1[j, 0][0], 0.001)
        assert_in_delta(0, mat1[j, 0][1], 0.001)
        assert_in_delta(0, mat2[j, 0][0], 0.001)
        assert_in_delta(0, mat2[j, 0][1], 0.001)
      end
      assert_in_delta(mat0[j, 0][0], mat3[j, 0][0], 0.001)
      assert_in_delta(mat0[j, 0][1], mat3[j, 0][1], 0.001)
    }
    assert_raise(TypeError) {
      mat0.dft(DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      mat0.dft(CV_DXT_FORWARD, DUMMY_OBJ)
    }
  end

  def test_dft_2D
    n = 32
    w = 2 * Math::PI / n
    c = 0
    mat0 = Cv::Mat.new(n, n, :cv32f, 2)
    n.times { |j|
      s = Math.sin(c * w)
      n.times { |i|
        mat0[j, i] = Cv::Scalar.new(s, s)
      }
      c += 1
    }
    mat1 = mat0.dft(CV_DXT_FORWARD)
    mat2 = mat0.dft(CV_DXT_FORWARD | CV_DXT_SCALE)
    mat3 = mat0.dft(CV_DXT_FORWARD | CV_DXT_SCALE).dft(CV_DXT_INVERSE)
    n.times { |j|
      n.times { |i|
        if i == 0 and j == 1
          assert_in_delta(n * n / 2, mat1[j, i][0], 0.001)
          assert_in_delta(-n * n / 2, mat1[j, i][1], 0.001)
          assert_in_delta(0.5, mat2[j, i][0], 0.001)
          assert_in_delta(-0.5, mat2[j, i][1], 0.001)
        elsif i == 0 and j == n - 1
          assert_in_delta(-n * n / 2, mat1[j, i][0], 0.001)
          assert_in_delta(n * n / 2, mat1[j, i][1], 0.001)
          assert_in_delta(-0.5, mat2[j, i][0], 0.001)
          assert_in_delta(0.5, mat2[j, i][1], 0.001)
        else
          assert_in_delta(0, mat1[j, i][0], 0.001)
          assert_in_delta(0, mat1[j, i][1], 0.001)
          assert_in_delta(0, mat2[j, i][0], 0.001)
          assert_in_delta(0, mat2[j, i][1], 0.001)
        end
        assert_in_delta(mat0[j, 0][0], mat3[j, i][0], 0.001)
        assert_in_delta(mat0[j, 0][1], mat3[j, i][1], 0.001)
      }
    }
  end

  def test_dct_1D
    n = 8
    w = 2 * Math::PI / n
    
    mat0 = create_mat(n, 1, :cv32f, 1) { |j, i, c|
      s = Math.sin(c * w)
      Cv::Scalar.new(s)
    }
    mat1 = mat0.dct(CV_DXT_FORWARD)
    mat2 = mat0.dct(CV_DXT_FORWARD).dct(CV_DXT_INVERSE)
    expected1 = [0, 1.599647, -0.765367, -0.906127, 0, -0.180240, 0, -0.042290]
    n.times { |j|
      assert_in_delta(expected1[j], mat1[j, 0][0], 0.001)
      assert_in_delta(mat0[j, 0][0], mat2[j, 0][0], 0.001)
    }
    assert_raise(TypeError) {
      mat0.dct(DUMMY_OBJ)
    }
  end

  def test_dct_2D
    n = 8
    w = 2 * Math::PI / n
    c = 0
    mat0 = Cv::Mat.new(n, n, :cv32f, 1)
    n.times { |j|
      s = Math.sin(c * w)
      n.times { |i|
        mat0[j, i] = Cv::Scalar.new(s, s)
      }
      c += 1
    }
    mat1 = mat0.dct(CV_DXT_FORWARD)
    mat2 = mat0.dct(CV_DXT_FORWARD).dct(CV_DXT_INVERSE)
    n.times { |j|
      n.times { |i|
        if i == 0 and j == 1
          assert_in_delta(4.524486, mat1[j, i][0], 0.001)
        elsif i == 0 and j == 2
          assert_in_delta(-2.164784, mat1[j, i][0], 0.001)
        elsif i == 0 and j == 3
          assert_in_delta(-2.562915, mat1[j, i][0], 0.001)
        elsif i == 0 and j == 5
          assert_in_delta(-0.509796, mat1[j, i][0], 0.001)
        elsif i == 0 and j == 7
          assert_in_delta(-0.119615, mat1[j, i][0], 0.001)
        else
          assert_in_delta(0, mat1[j, i][0], 0.001)
        end
        assert_in_delta(mat0[j, i][0], mat2[j, i][0], 0.001)
      }
    }
  end
end

