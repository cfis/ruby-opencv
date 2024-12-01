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

		def to_s
			"<#{self.class.name}:#{self.rows}x#{self.cols},type=#{self.type_to_string},channel=#{self.channels}>"
		end
	end
end
