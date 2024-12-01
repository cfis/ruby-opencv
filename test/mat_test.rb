#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::Mat
class MatTest < OpenCVTestCase
  def test_create
    mat = Cv::Mat.new(10, 20, CV_32F)
    assert_equal(10, mat.rows)
    assert_equal(20, mat.cols)
    assert_equal(CV_32F, mat.depth)
    a = mat.type
    assert_equal(CV_32F, mat.type)
    assert_equal(1, mat.channels)
  end

  def test_zeros
    mat_expr = Cv::Mat.zeros(5, 5, CV_32F)
    mat = mat_expr.to_mat
    assert_equal(5, mat.rows)
    assert_equal(5, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(1, mat.channels)
    assert_equal("[0, 0, 0, 0, 0;\n 0, 0, 0, 0, 0;\n 0, 0, 0, 0, 0;\n 0, 0, 0, 0, 0;\n 0, 0, 0, 0, 0]",
                 mat.inspect)
  end

  def test_ones
    mat_expr = Cv::Mat.ones(5, 5, CV_32F)
    mat = mat_expr.to_mat
    assert_equal(5, mat.rows)
    assert_equal(5, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(1, mat.channels)
    assert_equal("[1, 1, 1, 1, 1;\n 1, 1, 1, 1, 1;\n 1, 1, 1, 1, 1;\n 1, 1, 1, 1, 1;\n 1, 1, 1, 1, 1]",
                 mat.inspect)
  end

  def test_eye
    mat_expr = Cv::Mat.eye(5, 5, CV_32F)
    mat = mat_expr.to_mat
    assert_equal(5, mat.rows)
    assert_equal(5, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(1, mat.channels)
    assert_equal('<Cv::Mat:5x5,type=5,channel=1>', mat.to_s)
    assert_equal("[1, 0, 0, 0, 0;\n 0, 1, 0, 0, 0;\n 0, 0, 1, 0, 0;\n 0, 0, 0, 1, 0;\n 0, 0, 0, 0, 1]",
                 mat.inspect)
  end

  def test_addition
    mat_expr1 = Cv::Mat.eye(3, 2, CV_32F);
    mat_expr2 = Cv::Mat.ones(3, 2, CV_32F);
    mat_expr3 = mat_expr1 + mat_expr2
    mat = mat_expr3.to_mat
    assert_equal(3, mat.rows)
    assert_equal(2, mat.cols)
    assert_equal(CV_32F, mat.depth)
    assert_equal(1, mat.channels)

    expected = <<~EOS.chomp
      [2, 1;
       1, 2;
       1, 1]
    EOS
    assert_equal(expected, mat.inpsect)
  end

  def test_to_s
    mat = Cv::Mat.new
    assert_equal('<Cv::Mat:0x0,type=0,channel=1>', mat.to_s)
    mat = Cv::Mat.new(10, 20, CV_16S)
    assert_equal('<Cv::Mat:10x20,type=3,channel=1>', mat.to_s)
    mat = Cv::Mat.new(10, 20, CV_32F, 1)
    assert_equal('<OpenCV::Cv::Mat:20x10,type=cv32f,channel=1>', mat.to_s)
  end

  def test_inside
    mat = Cv::Mat.new(20, 10)
    assert(mat.inside? Cv::Point.new(0, 0))
    assert(mat.inside? Cv::Point.new(9, 19))
    assert((not mat.inside? Cv::Point.new(10, 0)))
    assert((not mat.inside? Cv::Point.new(0, 20)))
    assert((not mat.inside? Cv::Point.new(10, 20)))
  end

  def test_to_IplConvKernel
    kernel = Cv::Mat.new(10, 20).to_IplConvKernel(Cv::Point.new(2, 3))
    assert_equal(10, kernel.rows)
    assert_equal(20, kernel.cols)
    assert_equal(2, kernel.anchor.x)
    assert_equal(3, kernel.anchor.y)
    assert_equal(2, kernel.anchor_x)
    assert_equal(3, kernel.anchor_y)
  end

  def test_create_mask
    mask = Cv::Mat.new(10, 20).create_mask
    assert_equal(20, mask.width)
    assert_equal(10, mask.height)
    assert_equal(:cv8u, mask.depth)
    assert_equal(1, mask.channel)
  end

  def test_fields
    mat = Cv::Mat.new(20, 10)
    assert_equal(10, mat.width)
    assert_equal(10, mat.columns)
    assert_equal(10, mat.cols)
    assert_equal(20, mat.height)
    assert_equal(20, mat.rows)
    assert_equal(:cv8u, mat.depth)
    assert_equal(3, mat.channel)
    mat = Cv::Mat.new(20, 10, :cv16s, 1)
    assert_equal(10, mat.width)
    assert_equal(10, mat.columns)
    assert_equal(10, mat.cols)
    assert_equal(20, mat.height)
    assert_equal(20, mat.rows)
    assert_equal(:cv16s, mat.depth)
    assert_equal(1, mat.channel)
  end

  def test_clone
    m1 = create_cvmat(10, 20)
    m2 = m1.clone
    assert_equal(m1.data, m2.data)
  end

  def test_copy
    m1 = create_cvmat(10, 20, CV_32F, 1) { |j, i, c| Cv::Scalar.new(c) }
    m2 = m1.copy
    assert_equal(m1.data, m2.data)

    m2 = create_cvmat(10, 20, CV_32F, 1).zero
    m3 = m1.copy(m2)
    assert_equal(m1.data, m2.data)
    assert_equal(m1.data, m3.data)
    rows, cols = m1.rows, m1.cols
    mask = create_cvmat(rows, cols, CV_8U, 1) { |j, i, c|
      val = (i > cols / 2) ? 0 : 255
      Cv::Scalar.new(val)
    }
    m2_orig = m2.copy
    m3 = m1.copy(m2, mask)
    rows.times { |j|
      cols.times { |i|
        expected = (mask[j, i][0] == 0) ? m2_orig[j, i] : m1[j, i]
        assert_cvscalar_equal(expected, m2[j, i])
        assert_cvscalar_equal(expected, m3[j, i])
      }
    }

    assert_raise(TypeError) {
      m1.copy(DUMMY_OBJ)
    }
  end

  def test_convert_depth
    mat = Cv::Mat.new(10, 20, :cv32f)
    assert_equal(:cv8u, mat.to_8u.depth)
    assert_equal(:cv8s, mat.to_8s.depth)
    assert_equal(:cv16u, mat.to_16u.depth)
    assert_equal(:cv16s, mat.to_16s.depth)
    assert_equal(:cv32s, mat.to_32s.depth)
    assert_equal(:cv32f, mat.to_32f.depth)
    assert_equal(:cv64f, mat.to_64f.depth)
  end

  def test_vector
    mat = Cv::Mat.new(1, 2)
    assert(mat.vector?)
    mat = Cv::Mat.new(2, 2)
    assert((not mat.vector?))
  end

  # def test_square
  #   mat = Cv::Mat.new(2, 2)
  #   assert(mat.square?)
  #   mat = Cv::Mat.new(1, 2)
  #   assert((not mat.square?))
  # end
  #
  # def test_to_CvMat
  #   m1 = Cv::Mat.new(2, 3, :cv32f, 4)
  #   m2 = m1.to_CvMat
  #   assert_equal(Cv::Mat, m2.class)
  #   assert_equal(m1.rows, m2.rows)
  #   assert_equal(m1.cols, m2.cols)
  #   assert_equal(m1.depth, m2.depth)
  #   assert_equal(m1.channel, m2.channel)
  #   assert_equal(m1.data, m2.data)
  # end
  #
  # def test_sub_rect
  #   m1 = create_cvmat(10, 10)
  #   assert_raise(ArgumentError) {
  #     m1.sub_rect
  #   }
  #   m2 = m1.sub_rect(Cv::Rect.new(0, 0, 2, 3))
  #   assert_equal(2, m2.width)
  #   assert_equal(3, m2.height)
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       assert_cvscalar_equal(m1[j, i], m2[j, i])
  #     }
  #   }
  #
  #   topleft = Cv::Point.new(2, 3)
  #   m2 = m1.sub_rect(topleft, Cv::Size.new(4, 5))
  #   assert_equal(4, m2.width)
  #   assert_equal(5, m2.height)
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       assert_cvscalar_equal(m1[topleft.y + j, topleft.x + i], m2[j, i])
  #     }
  #   }
  #   topleft = Cv::Point.new(1, 2)
  #   m2 = m1.sub_rect(topleft.x, topleft.y, 3, 4)
  #   assert_equal(3, m2.width)
  #   assert_equal(4, m2.height)
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       assert_cvscalar_equal(m1[topleft.y + j, topleft.x + i], m2[j, i])
  #     }
  #   }
  #   # Alias
  #   m2 = m1.subrect(Cv::Rect.new(0, 0, 2, 3))
  #   assert_equal(2, m2.width)
  #   assert_equal(3, m2.height)
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       assert_cvscalar_equal(m1[j, i], m2[j, i])
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.sub_rect(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.sub_rect(DUMMY_OBJ, Cv::Size.new(1, 2))
  #   }
  #   assert_raise(TypeError) {
  #     m1.sub_rect(Cv::Point.new(1, 2), DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.sub_rect(DUMMY_OBJ, 2, 3, 4)
  #   }
  #   assert_raise(TypeError) {
  #     m1.sub_rect(1, DUMMY_OBJ, 3, 4)
  #   }
  #   assert_raise(TypeError) {
  #     m1.sub_rect(1, 2, DUMMY_OBJ, 4)
  #   }
  #   assert_raise(TypeError) {
  #     m1.sub_rect(1, 2, 3, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_get_rows
  #   m1 = create_cvmat(10, 20) { |j, i, c| Cv::Scalar.new(c) }
  #   row = 2
  #   m2 = m1.get_rows(row)
  #   assert_equal(1, m2.rows)
  #   assert_equal(m1.cols, m2.cols)
  #   m1.cols.times { |i|
  #     assert_cvscalar_equal(m1[row, i], m2[i])
  #   }
  #   row1 = 3..7
  #   row2 = 2...8
  #   [row1, row2].each { |row|
  #     m3 = m1.get_rows(row)
  #     w = (row.exclude_end?) ? row.last - row.begin : row.last - row.begin + 1
  #     assert_equal(w, m3.rows)
  #     assert_equal(m1.cols, m3.cols)
  #     m3.rows.times { |j|
  #       m3.cols.times { |i|
  #         assert_cvscalar_equal(m1[row.begin + j, i], m3[j, i])
  #       }
  #     }
  #   }
  #   [row1, row2].each { |row|
  #     delta = 2
  #     m3 = m1.get_rows(row, 2)
  #     w = (((row.exclude_end?) ? row.last - row.begin : row.last - row.begin + 1).to_f / delta).ceil
  #     assert_equal(w, m3.rows)
  #     assert_equal(m1.cols, m3.cols)
  #     m3.rows.times { |j|
  #       m3.cols.times { |i|
  #         assert_cvscalar_equal(m1[row.begin + j * delta, i], m3[j, i])
  #       }
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.get_rows(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.get_rows(1, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_get_cols
  #   m1 = create_cvmat(10, 20) { |j, i, c| Cv::Scalar.new(c) }
  #   col = 2
  #   m2 = m1.get_cols(col)
  #   assert_equal(m1.rows, m2.rows)
  #   assert_equal(1, m2.cols)
  #   m1.height.times { |j|
  #     assert_cvscalar_equal(m1[j, col], m2[j])
  #   }
  #   col1 = 3..7
  #   col2 = 2...8
  #   [col1, col2].each { |col|
  #     m3 = m1.get_cols(col)
  #     w = (col.exclude_end?) ? col.last - col.begin : col.last - col.begin + 1
  #     assert_equal(m1.rows, m3.rows)
  #     assert_equal(w, m3.cols)
  #     m3.rows.times { |j|
  #       m3.cols.times { |i|
  #         assert_cvscalar_equal(m1[j, col.begin + i], m3[j, i])
  #       }
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.get_cols(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_each_row
  #   m1 = create_cvmat(2, 3)
  #   a = [[1, 2, 3], [4, 5, 6]]
  #   a.map! { |a1|
  #     a1.map! { |a2|
  #       Cv::Scalar.new(a2, a2, a2, a2).to_ary
  #     }
  #   }
  #   j = 0
  #   m1.each_row { |r|
  #     a[j].size.times { |i|
  #       assert_cvscalar_equal(a[j][i], r[i])
  #     }
  #     j += 1
  #   }
  # end
  #
  # def test_each_col
  #   m1 = create_cvmat(2, 3)
  #   a = [[1, 4], [2, 5], [3, 6]]
  #   a.map! { |a1|
  #     a1.map! { |a2|
  #       Cv::Scalar.new(a2, a2, a2, a2).to_ary
  #     }
  #   }
  #   j = 0
  #   m1.each_col { |c|
  #     a[j].size.times { |i|
  #       assert_cvscalar_equal(a[j][i], c[i])
  #     }
  #     j += 1
  #   }
  #   # Alias
  #   j = 0
  #   m1.each_column { |c|
  #     a[j].size.times { |i|
  #       assert_cvscalar_equal(a[j][i], c[i])
  #     }
  #     j += 1
  #   }
  # end
  #
  # def test_diag
  #   mat = create_cvmat(5, 5)
  #   a = [1, 7, 13, 19, 25].map { |x| Cv::Scalar.new(x, x, x, x) }
  #   d = mat.diag
  #   a.each_with_index { |s, i|
  #     assert_cvscalar_equal(s, d[i])
  #   }
  #   a = [2, 8, 14, 20].map { |x| Cv::Scalar.new(x, x, x, x) }
  #   d = mat.diag(1)
  #   a.each_with_index { |s, i|
  #     assert_cvscalar_equal(s, d[i])
  #   }
  #   a = [6, 12, 18, 24].map { |x| Cv::Scalar.new(x, x, x, x) }
  #   d = mat.diag(-1)
  #   a.each_with_index { |s, i|
  #     assert_cvscalar_equal(s, d[i])
  #   }
  #   # Alias
  #   a = [1, 7, 13, 19, 25].map { |x| Cv::Scalar.new(x, x, x, x) }
  #   d = mat.diagonal
  #   a.each_with_index { |s, i|
  #     assert_cvscalar_equal(s, d[i])
  #   }
  #   [mat.rows, mat.cols, -mat.rows, -mat.cols].each { |d|
  #     assert_raise(Cv::StsOutOfRange) {
  #       mat.diag(d)
  #     }
  #   }
  # end
  #
  # def test_size
  #   mat = Cv::Mat.new(2, 3)
  #   assert_equal(3, mat.size.width)
  #   assert_equal(2, mat.size.height)
  # end
  #
  # def test_dims
  #   mat = Cv::Mat.new(2, 3)
  #   assert_equal([2, 3], mat.dims)
  # end
  #
  # def test_dim_size
  #   mat = Cv::Mat.new(2, 3)
  #   assert_equal(2, mat.dim_size(0))
  #   assert_equal(3, mat.dim_size(1))
  #   assert_raise(TypeError) {
  #     mat.dim_size(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_aref
  #   mat = create_cvmat(2, 3)
  #   assert_cvscalar_equal(Cv::Scalar.new(1, 1, 1, 1), mat[0])
  #   assert_cvscalar_equal(Cv::Scalar.new(5, 5, 5, 5), mat[4])
  #   assert_cvscalar_equal(Cv::Scalar.new(2, 2, 2, 2), mat[0, 1])
  #   assert_cvscalar_equal(Cv::Scalar.new(4, 4, 4, 4), mat[1, 0])
  #   assert_cvscalar_equal(Cv::Scalar.new(2, 2, 2, 2), mat[0, 1, 2])
  #   assert_cvscalar_equal(Cv::Scalar.new(4, 4, 4, 4), mat[1, 0, 3, 4])
  #   # Alias
  #   assert_cvscalar_equal(Cv::Scalar.new(1, 1, 1, 1), mat.at(0))
  #   assert_raise(TypeError) {
  #     mat[DUMMY_OBJ]
  #   }
  #
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[-1]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[6]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[2, 2]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[1, 3]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[2, 2, 1]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[1, 3, 1]
  #   }
  # end
  #
  # def test_aset
  #   mat = create_cvmat(2, 3)
  #   mat[0] = Cv::Scalar.new(10, 10, 10, 10)
  #   assert_cvscalar_equal(Cv::Scalar.new(10, 10, 10, 10), mat[0])
  #   mat[1, 0] = Cv::Scalar.new(20, 20, 20, 20)
  #   assert_cvscalar_equal(Cv::Scalar.new(20, 20, 20, 20), mat[1, 0])
  #   mat[1, 0, 2] = Cv::Scalar.new(4, 4, 4, 4)
  #   assert_cvscalar_equal(Cv::Scalar.new(4, 4, 4, 4), mat[1, 0])
  #   mat[1, 0, 2, 4] = Cv::Scalar.new(5, 5, 5, 5)
  #   assert_cvscalar_equal(Cv::Scalar.new(5, 5, 5, 5), mat[1, 0])
  #   assert_raise(TypeError) {
  #     mat[DUMMY_OBJ] = Cv::Scalar.new(10, 10, 10, 10)
  #   }
  #   assert_raise(TypeError) {
  #     mat[0] = DUMMY_OBJ
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[-1]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[6]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[2, 2]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[1, 3]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[2, 2, 1]
  #   }
  #   assert_raise(Cv::StsOutOfRange) {
  #     mat[1, 3, 1]
  #   }
  # end
  #
  # def test_set_data
  #   [CV_8U, CV_8S, CV_16U, CV_16S, CV_32S].each { |depth|
  #     a = [10, 20, 30, 40, 50, 60]
  #     mat = Cv::Mat.new(2, 3, depth, 1)
  #     mat.set_data(a)
  #     (mat.rows * mat.cols).times { |i|
  #       assert_equal(a[i], mat[i][0])
  #     }
  #   }
  #   [CV_32F, CV_64F].each { |depth|
  #     a = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6]
  #     mat = Cv::Mat.new(2, 3, depth, 1)
  #     mat.set_data(a)
  #     (mat.rows * mat.cols).times { |i|
  #       assert_in_delta(a[i], mat[i][0], 1.0e-5)
  #     }
  #   }
  #   a = [[10, 20, 30], [40, 50, 60]]
  #   mat = Cv::Mat.new(2, 3, CV_8U, 1)
  #   mat.set_data(a)
  #   (mat.rows * mat.cols).times { |i|
  #     assert_equal(a.flatten[i], mat[i][0])
  #   }
  #   [CV_8U, CV_8S, CV_16U, CV_16S, CV_32S, CV_32F, CV_64F].each { |depth|
  #     mat = Cv::Mat.new(2, 3, depth, 1)
  #     assert_raise(TypeError) {
  #       a = [DUMMY_OBJ] * 6
  #       mat.set_data(a)
  #     }
  #   }
  # end
  #
  # def test_fill
  #   m1 = create_cvmat(2, 3)
  #   m2 = m1.fill(Cv::Scalar.new(1, 2, 3, 4))
  #   m1.fill!(Cv::Scalar.new(1, 2, 3, 4))
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), m1[j, i])
  #       assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), m2[j, i])
  #     }
  #   }
  #   m1 = create_cvmat(5, 5)
  #   m0 = m1.clone
  #   mask = Cv::Mat.new(m1.height, m1.width, :cv8u, 1).clear
  #   2.times { |j|
  #     2.times { |i|
  #       mask[j, i] = Cv::Scalar.new(1, 1, 1, 1)
  #     }
  #   }
  #   m2 = m1.fill(Cv::Scalar.new(1, 2, 3, 4), mask)
  #   m1.fill!(Cv::Scalar.new(1, 2, 3, 4), mask)
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       if i < 2 and j < 2
  #         assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), m1[j, i])
  #         assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), m2[j, i])
  #       else
  #         assert_cvscalar_equal(m0[j, i], m1[j, i])
  #         assert_cvscalar_equal(m0[j, i], m2[j, i])
  #       end
  #     }
  #   }
  #
  #   # Alias
  #   m1 = create_cvmat(2, 3)
  #   m2 = m1.set(Cv::Scalar.new(1, 2, 3, 4))
  #   m1.set!(Cv::Scalar.new(1, 2, 3, 4))
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), m1[j, i])
  #       assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), m2[j, i])
  #     }
  #   }
  #   m1 = create_cvmat(5, 5)
  #   m0 = m1.clone
  #   mask = Cv::Mat.new(m1.height, m1.width, CV_8U, 1).clear
  #   2.times { |j|
  #     2.times { |i|
  #       mask[j, i] = Cv::Scalar.new(1, 1, 1, 1)
  #     }
  #   }
  #   m2 = m1.set(Cv::Scalar.new(1, 2, 3, 4), mask)
  #   m1.set!(Cv::Scalar.new(1, 2, 3, 4), mask)
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       if i < 2 and j < 2
  #         assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), m1[j, i])
  #         assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), m2[j, i])
  #       else
  #         assert_cvscalar_equal(m0[j, i], m1[j, i])
  #         assert_cvscalar_equal(m0[j, i], m2[j, i])
  #       end
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.fill(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.fill(Cv::Scalar.new(1), DUMMY_OBJ)
  #   }
  # end
  #
  # def test_clear
  #   m1 = create_cvmat(2, 3)
  #   m2 = m1.clear
  #   m1.clear!
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m1[j, i])
  #       assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m2[j, i])
  #     }
  #   }
  #   # Alias
  #   m1 = create_cvmat(2, 3)
  #   m2 = m1.set_zero
  #   m1.set_zero!
  #   m3 = create_cvmat(2, 3)
  #   m4 = m3.zero
  #   m3.zero!
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m1[j, i])
  #       assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m2[j, i])
  #       assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m3[j, i])
  #       assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m4[j, i])
  #     }
  #   }
  # end
  #
  # def test_identity
  #   m1 = create_cvmat(5, 5)
  #   m2 = m1.identity
  #   m1.identity!
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       if i == j
  #         assert_cvscalar_equal(Cv::Scalar.new(1, 0, 0, 0), m1[j, i])
  #         assert_cvscalar_equal(Cv::Scalar.new(1, 0, 0, 0), m2[j, i])
  #       else
  #         assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m1[j, i])
  #         assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m2[j, i])
  #       end
  #     }
  #   }
  #   m1 = Cv::Mat.new(5, 5, :cv8u, 4)
  #   s = Cv::Scalar.new(1, 2, 3, 4)
  #   m2 = m1.identity(s)
  #   m1.identity!(s)
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       if i == j
  #         assert_cvscalar_equal(s, m1[j, i])
  #         assert_cvscalar_equal(s, m2[j, i])
  #       else
  #         assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m1[j, i])
  #         assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m2[j, i])
  #       end
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.identity(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_range
  #   m1 = Cv::Mat.new(1, 10, CV_32S, 1)
  #   m2 = m1.range(0, m1.cols)
  #   m1.range!(0, m1.cols)
  #   m2.width.times { |i|
  #     assert_cvscalar_equal(Cv::Scalar.new(i, 0, 0, 0), m1[0, i])
  #     assert_cvscalar_equal(Cv::Scalar.new(i, 0, 0, 0), m2[0, i])
  #   }
  #   assert_raise(TypeError) {
  #     m1.range(DUMMY_OBJ, 2)
  #   }
  #   assert_raise(TypeError) {
  #     m1.range(1, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_reshape
  #   mat = create_cvmat(2, 3, CV_8U, 3)
  #   vec = mat.reshape(0, 1)
  #   assert_equal(6, vec.width)
  #   assert_equal(1, vec.height)
  #   size = mat.width * mat.height
  #   size.times { |i|
  #     assert_cvscalar_equal(mat[i], vec[i])
  #   }
  #   ch1 = mat.reshape(1)
  #   assert_equal(9, ch1.width)
  #   assert_equal(2, ch1.height)
  #   mat.height.times { |j|
  #     mat.width.times { |i|
  #       s1 = ch1[j, i * 3][0]
  #       s2 = ch1[j, i * 3 + 1][0]
  #       s3 = ch1[j, i * 3 + 2][0]
  #       assert_cvscalar_equal(mat[j, i], Cv::Scalar.new(s1, s2, s3, 0))
  #     }
  #   }
  #
  #   assert_raise(TypeError) {
  #     mat.reshape(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     mat.reshape(0, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_repeat
  #   m1 = create_cvmat(2, 3, :cv8u, 3)
  #   m2 = Cv::Mat.new(6, 9, :cv8u, 3)
  #   m2 = m1.repeat(m2)
  #   m2.height.times { |j|
  #     m2.width.times { |i|
  #       a = m1[j % m1.height, i % m1.width]
  #       assert_cvscalar_equal(m2[j, i], a)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.repeat(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_flip
  #   m0 = create_cvmat(2, 3)
  #   m1 = m0.clone
  #   m1.flip!(:x)
  #   m2 = m0.flip(:x)
  #   m3 = m0.clone
  #   m3.flip!(:y)
  #   m4 = m0.flip(:y)
  #   m5 = m0.clone
  #   m5.flip!(:xy)
  #   m6 = m0.flip(:xy)
  #   m7 = m0.clone
  #   m7.flip!
  #   m8 = m0.flip
  #
  #   [m1, m2, m3, m4, m5, m6, m7, m8].each { |mat|
  #     assert_equal(m0.height, mat.height)
  #     assert_equal(m0.width, mat.width)
  #   }
  #   m0.height.times { |j|
  #     m0.width.times { |i|
  #       ri = m0.width - i - 1
  #       rj = m0.height - j - 1
  #       assert_cvscalar_equal(m0[j, ri], m1[j, i])
  #       assert_cvscalar_equal(m0[j, ri], m2[j, i])
  #       assert_cvscalar_equal(m0[rj, i], m3[j, i])
  #       assert_cvscalar_equal(m0[rj, i], m4[j, i])
  #       assert_cvscalar_equal(m0[rj, ri], m5[j, i])
  #       assert_cvscalar_equal(m0[rj, ri], m6[j, i])
  #       assert_cvscalar_equal(m0[j, ri], m7[j, i])
  #       assert_cvscalar_equal(m0[j, ri], m8[j, i])
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m0.flip(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m0.flip!(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_split
  #   m0 = create_cvmat(2, 3, :cv8u, 3) { |j, i, c|
  #     Cv::Scalar.new(c * 10, c * 20, c * 30)
  #   }
  #   splitted = m0.split
  #   assert_equal(m0.channel, splitted.size)
  #   splitted.each_with_index { |mat, idx|
  #     assert_equal(Cv::Mat, mat.class)
  #     assert_equal(m0.height, mat.height)
  #     assert_equal(m0.width, mat.width)
  #     assert_equal(1, mat.channel)
  #     c = 0
  #     m0.height.times { |j|
  #       m0.width.times { |i|
  #         val = c * 10 * (idx + 1)
  #         assert_cvscalar_equal(Cv::Scalar.new(val), mat[j, i])
  #         c += 1
  #       }
  #     }
  #   }
  #   # IplImage#split should return Array<IplImage>
  #   image = create_iplimage(2, 3, :cv8u, 3) { |j, i, c|
  #     Cv::Scalar.new(c * 10, c * 20, c * 30)
  #   }
  #   splitted = image.split
  #   assert_equal(3, splitted.size)
  #   splitted.each_with_index { |img, channel|
  #     assert_equal(IplImage, img.class)
  #     assert_equal(image.height, img.height)
  #     assert_equal(image.width, img.width)
  #     assert_equal(1, img.channel)
  #     img.height.times { |j|
  #       img.width.times { |i|
  #         val = image[j, i][channel]
  #         assert_cvscalar_equal(Cv::Scalar.new(val), img[j, i])
  #       }
  #     }
  #   }
  # end
  #
  # def test_merge
  #   m0 = create_cvmat(2, 3, :cv8u, 4) { |j, i, c|
  #     Cv::Scalar.new(c * 10, c * 20, c * 30, c * 40)
  #   }
  #   m1 = create_cvmat(2, 3, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 10)
  #   }
  #   m2 = create_cvmat(2, 3, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 20)
  #   }
  #   m3 = create_cvmat(2, 3, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 30)
  #   }
  #   m4 = create_cvmat(2, 3, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 40)
  #   }
  #   mat = Cv::Mat.merge(m1, m2, m3, m4)
  #   assert_equal(m0.height, mat.height)
  #   assert_equal(m0.width, mat.width)
  #   m0.height.times { |j|
  #     m0.width.times { |i|
  #       assert_cvscalar_equal(m0[j, i], mat[j, i])
  #     }
  #   }
  #   m5 = create_cvmat(2, 3, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 50)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.merge(DUMMY_OBJ)
  #   }
  #   assert_raise(ArgumentError) {
  #     Cv::Mat.merge
  #   }
  #   assert_raise(ArgumentError) {
  #     Cv::Mat.merge(m1, m2, m3, m4, m5)
  #   }
  #   assert_raise(ArgumentError) {
  #     Cv::Mat.merge(Cv::Mat.new(1, 2, :cv8u, 2))
  #   }
  #   assert_raise(ArgumentError) {
  #     Cv::Mat.merge(Cv::Mat.new(1, 2, :cv8u, 1),
  #                 Cv::Mat.new(2, 2, :cv8u, 1))
  #   }
  #   assert_raise(ArgumentError) {
  #     Cv::Mat.merge(Cv::Mat.new(1, 2, :cv8u, 1),
  #                 Cv::Mat.new(1, 2, :cv32f, 1))
  #   }
  # end
  #
  # def test_rand_shuffle
  #   m0 = create_cvmat(2, 3)
  #   m1 = m0.clone
  #   m1.rand_shuffle!
  #   m2 = m0.rand_shuffle
  #   m3 = m0.clone
  #   m3.rand_shuffle!(123, 234)
  #   m4 = m0.rand_shuffle(123, 234)
  #
  #   assert_shuffled_equal = lambda { |src, shuffled|
  #     assert_equal(src.width, shuffled.width)
  #     assert_equal(src.height, shuffled.height)
  #     mat0, mat1 = [], []
  #     src.height { |j|
  #       src.width { |i|
  #         mat0 << src[j, i].to_s
  #         mat1 << shuffled[j, i].to_s
  #       }
  #     }
  #     assert_equal(0, (mat0 - mat1).size)
  #   }
  #   [m1, m2, m3, m4].each { |mat|
  #     assert_shuffled_equal.call(m0, mat)
  #   }
  #   assert_raise(TypeError) {
  #     m0.rand_shuffle(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m0.rand_shuffle(123, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_lut
  #   m0 = create_cvmat(2, 3, :cv8u, 3)
  #   lut_mat = create_cvmat(1, 256, :cv8u, 3) { |j, i, c|
  #     Cv::Scalar.new(255 - c, 255 - c, 255 - c)
  #   }
  #   mat = m0.lut(lut_mat)
  #   assert_equal(m0.height, mat.height)
  #   assert_equal(m0.width, mat.width)
  #   m0.height.times { |j|
  #     m0.width.times { |i|
  #       r, g, b = m0[j, i].to_ary.map { |c| 255 - c }
  #       assert_cvscalar_equal(Cv::Scalar.new(r, g, b, 0), mat[j, i])
  #     }
  #   }
  #
  #   assert_raise(TypeError) {
  #     m0.lut(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_convert_scale
  #   m0 = create_cvmat(2, 3, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(-c, -c, -c, -c)
  #   }
  #   m1 = m0.convert_scale(:depth => :cv8u)
  #   m2 = m0.convert_scale(:scale => 1.5)
  #   m3 = m0.convert_scale(:shift => 10.0)
  #   m4 = m0.convert_scale(:depth => CV_16U)
  #   [m1, m2, m3, m4].each { |mat|
  #     assert_equal(m0.height, mat.height)
  #     assert_equal(m0.width, mat.width)
  #   }
  #   m0.height.times { |j|
  #     m0.width.times { |i|
  #       assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m1[j, i])
  #       a = m0[j, i].to_ary.map { |x| x * 1.5 }
  #       assert_in_delta(a, m2[j, i], 0.001)
  #       a = m0[j, i].to_ary.map { |x| x + 10.0 }
  #       assert_in_delta(a, m3[j, i], 0.001)
  #       assert_cvscalar_equal(Cv::Scalar.new(0, 0, 0, 0), m4[j, i])
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m0.convert_scale(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_convert_scale_abs
  #   m0 = create_cvmat(2, 3, :cv8u, 4) { |j, i, c|
  #     Cv::Scalar.new(c, c, c, c)
  #   }
  #
  #   m1 = m0.convert_scale_abs(:depth => :cv64f)
  #   m2 = m0.convert_scale_abs(:scale => 2)
  #   m3 = m0.convert_scale_abs(:shift => 10.0)
  #   m4 = m0.convert_scale_abs(:depth => CV_64F)
  #   [m1, m2, m3, m4].each { |mat|
  #     assert_equal(m0.height, mat.height)
  #     assert_equal(m0.width, mat.width)
  #   }
  #   m0.height.times { |j|
  #     m0.width.times { |i|
  #       assert_cvscalar_equal(m0[j, i], m1[j, i])
  #       a = m0[j, i].to_ary.map { |x| (x * 2).abs }
  #       assert_in_delta(a, m2[j, i], 0.001)
  #       a = m0[j, i].to_ary.map { |x| (x + 10.0).abs }
  #       assert_in_delta(a, m3[j, i], 0.001)
  #       assert_cvscalar_equal(m0[j, i], m4[j, i])
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m0.convert_scale(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_add
  #   m1 = create_cvmat(6, 4, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(c * 0.1, c * 0.2, c * 0.3, c * 0.4)
  #   }
  #   m2 = create_cvmat(6, 4, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(c * 1, c * 2, c * 3, c * 4)
  #   }
  #   # Cv::Mat + Cv::Mat
  #   m3 = m1.add(m2)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       s = Cv::Scalar.new(n * 1.1, n * 2.2, n * 3.3, n * 4.4)
  #       assert_in_delta(s, m3[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   # Cv::Mat + Cv::Scalar
  #   s1 = Cv::Scalar.new(1, 2, 3, 4)
  #   m3 = m1.add(s1)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       s = Cv::Scalar.new(n * 0.1 + 1, n * 0.2 + 2, n * 0.3 + 3, n * 0.4 + 4)
  #       assert_in_delta(s, m3[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   # Alias
  #   m3 = m1 + m2
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       s = Cv::Scalar.new(n * 1.1, n * 2.2, n * 3.3, n * 4.4)
  #       assert_in_delta(s, m3[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   # Cv::Mat + Cv::Mat with Mask
  #   mask = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     (i < 3 and j < 2) ? 1 : 0
  #   }
  #   m4 = m1.add(m2, mask)
  #   assert_equal(m1.height, m4.height)
  #   assert_equal(m1.width, m4.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       if i < 3 and j < 2
  #         s = Cv::Scalar.new(n * 1.1, n * 2.2, n * 3.3, n * 4.4)
  #       else
  #         s = m1[j, i]
  #       end
  #       assert_in_delta(s, m4[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   # Cv::Mat + Cv::Scalar with Mask
  #   m4 = m1.add(s1, mask)
  #   assert_equal(m1.height, m4.height)
  #   assert_equal(m1.width, m4.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       if i < 3 and j < 2
  #         s = Cv::Scalar.new(n * 0.1 + 1, n * 0.2 + 2, n * 0.3 + 3, n * 0.4 + 4)
  #       else
  #         s = m1[j, i]
  #       end
  #       assert_in_delta(s, m4[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.add(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.add(Cv::Scalar.new(1), DUMMY_OBJ)
  #   }
  # end
  #
  # def test_sub
  #   m1 = create_cvmat(6, 4, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(c * 0.1, c * 0.2, c * 0.3, c * 0.4)
  #   }
  #   m2 = create_cvmat(6, 4, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(c * 1, c * 2, c * 3, c * 4)
  #   }
  #   # Cv::Mat - Cv::Mat
  #   m3 = m1.sub(m2)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       s = Cv::Scalar.new(-n * 0.9, -n * 1.8, -n * 2.7, -n * 3.6)
  #       assert_in_delta(s, m3[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   # Cv::Mat - Cv::Scalar
  #   s1 = Cv::Scalar.new(1, 2, 3, 4)
  #   m3 = m1.sub(s1)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       s = Cv::Scalar.new(n * 0.1 - 1, n * 0.2 - 2, n * 0.3 - 3, n * 0.4 - 4)
  #       assert_in_delta(s, m3[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   # Alias
  #   m3 = m1 - m2
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       s = Cv::Scalar.new(-n * 0.9, -n * 1.8, -n * 2.7, -n * 3.6)
  #       assert_in_delta(s, m3[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   mask = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     (i < 3 and j < 2) ? 1 : 0
  #   }
  #   # Cv::Mat - Cv::Mat with Mask
  #   m4 = m1.sub(m2, mask)
  #   assert_equal(m1.height, m4.height)
  #   assert_equal(m1.width, m4.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       if i < 3 and j < 2
  #         s = Cv::Scalar.new(-n * 0.9, -n * 1.8, -n * 2.7, -n * 3.6)
  #       else
  #         s = m1[j, i]
  #       end
  #       assert_in_delta(s, m4[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   # Cv::Mat - Cv::Scalar with Mask
  #   m4 = m1.sub(s1, mask)
  #   assert_equal(m1.height, m4.height)
  #   assert_equal(m1.width, m4.width)
  #   n = 0
  #   m1.height.times { |j|
  #     m1.width.times { |i|
  #       if i < 3 and j < 2
  #         s = Cv::Scalar.new(n * 0.1 - 1, n * 0.2 - 2, n * 0.3 - 3, n * 0.4 - 4)
  #       else
  #         s = m1[j, i]
  #       end
  #       assert_in_delta(s, m4[j, i], 0.001)
  #       n += 1
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.sub(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.sub(Cv::Scalar.new(1), DUMMY_OBJ)
  #   }
  # end
  #
  # def test_mul
  #   m1 = create_cvmat(3, 3, :cv32f)
  #   s1 = Cv::Scalar.new(0.1, 0.2, 0.3, 0.4)
  #   m2 = create_cvmat(3, 3, :cv32f) { s1 }
  #   # Cv::Mat * Cv::Mat
  #   m3 = m1.mul(m2)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3, 0.001) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n * 0.1, n * 0.2, n * 0.3, n * 0.4)
  #   }
  #
  #   # Cv::Mat * Cv::Mat * scale
  #   scale = 2.5
  #   m3 = m1.mul(m2, scale)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3, 0.001) { |j, i, c|
  #     n = (c + 1) * scale
  #     Cv::Scalar.new(n * 0.1, n * 0.2, n * 0.3, n * 0.4)
  #   }
  #   # Cv::Mat * Cv::Scalar
  #   scale = 2.5
  #   m3 = m1.mul(s1)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3, 0.001) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n * 0.1, n * 0.2, n * 0.3, n * 0.4)
  #   }
  #   # Cv::Mat * Cv::Scalar * scale
  #   m3 = m1.mul(s1, scale)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3, 0.001) { |j, i, c|
  #     n = (c + 1) * scale
  #     Cv::Scalar.new(n * 0.1, n * 0.2, n * 0.3, n * 0.4)
  #   }
  #   assert_raise(TypeError) {
  #     m1.mul(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.mul(m2, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_mat_mul
  #   m0 = create_cvmat(3, 3, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 0.1)
  #   }
  #   m1 = create_cvmat(3, 3, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c)
  #   }
  #   m2 = create_cvmat(3, 3, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c + 1)
  #   }
  #   m3 = m0.mat_mul(m1)
  #   m4 = m0 * m1
  #   [m3, m4].each { |mat|
  #     assert_equal(m1.width, mat.width)
  #     assert_equal(m1.height, mat.height)
  #     assert_in_delta(1.5, mat[0, 0][0], 0.001)
  #     assert_in_delta(1.8, mat[0, 1][0], 0.001)
  #     assert_in_delta(2.1, mat[0, 2][0], 0.001)
  #     assert_in_delta(4.2, mat[1, 0][0], 0.001)
  #     assert_in_delta(5.4, mat[1, 1][0], 0.001)
  #     assert_in_delta(6.6, mat[1, 2][0], 0.001)
  #     assert_in_delta(6.9, mat[2, 0][0], 0.001)
  #     assert_in_delta(9, mat[2, 1][0], 0.001)
  #     assert_in_delta(11.1, mat[2, 2][0], 0.001)
  #   }
  #   m5 = m0.mat_mul(m1, m2)
  #   [m5].each { |mat|
  #     assert_equal(m1.width, mat.width)
  #     assert_equal(m1.height, mat.height)
  #     assert_in_delta(2.5, mat[0, 0][0], 0.001)
  #     assert_in_delta(3.8, mat[0, 1][0], 0.001)
  #     assert_in_delta(5.1, mat[0, 2][0], 0.001)
  #     assert_in_delta(8.2, mat[1, 0][0], 0.001)
  #     assert_in_delta(10.4, mat[1, 1][0], 0.001)
  #     assert_in_delta(12.6, mat[1, 2][0], 0.001)
  #     assert_in_delta(13.9, mat[2, 0][0], 0.001)
  #     assert_in_delta(17, mat[2, 1][0], 0.001)
  #     assert_in_delta(20.1, mat[2, 2][0], 0.001)
  #   }
  #   assert_raise(TypeError) {
  #     m0.mat_mul(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m0.mat_mul(m1, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_div
  #   m1 = create_cvmat(3, 3, :cv32f)
  #   s1 = Cv::Scalar.new(0.1, 0.2, 0.3, 0.4)
  #   m2 = create_cvmat(3, 3, :cv32f) { s1 }
  #   # Cv::Mat / Cv::Mat
  #   m3 = m1.div(m2)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3, 0.001) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n / 0.1, n / 0.2, n / 0.3, n / 0.4)
  #   }
  #
  #   # scale * Cv::Mat / Cv::Mat
  #   scale = 2.5
  #   m3 = m1.div(m2, scale)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3, 0.001) { |j, i, c|
  #     n = (c + 1) * scale
  #     Cv::Scalar.new(n / 0.1, n / 0.2, n / 0.3, n / 0.4)
  #   }
  #   # Cv::Mat / Cv::Scalar
  #   scale = 2.5
  #   m3 = m1.div(s1)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3, 0.001) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n / 0.1, n / 0.2, n / 0.3, n / 0.4)
  #   }
  #   # scale * Cv::Mat / Cv::Scalar
  #   m3 = m1.div(s1, scale)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3, 0.001) { |j, i, c|
  #     n = (c + 1) * scale
  #     Cv::Scalar.new(n / 0.1, n / 0.2, n / 0.3, n / 0.4)
  #   }
  #   # Alias
  #   m3 = m1 / m2
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3, 0.001) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n / 0.1, n / 0.2, n / 0.3, n / 0.4)
  #   }
  #   assert_raise(TypeError) {
  #     m1.div(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.div(m2, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_add_weighted
  #   m1 = create_cvmat(3, 2, :cv8u) { |j, i, c| c + 1 }
  #   m2 = create_cvmat(3, 2, :cv8u) { |j, i, c| (c + 1) * 10 }
  #   a = 2.0
  #   b = 0.1
  #   g = 100
  #   m3 = Cv::Mat.add_weighted(m1, a, m2, b, g)
  #   assert_equal(m1.class, m3.class)
  #   assert_equal(m1.rows, m3.rows)
  #   assert_equal(m1.cols, m3.cols)
  #   assert_equal(m1.depth, m3.depth)
  #   assert_equal(m1.channel, m3.channel)
  #   m1.rows.times { |j|
  #     m1.cols.times { |i|
  #       expected = m1[j, i][0] * a + m2[j, i][0] * b + g
  #       assert_equal(expected, m3[j, i][0])
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.add_weighted(DUMMY_OBJ, a, m2, b, g)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.add_weighted(m1, DUMMY_OBJ, m2, b, g)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.add_weighted(m1, a, DUMMY_OBJ, b, g)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.add_weighted(m1, a, m2, DUMMY_OBJ, g)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.add_weighted(m1, a, m2, b, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_and
  #   m1 = create_cvmat(6, 4)
  #   s1 = Cv::Scalar.new(1, 2, 3, 4)
  #   m2 = create_cvmat(6, 4) { s1 }
  #   mask = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     s = (i < 3 and j < 2) ? 1 : 0
  #     Cv::Scalar.new(s)
  #   }
  #   # Cv::Mat & Cv::Mat
  #   m3 = m1.and(m2)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n & 1, n & 2, n & 3, n & 4)
  #   }
  #   # Cv::Mat & Cv::Mat with mask
  #   m3 = m1.and(m2, mask)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     if i < 3 and j < 2
  #       Cv::Scalar.new(n & 1, n & 2, n & 3, n & 4)
  #     else
  #       Cv::Scalar.new(n, n, n, n)
  #     end
  #   }
  #
  #   # Cv::Mat & Cv::Scalar
  #   m3 = m1.and(s1)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n & 1, n & 2, n & 3, n & 4)
  #   }
  #   # Cv::Mat & Cv::Scalar with mask
  #   m3 = m1.and(s1, mask)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     if i < 3 and j < 2
  #       Cv::Scalar.new(n & 1, n & 2, n & 3, n & 4)
  #     else
  #       Cv::Scalar.new(n, n, n, n)
  #     end
  #   }
  #   # Alias
  #   m3 = m1 & m2
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n & 1, n & 2, n & 3, n & 4)
  #   }
  #   m3 = m1 & s1
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n & 1, n & 2, n & 3, n & 4)
  #   }
  #   assert_raise(TypeError) {
  #     m1.and(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.and(m2, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_or
  #   m1 = create_cvmat(6, 4)
  #   s1 = Cv::Scalar.new(1, 2, 3, 4)
  #   m2 = create_cvmat(6, 4) { s1 }
  #   mask = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     s = (i < 3 and j < 2) ? 1 : 0
  #     Cv::Scalar.new(s)
  #   }
  #
  #   # Cv::Mat | Cv::Mat
  #   m3 = m1.or(m2)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n | 1, n | 2, n | 3, n | 4)
  #   }
  #   # Cv::Mat | Cv::Mat with mask
  #   m3 = m1.or(m2, mask)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     if i < 3 and j < 2
  #       Cv::Scalar.new(n | 1, n | 2, n | 3, n | 4)
  #     else
  #       Cv::Scalar.new(n, n, n, n)
  #     end
  #   }
  #
  #   # Cv::Mat | Cv::Scalar
  #   m3 = m1.or(s1)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n | 1, n | 2, n | 3, n | 4)
  #   }
  #   # Cv::Mat | Cv::Scalar with mask
  #   m3 = m1.or(s1, mask)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     if i < 3 and j < 2
  #       Cv::Scalar.new(n | 1, n | 2, n | 3, n | 4)
  #     else
  #       Cv::Scalar.new(n, n, n, n)
  #     end
  #   }
  #   # Alias
  #   m3 = m1 | m2
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n | 1, n | 2, n | 3, n | 4)
  #   }
  #   m3 = m1 | s1
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n | 1, n | 2, n | 3, n | 4)
  #   }
  #   assert_raise(TypeError) {
  #     m1.or(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.or(m2, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_xor
  #   m1 = create_cvmat(6, 4)
  #   s1 = Cv::Scalar.new(1, 2, 3, 4)
  #   m2 = create_cvmat(6, 4) { s1 }
  #   mask = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     s = (i < 3 and j < 2) ? 1 : 0
  #     Cv::Scalar.new(s)
  #   }
  #
  #   # Cv::Mat ^ Cv::Mat
  #   m3 = m1.xor(m2)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
  #   }
  #   # Cv::Mat ^ Cv::Mat with mask
  #   m3 = m1.xor(m2, mask)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     if i < 3 and j < 2
  #       Cv::Scalar.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
  #     else
  #       Cv::Scalar.new(n, n, n, n)
  #     end
  #   }
  #
  #   # Cv::Mat ^ Cv::Scalar
  #   m3 = m1.xor(s1)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
  #   }
  #   # Cv::Mat ^ Cv::Scalar with mask
  #   m3 = m1.xor(s1, mask)
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     if i < 3 and j < 2
  #       Cv::Scalar.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
  #     else
  #       Cv::Scalar.new(n, n, n, n)
  #     end
  #   }
  #   # Alias
  #   m3 = m1 ^ m2
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
  #   }
  #   m3 = m1 ^ s1
  #   assert_equal(m1.height, m3.height)
  #   assert_equal(m1.width, m3.width)
  #   assert_each_cvscalar(m3) { |j, i, c|
  #     n = c + 1
  #     Cv::Scalar.new(n ^ 1, n ^ 2, n ^ 3, n ^ 4)
  #   }
  #   assert_raise(TypeError) {
  #     m1.xor(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m1.xor(m2, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_not
  #   m1 = create_cvmat(6, 4, :cv8s)
  #   m2 = m1.not;
  #   m3 = m1.clone
  #   m3.not!
  #   [m2, m3].each { |mat|
  #     assert_equal(m1.height, mat.height)
  #     assert_equal(m1.width, mat.width)
  #     assert_each_cvscalar(mat) { |j, i, c|
  #       n = c + 1
  #       Cv::Scalar.new(~n, ~n, ~n, ~n)
  #     }
  #   }
  # end
  #
  # def test_eq
  #   m1 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     n = (c.even?) ? 10 : c
  #     Cv::Scalar.new(n, 0, 0, 0)
  #   }
  #   m2 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(10, 0, 0, 0)
  #   }
  #   s1 = Cv::Scalar.new(10, 0, 0, 0)
  #   m3 = m1.eq(m2)
  #   m4 = m1.eq(s1)
  #   m5 = m1.eq(10)
  #   [m3, m4, m5].each { |mat|
  #     assert_equal(m1.height, mat.height)
  #     assert_equal(m1.width, mat.width)
  #     assert_each_cvscalar(mat) { |j, i, c|
  #       n = (c.even?) ? 0xff : 0
  #       Cv::Scalar.new(n, 0, 0, 0)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.eq(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_gt
  #   m1 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c, 0, 0, 0)
  #   }
  #   m2 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(10, 0, 0, 0)
  #   }
  #   s1 = Cv::Scalar.new(10, 0, 0, 0)
  #   m3 = m1.gt(m2)
  #   m4 = m1.gt(s1)
  #   m5 = m1.gt(10)
  #   [m3, m4, m5].each { |mat|
  #     assert_equal(m1.height, mat.height)
  #     assert_equal(m1.width, mat.width)
  #     assert_each_cvscalar(mat) { |j, i, c|
  #       n = (c > 10) ? 0xff : 0
  #       Cv::Scalar.new(n, 0, 0, 0)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.gt(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_ge
  #   m1 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c, 0, 0, 0)
  #   }
  #   m2 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(10, 0, 0, 0)
  #   }
  #   s1 = Cv::Scalar.new(10, 0, 0, 0)
  #   m3 = m1.ge(m2)
  #   m4 = m1.ge(s1)
  #   m5 = m1.ge(10)
  #   [m3, m4, m5].each { |mat|
  #     assert_equal(m1.height, mat.height)
  #     assert_equal(m1.width, mat.width)
  #     assert_each_cvscalar(mat) { |j, i, c|
  #       n = (c >= 10) ? 0xff : 0
  #       Cv::Scalar.new(n, 0, 0, 0)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.ge(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_lt
  #   m1 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c, 0, 0, 0)
  #   }
  #   m2 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(10, 0, 0, 0)
  #   }
  #   s1 = Cv::Scalar.new(10, 0, 0, 0)
  #   m3 = m1.lt(m2)
  #   m4 = m1.lt(s1)
  #   m5 = m1.lt(10)
  #   [m3, m4, m5].each { |mat|
  #     assert_equal(m1.height, mat.height)
  #     assert_equal(m1.width, mat.width)
  #     assert_each_cvscalar(mat) { |j, i, c|
  #       n = (c < 10) ? 0xff : 0
  #       Cv::Scalar.new(n, 0, 0, 0)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.lt(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_le
  #   m1 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c, 0, 0, 0)
  #   }
  #   m2 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(10, 0, 0, 0)
  #   }
  #   s1 = Cv::Scalar.new(10, 0, 0, 0)
  #   m3 = m1.le(m2)
  #   m4 = m1.le(s1)
  #   m5 = m1.le(10)
  #   [m3, m4, m5].each { |mat|
  #     assert_equal(m1.height, mat.height)
  #     assert_equal(m1.width, mat.width)
  #     assert_each_cvscalar(mat) { |j, i, c|
  #       n = (c <= 10) ? 0xff : 0
  #       Cv::Scalar.new(n, 0, 0, 0)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m1.le(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_in_range
  #   lower, upper = 10, 20
  #   m0 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(c + 5, 0, 0, 0)
  #   }
  #   m1 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(lower, 0, 0, 0)
  #   }
  #   m2 = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     Cv::Scalar.new(upper, 0, 0, 0)
  #   }
  #   s1 = Cv::Scalar.new(lower, 0, 0, 0)
  #   s2 = Cv::Scalar.new(upper, 0, 0, 0)
  #   m3 = m0.in_range(m1, m2)
  #   m4 = m0.in_range(s1, s2)
  #   m5 = m0.in_range(lower, upper)
  #   [m3, m4, m5].each { |mat|
  #     assert_equal(m0.height, mat.height)
  #     assert_equal(m0.width, mat.width)
  #     assert_each_cvscalar(mat) { |j, i, c|
  #       val = m0[j, i][0]
  #       n = ((lower..upper).include? val) ? 0xff : 0
  #       Cv::Scalar.new(n, 0, 0, 0)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m0.in_range(DUMMY_OBJ, m2)
  #   }
  #   assert_raise(TypeError) {
  #     m0.in_range(m1, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_abs_diff
  #   m0 = create_cvmat(6, 4, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(-10 + 10.5, 20 + 10.5, -30 + 10.5, 40 - 10.5)
  #   }
  #   m1 = create_cvmat(6, 4, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(c + 10.5, c - 10.5, c + 10.5, c - 10.5)
  #   }
  #   m2 = create_cvmat(6, 4, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(c, c, c, c)
  #   }
  #   s1 = Cv::Scalar.new(-10, 20, -30, 40)
  #   m3 = m1.abs_diff(m2)
  #   m4 = m0.abs_diff(s1)
  #   [m3, m4].each { |mat|
  #     assert_equal(m1.width, mat.width)
  #     assert_equal(m1.height, mat.height)
  #     assert_each_cvscalar(mat, 0.001) {
  #       Cv::Scalar.new(10.5, 10.5, 10.5, 10.5)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m0.abs_diff(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_normalize
  #   mat = create_cvmat(2, 2, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c, 0, 0, 0)
  #   }
  #   mat = mat.normalize
  #   expected = [0.0, 0.267, 0.534, 0.801]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, mat[i][0], 0.001)
  #   }
  #   minf = mat.normalize(1, 0, CV_NORM_INF)
  #   expected = [0.0, 0.333, 0.666, 1.0]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, minf[i][0], 0.001)
  #   }
  #   ml1 = mat.normalize(1, 0, CV_NORM_L1)
  #   expected = [0.0, 0.166, 0.333, 0.5]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, ml1[i][0], 0.001)
  #   }
  #   ml2 = mat.normalize(1, 0, CV_NORM_L2)
  #   expected = [0.0, 0.267, 0.534, 0.801]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, ml2[i][0], 0.001)
  #   }
  #   mminmax = mat.normalize(10, 5, CV_NORM_MINMAX)
  #   expected = [5.0, 6.666, 8.333, 10.0]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, mminmax[i][0], 0.001)
  #   }
  #   minf = mat.normalize(1, 0, CV_NORM_INF, CV_32FC3)
  #   expected = [0.0, 0.333, 0.666, 1.0]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, minf[i][0], 0.001)
  #   }
  #   mask = mat.to_8u.zero
  #   mask[0, 0] = Cv::Scalar.new(255, 0, 0)
  #   mask[1, 0] = Cv::Scalar.new(255, 0, 0)
  #   minf = mat.normalize(1, 0, CV_NORM_INF, -1, mask)
  #   expected = [0.0, 0.0, 1.0, 0.0]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, minf[i][0], 0.001)
  #   }
  #   assert_raise(TypeError) {
  #     mat.normalize(DUMMY_OBJ, 0, CV_NORM_INF)
  #   }
  #   assert_raise(TypeError) {
  #     mat.normalize(1, DUMMY_OBJ, CV_NORM_INF)
  #   }
  #   assert_raise(TypeError) {
  #     mat.normalize(1, 0, DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     mat.normalize(1, 0, CV_NORM_INF, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_count_non_zero
  #   m0 = create_cvmat(6, 4, :cv32f, 1) { |j, i, c|
  #     n = 0
  #     n = 1 if i == 0
  #     Cv::Scalar.new(n, 0, 0, 0)
  #   }
  #   assert_equal(6, m0.count_non_zero)
  # end
  #
  # def test_sum
  #   m0 = create_cvmat(6, 4, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c, c, c, c)
  #   }
  #   assert_cvscalar_equal(Cv::Scalar.new(276, 0, 0, 0), m0.sum)
  #   m0 = create_cvmat(6, 4, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(-c)
  #   }
  #   assert_cvscalar_equal(Cv::Scalar.new(-276, 0, 0, 0), m0.sum)
  # end
  #
  # def test_avg_sdv
  #   m0 = create_cvmat(6, 4, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(c * 0.1, -c * 0.1, c, -c)
  #   }
  #   # Cv::Mat#avg
  #   assert_in_delta(Cv::Scalar.new(1.15, -1.15, 11.5, -11.5), m0.avg, 0.001)
  #   # Cv::Mat#sdv
  #   assert_in_delta(Cv::Scalar.new(0.69221, 0.69221, 6.9221, 6.9221), m0.sdv, 0.001)
  #   # Cv::Mat#avg_sdv
  #   avg, sdv = m0.avg_sdv
  #   assert_in_delta(Cv::Scalar.new(1.15, -1.15, 11.5, -11.5), avg, 0.001)
  #   assert_in_delta(Cv::Scalar.new(0.69221, 0.69221, 6.9221, 6.9221), sdv, 0.001)
  #   mask = create_cvmat(6, 4, :cv8u, 1) { |j, i, c|
  #     n = (i == j) ? 1 : 0
  #     Cv::Scalar.new(n)
  #   }
  #   # Cv::Mat#avg
  #   assert_in_delta(Cv::Scalar.new(0.75, -0.75, 7.5, -7.5), m0.avg(mask), 0.001)
  #   # Cv::Mat#sdv
  #   assert_in_delta(Cv::Scalar.new(0.55901, 0.55901, 5.5901, 5.5901), m0.sdv(mask), 0.001)
  #   # Cv::Mat#avg_sdv
  #   avg, sdv = m0.avg_sdv(mask)
  #   assert_in_delta(Cv::Scalar.new(0.75, -0.75, 7.5, -7.5), avg, 0.001)
  #   assert_in_delta(Cv::Scalar.new(0.55901, 0.55901, 5.5901, 5.5901), sdv, 0.001)
  #   assert_raise(TypeError) {
  #     m0.avg(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m0.sdv(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m0.avg_sdv(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_min_max_loc
  #   m0 = create_cvmat(6, 4, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 0.5)
  #   }
  #   m0[2, 3] = Cv::Scalar.new(100.5) # Max
  #   m0[5, 1] = Cv::Scalar.new(-100.5) # Min
  #   min_val, max_val, min_loc, max_loc = m0.min_max_loc
  #   assert_equal(-100.5, min_val)
  #   assert_equal(5, min_loc.y)
  #   assert_equal(1, min_loc.x)
  #   assert_equal(100.5, max_val)
  #   assert_equal(2, max_loc.y)
  #   assert_equal(3, max_loc.x)
  #   assert_raise(TypeError) {
  #     m0.min_max_loc(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_norm
  #   src1 = Cv::Mat.new(3, 3, :cv32f, 1).set_data([1, 2, 3, 4, 5, 6, 7, 8, 9])
  #   src2 = Cv::Mat.new(3, 3, :cv32f, 1).set_data([2, 3, 4, 5, 6, 7, 8, 9, 1])
  #   mask = Cv::Mat.new(3, 3, :cv8u, 1).set_data([1, 1, 0, 1, 1, 0, 0, 0, 0])
  #   assert_in_delta(Cv::Mat.norm(src1), 16.88, 0.01)
  #   assert_in_delta(Cv::Mat.norm(src1, nil, CV_NORM_L1), 45.0, 0.01)
  #   assert_in_delta(Cv::Mat.norm(src1, nil, CV_NORM_L2), 16.88, 0.01)
  #   assert_in_delta(Cv::Mat.norm(src1, nil, CV_NORM_INF), 9.0, 0.01)
  #   assert_in_delta(Cv::Mat.norm(src1, src2, CV_NORM_L1), 16.0, 0.01)
  #   assert_in_delta(Cv::Mat.norm(src1, src2, CV_NORM_L2), 8.49, 0.01)
  #   assert_in_delta(Cv::Mat.norm(src1, src2, CV_NORM_INF), 8.0, 0.01)
  #   assert_in_delta(Cv::Mat.norm(src1, src2, CV_NORM_L1, mask), 4.0, 0.01)
  #   assert_in_delta(Cv::Mat.norm(src1, src2, CV_NORM_L2, mask), 2.0, 0.01)
  #   assert_in_delta(Cv::Mat.norm(src1, src2, CV_NORM_INF, mask), 1.0, 0.01)
  #   assert_raise(TypeError) {
  #     Cv::Mat.norm(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.norm(src1, DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.norm(src1, src2, DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.norm(src1, src2, CV_NORM_L1, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_dot_product
  #   m1 = create_cvmat(2, 2, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 0.5)
  #   }
  #   m2 = create_cvmat(2, 2, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 1.5)
  #   }
  #   assert_in_delta(10.5, m1.dot_product(m2), 0.001)
  #   m1 = create_cvmat(2, 2, :cv32f) { |j, i, c|
  #     Cv::Scalar.new(c * 0.5, c * 0.6, c * 0.7, c * 0.8)
  #   }
  #   m2 = create_cvmat(2, 2, :cv32f) { |j, i, c|
  #     Cv::Scalar.new(c * 1.5, c * 2.0, c * 2.5, c * 3.0)
  #   }
  #   assert_in_delta(85.39999, m1.dot_product(m2), 0.001)
  #   assert_raise(TypeError) {
  #     m1.dot_product(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_cross_product
  #   m1 = create_cvmat(1, 3, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c * 0.5)
  #   }
  #   m2 = create_cvmat(1, 3, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c + 1)
  #   }
  #   m3 = m1.cross_product(m2)
  #   assert_in_delta(Cv::Scalar.new(-0.5), m3[0, 0], 0.001)
  #   assert_in_delta(Cv::Scalar.new(1), m3[0, 1], 0.001)
  #   assert_in_delta(Cv::Scalar.new(-0.5), m3[0, 2], 0.001)
  #   assert_raise(TypeError) {
  #     m1.cross_product(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_transform
  #   m0 = create_cvmat(5, 5, :cv32f, 3) { |j, i, c|
  #     Cv::Scalar.new(c * 0.5, c * 1.0, c * 1.5)
  #   }
  #   transmat = Cv::Mat.new(3, 3, :cv32f, 1);
  #   transmat[0, 0] = Cv::Scalar.new(0.0)
  #   transmat[1, 0] = Cv::Scalar.new(0.0)
  #   transmat[2, 0] = Cv::Scalar.new(0.0)
  #   transmat[0, 1] = Cv::Scalar.new(0.0)
  #   transmat[1, 1] = Cv::Scalar.new(0.0)
  #   transmat[2, 1] = Cv::Scalar.new(1.0)
  #   transmat[0, 2] = Cv::Scalar.new(1.0)
  #   transmat[1, 2] = Cv::Scalar.new(0.0)
  #   transmat[2, 2] = Cv::Scalar.new(0.0)
  #   m1 = m0.transform(transmat)
  #   assert_each_cvscalar(m1, 0.01) { |j, i, c|
  #     Cv::Scalar.new(c * 1.5, 0, c, 0)
  #   }
  #   stf = Cv::Mat.new(3, 1, :cv32f, 1)
  #   stf[0, 0] = Cv::Scalar.new(-10)
  #   stf[1, 0] = Cv::Scalar.new(0.0)
  #   stf[2, 0] = Cv::Scalar.new(5)
  #   m1 = m0.transform(transmat, stf)
  #   assert_each_cvscalar(m1, 0.01) { |j, i, c|
  #     Cv::Scalar.new(c * 1.5 - 10, 0, c + 5, 0)
  #   }
  #   assert_raise(TypeError) {
  #     m0.transform(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m0.transform(transmat, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_perspective_transform
  #   mat = Cv::Mat.new(1, 1, :cv32f, 2)
  #   mat[0] = Cv::Scalar.new(2, 3)
  #   transmat = Cv::Mat.new(3, 3, :cv32f, 1).clear
  #   mat.channel.times { |c|
  #     transmat[c, c] = Cv::Scalar.new(1.0)
  #   }
  #   transmat[2, 2] = Cv::Scalar.new(0.5)
  #   mat = mat.perspective_transform(transmat)
  #   assert_equal(1, mat.height)
  #   assert_equal(1, mat.width)
  #   assert_equal(:cv32f, mat.depth)
  #   assert_equal(2, mat.channel)
  #   assert_in_delta(Cv::Scalar.new(4, 6), mat[0], 0.001);
  #   mat = Cv::Mat.new(1, 1, :cv32f, 3)
  #   mat[0] = Cv::Scalar.new(2, 3, 4)
  #   transmat = Cv::Mat.new(4, 4, :cv32f, 1).clear
  #   mat.channel.times { |c|
  #     transmat[c, c] = Cv::Scalar.new(1.0)
  #   }
  #   transmat[3, 3] = Cv::Scalar.new(0.5)
  #   mat = mat.perspective_transform(transmat)
  #   assert_equal(1, mat.height)
  #   assert_equal(1, mat.width)
  #   assert_equal(:cv32f, mat.depth)
  #   assert_equal(3, mat.channel)
  #   assert_in_delta(Cv::Scalar.new(4, 6, 8), mat[0], 0.001);
  #   assert_raise(TypeError) {
  #     mat.perspective_transform(DUMMY_OBJ)
  #   }
  #   assert_raise(Cv::StsAssert) {
  #     mat.perspective_transform(Cv::Mat.new(3, 3, :cv32f, 3))
  #   }
  # end
  #
  # def test_mul_transposed
  #   mat0 = create_cvmat(2, 2, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new((c + 1) * 2)
  #   }
  #   delta = create_cvmat(2, 2, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c + 1)
  #   }
  #   [mat0.mul_transposed,
  #    mat0.mul_transposed(:delta => nil),
  #    mat0.mul_transposed(:order => 0),
  #    mat0.mul_transposed(:scale => 1.0)].each { |mat|
  #     expected = [20, 44,
  #                 44, 100]
  #     assert_equal(2, mat.rows)
  #     assert_equal(2, mat.cols)
  #     assert_equal(:cv32f, mat.depth)
  #     expected.each_with_index { |x, i|
  #       assert_in_delta(x, mat[i][0], 0.1)
  #     }
  #   }
  #   mat = mat0.mul_transposed(:delta => delta)
  #   expected = [5, 11,
  #               11, 25]
  #   assert_equal(2, mat.rows)
  #   assert_equal(2, mat.cols)
  #   assert_equal(:cv32f, mat.depth)
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, mat[i][0], 0.1)
  #   }
  #   mat = mat0.mul_transposed(:delta => delta, :order => 1, :scale => 2.0)
  #   expected = [20, 28,
  #               28, 40]
  #   assert_equal(2, mat.rows)
  #   assert_equal(2, mat.cols)
  #   assert_equal(:cv32f, mat.depth)
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, mat[i][0], 0.1)
  #   }
  # end
  #
  # def test_trace
  #   m0 = create_cvmat(5, 5, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(c * 0.5, c * 1.0, c * 1.5, c * 2.0)
  #   }
  #   assert_in_delta(Cv::Scalar.new(30, 60, 90, 120), m0.trace, 0.001)
  # end
  #
  # def test_transpose
  #   m0 = create_cvmat(2, 3, :cv32f, 4) { |j, i, c|
  #     Cv::Scalar.new(c * 0.5, c * 1.0, c * 1.5, c * 2.0)
  #   }
  #   m1 = m0.transpose
  #   m2 = m0.t
  #   [m1, m2].each { |mat|
  #     assert_equal(m0.rows, mat.cols)
  #     assert_equal(m0.cols, mat.rows)
  #     assert_each_cvscalar(mat, 0.001) { |j, i, c|
  #       m0[i, j]
  #     }
  #   }
  # end
  #
  # def test_det
  #   elems = [2.5, 4.5, 2.0,
  #            3.0, 2.5, -0.5,
  #            1.0, 0.5, 1.5]
  #   m0 = create_cvmat(3, 3, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(elems[c])
  #   }
  #   assert_in_delta(-14.5, m0.det, 0.001)
  # end
  #
  # def test_invert
  #   elems = [1, 2, 3,
  #            2, 6, 9,
  #            1, 4, 7]
  #   m0 = create_cvmat(3, 3, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(elems[c])
  #   }
  #   m1 = m0.invert
  #   m2 = m0.invert(:lu)
  #   m3 = m0.invert(:svd)
  #   m4 = m0.invert(:svd_sym)
  #   m5 = m0.invert(:svd_symmetric)
  #   expected = [3, -1, 0, -2.5, 2, -1.5, 1, -1, 1]
  #   [m1, m2, m3].each { |mat|
  #     assert_equal(m0.width, mat.width)
  #     assert_equal(m0.height, mat.height)
  #     assert_each_cvscalar(mat, 0.001) { |j, i, c|
  #       Cv::Scalar.new(expected[c])
  #     }
  #   }
  #   expected = [3, -1, 0, -1.0, 0.15, 0.23, 0, 0.23, -0.15]
  #   [m4, m5].each { |mat|
  #     assert_equal(m0.width, mat.width)
  #     assert_equal(m0.height, mat.height)
  #     assert_each_cvscalar(mat, 0.1) { |j, i, c|
  #       Cv::Scalar.new(expected[c])
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     m0.invert(DUMMY_OBJ)
  #   }
  # end
  #
  # def test_solve
  #   elems1 = [3, 4, 5,
  #             8, 9, 6,
  #             3, 5, 9]
  #   elems2 = [3,
  #             4,
  #             5]
  #   a = create_cvmat(3, 3, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(elems1[c])
  #   }
  #   b = create_cvmat(3, 1, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(elems2[c])
  #   }
  #   m1 = Cv::Mat.solve(a, b)
  #   m2 = Cv::Mat.solve(a, b, :lu)
  #   m3 = Cv::Mat.solve(a, b, :svd)
  #   m4 = Cv::Mat.solve(a, b, :svd_sym)
  #   m5 = Cv::Mat.solve(a, b, :svd_symmetric)
  #   expected = [2, -2, 1]
  #   [m1, m2, m3].each { |mat|
  #     assert_equal(b.width, mat.width)
  #     assert_equal(a.height, mat.height)
  #     assert_each_cvscalar(mat, 0.001) { |j, i, c|
  #       Cv::Scalar.new(expected[c])
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.solve(DUMMY_OBJ, b)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.solve(a, DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.solve(a, b, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_svd
  #   rows = 2
  #   cols = 3
  #   m0 = create_cvmat(rows, cols, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(c + 1)
  #   }
  #   [m0.svd, m0.clone.svd(CV_SVD_MODIFY_A)].each { |w, u, v|
  #     expected = [0.38632, -0.92237,
  #                 0.92237, 0.38632]
  #     assert_equal(rows, u.rows)
  #     assert_equal(rows, u.cols)
  #     expected.each_with_index { |x, i|
  #       assert_in_delta(x, u[i][0], 0.0001)
  #     }
  #     assert_equal(rows, w.rows)
  #     assert_equal(cols, w.cols)
  #     expected = [9.50803, 0, 0,
  #                 0, 0.77287, 0]
  #     expected.each_with_index { |x, i|
  #       assert_in_delta(x, w[i][0], 0.0001)
  #     }
  #     assert_equal(cols, v.rows)
  #     assert_equal(rows, v.cols)
  #     expected = [0.42867, 0.80596,
  #                 0.56631, 0.11238,
  #                 0.70395, -0.58120]
  #
  #     expected.each_with_index { |x, i|
  #       assert_in_delta(x, v[i][0], 0.0001)
  #     }
  #   }
  #   w, ut, v = m0.svd(CV_SVD_U_T)
  #   expected = [0.38632, 0.92237,
  #               -0.92237, 0.38632]
  #   assert_equal(rows, ut.rows)
  #   assert_equal(rows, ut.cols)
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, ut[i][0], 0.0001)
  #   }
  #   assert_equal(rows, w.rows)
  #   assert_equal(cols, w.cols)
  #   expected = [9.50803, 0, 0,
  #               0, 0.77287, 0]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, w[i][0], 0.0001)
  #   }
  #   assert_equal(cols, v.rows)
  #   assert_equal(rows, v.cols)
  #   expected = [0.42867, 0.80596,
  #               0.56631, 0.11238,
  #               0.70395, -0.58120]
  #
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, v[i][0], 0.0001)
  #   }
  #   w, u, vt = m0.svd(CV_SVD_V_T)
  #   expected = [0.38632, -0.92237,
  #               0.92237, 0.38632]
  #   assert_equal(rows, u.rows)
  #   assert_equal(rows, u.cols)
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, u[i][0], 0.0001)
  #   }
  #   assert_equal(rows, w.rows)
  #   assert_equal(cols, w.cols)
  #   expected = [9.50803, 0, 0,
  #               0, 0.77287, 0]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, w[i][0], 0.0001)
  #   }
  #   assert_equal(rows, vt.rows)
  #   assert_equal(cols, vt.cols)
  #   expected = [0.42867, 0.56631, 0.70395,
  #               0.80596, 0.11238, -0.58120]
  #   expected.each_with_index { |x, i|
  #     assert_in_delta(x, vt[i][0], 0.0001)
  #   }
  # end
  #
  # def test_eigenvv
  #   elems = [6, -2, -3, 7]
  #   m0 = create_cvmat(2, 2, :cv32f, 1) { |j, i, c|
  #     Cv::Scalar.new(elems[c])
  #   }
  #   v1 = m0.eigenvv
  #   v2 = m0.eigenvv(10 ** -15)
  #   v3 = m0.eigenvv(10 ** -15, 1, 1)
  #   [v1, v2].each { |vec, val|
  #     assert_in_delta(-0.615, vec[0, 0][0], 0.01)
  #     assert_in_delta(0.788, vec[0, 1][0], 0.01)
  #     assert_in_delta(0.788, vec[1, 0][0], 0.01)
  #     assert_in_delta(0.615, vec[1, 1][0], 0.01)
  #     assert_in_delta(8.562, val[0][0], 0.01)
  #     assert_in_delta(4.438, val[1][0], 0.01)
  #   }
  #   vec3, val3 = v3
  #   assert_in_delta(-0.615, vec3[0, 0][0], 0.01)
  #   assert_in_delta(0.788, vec3[0, 1][0], 0.01)
  #   assert_in_delta(8.562, val3[0][0], 0.01)
  #   assert_raise(TypeError) {
  #     m0.eigenvv(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m0.eigenvv(nil, DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     m0.eigenvv(nil, nil, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_find_homography
  #   # Nx2
  #   src = Cv::Mat.new(4, 2, :cv32f, 1)
  #   dst = Cv::Mat.new(4, 2, :cv32f, 1)
  #   # Nx3 (Homogeneous coordinates)
  #   src2 = Cv::Mat.new(4, 3, :cv32f, 1)
  #   dst2 = Cv::Mat.new(4, 3, :cv32f, 1)
  #
  #   # Homography
  #   #   <src>     =>    <dst>
  #   # (0, 0)      =>  (50, 0)
  #   # (255, 0)    =>  (205, 0)
  #   # (255, 255)  =>  (255, 220)
  #   # (0, 255)    =>  (0, 275)
  #   [[0, 0], [255, 0], [255, 255], [0, 255]].each_with_index { |coord, i|
  #     src[i, 0] = coord[0]
  #     src[i, 1] = coord[1]
  #     src2[i, 0] = coord[0] * 2
  #     src2[i, 1] = coord[1] * 2
  #     src2[i, 2] = 2
  #   }
  #   [[50, 0], [205, 0], [255, 220], [0, 275]].each_with_index { |coord, i|
  #     dst[i, 0] = coord[0]
  #     dst[i, 1] = coord[1]
  #     dst2[i, 0] = coord[0] * 2
  #     dst2[i, 1] = coord[1] * 2
  #     dst2[i, 2] = 2
  #   }
  #   mat1 = Cv::Mat.find_homography(src, dst)
  #   mat2 = Cv::Mat.find_homography(src, dst, :all)
  #   mat3 = Cv::Mat.find_homography(src, dst, :ransac)
  #   mat4 = Cv::Mat.find_homography(src, dst, :lmeds)
  #   mat5, status5 = Cv::Mat.find_homography(src, dst, :ransac, 5, true)
  #   mat6, status6 = Cv::Mat.find_homography(src, dst, :ransac, 5, true)
  #   mat7 = Cv::Mat.find_homography(src, dst, :ransac, 5, false)
  #   mat8 = Cv::Mat.find_homography(src, dst, :ransac, 5, nil)
  #   mat9 = Cv::Mat.find_homography(src, dst, :all, 5, true)
  #   mat10, status10 = Cv::Mat.find_homography(src2, dst2, :ransac, 5, true)
  #   [mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8, mat9, mat10].each { |mat|
  #     assert_equal(3, mat.rows)
  #     assert_equal(3, mat.cols)
  #     assert_equal(:cv32f, mat.depth)
  #     assert_equal(1, mat.channel)
  #     [0.72430, -0.19608, 50.0,
  #      0.0, 0.62489, 0.0,
  #      0.00057, -0.00165, 1.0].each_with_index { |x, i|
  #       assert_in_delta(x, mat[i][0], 0.0001)
  #     }
  #   }
  #
  #   [status5, status6, status10].each { |status|
  #     assert_equal(1, status.rows)
  #     assert_equal(4, status.cols)
  #     assert_equal(:cv8u, status.depth)
  #     assert_equal(1, status.channel)
  #     4.times { |i|
  #       assert_in_delta(1.0, status[i][0], 0.0001)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.find_homography(DUMMY_OBJ, dst, :ransac, 5, true)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.find_homography(src, DUMMY_OBJ, :ransac, 5, true)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.find_homography(src, dst, DUMMY_OBJ, 5, true)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.find_homography(src, dst, :ransac, DUMMY_OBJ, true)
  #   }
  #   Cv::Mat.find_homography(src, dst, :ransac, 5, DUMMY_OBJ)
  # end
  #
  # def test_find_fundamental_mat
  #   points1 = [[488.362, 169.911],
  #              [449.488, 174.44],
  #              [408.565, 179.669],
  #              [364.512, 184.56],
  #              [491.483, 122.366],
  #              [451.512, 126.56],
  #              [409.502, 130.342],
  #              [365.5, 134.0],
  #              [494.335, 74.544],
  #              [453.5, 76.5],
  #              [411.646, 79.5901],
  #              [366.498, 81.6577],
  #              [453.5, 76.5],
  #              [411.646, 79.5901],
  #              [366.498, 81.6577]]
  #
  #   points2 =  [[526.605, 213.332],
  #               [470.485, 207.632],
  #               [417.5, 201.0],
  #               [367.485, 195.632],
  #               [530.673, 156.417],
  #               [473.749, 151.39],
  #               [419.503, 146.656],
  #               [368.669, 142.565],
  #               [534.632, 97.5152],
  #               [475.84, 94.6777],
  #               [421.16, 90.3223],
  #               [368.5, 87.5],
  #               [475.84, 94.6777],
  #               [421.16, 90.3223],
  #               [368.5, 87.5]]
  #   # 7 point
  #   num_points = 7
  #   mat1 = Cv::Mat.new(num_points, 2, :cv64f, 1)
  #   mat2 = Cv::Mat.new(num_points, 2, :cv64f, 1)
  #   points1[0...num_points].each_with_index { |pt, i|
  #     mat1[i, 0] = Cv::Scalar.new(pt[0])
  #     mat1[i, 1] = Cv::Scalar.new(pt[1])
  #   }
  #   points2[0...num_points].each_with_index { |pt, i|
  #     mat2[i, 0] = Cv::Scalar.new(pt[0])
  #     mat2[i, 1] = Cv::Scalar.new(pt[1])
  #   }
  #   f_mat1 = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_7POINT)
  #   f_mat2, status = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_7POINT, :with_status => true)
  #   expected = [0.000009, 0.000029, -0.010343,
  #               -0.000033, 0.000000, 0.014590,
  #               0.004415, -0.013420, 1.000000,
  #               0.000000, 0.000001, -0.000223,
  #               -0.000001, 0.000036, -0.005309,
  #               -0.000097, -0.006463, 1.000000,
  #               0.000002, 0.000005, -0.001621,
  #               -0.000005, 0.000031, -0.002559,
  #               0.000527, -0.007424, 1.000000]
  #   [f_mat1, f_mat2].each { |f_mat|
  #     assert_equal(9, f_mat.rows)
  #     assert_equal(3, f_mat.cols)
  #     expected.each_with_index { |val, i|
  #       assert_in_delta(val, f_mat[i][0], 1.0e-5)
  #     }
  #   }
  #   assert_equal(num_points, status.cols)
  #   num_points.times { |i|
  #     assert_in_delta(1, status[i][0], 1.0e-5)
  #   }
  #   # 8 point
  #   num_points = 8
  #   mat1 = Cv::Mat.new(num_points, 2, :cv64f, 1)
  #   mat2 = Cv::Mat.new(num_points, 2, :cv64f, 1)
  #   points1[0...num_points].each_with_index { |pt, i|
  #     mat1[i, 0] = Cv::Scalar.new(pt[0])
  #     mat1[i, 1] = Cv::Scalar.new(pt[1])
  #   }
  #   points2[0...num_points].each_with_index { |pt, i|
  #     mat2[i, 0] = Cv::Scalar.new(pt[0])
  #     mat2[i, 1] = Cv::Scalar.new(pt[1])
  #   }
  #   f_mat1 = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_8POINT)
  #   f_mat2, status = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_8POINT, :with_status => true)
  #   expected = [0.000001, 0.000004, -0.001127,
  #               -0.000005, 0.000038, -0.003778,
  #               0.000819, -0.008325, 1.000000]
  #   [f_mat1, f_mat2].each { |f_mat|
  #     assert_equal(3, f_mat.rows)
  #     assert_equal(3, f_mat.cols)
  #     expected.each_with_index { |val, i|
  #       assert_in_delta(val, f_mat[i][0], 1.0e-5)
  #     }
  #   }
  #   assert_equal(num_points, status.cols)
  #   num_points.times { |i|
  #     assert_in_delta(1, status[i][0], 1.0e-5)
  #   }
  #   # RANSAC default
  #   num_points = points1.size
  #   mat1 = Cv::Mat.new(num_points, 2, :cv64f, 1)
  #   mat2 = Cv::Mat.new(num_points, 2, :cv64f, 1)
  #   points1[0...num_points].each_with_index { |pt, i|
  #     mat1[i, 0] = Cv::Scalar.new(pt[0])
  #     mat1[i, 1] = Cv::Scalar.new(pt[1])
  #   }
  #   points2[0...num_points].each_with_index { |pt, i|
  #     mat2[i, 0] = Cv::Scalar.new(pt[0])
  #     mat2[i, 1] = Cv::Scalar.new(pt[1])
  #   }
  #   [Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_RANSAC, :with_status => false,
  #                               :maximum_distance => 1.0, :desirable_level => 0.99),
  #    Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_RANSAC)].each { |f_mat|
  #     assert_equal(3, f_mat.rows)
  #     assert_equal(3, f_mat.cols)
  #     expected = [0.000010, 0.000039, -0.011141,
  #                 -0.000045, -0.000001, 0.019631,
  #                 0.004873, -0.017604, 1.000000]
  #     expected.each_with_index { |val, i|
  #       assert_in_delta(val, f_mat[i][0], 1.0e-5)
  #     }
  #   }
  #
  #   # RANSAC with options
  #   f_mat, status = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_RANSAC, :with_status => true,
  #                                              :maximum_distance => 2.0, :desirable_level => 0.8)
  #   assert_equal(3, f_mat.rows)
  #   assert_equal(3, f_mat.cols)
  #   assert_equal(1, status.rows)
  #   assert_equal(num_points, status.cols)
  #   expected_f_mat = [0.000009, 0.000030, -0.010692,
  #                     -0.000039, 0.000000, 0.020567,
  #                     0.004779, -0.018064, 1.000000]
  #   expected_f_mat.each_with_index { |val, i|
  #     assert_in_delta(val, f_mat[i][0], 1.0e-5)
  #   }
  #   expected_status = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
  #   expected_status.each_with_index { |val, i|
  #     assert_in_delta(val, status[i][0], 1.0e-5)
  #   }
  #   # LMedS default
  #   num_points = 12
  #   mat1 = Cv::Mat.new(num_points, 2, :cv64f, 1)
  #   mat2 = Cv::Mat.new(num_points, 2, :cv64f, 1)
  #   points1[0...num_points].each_with_index { |pt, i|
  #     mat1[i, 0] = Cv::Scalar.new(pt[0])
  #     mat1[i, 1] = Cv::Scalar.new(pt[1])
  #   }
  #   points2[0...num_points].each_with_index { |pt, i|
  #     mat2[i, 0] = Cv::Scalar.new(pt[0])
  #     mat2[i, 1] = Cv::Scalar.new(pt[1])
  #   }
  #   [Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_LMEDS, :with_status => false,
  #                               :maximum_distance => 1.0, :desirable_level => 0.99),
  #    Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_LMEDS)].each { |f_mat|
  #     assert_equal(3, f_mat.rows)
  #     assert_equal(3, f_mat.cols)
  #     expected = [0.0, 0.0, 0.0,
  #                 0.0, 0.0, 0.0,
  #                 0.0, 0.0, 1.0]
  #     expected.each_with_index { |val, i|
  #       assert_in_delta(val, f_mat[i][0], 0.1)
  #     }
  #   }
  #
  #   # LMedS with options
  #   f_mat, status = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_LMEDS, :with_status => true,
  #                                              :desirable_level => 0.8)
  #   assert_equal(3, f_mat.rows)
  #   assert_equal(3, f_mat.cols)
  #   assert_equal(1, status.rows)
  #   assert_equal(num_points, status.cols)
  #   expected_fmat = [0.0, 0.0, 0.0,
  #                    0.0, 0.0, 0.0,
  #                    0.0, 0.0, 1.0]
  #   expected_f_mat.each_with_index { |val, i|
  #     assert_in_delta(val, f_mat[i][0], 0.1)
  #   }
  #   expected_status = [0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1]
  #   expected_status.each_with_index { |val, i|
  #     assert_equal(val, status[i][0].to_i)
  #   }
  #   [CV_FM_7POINT, CV_FM_8POINT, CV_FM_RANSAC, CV_FM_LMEDS].each { |method|
  #     assert_raise(TypeError) {
  #       Cv::Mat.find_fundamental_mat(DUMMY_OBJ, mat2, method, :with_status => true)
  #     }
  #     assert_raise(TypeError) {
  #       Cv::Mat.find_fundamental_mat(mat1, DUMMY_OBJ, method, :with_status => true)
  #     }
  #     assert_raise(TypeError) {
  #       Cv::Mat.find_fundamental_mat(mat1, mat2, method, DUMMY_OBJ)
  #     }
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.find_fundamental_mat(mat1, mat2, DUMMY_OBJ, :with_status => true)
  #   }
  # end
  #
  # def test_compute_correspond_epilines
  #   test_func = lambda { |mat1, mat2, f_mat_arr, num_points|
  #     f_mat = Cv::Mat.new(3, 3, CV_64F, 1)
  #     f_mat_arr.each_with_index { |a, i|
  #       f_mat[i] = Cv::Scalar.new(a)
  #     }
  #
  #     line = Cv::Mat.compute_correspond_epilines(mat1, 1, f_mat)
  #     assert_equal(num_points, line.rows)
  #     assert_equal(3, line.cols)
  #
  #     expected = [[-0.221257, -0.975215, 6.03758],
  #                 [0.359337, -0.933208, -3.61419],
  #                 [0.958304, -0.28575, -15.0573],
  #                 [0.73415, -0.678987, -10.4037],
  #                 [0.0208539, -0.999783, 2.11625],
  #                 [0.284451, -0.958691, -2.31993],
  #                 [0.624647, -0.780907, -8.35208],
  #                 [0.618494, -0.785789, -8.23888],
  #                 [0.766694, -0.642012, -11.0298],
  #                 [0.700293, -0.713855, -9.76109]]
  #
  #     expected.size.times { |i|
  #       assert_in_delta(expected[i][0], line[i, 0][0], 1.0e-3)
  #       assert_in_delta(expected[i][1], line[i, 1][0], 1.0e-3)
  #       assert_in_delta(expected[i][2], line[i, 2][0], 1.0e-3)
  #     }
  #     assert_raise(ArgumentError) {
  #       mat = Cv::Mat.new(10, 10, CV_32F, 1)
  #       Cv::Mat.compute_correspond_epilines(mat, 1, f_mat)
  #     }
  #   }
  #   num_points = 10
  #   # input points are Nx2 matrix
  #   points1 =[[17, 175],
  #             [370, 24],
  #             [192, 456],
  #             [614, 202],
  #             [116, 111],
  #             [305, 32],
  #             [249, 268],
  #             [464, 157],
  #             [259, 333],
  #             [460, 224]]
  #   points2 = [[295, 28],
  #              [584, 221],
  #              [67, 172],
  #              [400, 443],
  #              [330, 9],
  #              [480, 140],
  #              [181, 140],
  #              [350, 265],
  #              [176, 193],
  #              [333, 313]]
  #   mat1 = Cv::Mat.new(num_points, 2, CV_64F, 1)
  #   mat2 = Cv::Mat.new(num_points, 2, CV_64F, 1)
  #   points1.flatten.each_with_index { |pt, i|
  #     mat1[i] = Cv::Scalar.new(pt)
  #   }
  #   points2.flatten.each_with_index { |pt, i|
  #     mat2[i] = Cv::Scalar.new(pt)
  #   }
  #   # pre computed f matrix from points1, points2
  #   # f_mat = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_LMEDS)
  #   f_mat_arr = [0.000266883, 0.000140277, -0.0445223,
  #                -0.00012592, 0.000245543, -0.108868,
  #                -0.00407942, -0.00291097, 1]
  #   test_func.call(mat1, mat2, f_mat_arr, num_points)
  #   # input points are 2xN matrix
  #   points1 = [[17, 370, 192, 614, 116, 305, 249, 464, 259, 460],
  #              [175, 24, 456, 202, 111, 32, 268, 157, 333, 224]]
  #   points2 = [[295, 584, 67, 400, 330, 480, 181, 350, 176, 333],
  #              [28, 221, 172, 443, 9, 140, 140, 265, 193, 313]]
  #   mat1 = Cv::Mat.new(2, num_points, CV_64F, 1)
  #   mat2 = Cv::Mat.new(2, num_points, CV_64F, 1)
  #   points1.flatten.each_with_index { |pt, i|
  #     mat1[i] = Cv::Scalar.new(pt)
  #   }
  #   points2.flatten.each_with_index { |pt, i|
  #     mat2[i] = Cv::Scalar.new(pt)
  #   }
  #   test_func.call(mat1, mat2, f_mat_arr, num_points)
  #
  #   f_mat = Cv::Mat.new(3, 3, CV_64F, 1)
  #   f_mat_arr.each_with_index { |a, i|
  #     f_mat[i] = Cv::Scalar.new(a)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.compute_correspond_epilines(DUMMY_OBJ, 1, f_mat)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.compute_correspond_epilines(mat1, DUMMY_OBJ, f_mat)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.compute_correspond_epilines(mat1, 1, DUMMY_OBJ)
  #   }
  # end
  #
  # def test_apply_color_map
  #   mat = Cv::Mat.new(64, 256, :cv8u, 1)
  #   mat.cols.times { |c|
  #     mat.rows.times { |r|
  #       mat[r, c] = c
  #     }
  #   }
  #   results = []
  #   [COLORMAP_AUTUMN, COLORMAP_BONE, COLORMAP_JET, COLORMAP_WINTER,
  #    COLORMAP_RAINBOW, COLORMAP_OCEAN, COLORMAP_SUMMER, COLORMAP_SPRING,
  #    COLORMAP_COOL, COLORMAP_HSV, COLORMAP_PINK, COLORMAP_HOT].each { |colormap|
  #     cmap = mat.apply_color_map(colormap)
  #     assert_equal(Cv::Mat, cmap.class)
  #     assert_equal(mat.rows, cmap.rows)
  #     assert_equal(mat.cols, cmap.cols)
  #     results << cmap
  #   }
  #   assert_raise(TypeError) {
  #     mat.apply_color_map(DUMMY_OBJ)
  #   }
  #   # Uncomment the following line to show the result
  #   # snap *results
  # end
  #
  # def test_subspace_project
  #   w = Cv::Mat.new(10, 20, :cv32f, 1)
  #   mean = Cv::Mat.new(w.rows, 1, :cv32f, 1)
  #   mat = Cv::Mat.new(w.cols, w.rows, :cv32f, 1)
  #   result = mat.subspace_project(w, mean)
  #   assert_equal(Cv::Mat, result.class)
  #   assert_equal(w.cols, result.rows)
  #   assert_equal(w.cols, result.cols)
  # end
  #
  # def test_subspace_reconstruct
  #   w = Cv::Mat.new(10, 20, :cv32f, 1)
  #   mean = Cv::Mat.new(w.rows, 1, :cv32f, 1)
  #   mat = Cv::Mat.new(w.cols, w.cols, :cv32f, 1)
  #   result = mat.subspace_reconstruct(w, mean)
  #   assert_equal(Cv::Mat, result.class)
  #   assert_equal(w.cols, result.rows)
  #   assert_equal(w.rows, result.cols)
  # end
end
