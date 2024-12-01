module Cv
	class Mat
		def type_to_string
			case self.type
				when CV_8UC1
				  "CV_8UC1"
				when CV_8UC2
				  "CV_8UC2"
				when CV_8UC3
				  "CV_8UC3"
				when CV_8UC4
				  "CV_8UC4"
				when CV_8SC1
				  "CV_8SC1"
				when CV_8SC2
				  "CV_8SC2"
				when CV_8SC3
				  "CV_8SC3"
				when CV_8SC4
				  "CV_8SC4"
				when CV_16UC1
				  "CV_16UC1"
				when CV_16UC2
				  "CV_16UC2"
				when CV_16UC3
				  "CV_16UC3"
				when CV_16UC4
				  "CV_16UC4"
				when CV_16SC1
				  "CV_16SC1"
				when CV_16SC2
				  "CV_16SC2"
				when CV_16SC3
				  "CV_16SC3"
				when CV_16SC4
				  "CV_16SC4"
				when CV_32SC1
				  "CV_32SC1"
				when CV_32SC2
				  "CV_32SC2"
				when CV_32SC3
				  "CV_32SC3"
				when CV_32SC4
				  "CV_32SC4"
				when CV_32FC1
				  "CV_32FC1"
				when CV_32FC2
				  "CV_32FC2"
				when CV_32FC3
				  "CV_32FC3"
				when CV_32FC4
				  "CV_32FC4"
				when CV_64FC1
				  "CV_64FC1"
				when CV_64FC2
				  "CV_64FC2"
				when CV_64FC3
				  "CV_64FC3"
				when CV_64FC4
				  "CV_64FC4"
				when CV_16FC1
				  "CV_16FC1"
				when CV_16FC2
				  "CV_16FC2"
				when CV_16FC3
				  "CV_16FC3"
				when CV_16FC4
				  "CV_16FC4"
				else
					raise("Uknown type: #{self.type}")
			end
		end

		def mat_klass
			case self.type
				when CV_8UC1
					Cv::Mat1b
				when CV_8UC2
					Cv::Mat2b
				when CV_8UC3
					Cv::Mat3b
				when CV_8UC4
					Cv::Mat4b
				when CV_8SC1
					raise("CV_8SC1 has not corresponding Mat_ class")
				when CV_8SC2
					raise("CV_8SC2 has not corresponding Mat_ class")
				when CV_8SC3
					raise("CV_8SC3 has not corresponding Mat_ class")
				when CV_8SC4
					raise("CV_8SC4 has not corresponding Mat_ class")
				when CV_16UC1
					Cv::Mat1w
				when CV_16UC2
					Cv::Mat2w
				when CV_16UC3
					Cv::Mat3w
				when CV_16UC4
					Cv::Mat4w
				when CV_16SC1
					Cv::Mat1s
				when CV_16SC2
					Cv::Mat2s
				when CV_16SC3
					Cv::Mat3s
				when CV_16SC4
					Cv::Mat4s
				when CV_32SC1
					Cv::Mat1i
				when CV_32SC2
					Cv::Mat2i
				when CV_32SC3
					Cv::Mat3i
				when CV_32SC4
					Cv::Mat4i
				when CV_32FC1
					Cv::Mat1f
				when CV_32FC2
					Cv::Mat2f
				when CV_32FC3
					Cv::Mat3f
				when CV_32FC4
					Cv::Mat4f
				when CV_64FC1
					Cv::Mat1d
				when CV_64FC2
					Cv::Mat2d
				when CV_64FC3
					Cv::Mat3d
				when CV_64FC4
					Cv::Mat4d
				when CV_16FC1
					raise("CV_16FC1 has not corresponding Mat_ class")
				when CV_16FC2
					raise("CV_16FC2 has not corresponding Mat_ class")
				when CV_16FC3
					raise("CV_16FC3 has not corresponding Mat_ class")
				when CV_16FC4
					raise("CV_16FC4 has not corresponding Mat_ class")
				else
					raise("Uknown type: #{self.type}")
			end
		end

		def vec_klass
			case self.type
				when CV_8UC1
					Cv::Vec1b
				when CV_8UC2
					Cv::Vec2b
				when CV_8UC3
					Cv::Vec3b
				when CV_8UC4
					Cv::Vec4b
				when CV_8SC1
					raise("CV_8SC1 has not corresponding Mat_ class")
				when CV_8SC2
					raise("CV_8SC2 has not corresponding Mat_ class")
				when CV_8SC3
					raise("CV_8SC3 has not corresponding Mat_ class")
				when CV_8SC4
					raise("CV_8SC4 has not corresponding Mat_ class")
				when CV_16UC1
					Cv::Vec1w
				when CV_16UC2
					Cv::Vec2w
				when CV_16UC3
					Cv::Vec3w
				when CV_16UC4
					Cv::Vec4w
				when CV_16SC1
					Cv::Vec1s
				when CV_16SC2
					Cv::Vec2s
				when CV_16SC3
					Cv::Vec3s
				when CV_16SC4
					Cv::Vec4s
				when CV_32SC1
					Cv::Vec1i
				when CV_32SC2
					Cv::Vec2i
				when CV_32SC3
					Cv::Vec3i
				when CV_32SC4
					Cv::Vec4i
				when CV_32FC1
					Cv::Vec1f
				when CV_32FC2
					Cv::Vec2f
				when CV_32FC3
					Cv::Vec3f
				when CV_32FC4
					Cv::Vec4f
				when CV_64FC1
					Cv::Vec1d
				when CV_64FC2
					Cv::Vec2d
				when CV_64FC3
					Cv::Vec3d
				when CV_64FC4
					Cv::Vec4d
				when CV_16FC1
					raise("CV_16FC1 has not corresponding Mat_ class")
				when CV_16FC2
					raise("CV_16FC2 has not corresponding Mat_ class")
				when CV_16FC3
					raise("CV_16FC3 has not corresponding Mat_ class")
				when CV_16FC4
					raise("CV_16FC4 has not corresponding Mat_ class")
				else
					raise("Uknown type: #{self.type}")
			end
		end

		def compare(other, operation)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::compare(self.input_array, other.input_array, dest.output_array, operation)
			dest
		end

		def eq(other)
			compare(other, Cv::CmpTypes::CMP_EQ)
		end

		def gt(other)
			compare(other, Cv::CmpTypes::CMP_GT)
		end

		def ge(other)
			compare(other, Cv::CmpTypes::CMP_GE)
		end

		def lt(other)
			compare(other, Cv::CmpTypes::CMP_LT)
		end

		def le(other)
			compare(other, Cv::CmpTypes::CMP_LE)
		end

		def ne(other)
			compare(other, Cv::CmpTypes::CMP_NE)
		end

		def bitwise_and(other, mask = nil)
			dest = self.clone
			Cv::bitwise_and(self.input_array, other.input_array, dest.output_array, mask&.input_array)
			dest
		end

		def bitwise_or(other, mask = nil)
			dest = self.clone
			Cv::bitwise_or(self.input_array, other.input_array, dest.output_array, mask&.input_array)
			dest
		end

		def bitwise_xor(other, mask = nil)
			dest = self.clone
			Cv::bitwise_xor(self.input_array, other.input_array, dest.output_array, mask&.input_array)
			dest
		end

		def bitwise_not(mask = nil)
			dest = self.clone
			Cv::bitwise_not(self.input_array, dest.output_array, mask&.input_array)
			dest
		end

		def to_s
			"<#{self.class.name}:#{self.rows}x#{self.cols},type=#{self.type_to_string},channel=#{self.channels}>"
		end

		def median_blur(ksize)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::median_blur(self.input_array, dest.output_array, ksize)
		end

		#### Image Procs - make a more Ruby like interface

		# rb_mCv.define_module_function("median_blur", &cv::medianBlur,
		# 															Arg("src"), Arg("dst"), Arg("ksize"));
		#
		# rb_mCv.define_module_function("gaussian_blur", &cv::GaussianBlur,
		# 															Arg("src"), Arg("dst"), Arg("ksize"), Arg("sigma_x"), Arg("sigma_y") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("bilateral_filter", &cv::bilateralFilter,
		# 															Arg("src"), Arg("dst"), Arg("d"), Arg("sigma_color"), Arg("sigma_space"), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("box_filter", &cv::boxFilter,
		# 															Arg("src"), Arg("dst"), Arg("ddepth"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("normalize") = static_cast<bool>(true), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("sqr_box_filter", &cv::sqrBoxFilter,
		# 															Arg("src"), Arg("dst"), Arg("ddepth"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1, -1)), Arg("normalize") = static_cast<bool>(true), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("blur", &cv::blur,
		# 															Arg("src"), Arg("dst"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("stack_blur", &cv::stackBlur,
		# 															Arg("src"), Arg("dst"), Arg("ksize"));
		#
		# rb_mCv.define_module_function("filter2_d", &cv::filter2D,
		# 															Arg("src"), Arg("dst"), Arg("ddepth"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("sep_filter2_d", &cv::sepFilter2D,
		# 															Arg("src"), Arg("dst"), Arg("ddepth"), Arg("kernel_x"), Arg("kernel_y"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("sobel", &cv::Sobel,
		# 															Arg("src"), Arg("dst"), Arg("ddepth"), Arg("dx"), Arg("dy"), Arg("ksize") = static_cast<int>(3), Arg("scale") = static_cast<double>(1), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("spatial_gradient", &cv::spatialGradient,
		# 															Arg("src"), Arg("dx"), Arg("dy"), Arg("ksize") = static_cast<int>(3), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("scharr", &cv::Scharr,
		# 															Arg("src"), Arg("dst"), Arg("ddepth"), Arg("dx"), Arg("dy"), Arg("scale") = static_cast<double>(1), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("laplacian", &cv::Laplacian,
		# 															Arg("src"), Arg("dst"), Arg("ddepth"), Arg("ksize") = static_cast<int>(1), Arg("scale") = static_cast<double>(1), Arg("delta") = static_cast<double>(0), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, double, double, int, bool)>("canny", &cv::Canny,
		# Arg("image"), Arg("edges"), Arg("threshold1"), Arg("threshold2"), Arg("aperture_size") = static_cast<int>(3), Arg("l2gradient") = static_cast<bool>(false));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, double, double, bool)>("canny", &cv::Canny,
		# Arg("dx"), Arg("dy"), Arg("edges"), Arg("threshold1"), Arg("threshold2"), Arg("l2gradient") = static_cast<bool>(false));
		#
		def corner_min_eigen_val(block_size, ksize = 3, border_type = Cv::BorderTypes::BORDER_DEFAULT)
			dest = Cv::Mat1f.new(self.rows, self.cols)
			Cv::corner_min_eigen_val(self.input_array, dest.output_array, block_size, ksize, border_type)
			dest
		end

		def corner_harris(block_size, ksize, k, border_type = Cv::BorderTypes::BORDER_DEFAULT)
			dest = Cv::Mat1f.new(self.rows, self.cols)
			Cv::corner_harris(self.input_array, dest.output_array, block_size, ksize, k, border_type)
			dest
		end

		# rb_mCv.define_module_function("corner_harris", &cv::cornerHarris,
		# 															Arg("src"), Arg("dst"), Arg("block_size"), Arg("ksize"), Arg("k"), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#

		def corner_eigen_vals_and_vecs(block_size, ksize, border_type = Cv::BorderTypes::BORDER_DEFAULT)
			dest = Cv::Mat6f.new(self.rows, self.cols)
			Cv::corner_eigen_vals_and_vecs(self.input_array, dest.output_array, block_size, ksize, border_type)
			dest
		end

		def pre_corner_detect(ksize, border_type = Cv::BorderTypes::BORDER_DEFAULT)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::pre_corner_detect(self.input_array, dest.output_array, ksize, border_type)
			dest
		end

		def corner_sub_pix(corners, win_size, zero_zone, criteria)
			Cv::corner_sub_pix(self.input_array, corners, win_size, zero_zone, criteria)
			corners
		end

		# rb_mCv.define_module_function("corner_sub_pix", &cv::cornerSubPix,
		# 															Arg("image"), Arg("corners"), Arg("win_size"), Arg("zero_zone"), Arg("criteria"));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, cv::InputArray, int, bool, double)>("good_features_to_track", &cv::goodFeaturesToTrack,
		# Arg("image"), Arg("corners"), Arg("max_corners"), Arg("quality_level"), Arg("min_distance"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("block_size") = static_cast<int>(3), Arg("use_harris_detector") = static_cast<bool>(false), Arg("k") = static_cast<double>(0.04));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, cv::InputArray, int, int, bool, double)>("good_features_to_track", &cv::goodFeaturesToTrack,
		# Arg("image"), Arg("corners"), Arg("max_corners"), Arg("quality_level"), Arg("min_distance"), Arg("mask"), Arg("block_size"), Arg("gradient_size"), Arg("use_harris_detector") = static_cast<bool>(false), Arg("k") = static_cast<double>(0.04));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, double, double, cv::InputArray, cv::OutputArray, int, int, bool, double)>("good_features_to_track", &cv::goodFeaturesToTrack,
		# Arg("image"), Arg("corners"), Arg("max_corners"), Arg("quality_level"), Arg("min_distance"), Arg("mask"), Arg("corners_quality"), Arg("block_size") = static_cast<int>(3), Arg("gradient_size") = static_cast<int>(3), Arg("use_harris_detector") = static_cast<bool>(false), Arg("k") = static_cast<double>(0.04));
		#
		# rb_mCv.define_module_function("hough_lines", &cv::HoughLines,
		# 															Arg("image"), Arg("lines"), Arg("rho"), Arg("theta"), Arg("threshold"), Arg("srn") = static_cast<double>(0), Arg("stn") = static_cast<double>(0), Arg("min_theta") = static_cast<double>(0), Arg("max_theta") = static_cast<double>(CV_PI));
		#
		# rb_mCv.define_module_function("hough_lines_p", &cv::HoughLinesP,
		# 															Arg("image"), Arg("lines"), Arg("rho"), Arg("theta"), Arg("threshold"), Arg("min_line_length") = static_cast<double>(0), Arg("max_line_gap") = static_cast<double>(0));
		#
		# rb_mCv.define_module_function("hough_lines_point_set", &cv::HoughLinesPointSet,
		# 															Arg("point"), Arg("lines"), Arg("lines_max"), Arg("threshold"), Arg("min_rho"), Arg("max_rho"), Arg("rho_step"), Arg("min_theta"), Arg("max_theta"), Arg("theta_step"));
		#
		# rb_mCv.define_module_function("hough_circles", &cv::HoughCircles,
		# 															Arg("image"), Arg("circles"), Arg("method"), Arg("dp"), Arg("min_dist"), Arg("param1") = static_cast<double>(100), Arg("param2") = static_cast<double>(100), Arg("min_radius") = static_cast<int>(0), Arg("max_radius") = static_cast<int>(0));
		#
		# rb_mCv.define_module_function("erode", &cv::erode,
		# 															Arg("src"), Arg("dst"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("iterations") = static_cast<int>(1), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar &>(cv::morphologyDefaultBorderValue()));
		#
		# rb_mCv.define_module_function("dilate", &cv::dilate,
		# 															Arg("src"), Arg("dst"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("iterations") = static_cast<int>(1), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar &>(cv::morphologyDefaultBorderValue()));
		#
		# rb_mCv.define_module_function("morphology_ex", &cv::morphologyEx,
		# 															Arg("src"), Arg("dst"), Arg("op"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("iterations") = static_cast<int>(1), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar &>(cv::morphologyDefaultBorderValue()));
		#
		# rb_mCv.define_module_function("resize", &cv::resize,
		# 															Arg("src"), Arg("dst"), Arg("dsize"), Arg("fx") = static_cast<double>(0), Arg("fy") = static_cast<double>(0), Arg("interpolation") = static_cast<int>(cv::InterpolationFlags::INTER_LINEAR));
		#
		# rb_mCv.define_module_function("warp_affine", &cv::warpAffine,
		# 															Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::InterpolationFlags::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BorderTypes::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar &>(cv::Scalar()));
		#
		# rb_mCv.define_module_function("warp_perspective", &cv::warpPerspective,
		# 															Arg("src"), Arg("dst"), Arg("m"), Arg("dsize"), Arg("flags") = static_cast<int>(cv::InterpolationFlags::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BorderTypes::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar &>(cv::Scalar()));
		#
		# rb_mCv.define_module_function("remap", &cv::remap,
		# 															Arg("src"), Arg("dst"), Arg("map1"), Arg("map2"), Arg("interpolation"), Arg("border_mode") = static_cast<int>(cv::BorderTypes::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar &>(cv::Scalar()));
		#
		# rb_mCv.define_module_function("convert_maps", &cv::convertMaps,
		# 															Arg("map1"), Arg("map2"), Arg("dstmap1"), Arg("dstmap2"), Arg("dstmap1type"), Arg("nninterpolation") = static_cast<bool>(false));
		#
		# rb_mCv.define_module_function<cv::Mat(*)(cv::Point2f, double, double)>("get_rotation_matrix2_d", &cv::getRotationMatrix2D,
		# Arg("center"), Arg("angle"), Arg("scale"));
		#
		# rb_mCv.define_module_function("get_rotation_matrix2_d_", &cv::getRotationMatrix2D_,
		# 															Arg("center"), Arg("angle"), Arg("scale"));
		#
		# rb_mCv.define_module_function<cv::Mat(*)(cv::Point2f, double, double)>("get_rotation_matrix2_d", &cv::getRotationMatrix2D,
		# Arg("center"), Arg("angle"), Arg("scale"));
		#
		# rb_mCv.define_module_function<cv::Mat(*)(const cv::Point_<float>[], const cv::Point_<float>[])>("get_affine_transform", &cv::getAffineTransform,
		# Arg("src"), Arg("dst"));
		#
		# rb_mCv.define_module_function("invert_affine_transform", &cv::invertAffineTransform,
		# 															Arg("m"), Arg("i_m"));
		#
		# rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray, int)>("get_perspective_transform", &cv::getPerspectiveTransform,
		# Arg("src"), Arg("dst"), Arg("solve_method") = static_cast<int>(cv::DecompTypes::DECOMP_LU));
		#
		# rb_mCv.define_module_function<cv::Mat(*)(const cv::Point_<float>[], const cv::Point_<float>[], int)>("get_perspective_transform", &cv::getPerspectiveTransform,
		# Arg("src"), Arg("dst"), Arg("solve_method") = static_cast<int>(cv::DecompTypes::DECOMP_LU));
		#
		# rb_mCv.define_module_function<cv::Mat(*)(cv::InputArray, cv::InputArray)>("get_affine_transform", &cv::getAffineTransform,
		# Arg("src"), Arg("dst"));
		#
		# rb_mCv.define_module_function("get_rect_sub_pix", &cv::getRectSubPix,
		# 															Arg("image"), Arg("patch_size"), Arg("center"), Arg("patch"), Arg("patch_type") = static_cast<int>(-1));
		#
		# rb_mCv.define_module_function("log_polar", &cv::logPolar,
		# 															Arg("src"), Arg("dst"), Arg("center"), Arg("m"), Arg("flags"));
		#
		# rb_mCv.define_module_function("linear_polar", &cv::linearPolar,
		# 															Arg("src"), Arg("dst"), Arg("center"), Arg("max_radius"), Arg("flags"));
		#
		# rb_mCv.define_module_function("warp_polar", &cv::warpPolar,
		# 															Arg("src"), Arg("dst"), Arg("dsize"), Arg("center"), Arg("max_radius"), Arg("flags"));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int, int)>("integral", &cv::integral,
		# Arg("src"), Arg("sum"), Arg("sqsum"), Arg("tilted"), Arg("sdepth") = static_cast<int>(-1), Arg("sqdepth") = static_cast<int>(-1));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int)>("integral", &cv::integral,
		# Arg("src"), Arg("sum"), Arg("sdepth") = static_cast<int>(-1));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, int, int)>("integral", &cv::integral,
		# Arg("src"), Arg("sum"), Arg("sqsum"), Arg("sdepth") = static_cast<int>(-1), Arg("sqdepth") = static_cast<int>(-1));
		#
		# rb_mCv.define_module_function("accumulate", &cv::accumulate,
		# 															Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
		#
		# rb_mCv.define_module_function("accumulate_square", &cv::accumulateSquare,
		# 															Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
		#
		# rb_mCv.define_module_function("accumulate_product", &cv::accumulateProduct,
		# 															Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
		#
		# rb_mCv.define_module_function("accumulate_weighted", &cv::accumulateWeighted,
		# 															Arg("src"), Arg("dst"), Arg("alpha"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
		#
		# rb_mCv.define_module_function("phase_correlate", &cv::phaseCorrelate,
		# 															Arg("src1"), Arg("src2"), Arg("window") = static_cast<cv::InputArray>(cv::noArray()), Arg("response") = static_cast<double *>(0));
		#
		# rb_mCv.define_module_function("create_hanning_window", &cv::createHanningWindow,
		# 															Arg("dst"), Arg("win_size"), Arg("type"));
		#
		# rb_mCv.define_module_function("div_spectrums", &cv::divSpectrums,
		# 															Arg("a"), Arg("b"), Arg("c"), Arg("flags"), Arg("conj_b") = static_cast<bool>(false));
		#

		def threshold(threshold, max_value, threshold_type)
			dest = self.class.new(self.rows, self.cols, self.type)
			computed = Cv::threshold(self.input_array, dest.output_array, threshold, max_value, threshold_type)
			[dest, computed]
		end

		def adaptive_threshold(max_value, adaptive_method, threshold_type, block_size, c)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::adaptive_threshold(self.input_array, dest.output_array, max_value, adaptive_method, threshold_type, block_size, c)
			dest
		end

		def pyr_down(dstsize = Cv::Size.new(), border_type = Cv::BorderTypes::BORDER_DEFAULT)
			dest = self.class.new(dstsize, self.type)
			Cv::pyr_down(self.input_array, dest.output_array, dstsize, border_type)
			dest
		end

		def pyr_up(dstsize = Cv::Size.new(), border_type = Cv::BorderTypes::BORDER_DEFAULT)
			dest = self.class.new(dstsize, self.type)
			Cv::pyr_up(self.input_array, dest.output_array, dstsize, border_type)
			dest
		end

		def in_range(lowerb, upperb)
			dest = self.class.new(self.rows, self.cols, CV_8UC1)
			Cv::in_range(self.input_array, lowerb.input_array, upperb.input_array, dest.output_array)
			dest
		end

		def absdiff(other)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::absdiff(self.input_array, other.input_array, dest.output_array)
			dest
		end

		# rb_mCv.define_module_function("pyr_up", &cv::pyrUp,
		# 															Arg("src"), Arg("dst"), Arg("dstsize") = static_cast<const cv::Size &>(cv::Size()), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# rb_mCv.define_module_function("build_pyramid", &cv::buildPyramid,
		# 															Arg("src"), Arg("dst"), Arg("maxlevel"), Arg("border_type") = static_cast<int>(cv::BorderTypes::BORDER_DEFAULT));
		#
		# //  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, cv::InputArray, cv::OutputArray, int, const int*, const float**, bool, bool)>("calc_hist", &cv::calcHist,
		# //   Arg("images"), Arg("nimages"), Arg("channels"), Arg("mask"), Arg("hist"), Arg("dims"), Arg("hist_size"), Arg("ranges"), Arg("uniform") = static_cast<bool>(true), Arg("accumulate") = static_cast<bool>(false));
		#
		# //  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, cv::InputArray, cv::SparseMat&, int, const int*, const float**, bool, bool)>("calc_hist", &cv::calcHist,
		# //    Arg("images"), Arg("nimages"), Arg("channels"), Arg("mask"), Arg("hist"), Arg("dims"), Arg("hist_size"), Arg("ranges"), Arg("uniform") = static_cast<bool>(true), Arg("accumulate") = static_cast<bool>(false));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, const std::vector<int>&, cv::InputArray, cv::OutputArray, const std::vector<int>&, const std::vector<float>&, bool)>("calc_hist", &cv::calcHist,
		# Arg("images"), Arg("channels"), Arg("mask"), Arg("hist"), Arg("hist_size"), Arg("ranges"), Arg("accumulate") = static_cast<bool>(false));
		#
		# //  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, cv::InputArray, cv::OutputArray, const float**, double, bool)>("calc_back_project", &cv::calcBackProject,
		# //   Arg("images"), Arg("nimages"), Arg("channels"), Arg("hist"), Arg("back_project"), Arg("ranges"), Arg("scale") = static_cast<double>(1), Arg("uniform") = static_cast<bool>(true));
		#
		# //rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, const cv::SparseMat&, cv::OutputArray, const float**, double, bool)>("calc_back_project", &cv::calcBackProject,
		# //    Arg("images"), Arg("nimages"), Arg("channels"), Arg("hist"), Arg("back_project"), Arg("ranges"), Arg("scale") = static_cast<double>(1), Arg("uniform") = static_cast<bool>(true));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, const std::vector<int>&, cv::InputArray, cv::OutputArray, const std::vector<float>&, double)>("calc_back_project", &cv::calcBackProject,
		# Arg("images"), Arg("channels"), Arg("hist"), Arg("dst"), Arg("ranges"), Arg("scale"));
		#
		# rb_mCv.define_module_function<double(*)(cv::InputArray, cv::InputArray, int)>("compare_hist", &cv::compareHist,
		# Arg("h1"), Arg("h2"), Arg("method"));
		#
		# rb_mCv.define_module_function<double(*)(const cv::SparseMat&, const cv::SparseMat&, int)>("compare_hist", &cv::compareHist,
		# Arg("h1"), Arg("h2"), Arg("method"));
		#
		# rb_mCv.define_module_function("equalize_hist", &cv::equalizeHist,
		# 															Arg("src"), Arg("dst"));
		#
		# rb_mCv.define_module_function("create_clahe", &cv::createCLAHE,
		# 															Arg("clip_limit") = static_cast<double>(40.0), Arg("tile_grid_size") = static_cast<cv::Size>(cv::Size(8, 8)));
		#
		# rb_mCv.define_module_function("emd", &cv::EMD,
		# 															Arg("signature1"), Arg("signature2"), Arg("dist_type"), Arg("cost") = static_cast<cv::InputArray>(cv::noArray()), Arg("lower_bound") = static_cast<float *>(0), Arg("flow") = static_cast<cv::OutputArray>(cv::noArray()));
		#
		# rb_mCv.define_module_function("wrapper_emd", &cv::wrapperEMD,
		# 															Arg("signature1"), Arg("signature2"), Arg("dist_type"), Arg("cost") = static_cast<cv::InputArray>(cv::noArray()), Arg("lower_bound") = static_cast<cv::Ptr<float>>(cv::Ptr<float>()), Arg("flow") = static_cast<cv::OutputArray>(cv::noArray()));
		#
		# rb_mCv.define_module_function("watershed", &cv::watershed,
		# 															Arg("image"), Arg("markers"));
		#
		# rb_mCv.define_module_function("pyr_mean_shift_filtering", &cv::pyrMeanShiftFiltering,
		# 															Arg("src"), Arg("dst"), Arg("sp"), Arg("sr"), Arg("max_level") = static_cast<int>(1), Arg("termcrit") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::MAX_ITER+cv::TermCriteria::Type::EPS,5,1)));
		#
		# rb_mCv.define_module_function("grab_cut", &cv::grabCut,
		# 															Arg("img"), Arg("mask"), Arg("rect"), Arg("bgd_model"), Arg("fgd_model"), Arg("iter_count"), Arg("mode") = static_cast<int>(cv::GC_EVAL));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, int, int, int)>("distance_transform", &cv::distanceTransform,
		# Arg("src"), Arg("dst"), Arg("labels"), Arg("distance_type"), Arg("mask_size"), Arg("label_type") = static_cast<int>(cv::DistanceTransformLabelTypes::DIST_LABEL_CCOMP));
		#
		# rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, int, int)>("distance_transform", &cv::distanceTransform,
		# Arg("src"), Arg("dst"), Arg("distance_type"), Arg("mask_size"), Arg("dst_type") = static_cast<int>(CV_32F));
		#
		# rb_mCv.define_module_function<int(*)(cv::InputOutputArray, cv::InputOutputArray, cv::Point, cv::Scalar, cv::Rect*, cv::Scalar, cv::Scalar, int)>("flood_fill", &cv::floodFill,
		# Arg("image"), Arg("mask"), Arg("seed_point"), Arg("new_val"), Arg("rect") = static_cast<cv::Rect *>(0), Arg("lo_diff") = static_cast<cv::Scalar>(cv::Scalar()), Arg("up_diff") = static_cast<cv::Scalar>(cv::Scalar()), Arg("flags") = static_cast<int>(4));
		#
		# rb_mCv.define_module_function<int(*)(cv::InputOutputArray, cv::Point, cv::Scalar, cv::Rect*, cv::Scalar, cv::Scalar, int)>("flood_fill", &cv::floodFill,
		# Arg("image"), Arg("seed_point"), Arg("new_val"), Arg("rect") = static_cast<cv::Rect *>(0), Arg("lo_diff") = static_cast<cv::Scalar>(cv::Scalar()), Arg("up_diff") = static_cast<cv::Scalar>(cv::Scalar()), Arg("flags") = static_cast<int>(4));
		#
		# rb_mCv.define_module_function("blend_linear", &cv::blendLinear,
		# 															Arg("src1"), Arg("src2"), Arg("weights1"), Arg("weights2"), Arg("dst"));
		#

		def cvt_color(color_conversion_code, dst_cn = 0)
			dest = self.class.new(self.rows, self.cols, self.type)
			computed = Cv::cvt_color(self.input_array, dest.output_array, color_conversion_code, dst_cn)
			dest
		end

		def count_non_zero
			Cv.count_non_zero(self.input_array)
		end

		def determinant
			Cv.determinant(self.input_array)
		end

		def invert(flags = Cv::DecompTypes::DECOMP_LU)
			dest = self.class.new(self.cols, self.rows, self.type)
			Cv.invert(self.input_array, dest.output_array, flags)
			dest
		end

		def min_max_loc(mask = Cv::no_array)
			Cv.min_max_loc(self.input_array, mask)
		end

		def normalize(alpha = 1, beta = 0, norm_type = Cv::NormTypes::NORM_L2, dtype = -1, mask =  Cv::no_array)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.normalize(self.input_array, dest.input_output_array, alpha, beta, norm_type, dtype, mask)
			dest
		end

		def sum
			Cv.sum(self.input_array)
		end

		def trace
			Cv.trace(self.input_array)
		end

		def mul_transposed(ata = true, delta = Cv::no_array, scale = 1, dtype = -1)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.mul_transposed(self.input_array, dest.output_array, ata, delta, scale, dtype)
			dest
		end

		def perspective_transform(matrix)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.perspective_transform(self.input_array, dest.output_array, matrix.input_array)
			dest
		end

		def transform(matrix)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.transform(self.input_array, dest.output_array, matrix.input_array)
			dest
		end

		def transpose
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.transpose(self.input_array, dest.output_array)
			dest
		end

		# rb_mCv.define_module_function("cvt_color_two_plane", &cv::cvtColorTwoPlane,
		# 															Arg("src1"), Arg("src2"), Arg("dst"), Arg("code"));
		#
		# rb_mCv.define_module_function("demosaicing", &cv::demosaicing,
		# 															Arg("src"), Arg("dst"), Arg("code"), Arg("dst_cn") = static_cast<int>(0));
		#
		# rb_mCv.define_module_function("moments", &cv::moments,
		# 															Arg("array"), Arg("binary_image") = static_cast<bool>(false));
		#
		# rb_mCv.define_module_function<void(*)(const cv::Moments&, double[7])>("hu_moments", &cv::HuMoments,
		# Arg("moments"), Arg("hu"));
		#
		# rb_mCv.define_module_function<void(*)(const cv::Moments&, cv::OutputArray)>("hu_moments", &cv::HuMoments,
		# Arg("m"), Arg("hu"));

		# Calib3d
		def find_chessboard_corners(pattern_size, flags = Cv::CALIB_CB_ADAPTIVE_THRESH + Cv::CALIB_CB_NORMALIZE_IMAGE)
			mat = Cv::Mat2f.new
			corners = Cv::OutputArray.new(mat)
			found = Cv::find_chessboard_corners(self.input_array, pattern_size, corners, flags)
			[mat, found]
		end
		# CV_EXPORTS_W bool findChessboardCorners( InputArray image, Size patternSize, OutputArray corners,
		#                                          int flags = CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE );
	end
end
