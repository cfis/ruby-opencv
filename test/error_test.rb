#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::Error
class ErrorTest < OpenCVTestCase
  def test_cverror
    assert_equal(StandardError, Cv::Error.superclass)
    begin
      raise Cv::Error
    rescue
      assert_equal(Cv::Error, $!.class)
    end
  end

  
  def test_subclass
    errors = [Cv::StsBackTrace, Cv::StsError, Cv::StsInternal, Cv::StsNoMem, Cv::StsBadArg, Cv::StsBadFunc, Cv::StsNoConv, Cv::StsAutoTrace, Cv::HeaderIsNull, Cv::BadImageSize, Cv::BadOffset, Cv::BadDataPtr, Cv::BadStep, Cv::BadModelOrChSeq, Cv::BadNumChannels, Cv::BadNumChannel1U, Cv::BadDepth, Cv::BadAlphaChannel, Cv::BadOrder, Cv::BadOrigin, Cv::BadAlign, Cv::BadCallBack, Cv::BadTileSize, Cv::BadCOI, Cv::BadROISize, Cv::MaskIsTiled, Cv::StsNullPtr, Cv::StsVecLengthErr, Cv::StsFilterStructContentErr, Cv::StsKernelStructContentErr, Cv::StsFilterOffsetErr, Cv::StsBadSize, Cv::StsDivByZero, Cv::StsInplaceNotSupported, Cv::StsObjectNotFound, Cv::StsUnmatchedFormats, Cv::StsBadFlag, Cv::StsBadPoint, Cv::StsBadMask, Cv::StsUnmatchedSizes, Cv::StsUnsupportedFormat, Cv::StsOutOfRange, Cv::StsParseError, Cv::StsNotImplemented, Cv::StsBadMemBlock, Cv::StsAssert, Cv::GpuNotSupported, Cv::GpuApiCallError]
    errors.each { |err|
      assert_equal(Cv::Error, err.superclass)
      begin
        raise err
      rescue err
        assert_equal(err, $!.class)
      rescue
        flunk("Failed to catch #{err}")
      end
      begin
        raise err
      rescue Cv::Error
        assert_equal(err, $!.class)
      rescue
        flunk("Failed to catch #{err}")
      end
      begin
        raise err
      rescue
        assert_equal(err, $!.class)
      end
    }
  end
end
